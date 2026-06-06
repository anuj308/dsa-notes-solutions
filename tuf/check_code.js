const fs = require('fs');
const html = fs.readFileSync('dsa_revision_v2.html', 'utf8');
const scriptStart = html.indexOf('<script>');
const scriptEnd = html.indexOf('</script>', scriptStart + 1);
const js = html.substring(scriptStart + 8, scriptEnd);
const lines = js.split('\n');

for(let i = 0; i < lines.length; i++) {
  const line = lines[i];
  if(line.includes("code:'")) {
    const codeMatch = line.match(/code:'(.*)'/);
    if(!codeMatch) {
      console.log('Possible unclosed code string at line', (i+1));
      console.log('  Content:', line.substring(0, 120));
    }
  }
}
console.log('Finished checking');
