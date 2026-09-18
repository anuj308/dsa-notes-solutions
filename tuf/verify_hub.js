#!/usr/bin/env node
/* verify_hub.js — sanity checks for the generated dsa-revision.html */
'use strict';
const fs = require('fs');
const path = require('path');
const vm = require('vm');

let fail = 0;
const bad = m => { console.log('  ✗ ' + m); fail++; };
const ok = m => console.log('  ✓ ' + m);

const P = require('./problems.json');
const html = fs.readFileSync('dsa-revision.html', 'utf8');

console.log('== 1. Data shape ==');
if (P.length === 0) bad('no problems parsed');
else ok(P.length + ' problems');
let shapeBad = 0;
for (const p of P) {
  if (!p.id || !p.title || !p.file || !p.topic) { bad('missing core field in ' + JSON.stringify(p).slice(0, 80)); shapeBad++; break; }
  if (!Array.isArray(p.approaches) || p.approaches.length === 0) { bad('no approaches: ' + p.title); shapeBad++; }
  for (const a of p.approaches) {
    if (!a.langs || Object.keys(a.langs).length === 0) { bad('approach without languages: ' + p.title); shapeBad++; }
    for (const [k, v] of Object.entries(a.langs || {})) {
      if (typeof v.code !== 'string' || v.code.length === 0) { bad('empty code: ' + p.title + ' / ' + k + ' (' + (a.srcFile || p.file) + ')'); shapeBad++; }
    }
  }
}
if (!shapeBad) ok('all cards have approaches with non-empty code');

console.log('== 2. Verbatim preservation ==');
/* TCS-mode files (college assignment sheets) intentionally drop boilerplate
   comment lines during the build (see TCS_SKIP_PATTERNS in build_hub.js:
   "// Company Tags:", "// Input format :", sample test cases, ...).
   For those, every kept code line must still appear in the source IN ORDER.
   All other files require an exact contiguous verbatim match. */
const TCS_FILE_RE = /^dsa\/unit \d|^dsa\/allquestion\.js$/;
function isOrderedLineSubsequence(code, src) {
  const srcLines = src.split('\n');
  let i = 0;
  for (const l of code.split('\n')) {
    if (l.trim() === '') continue;              // blank lines are layout only
    while (i < srcLines.length && srcLines[i] !== l) i++;
    if (i >= srcLines.length) return false;
    i++;
  }
  return true;
}
/* code may live in tuf/ (primary files) or in ../LeetcodeDaliy/ + ../dsa/ */
function readSource(file) {
  const candidates = [
    path.join(__dirname, file),
    path.join(__dirname, '..', file.replace(/^LeetcodeDaliy\//, 'LeetcodeDaliy/').replace(/^dsa\//, 'dsa/'))
  ];
  for (const c of candidates) { try { return fs.readFileSync(c, 'utf8'); } catch {} }
  return null;
}
const srcCache = new Map();
function srcOf(file) {
  if (!srcCache.has(file)) srcCache.set(file, readSource(file));
  return srcCache.get(file);
}
let checked = 0, missing = [], tcsCount = 0;
for (const p of P) {
  for (const a of p.approaches) {
    const src = srcOf(a.srcFile || p.file);
    if (!src) { bad('cannot read ' + (a.srcFile || p.file)); continue; }
    for (const [lang, v] of Object.entries(a.langs)) {
      checked++;
      const tcsFile = TCS_FILE_RE.test(a.srcFile || p.file);
      const verbatim = src.includes(v.code) || (tcsFile && isOrderedLineSubsequence(v.code, src));
      if (!verbatim) missing.push(p.title + ' [' + lang + '] (' + (a.srcFile || p.file) + ')');
      else if (tcsFile && !src.includes(v.code)) tcsCount++;
    }
  }
}
if (missing.length) { bad(missing.length + '/' + checked + ' code chunks NOT verbatim:'); missing.slice(0, 10).forEach(m => bad('   ' + m)); }
else if (tcsCount) ok(checked + ' code chunks verified (' + (checked - tcsCount) + ' exact, ' + tcsCount + ' TCS boilerplate-stripped, line order preserved)');
else ok('all ' + checked + ' code chunks are exact substrings of their source files');

console.log('== 3. Injection safety ==');
const scriptStart = html.indexOf('<script>');
const scriptEnd = html.indexOf('</' + 'script>', scriptStart);
const blob = scriptEnd === -1 ? '' : html.slice(scriptStart + 8, scriptEnd);
if (scriptEnd === -1) bad('no closing script tag');
else {
  if (blob.includes('</' + 'script')) bad('embedded code contains a literal script closer');
  else ok('no premature </script> inside embedded data');
  console.log('== 4. Script syntax ==');
  try { new vm.Script(blob, { filename: 'dsa-revision-inline.js' }); ok('inline script parses cleanly'); }
  catch (e) { bad('inline script syntax error: ' + e.message); }
  const mustHave = ['const PROBLEMS', 'const ALGORITHMS', 'const SUGGESTED', 'function render()', 'renderAlgos', 'renderSuggested', 'localStorage'];
  for (const m of mustHave) if (!blob.includes(m)) bad('missing in script: ' + m);
  if (fail === 0) ok('all expected functions present');
}

console.log('== 5. Placeholder leftovers ==');
for (const ph of ['__PROBLEMS_JSON__', '__ALGOS_JSON__', '__SUGGESTED_JSON__', '__META_JSON__', '__GENDATE__', '__NPROBLEMS__', '__NTOPICS__', '__NALGOS__']) {
  if (html.includes(ph)) bad('unreplaced placeholder ' + ph);
}
if (fail === 0) ok('no placeholders left');

console.log('== 6. Counts in footer match data ==');
const metaMatch = blob.match(/const META\s*=\s*(\{.*?\});/);
if (!metaMatch) { bad('META object not found in inline script'); }
else {
  let meta = null;
  try { meta = JSON.parse(metaMatch[1]); } catch (e) { bad('META JSON does not parse: ' + e.message); }
  if (meta) {
    const checks = [
      ['<b>' + P.length + '</b> problems', 'problem count', P.length],
      ['<b>' + meta.topicsCount + '</b> topics', 'topic count', meta.topicsCount],
      ['<b>' + meta.algosCount + '</b> algorithm templates', 'algo count', meta.algosCount]
    ];
    let allOk = true;
    for (const [needle, label, n] of checks) {
      if (!html.includes(needle)) { bad('footer ' + label + ' mismatch (expected ' + n + ')'); allOk = false; }
    }
    if (allOk) ok('footer counts match data (' + P.length + ' problems, ' + meta.topicsCount + ' topics, ' + meta.algosCount + ' algos)');
  }
}
console.log(fail === 0 ? '\nALL CHECKS PASSED ✓' : '\n' + fail + ' CHECK FAILURE(S) ✗');
process.exit(fail ? 1 : 0);
