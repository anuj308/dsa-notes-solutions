#!/usr/bin/env node
/* build_hub.js — scans local solution files, parses problems, generates dsa-revision.html
   Sources: tuf/*.cpp (primary), ../LeetcodeDaliy/**, ../dsa/** */
'use strict';
const fs = require('fs');
const path = require('path');

const CPP_FILES = [
  '01partten.cpp','02stl.cpp','03BasicMath.cpp','03recursion.cpp','04hashing.cpp','05sorting.cpp',
  '06arraylargest.cpp','07ArraysPart2.cpp','08ArraysPart3.cpp','09ArraysPart4.cpp','10ArraysMediumPart5.cpp',
  '11ArraysMediumHardPart6.cpp','12ArraysHardPart7.cpp','12BinarySearchEasy.cpp','13BinarySearchMedium.cpp',
  '14BinarySearchHard.cpp','15String.cpp','16LinkListBasic.cpp','17LinkListMedium.cpp','19Recurion2.cpp',
  '20Bits.cpp','21Stack&Queue.cpp','22SlidingWindow.cpp','23Greedy.cpp','24Dp.cpp','25BinaryTreePart1.cpp',
  '26BinaryTreePart2.cpp','27BinarySeacrchTree.cpp','28GraphPart1.cpp','29GraphPart2.cpp','30GraphPart3.cpp',
  '31GraphPart4.cpp','32DPPart1.cpp','learn.cpp','demo.cpp'
];

const EXCLUDED = [
  'README.md','check_code.js','code_data.js','input.txt','output.txt','dsa.html','dsa_revision_v2.html',
  'learn.exe','demo.exe','a.out','node_modules/','.vscode/'
];

/* ---- additional source roots (scanned recursively) ---- */
const EXTRA_DIRS = [
  { root: '../LeetcodeDaliy', label: 'LeetcodeDaliy' },
  { root: '../dsa',           label: 'dsa' }
];
const SRC_EXT = /\.(cpp|cc|cxx|py|java|js)$/i;
/* whole-file junk: not problems */
const SKIP_FILES = new Set(['tempCodeRunnerFile.py', 'cloud.txt', 'read.txt']);

/* college "Single File Programming Question" assignment boilerplate (stripped);
   marker/labels may be commented (// ...) or plain text (q6cla.cpp style) */
const TCS_SKIP_PATTERNS = [
  /^\s*\/\/?\s*problem statement\s*$/i,
  /^\s*\/\/?\s*(input format|output format|code constraints|sample test cases|company tags?)\s*:/i,
  /^\s*\/\/?\s*(for example|explanation|follow\s*up|expected time|expected auxili)/i,
  /^\s*\/\/?\s*(input\s*\d+\s*:|output\s*\d+\s*:)/i,
  /^\s*\/\/?\s*refer to the sample/i
];

/* GFG slug -> [canonical title, difficulty] (used when the URL slug is terse) */
const GFG_HINTS = {
  'minimum-platforms': ['Minimum Platforms','Medium'],
  'number-of-provinces': ['Number of Provinces','Medium'],
  'bfs-traversal-of-graph': ['BFS Traversal of Graph','Easy'],
  'depth-first-traversal-for-a-graph': ['DFS Traversal of Graph','Easy'],
  'detect-cycle-in-an-undirected-graph': ['Detect Cycle in an Undirected Graph','Medium'],
  'rat-in-a-maze-problem': ['Rat in a Maze','Medium'],
  'number-of-islands': ['Number of Islands','Medium']
};

/* LC number -> [canonical title, difficulty]; used when a segment/file carries
   only a bare number. Only well-known mappings are listed. */
const LC_TITLES = {
  3:['Longest Substring Without Repeating Characters','Medium'],
  13:['Roman to Integer','Easy'],
  20:['Valid Parentheses','Easy'],
  27:['Remove Element','Easy'],
  28:['Find the Index of the First Occurrence in a String','Easy'],
  290:['Word Pattern','Easy'],
  317:['Lexicographically Minimum String After Deleting Stars','Medium'],
  35:['Search Insert Position','Easy'],
  36:['Valid Sudoku','Medium'],
  45:['Jump Game II','Medium'],
  48:['Rotate Image','Medium'],
  50:['Pow(x, n)','Medium'],
  55:['Jump Game','Medium'],
  56:['Merge Intervals','Medium'],
  57:['Insert Interval','Medium'],
  70:['Climbing Stairs','Easy'],
  76:['Minimum Window Substring','Hard'],
  94:['Binary Tree Inorder Traversal','Easy'],
  100:['Same Tree','Easy'],
  101:['Symmetric Tree','Easy'],
  102:['Binary Tree Level Order Traversal','Medium'],
  103:['Binary Tree Zigzag Level Order Traversal','Medium'],
  104:['Maximum Depth of Binary Tree','Easy'],
  110:['Balanced Binary Tree','Easy'],
  124:['Binary Tree Maximum Path Sum','Hard'],
  135:['Candy','Hard'],
  136:['Single Number','Easy'],
  144:['Binary Tree Preorder Traversal','Easy'],
  145:['Binary Tree Postorder Traversal','Easy'],
  169:['Majority Element','Easy'],
  190:['Reverse Bits','Easy'],
  199:['Binary Tree Right Side View','Medium'],
  202:['Happy Number','Easy'],
  209:['Minimum Size Subarray Sum','Medium'],
  213:['House Robber II','Medium'],
  257:['Binary Tree Paths','Easy'],
  258:['Add Digits','Easy'],
  278:['First Bad Version','Easy'],
  3170:['Lexicographically Minimum String After Deleting Stars','Medium'],
  322:['Coin Change','Medium'],
  342:['Power of Four','Easy'],
  386:['Lexicographical Numbers','Medium'],
  387:['First Unique Character in a String','Easy'],
  424:['Longest Repeating Character Replacement','Medium'],
  440:['K-th Smallest in Lexicographical Order','Hard'],
  455:['Assign Cookies','Easy'],
  498:['Diagonal Traverse','Medium'],
  543:['Diameter of Binary Tree','Easy'],
  678:['Valid Parenthesis String','Medium'],
  717:['1-bit and 2-bit Characters','Easy'],
  788:['Rotated Digits','Medium'],
  812:['Largest Triangle Area','Easy'],
  904:['Fruit Into Baskets','Medium'],
  930:['Binary Subarrays With Sum','Medium'],
  966:['Vowel Spellchecker','Medium'],
  987:['Vertical Order Traversal of a Binary Tree','Hard'],
  1004:['Max Consecutive Ones III','Medium'],
  1061:['Lexicographically Smallest Equivalent String','Medium'],
  1248:['Count Number of Nice Subarrays','Medium'],
  1304:['Find N Unique Integers Sum up to Zero','Easy'],
  1317:['Convert Integer to the Sum of Two No-Zero Integers','Easy'],
  1358:['Number of Substrings Containing All Three Characters','Medium'],
  1423:['Maximum Points You Can Obtain from Cards','Medium'],
  1437:['Check If All 1s Are at Least Length K Places Away','Easy'],
  1518:['Water Bottles','Easy'],
  1653:['Minimum Deletions to Make String Balanced','Medium'],
  1716:['Calculate Money in Leetcode Bank','Easy'],
  1792:['Maximum Average Pass Ratio','Medium'],
  1841:['Cyclically Rotating a Grid','Medium'],
  1861:['Rotating the Box','Medium'],
  1930:['Unique Length-3 Palindromic Subsequences','Medium'],
  1935:['Maximum Number of Words You Can Type','Easy'],
  2043:['Simple Bank System','Medium'],
  2125:['Number of Laser Beams in a Bank','Medium'],
  2130:['Maximum Twin Sum of a Linked List','Medium'],
  2154:['Keep Multiplying Found Values by Two','Easy'],
  2169:['Count Operations to Obtain Zero','Easy'],
  2221:['Find Triangular Sum of an Array','Medium'],
  2273:['Find Resultant Array After Removing Anagrams','Easy'],
  2300:['Successful Pairs of Spells and Potions','Medium'],
  2348:['Number of Zero-Filled Subarrays','Medium'],
  2434:['Using a Robot to Print the Lexicographically Smallest String','Medium'],
  2536:['Increment Submatrices by One','Medium'],
  2566:['Maximum Difference by Remapping a Digit','Easy'],
  2785:['Sort Vowels in a String','Medium'],
  2966:['Divide Array Into Arrays With Max Difference','Medium'],
  3005:['Count Elements With Maximum Frequency','Easy'],
  3021:['Alice and Bob Playing Flower Game','Medium'],
  3025:['Find the Number of Ways to Place People I','Medium'],
  3027:['Find the Number of Ways to Place People II','Hard'],
  3100:['Water Bottles II','Medium'],
  3217:['Delete Nodes From Linked List Present in Array','Medium'],
  3227:['Vowels Game in a String','Medium'],
  3228:['Maximum Number of Operations to Move Ones to the End','Medium'],
  3318:['Find X-Sum of All K-Long Subarrays I','Easy'],
  3349:['Adjacent Increasing Subarrays Detection I','Easy'],
  3350:['Adjacent Increasing Subarrays Detection II','Hard'],
  3370:['Smallest Number With All Set Bits','Easy'],
  3403:['Find the Lexicographically Largest String From the Box I','Medium'],
  3442:['Maximum Difference Between Even and Odd Frequency I','Easy'],
  3445:['Maximum Difference Between Even and Odd Frequency II','Hard'],
  3446:['Sort Matrix by Diagonal','Medium'],
  3516:['Find Closest Person','Easy'],
  3541:['Find Most Frequent Vowel and Consonant','Easy'],
  3674:['Minimum Operations to Equalize Array','Easy'],
  3692:['Majority Frequency Characters','Easy'],
  3693:['Climbing Stairs II','Medium']
};

/* garbled/ambiguous filename slugs -> [lc, canonical title, difficulty] */
const BAD_SLUG = {
  '0342-four-of-power.cpp':                      [342,  'Power of Four', 'Easy'],
  '165-compare-version-number.cpp':              [165,  'Compare Version Numbers', 'Medium'],
  '498-diagonal-tranverse.cpp':                  [498,  'Diagonal Traverse', 'Medium'],
  '812-larget-area-triabgle.cpp':                [812,  'Largest Triangle Area', 'Easy'],
  '35upperbound.cpp':                            [35,   'Search Insert Position', 'Easy'],
  '13romantoint.py':                             [13,   'Roman to Integer', 'Easy'],
  '20validparenthess.py':                        [20,   'Valid Parentheses', 'Easy'],
  '48easy.py':                                   [48,   'Rotate Image', 'Medium'],
  '7171-bit-and-2-bit-characters.cpp':           [717,  '1-bit and 2-bit Characters', 'Easy'],
  '3713-ongest-balanced-substring-i.cpp':        [3713, 'Longest Balanced Substring I', 'Easy']
};

/* whole-file overrides (multi-problem scrap or helper-dump files) */
const SCRAP_FILE_META = {
  'dsa/store.cpp': { topic: 'Trees', title: 'Boundary Traversal of Binary Tree' }
};

/* fallback titles when nothing better than the raw filename was inferred */
const SCRAP_TITLE = {
  'dsa/summer/3sum.cpp': '3Sum',
  'dsa/summer/mergeinterval.cpp': 'Merge Intervals',
  'dsa/summer/linkedlistdeletenthfromlast.cpp': 'Remove Nth Node From End of List',
  'dsa/summer/binarysearch1.cpp': 'Binary Search Basics',
  'dsa/summer/bs2.cpp': 'Binary Search Practice II',
  'dsa/summer/bs3.cpp': 'Binary Search Practice III',
  'dsa/summer/greedytowers.cpp': 'Greedy Towers',
  'dsa/summer/graphNewsDistributioncodeforces.cpp': 'News Distribution (Codeforces)',
  'dsa/summer/treeinorderrecursion.cpp': 'Binary Tree Inorder Traversal (Recursion)'
};

/* python files whose function names are too generic for titles */
const PY_FILE_TITLES = {
  'dsa/in python/floorceil.py': 'Floor and Ceil in a Sorted Array',
  'dsa/in python/ins.py': 'Search Insert Position (Ceil / Lower Bound)',
  'dsa/in python/medianof2arr.py': 'Median of Two Sorted Arrays',
  'dsa/in python/searchInRotatedSorted.py': 'Search in Rotated Sorted Array'
};

/* canonical titles for files whose names are misspelled or too terse */
Object.assign(SCRAP_TITLE, {
  'dsa/leetcode/tree/lcaBSTlowerstcomman ancestor.cpp': 'Lowest Common Ancestor of a BST',
  'dsa/leetcode/tree/leftsideviewGeekofgreeks.cpp': 'Left Side View of Binary Tree',
  'dsa/leetcode/tree/rightSideView.cpp': 'Binary Tree Right Side View',
  'dsa/leetcode/tree/maxdepthoftree.cpp': 'Maximum Depth of Binary Tree',
  'dsa/leetcode/tree/mindepthoftree.cpp': 'Minimum Depth of Binary Tree',
  'dsa/leetcode/tree/inoderReturnVector.cpp': 'Binary Tree Inorder Traversal (Iterative)',
  'dsa/leetcode/tree/preOrderReturnVector.cpp': 'Binary Tree Preorder Traversal (Iterative)',
  'dsa/leetcode/tree/postOrderReturnVector.cpp': 'Binary Tree Postorder Traversal (Iterative)',
  'dsa/leetcode/tree/searchBinarytree.cpp': 'Search in a Binary Tree',
  'dsa/leetcode/tree/validBST.cpp': 'Validate Binary Search Tree',
  'dsa/leetcode/tree/me/sametree.cpp': 'Same Tree',
  'dsa/leetcode/tree/me/symmetricTree.cpp': 'Symmetric Tree',
  'dsa/leetcode/mergesort/mergesortReturnVector.cpp': 'Merge Sort — Return Sorted Vector',
  'dsa/summer/graphsdetectcycleinundirectedgraphs.cpp': 'Detect Cycle in an Undirected Graph',
  'dsa/summer/graphdetectcyclindirectedgraphedfs.cpp': 'Detect Cycle in a Directed Graph (DFS)',
  'dsa/summer/graphdisjointsset.cpp': 'Disjoint Set (Union-Find)',
  'dsa/summer/graphsdisjointsetmakingalargeisland.cpp': 'Making a Large Island (DSU)',
  'dsa/summer/graphskruskalminimumspanningtreewithdisjointsset.cpp': 'Kruskal — Minimum Spanning Tree (DSU)',
  'dsa/summer/graphsprimsalgominimumspanningtree.cpp': "Prim's Algorithm — Minimum Spanning Tree",
  'dsa/summer/graphtoposortbfs.cpp': "Topological Sort (BFS / Kahn's)",
  'dsa/summer/graphtoposortdfs.cpp': 'Topological Sort (DFS)',
  'dsa/summer/graphbfstraversalofgraph.cpp': 'BFS Traversal of Graph',
  'dsa/summer/graphdfstraversal.cpp': 'DFS Traversal of Graph',
  'dsa/summer/graphbellmanford.cpp': 'Bellman-Ford Algorithm',
  'dsa/summer/graphflloydwarshall.cpp': 'Floyd-Warshall Algorithm',
  'dsa/summer/graphdijkstra.cpp': "Dijkstra's Algorithm",
  'dsa/summer/graphnetworkdelay.cpp': 'Network Delay Time',
  'dsa/summer/grphsconnectedcomponentinundirectedgraph.cpp': 'Connected Components in Undirected Graph',
  'dsa/summer/graphsnoofconnectedcomponets.cpp': 'Number of Connected Components',
  'dsa/summer/leetcodeclonegrap.cpp': 'Clone Graph',
  'dsa/summer/grahsrottenOranges.cpp': 'Rotting Oranges',
  'dsa/summer/gfgratinmaze.cpp': 'Rat in a Maze',
  'dsa/summer/dpcountsubstringpalindrome.cpp': 'Count Palindromic Substrings',
  'dsa/summer/dplongestsubstringpalindrome.cpp': 'Longest Palindromic Substring',
  'dsa/summer/dpbesttimetobuyandsellstock2.cpp': 'Best Time to Buy and Sell Stock II',
  'dsa/summer/dpfibo.cpp': 'Fibonacci Number (DP)',
  'dsa/summer/dphouserobber.cpp': 'House Robber',
  'dsa/summer/dprobhouse.cpp': 'House Robber',
  'dsa/summer/dprobberhouse2.cpp': 'House Robber II',
  'dsa/summer/dpuniquepath.cpp': 'Unique Paths',
  'dsa/summer/subset2.cpp': 'Subsets II',
  'dsa/summer/recursiondfswordsearch.cpp': 'Word Search',
  'dsa/summer/recursionlettercombiofphoneno.cpp': 'Letter Combinations of a Phone Number',
  'dsa/summer/generateallbinarystring.cpp': 'Generate All Binary Strings',
  'dsa/summer/greedyjump1.cpp': 'Jump Game',
  'dsa/summer/greedyjump2.cpp': 'Jump Game II',
  'dsa/summer/greedymaxMettinggfg.cpp': 'Maximum Meetings in One Room',
  'dsa/summer/stringrotatestring.cpp': 'Rotate String',
  'dsa/summer/stringsortcharbufreq.cpp': 'Sort Characters by Frequency',
  'dsa/summer/linkedlistdeletenode.cpp': 'Delete Node in a Linked List',
  'dsa/summer/linkedlistdetectcycle.cpp': 'Linked List Cycle',
  'dsa/summer/linkedlistinsertatpos.cpp': 'Insert Node at Position (Linked List)',
  'dsa/summer/linkedlistinsertatthebegining.cpp': 'Insert at Beginning (Linked List)',
  'dsa/summer/linkedlistinsertattheend.cpp': 'Insert at End (Linked List)',
  'dsa/summer/linkedlistmiddleofthelinkedlist.cpp': 'Middle of the Linked List',
  'dsa/summer/linkedlistpartitionlist.cpp': 'Partition List',
  'dsa/summer/linkedlistremovedublicatenodes.cpp': 'Remove Duplicate Nodes (Linked List)',
  'dsa/summer/linkedlistreverse2.cpp': 'Reverse Linked List',
  'dsa/summer/linkedlistsearch.cpp': 'Search in a Linked List',
  'dsa/summer/treeBalancedBinaryTree.cpp': 'Balanced Binary Tree',
  'dsa/summer/treebottomviewofbinarytree.cpp': 'Bottom View of Binary Tree',
  'dsa/summer/treeboundarytraversal.cpp': 'Boundary Traversal of Binary Tree',
  'dsa/summer/treebstiterator.cpp': 'Binary Search Tree Iterator',
  'dsa/summer/treecheckforbst.cpp': 'Check for BST',
  'dsa/summer/treeHeightofbinarytreerecursion.cpp': 'Height of Binary Tree (Recursion)',
  'dsa/summer/treeinorderrecursion.cpp': 'Binary Tree Inorder Traversal (Recursion)',
  'dsa/summer/treelevelorderbfs.cpp': 'Binary Tree Level Order Traversal (BFS)',
  'dsa/summer/treelowercommonancestorinbst.cpp': 'Lowest Common Ancestor of a BST',
  'dsa/summer/treelowerstcommonfactor.cpp': 'Lowest Common Ancestor of a Binary Tree',
  'dsa/summer/treepostorderrecursion.cpp': 'Binary Tree Postorder Traversal (Recursion)',
  'dsa/summer/treepreorderrecursion.cpp': 'Binary Tree Preorder Traversal (Recursion)',
  'dsa/summer/treereversepreordderrightsideview.cpp': 'Reverse Preorder — Right Side View',
  'dsa/summer/treerightviewlevelordertr.cpp': 'Right View (Level Order)',
  'dsa/summer/treesearchinabst.cpp': 'Search in a Binary Search Tree',
  'dsa/summer/treesumsumiv.cpp': 'Path Sum III',
  'dsa/summer/treetopview.cpp': 'Top View of Binary Tree',
  'dsa/summer/treeverticalorder.cpp': 'Vertical Order Traversal',
  'dsa/summer/treezigzagtraversal.cpp': 'Zigzag Level Order Traversal'
});

const FILE_META = {
  '01partten.cpp':            { topic:'Patterns',               title:'Pattern Printing — Basics Practice' },
  '02stl.cpp':                { topic:'C++ STL',                title:'C++ STL Reference (Containers & Utilities)' },
  '03BasicMath.cpp':          { topic:'Math & Number Theory',   title:'Basic Math Drill (Count Digits, Reverse, Palindrome)' },
  '03recursion.cpp':          { topic:'Recursion & Backtracking', title:'Recursion Basics (Print 1→N, N→1, Sum, Factorial)' },
  '04hashing.cpp':            { topic:'Arrays',                 title:'Hashing Basics — Frequency Counting (Highest/Lowest Frequency Elements)' },
  '05sorting.cpp':            { topic:'Sorting',                title:'Sorting Algorithms (Selection, Bubble, Insertion, Merge, Quick, Counting)' },
  '06arraylargest.cpp':       { topic:'Sorting',                title:'Largest Element & Counting Sort' },
  '07ArraysPart2.cpp':        { topic:'Arrays',                 title:'Array Rotation (Left / Right by K)' },
  '08ArraysPart3.cpp':        { topic:'Arrays',                 title:'Missing Number (Brute → Better → Optimal)' },
  '09ArraysPart4.cpp':        { topic:'Arrays',                 title:'Two Sum (BF → HashMap) & Kadane’s Maximum Subarray' },
  '11ArraysMediumHardPart6.cpp': { topic:'Arrays',              title:'Arrays Medium-Hard Set 6 (Pascal’s Triangle, Majority Element n/3, …)' },
  '12ArraysHardPart7.cpp':    { topic:'Arrays',                 title:'Arrays Hard Set 7 (Merge Intervals & friends)' },
  '12BinarySearchEasy.cpp':   { topic:'Binary Search',          title:'Binary Search Easy (Search, Floor/Ceil, Lower/Upper Bound)' },
  '14BinarySearchHard.cpp':   { topic:'Binary Search',          title:'Binary Search Hard (Row with Max 1s, Rotated & 2D Search)' },
  '15String.cpp':             { topic:'Strings',                title:'String Basics (Remove Outer Parens, Reverse Words, …)' },
  '16LinkListBasic.cpp':      { topic:'Linked List',            title:'Linked List Basics (Construct, Print, Insert, Delete)' },
  '17LinkListMedium.cpp':     { topic:'Linked List',            title:'Linked List Medium (Middle, Reverse, Palindrome, Add Two, …)' },
  '19Recurion2.cpp':          { topic:'Math & Number Theory',   title:'Pow(x, n) — Binary Exponentiation', lc:50, url:'https://leetcode.com/problems/powx-n/' },
  '20Bits.cpp':               { topic:'Bit Manipulation',       title:'Bit Manipulation Basics (Kth Bit, Set Bits, Power of Two, …)' },
  '21Stack&Queue.cpp':        { topic:'Stack & Queue',          title:'Stack & Queue Implementations + Infix → Postfix' },
  '31GraphPart4.cpp':         { topic:'Graphs',                 title:'Disjoint Set (Union-Find) — Union by Rank & Size + Applications' },
  '32DPPart1.cpp':            { topic:'Dynamic Programming',    title:'1D DP Basics — Fibonacci-style (Memo → Tab → Space Optimized)' },
  'learn.cpp':                { topic:'Arrays',                 title:'Minimum Operations to Make Elements Distinct', lc:3396 },
  'demo.cpp':                 { topic:'Uncategorized',          title:'Scratch Experiments (Digit-Palindrome Permutations)' }
};

/* ---------------- helpers ---------------- */
const cap = s => s ? s[0].toUpperCase() + s.slice(1).toLowerCase() : s;
const ORE = /O\s*\((?:[^()]|\([^()]*\))*\)/g;
const MINOR = new Set(['of','in','a','an','the','to','for','and','or','with','by','from','at','on']);
const ACR = { bst:'BST', kth:'Kth', lca:'LCA', lru:'LRU', bfs:'BFS', dfs:'DFS', gcd:'GCD', stl:'STL', xor:'XOR', ncr:'nCr', ii:'II', iii:'III', iv:'IV', dll:'DLL' };

function titleFromWords(w) {
  return w.split(/\s+/).filter(Boolean).map((wd, i) => {
    const l = wd.toLowerCase();
    if (ACR[l]) return ACR[l];
    if (i > 0 && MINOR.has(l)) return l;
    return l[0].toUpperCase() + l.slice(1);
  }).join(' ');
}
function camelToTitle(n) {
  const words = n
    .replace(/([a-z0-9])([A-Z])/g, '$1 $2')
    .replace(/([A-Z]+)([A-Z][a-z])/g, '$1 $2')
    .split(/[\s_]+/).filter(Boolean);
  return titleFromWords(words.join(' '));
}
function slugTitle(u) {
  try {
    const p = new URL(u).pathname;
    const m = p.match(/\/problems\/([^/]+)/) || p.match(/\/([^/]+)\/\d+\/?$/);
    let slug = m ? (m[1] || m[2]) : (p.split('/').filter(Boolean).pop() || '');
    slug = slug.replace(/[_-]?\d{4,}$/,'').replace(/[-_]+/g,' ').trim();
    return slug ? titleFromWords(slug) : null;
  } catch { return null; }
}
function gfgHint(u) {
  const m = String(u).match(/geeksforgeeks\.org\/problems\/([a-z0-9-]+)/i);
  if (!m) return null;
  const slug = m[1].replace(/-\d{6,}$/,'');
  return GFG_HINTS[slug] || null;
}
function sourceOf(u) {
  if (/leetcode\.com/.test(u)) return 'LeetCode';
  if (/geeksforgeeks\.org/.test(u)) return 'GFG';
  if (/naukri\.com/.test(u)) return 'Code360';
  if (/codeforces\.com/.test(u)) return 'Codeforces';
  if (/codechef\.com/.test(u)) return 'CodeChef';
  if (/hackerrank\.com/.test(u)) return 'HackerRank';
  if (/interviewbit\.com/.test(u)) return 'InterviewBit';
  return 'Other';
}
function complexityOf(text) {
  let tc = null, sc = null;
  for (const line of String(text).split('\n')) {
    if (tc && sc) break;
    const low = line.toLowerCase();
    const hasSc = /\bsc\b|\bspace\b/.test(low);
    const hasTc = /\btc\b|\btime\b/.test(low);
    if (!tc && hasTc) { const m = line.match(ORE); if (m) tc = m[0].replace(/\s+/g,''); }
    if (!sc && hasSc) {
      const idx = low.search(/\bsc\b|\bspace\b/);
      const m = line.slice(Math.max(0, idx)).match(ORE);
      if (m) sc = m[0].replace(/\s+/g,'');
    }
    if (!tc && !hasTc && hasSc) {
      const ms = line.match(ORE);
      if (ms && ms.length >= 2) { tc = ms[0].replace(/\s+/g,''); if (!sc) sc = ms[1].replace(/\s+/g,''); }
    }
  }
  return { tc, sc };
}
const FUNC_SKIP = new Set(['main','swap','solve','ans','check','get','read','book','fun1','fun2','fun3','fun4','countUnique','funMul','lowerBound','search','setup','run']);
const FUNC_SKIP_LOW = new Set(['a','b','c','d','v','pos','task','infunc','ceil','floor','median','find','insert','fun','calc','helper','node','set','arr','res','ans','out','tmp','temp','adj','mat','grid','dp','nums','vis','dist','cur','prev']);
function firstFunctionName(code) {
  const RE1 = /(?:int|void|bool|string|double|float|char|auto|long\s+long)\s+\*?\s*([A-Za-z_]\w*)\s*\(/;
  const RE2 = /(?:vector|ListNode|TreeNode|Node)\s*<[^;{}()]*>\s*\*?\s*([A-Za-z_]\w*)\s*\(/;
  for (const line of code.split('\n')) {
    const m = line.match(RE1) || line.match(RE2);
    if (m && m[1].length > 1 && !FUNC_SKIP.has(m[1]) && !FUNC_SKIP_LOW.has(m[1].toLowerCase())) return m[1];
  }
  return null;
}
/* short gist from a story-style problem statement (college assignment sheets) */
function gistTitle(text) {
  const STOP = new Set(['is','a','an','the','for','and','to','of','in','with','that','this','program','write','task','your','you','are','given','need','needs','want','wants','help','assist','by','on','at','as','it','its','their','his','her','they','he','she','from','into','using','use','implement','create','design','develop','developing','working','project','involves','involving','also','later','can','should','must','has','have','additionally','system','allows','allow','him','them','when','whenever','some','any','all','one','two','new','based']);  const words = String(text).replace(/\ufeff/g, ' ').replace(/[^A-Za-z0-9\s-]/g, ' ').split(/\s+/).filter(Boolean);
  const sig = [];
  for (const w of words) {
    const lw = w.toLowerCase();
    if (STOP.has(lw) || !/[A-Za-z]/.test(w)) continue;
    if (sig.length >= 7) break;
    sig.push(w.length > 2 ? lw[0].toUpperCase() + lw.slice(1) : w.toUpperCase());
  }
  return sig.join(' ');
}

/* ---------------- C++/multi-language file parser ---------------- */
const LANG_RE      = /^\s*\/\/?\s*(?:\/\*)?\s*=+\s*(C\+\+|Python|Java)\s*:?\??\.?\s*solution\s*=+/i;
const PROB_RE      = /^\s*\/\/\s*Problem\s*:\s*(.+?)\s*$/i;
const DIFF_RE      = /^\s*\/\/\s*Difficulty\s*:\s*(easy|medium|hard)\b/i;
const NUM_RE       = /^\s*\/\/\s*(\d{2,4})(\s|$)/;
const NUMLEET_RE   = /^\s*\/\/\s*(\d{1,4})\s+leetcode\b/i;
const COIN_RE      = /^\s*\/\/\s*coin\s+change\b/i;
const URL_RE       = /^\s*(?:\/\/\s*)?(?:(?:link|url)\s*[\s:=\-]*)?(https?:\/\/\S+)\s*$/i;
const APPROACH_RE  = /^\s*\/\/\s*(brute|better|optimal)\b/i;
const BLOCKEND_RE  = /^\s*\*\/\s*$/;
const TCS_SPLIT_RE = /^\s*\/\/?\s*single file programming question\s*$/i;
const isProblemUrl = u => /\/problems\//.test(u) || /\/problemset\//.test(u) || /geeksforgeeks\.org\/problems\//.test(u);
function cleanUrl(u) {
  return u.replace(/\?(.*)$/, '')
          .replace(/\/(solutions\/.*)$/, '')
          .replace(/\/(description|submissions)(\/.*)?\/?$/, '')
          .replace(/\/+$/, '');
}

function parseCpp(fileName, src, opts = {}) {
  const lines = src.split('\n');
  const segs = [];
  let seg = null, cur = null, inLangBlock = false;
  const TCS = !!opts.tcs;               // college "Single File Programming Question" sheets
  let tcsTail = false;                  // after "Sample test cases" until next question
  const inTcsSkip = line => TCS && (tcsTail || TCS_SKIP_PATTERNS.some(re => re.test(line)) ||
    /^\/\/\s*\d+(\s+\d+)*\s*$/.test(line) ||          // sample I/O number lists
    /^\/\/\s*\d+\s*[≤>=]/.test(line));                 // constraint lines

  const mkSeg = () => ({ title:null, lc:null, url:null, difficulty:null, numText:null, chunks:[], hasCode:false, hasLeetMarker:false });
  const langKey = s => { s = s.toLowerCase(); return s === 'c++' ? 'cpp' : s === 'python' ? 'python' : 'java'; };

  function flushChunk() {
    if (cur) {
      const code = cur.buf.join('\n').replace(/^\n+/, '').replace(/[ \t]+$/, '');
      if (code.trim() !== '') {
        seg.chunks.push({ lang: cur.lang, tag: cur.tag, note: cur.note, code });
        seg.hasCode = true;
      }
    }
    cur = null;
  }
  function startChunk(lang, tag, note) {
    flushChunk();
    cur = { lang, tag: tag || null, note: note || null, buf: [] };
  }
  function needNewSeg(cond, extraUrl) {
    if (cond) {
      flushChunk();
      /* carry weak metadata from a code-less segment into the next one */
      let carry = null;
      if (!seg.hasCode && (seg.lc != null || seg.numText || seg.difficulty || seg.url)) {
        carry = { lc: seg.lc, numText: seg.numText, difficulty: seg.difficulty, url: seg.url, hasLeetMarker: seg.hasLeetMarker };
      }
      seg = mkSeg();
      segs.push(seg);
      if (carry) {
        seg.lc = carry.lc; seg.numText = carry.numText; seg.difficulty = carry.difficulty; seg.url = carry.url; seg.hasLeetMarker = carry.hasLeetMarker;
      }
      if (extraUrl && !seg.url) seg.url = extraUrl;
      startChunk('cpp');
    }
  }

  seg = mkSeg(); segs.push(seg); startChunk('cpp');
  let pendingUrl = null;   // column-0 URL seen AFTER code: belongs to the next
                           // problem if more code follows, else to this one (EOF)

  for (const line of lines) {
    if (TCS && TCS_SPLIT_RE.test(line)) { needNewSeg(true, pendingUrl); pendingUrl = null; tcsTail = false; continue; }  // separator between assignment questions
    if (TCS && /^\s*\/\/?\s*sample test cases/i.test(line)) { flushChunk(); tcsTail = true; continue; }
    if (inTcsSkip(line)) continue;   // assignment template boilerplate
    /* once a segment contains real code, only COLUMN-0 metadata comments may
       start a new problem; indented // URL / // 123 lines inside function
       bodies are just code comments and must stay in the code */
    if (seg.hasCode && /^\s/.test(line) &&
        (LANG_RE.test(line) || PROB_RE.test(line) || DIFF_RE.test(line) || URL_RE.test(line) ||
         NUMLEET_RE.test(line) || NUM_RE.test(line) || COIN_RE.test(line) || APPROACH_RE.test(line) ||
         /^\s*\/\/\s*by\s+(dfs|bfs)\b/i.test(line))) {
      cur.buf.push(line);
      continue;
    }
    if (inLangBlock && BLOCKEND_RE.test(line)) { inLangBlock = false; continue; }
    const mLang = line.match(LANG_RE);
    if (mLang) {
      inLangBlock = line.includes('/*');
      startChunk(langKey(mLang[1]));
      continue;
    }
    const mProb = line.match(PROB_RE);
    if (mProb) {
      needNewSeg(seg.hasCode || (seg.title && seg.url), pendingUrl); pendingUrl = null;
      if (!seg.title) {
        seg.title = mProb[1].replace(/\((\d{3,4})\)\s*$/, (mm, n) => { seg.lc = seg.lc || +n; return ''; }).trim() || mProb[1].trim();
      }
      continue;
    }
    const mDiff = line.match(DIFF_RE);
    if (mDiff) { if (!seg.difficulty) seg.difficulty = cap(mDiff[1]); continue; }
    const mUrl = line.match(URL_RE);
    if (mUrl && isProblemUrl(mUrl[1])) {
      const u = cleanUrl(mUrl[1]);
      if (seg.hasCode && !seg.url) { pendingUrl = u; continue; }  // may belong to the next problem — decide later
      needNewSeg(seg.hasCode || !!seg.url, pendingUrl); pendingUrl = null;
      if (!seg.url) seg.url = u;
      continue;
    }
    const mBy = line.match(/^\s*\/\/\s*by\s+(dfs|bfs)\b/i);
    if (mBy) { if (cur && !cur.note) cur.note = 'by ' + mBy[1].toUpperCase(); continue; }
    const mNum = opts.noNums ? null : (line.match(NUMLEET_RE) || line.match(NUM_RE) || (COIN_RE.test(line) ? [line] : null));
    if (mNum) {
      needNewSeg(seg.hasCode || seg.lc != null || !!seg.numText || !!seg.url, pendingUrl); pendingUrl = null;
      if (NUMLEET_RE.test(line)) {
        seg.hasLeetMarker = true;
        seg.lc = seg.lc || +line.match(NUMLEET_RE)[1];
      } else if (COIN_RE.test(line)) {
        if (!seg.title) seg.title = 'Coin Change';
      } else {
        seg.lc = seg.lc || +line.trim().replace(/^\s*\/\/\s*/, '').match(/^\d+/)[0];
      }
      const rest = line.replace(/^\s*\/\/\s*/, '').replace(/^\d+/, '').replace(/^[\s,:\-–]+/, '');
      const looksComplexity = /\btc\b|\bsc\b|\btime\b|\bspace\b|O\s*\(/i.test(rest);
      if (rest) {
        const dm = rest.match(/^(easy|medium|hard)\b/i);
        if (dm && !seg.difficulty) seg.difficulty = cap(dm[1]);
        else if (!looksComplexity && /^[a-z]/i.test(rest) && !/^(easy|medium|hard|leetcode|by\s+(me|dfs|bfs)|brute\b|better\b|optimal\b)/i.test(rest) && !seg.title) {
          seg.numText = rest; seg.title = titleFromWords(rest.replace(/\b(medium|easy|hard)\b.*$/i, '').trim());
        }
      }
      const am = line.match(APPROACH_RE);
      const rm = !am && /^(brute|better|optimal)\b/i.test(rest) ? rest.match(/^(brute|better|optimal)\b/i) : null;
      if ((am || rm) && !cur.tag) { cur.tag = cap((am || rm)[1]); cur.note = line.replace(/^\s*\/\/\s*/, '').trim(); }
      continue;
    }
    const mApp = line.match(APPROACH_RE);
    if (mApp) {
      startChunk(cur ? cur.lang : 'cpp', cap(mApp[1]), line.replace(/^\s*\/\/\s*/, '').trim());
      continue;
    }
    /* plain code line after a pending URL: that URL opened the next problem */
    if (pendingUrl && line.trim() !== '') {
      const isMeta = LANG_RE.test(line) || PROB_RE.test(line) || DIFF_RE.test(line) || URL_RE.test(line) ||
                     NUMLEET_RE.test(line) || NUM_RE.test(line) || COIN_RE.test(line) || APPROACH_RE.test(line) ||
                     (TCS && (TCS_SPLIT_RE.test(line) || TCS_SKIP_PATTERNS.some(re => re.test(line))));
      if (!isMeta) { needNewSeg(true, pendingUrl); pendingUrl = null; }
    }
    cur.buf.push(line);
    if (line.trim() !== '') seg.hasCode = true;
  }
  flushChunk();
  if (segs.length) {
    const lastSeg = segs[segs.length - 1];
    if (pendingUrl && !lastSeg.url) lastSeg.url = pendingUrl;
    /* trailing URL-only comment (any indentation) is metadata, not code:
       record the link but keep the line in the displayed code verbatim */
    if (!lastSeg.url && lastSeg.chunks.length) {
      const tail = lastSeg.chunks[lastSeg.chunks.length - 1].code.split('\n').filter(l => l.trim() !== '').pop() || '';
      const tm = tail.match(/^\s*\/\/?\s*(?:(?:link|url)\s*[\s:=\-]*)?(https?:\/\/\S+)\s*$/i);
      if (tm && isProblemUrl(tm[1])) lastSeg.url = cleanUrl(tm[1]);
    }
  }

  /* ---- segments -> problems ---- */
  const out = [];
  segs.forEach((sg, i) => {
    if (!sg.chunks.length) return;
    if (TCS) {
      /* story-style problem statement -> gist title. Story = leading prose
         lines (commented or plain) of the chunk; stop at code / Input format */
      if (!sg.title) {
        const stmt = sg.chunks.find(c => c.lang === 'cpp');
        if (stmt) {
          const ls = stmt.code.split('\n');
          let k = 0;
          while (k < ls.length && ls[k].trim() === '') k++;
          if (k < ls.length && !/^(#include|using namespace|int main)/.test(ls[k].trim())) {
            let story = '';
            for (; k < ls.length; k++) {
              const l = ls[k];
              if (l.trim() === '') continue;
              const t = l.replace(/^\s*\/\/\s?/, '').replace(/\ufeff/g, '').trim();
              if (/input format|output format|company tag/i.test(t)) break;
              if (/^[{}#]/.test(t) || /int main/.test(t)) break;
              /* "... Write a program to help X" rides on the story line:
                 keep only the prose part of the line */
              const cut = t.search(/\b(write a program|write a function|can you help|help him|help her|help them|your task|assist)\b/i);
              const prose = (cut >= 0 ? t.slice(0, cut) : t).trim().replace(/[.;]\s*$/, '');
              if (prose) story += ' ' + prose;
              if (story.length > 400) break;
            }
            sg.title = gistTitle(story) || null;
          }
        }
      }
      const langOrder = { cpp: 0, python: 1, java: 2 };
      sg.chunks.sort((a, b) => ((langOrder[a.lang] ?? 9) - (langOrder[b.lang] ?? 9)));
    }
    if (opts.sortLangs) {
      const langOrder = { cpp: 0, python: 1, java: 2 };
      sg.chunks.sort((a, b) => ((langOrder[a.lang] ?? 9) - (langOrder[b.lang] ?? 9)));
    }
    const approaches = [];
    for (const c of sg.chunks) {
      const cx = { ...complexityOf(c.code) };
      if (c.note) { const nc = complexityOf(c.note); cx.tc = cx.tc || nc.tc; cx.sc = cx.sc || nc.sc; }
      if (c.lang === 'cpp') {
        approaches.push({ tag: c.tag, note: c.note, srcFile: fileName, langs: { cpp: { code: c.code, tc: cx.tc, sc: cx.sc } } });
      } else {
        const key = c.lang;
        const last = approaches[approaches.length - 1];
        if (last && !last.langs[key]) {
          last.langs[key] = { code: c.code, tc: cx.tc, sc: cx.sc };
          if (!last.tag && c.tag) last.tag = c.tag;
        } else {
          approaches.push({ tag: c.tag || (last ? last.tag : null), note: c.note, srcFile: fileName, langs: { [key]: { code: c.code, tc: cx.tc, sc: cx.sc } } });
        }
      }
    }
    let title = sg.title || (sg.url ? slugTitle(sg.url) : null) || sg.numText || null;
    let difficulty = sg.difficulty;
    const cppChunk = sg.chunks.find(c => c.lang === 'cpp');
    const fnTitle = cppChunk ? (() => { const fn = firstFunctionName(cppChunk.code); return fn ? camelToTitle(fn) : null; })() : null;
    const wholeFile = segs.length === 1 && !sg.title && !sg.url && sg.lc == null;
    const lcInfo = sg.lc != null ? LC_TITLES[sg.lc] : null;
    if (wholeFile && FILE_META[fileName]) {
      title = FILE_META[fileName].title;
    } else if (lcInfo && !sg.title && !sg.url && !sg.numText) {
      title = lcInfo[0];
      if (!difficulty) difficulty = lcInfo[1];
    } else {
      if (!title && sg.lc != null) title = fnTitle;
      if (!title) title = fnTitle;
      if (!title) title = fileName;
    }
    /* a bare number comment inside an unrelated file (e.g. "1114 825 357") is
       not an LC number: drop it when nothing corroborates it */
    if (sg.lc != null && !LC_TITLES[sg.lc] && !sg.hasLeetMarker && !opts.trustNumbers) {
      const corroborated = (sg.url && /leetcode\.com/.test(sg.url)) || (sg.title && sg.title !== fnTitle);
      if (!corroborated) sg.lc = null;
    }
    if (!difficulty) {
      for (const c of sg.chunks) {
        const m = c.code.split('\n').slice(0, 12).join('\n').match(/\b(easy|medium|hard)\b/i);
        if (m) { difficulty = cap(m[1]); break; }
      }
    }
    if (sg.url && !difficulty) { const h = gfgHint(sg.url); if (h) difficulty = h[1]; }
    const tags = new Set();
    const topic = (wholeFile && FILE_META[fileName] ? FILE_META[fileName].topic : (opts.topic || topicFromFile(fileName)));
    if (topic) tags.add(topic);
    if (sg.lc) tags.add('LC ' + sg.lc);
    if (sg.url) tags.add(sourceOf(sg.url));
    if (TCS) tags.add('TCS');
    const codeBlob = sg.chunks.map(c => c.code).join('\n');
    const variantHits = new Set();
    for (const m of codeBlob.matchAll(/\b\w*(brute|better|optimal|best)\w*\b/gi)) variantHits.add(cap(m[1] === 'best' ? 'optimal' : m[1]));
    const hasNamedVariants = /\w*(BruteForce|Brute|Better|Best|Optimal)\w*\s*\(/.test(codeBlob);
    if (!hasNamedVariants) variantHits.clear();
    for (const a of approaches) if (a.tag) variantHits.add(a.tag);

    out.push({
      id: fileName + '#' + i,
      file: fileName,
      title: title || fileName,
      lc: sg.lc || (wholeFile && FILE_META[fileName] && FILE_META[fileName].lc) || null,
      topic,
      difficulty: difficulty || null,
      url: sg.url || (wholeFile && FILE_META[fileName] && FILE_META[fileName].url) || null,
      source: (sg.url || (wholeFile && FILE_META[fileName] && FILE_META[fileName].url)) ? sourceOf(sg.url || FILE_META[fileName].url) : null,
      tags: [...tags, ...variantHits],
      approaches
    });
  });
  return out;
}


/* GFG-style snake_case python file: def name(...)  -> one problem */
function parseSnakePy(fileName, src) {
  const fn = src.match(/def\s+([A-Za-z_]\w*)\s*\(/);
  if (!fn) return null;
  const name = fn[1];
  if (['main','solution'].includes(name.toLowerCase())) return null;
  const cx = complexityOf(src);
  return [{
    id: fileName + '#py', file: fileName,
    title: titleFromWords(name.replace(/([a-z0-9])([A-Z])/g,'$1 $2').replace(/_/g,' ')),
    lc: null, topic: null, difficulty: null, url: null, source: null,
    tags: [],
    approaches: [{ tag: null, note: null, srcFile: fileName, langs: { python: { code: src.replace(/\s+$/,''), tc: cx.tc, sc: cx.sc } } }]
  }];
}

/* ---- LeetcodeDaliy filename -> {lc, title, difficulty} ---- */
function leetFilenameMeta(base) {
  const fix = BAD_SLUG[base.toLowerCase()];
  if (fix) return { lc: fix[0], title: fix[1], difficulty: fix[2] };
  const stem = base.replace(/\.(cpp|py|java)$/i, '');
  const m = stem.match(/^(\d{1,4})[-_ ]?(.*)$/);
  const lc = m ? +m[1] : null;
  let slug = m ? m[2] : stem;
  slug = slug.replace(/[^a-z0-9\s-]/gi, ' ').replace(/[_-]+/g, ' ').replace(/\s+/g, ' ').trim();
  let title = slug ? titleFromWords(slug) : null;
  let difficulty = null;
  if (lc != null && LC_TITLES[lc] && !slug) { title = LC_TITLES[lc][0]; difficulty = LC_TITLES[lc][1]; }
  return { lc, title, difficulty };
}

/* ---- discover extra source files ---- */
function discoverExtraFiles() {
  const files = [];
  for (const d of EXTRA_DIRS) {
    const rootDir = path.resolve(__dirname, d.root);
    const walk = dir => {
      let entries = [];
      try { entries = fs.readdirSync(dir, { withFileTypes: true }); } catch { return; }
      for (const e of entries) {
        const full = path.join(dir, e.name);
        if (e.isDirectory()) walk(full);
        else if (SRC_EXT.test(e.name) && !SKIP_FILES.has(e.name)) {
          files.push({
            path: full,
            dir: d.label,
            rel: d.label + '/' + path.relative(rootDir, full).replace(/\\/g, '/')
          });
        }
      }
    };
    walk(rootDir);
  }
  return files;
}

/* topic for extra files from folder + filename */
function extraTopic(relPath, base) {
  const p = relPath.toLowerCase();
  const b = (base || '').toLowerCase();
  if (/unit 2/.test(p)) return 'Linked List';
  if (/unit 3/.test(p)) return 'Stack & Queue';
  if (/unit 4/.test(p)) return 'Trees';
  if (/unit 5/.test(p)) return 'Heap & Priority Queue';
  if (/unit 6/.test(p)) return 'Hashing';
  if (/\/tree\//.test(p)) return 'Trees';
  if (/\/graph\//.test(p)) return 'Graphs';
  if (/\/mergesort\//.test(p)) return 'Sorting';
  if (/codeforces/.test(p)) return 'Codeforces';
  if (/leetcode/.test(p)) return 'LeetCode Practice';
  if (/in python/.test(p)) return 'Binary Search';
  if (/leetcodedaliy/.test(p)) {
    if (/linked-list|-list-|nodes|twin/.test(b)) return 'Linked List';
    if (/string|vowel|palindrome|anagram|word|spellcheck/.test(b)) return 'Strings';
    if (/matrix|submatrices|diagonal|grid|box/.test(b)) return 'Matrix';
    if (/tree|bst/.test(b)) return 'Trees';
    if (/subarray|array|pairs|spells|potions|elements|operations/.test(b)) return 'Arrays';
    if (/number|digit|integer|zero|bits|bottles|money|triangular/.test(b)) return 'Math & Number Theory';
    return 'LeetCode Daily';
  }
  if (/summer/.test(p)) {
    if (/^dp/.test(b)) return 'Dynamic Programming';
    if (/^graph|^grph|^grah|clonegrap/.test(b)) return 'Graphs';
    if (/^greedy|maxmetting/.test(b)) return 'Greedy';
    if (/^tree/.test(b)) return 'Trees';
    if (/^linkedlist/.test(b)) return 'Linked List';
    if (/^recursion|wordsearch|lettercomb/.test(b)) return 'Recursion & Backtracking';
    if (/^string|rotatestring/.test(b)) return 'Strings';
    if (/^3sum$/.test(b.replace(/\.cpp$/,''))) return 'Arrays';
    if (/^mergeinterval/.test(b)) return 'Intervals';
    if (/^minimumplatform/.test(b)) return 'Greedy';
    if (/^subset/.test(b)) return 'Recursion & Backtracking';
    if (/^generateallbinarystring/.test(b)) return 'Recursion & Backtracking';
    if (/^binarysearch|^bs\d/.test(b)) return 'Binary Search';
    return 'Uncategorized';
  }
  return 'Uncategorized';
}

/* ---------------- merge duplicates ----------------
   Same problem detected by URL / LC number / same file+title.
   Extra-directory problems may additionally merge into any card with the
   same normalized title when they carry no url/lc of their own. */
function normTitle(t) { return String(t).toLowerCase().replace(/[^a-z0-9]+/g, ' ').trim(); }
function mergeInto(q, p) {
  for (const a of p.approaches) q.approaches.push(a);
  q.tags = [...new Set([...q.tags, ...p.tags])];
  if (!q.difficulty && p.difficulty) q.difficulty = p.difficulty;
  if (!q.lc && p.lc) q.lc = p.lc;
  if (!q.url && p.url) { q.url = p.url; q.source = p.source; }
  if (p.title && p.title !== p.file && (!q.title || q.title === p.file)) q.title = p.title;
}
function mergeDuplicates(list) {
  const out = [];
  const idx = new Map();          // key -> index in out
  const titleIdx = new Map();     // normalized title -> index in out (primary cards only)
  for (const p of list) {
    let key = p.url ? 'u:' + p.url : null;
    if (key && !idx.has(key)) {
      const alias = [...idx.keys()].find(k => k.startsWith('u:') &&
        k.slice(2).replace(/^www\./, '').replace(/\/$/, '') === key.slice(2).replace(/^www\./, '').replace(/\/$/, ''));
      if (alias) key = alias;
    }
    if (!key) key = p.lc ? 'n:' + p.lc : 't:' + p.file + '|' + p.title.toLowerCase();
    /* last resort: identical titles inside the same file are the same problem */
    if (!idx.has(key)) {
      const tt = 'tt:' + p.file + '|' + normTitle(p.title);
      if (idx.has(tt)) key = tt; else idx.set(tt, out.length);
    }
    /* cross-directory: the same problem solved in another folder under the
       same title is one card — merge directly into the mapped card */
    if (!idx.has(key) && p.extra && titleIdx.has(normTitle(p.title))) {
      mergeInto(out[titleIdx.get(normTitle(p.title))], p);
      continue;
    }
    if (!p.extra && !titleIdx.has(normTitle(p.title))) titleIdx.set(normTitle(p.title), out.length);
    if (idx.has(key)) {
      mergeInto(out[idx.get(key)], p);
    } else {
      idx.set(key, out.length);
      out.push(p);
    }
  }
  /* disambiguate any surviving identical titles (extra sources only) */
  const seen = new Map();
  for (const p of out) {
    if (!p.extra) continue;
    const nt = normTitle(p.title);
    if (seen.has(nt)) {
      seen.set(nt, seen.get(nt) + 1);
      p.title = p.title + ' — ' + p.file.split('/').pop().replace(/\.(cpp|py|java|js)$/i, '');
    } else seen.set(nt, 1);
  }
  return out;
}

function topicFromFile(fn) {
  const f = fn.toLowerCase();
  if (/bst/.test(f)) return 'BST';
  if (/binarytree|tree/.test(f)) return 'Trees';
  if (/graph/.test(f)) return 'Graphs';
  if (/dp/.test(f)) return 'Dynamic Programming';
  if (/binarysearch/.test(f)) return 'Binary Search';
  if (/linklist/.test(f)) return 'Linked List';
  if (/stack|queue/.test(f)) return 'Stack & Queue';
  if (/sliding/.test(f)) return 'Sliding Window';
  if (/string/.test(f)) return 'Strings';
  if (/sort|arraylargest/.test(f)) return 'Sorting';
  if (/array/.test(f)) return 'Arrays';
  if (/hash/.test(f)) return 'Arrays';
  if (/greedy/.test(f)) return 'Greedy';
  if (/bit/.test(f)) return 'Bit Manipulation';
  if (/recursion/.test(f)) return 'Recursion & Backtracking';
  if (/math/.test(f)) return 'Math & Number Theory';
  if (/stl/.test(f)) return 'C++ STL';
  if (/pattern|partten/.test(f)) return 'Patterns';
  return 'Uncategorized';
}

/* ---------------- main ---------------- */
function main() {
  const report = [];
  const allProblems = [];
  const perFile = [];
  let extraTotal = 0;

  /* ---- 1. primary tuf/ files ---- */
  for (const f of CPP_FILES) {
    const p = path.join(__dirname, f);
    if (!fs.existsSync(p)) { perFile.push({ file: f, error: 'MISSING' }); continue; }
    const src = fs.readFileSync(p, 'utf8');
    let probs = [];
    let err = null;
    try { probs = parseCpp(f, src); } catch (e) { err = e.message; }
    perFile.push({ file: f, problems: probs.map(x => x.title), count: probs.length, error: err });
    allProblems.push(...probs);
  }

  /* ---- 2. extra directories ---- */
  const extraFiles = discoverExtraFiles();
  const skipped = [];
  for (const ef of extraFiles) {
    const src = fs.readFileSync(ef.path, 'utf8');
    if (!src.trim()) { skipped.push({ file: ef.rel, reason: 'empty file' }); continue; }
    const base = path.basename(ef.path);
    const rel = ef.rel;
    let probs = null;
    try {
      if (/^dsa\/store\.cpp$/.test(rel)) {
        probs = parseCpp(rel, src);
        probs.forEach(p => { p.title = SCRAP_FILE_META['dsa/store.cpp'].title; p.topic = SCRAP_FILE_META['dsa/store.cpp'].topic; });
      } else if (/^dsa\/lexcographically\.cpp$/.test(rel)) {
        probs = parseCpp(rel, src, { trustNumbers: true });
        probs.forEach(p => {
          p.topic = 'Strings';
          if (p.lc != null && LC_TITLES[p.lc]) {
            p.title = LC_TITLES[p.lc][0];
            if (!p.difficulty) p.difficulty = LC_TITLES[p.lc][1];
          }
        });
      } else if (/^dsa\/in python\/recursion\.py$/.test(rel)) {
        probs = [{
          id: rel + '#py', file: rel, title: 'Recursion Basics Drill (Python)', lc: null,
          topic: null, difficulty: null, url: null, source: null, tags: [],
          approaches: [{ tag: null, note: null, langs: { python: { code: src.replace(/\s+$/,''), tc: null, sc: null } } }]
        }];
      } else if (/\.py$/i.test(base)) {
        probs = parseSnakePy(rel, src) || [{
          id: rel + '#py', file: rel, title: camelToTitle(base.replace(/\.py$/i,'')), lc: null,
          topic: null, difficulty: null, url: null, source: null, tags: [],
          approaches: [{ tag: null, note: null, langs: { python: { code: src.replace(/\s+$/,''), tc: null, sc: null } } }]
        }];
        if (PY_FILE_TITLES[rel]) probs.forEach(p => { p.title = PY_FILE_TITLES[rel]; });
      } else if (/^LeetcodeDaliy\//.test(rel)) {
        probs = parseCpp(rel, src);
        const fm = leetFilenameMeta(base);
        probs.forEach(p => {
          if (p.lc == null && fm.lc != null) p.lc = fm.lc;
          if ((!p.title || p.title === rel) && fm.title) p.title = fm.title;
          if (!p.difficulty && fm.difficulty) p.difficulty = fm.difficulty;
        });
      } else if (/^dsa\/leetcode\//.test(rel)) {
        probs = parseCpp(rel, src, { sortLangs: true });
        const fm = leetFilenameMeta(base);
        const folderDiff = rel.match(/\/(easy|medium|hard)\//i);
        probs.forEach(p => {
          if (p.lc == null && fm.lc != null) p.lc = fm.lc;
          if ((!p.title || p.title === rel) && fm.title) p.title = fm.title;
          if (!p.difficulty && folderDiff) p.difficulty = cap(folderDiff[1]);
          if (!p.difficulty && p.lc != null && LC_TITLES[p.lc]) p.difficulty = LC_TITLES[p.lc][1];
        });
      } else if (/^dsa\/unit \d/.test(rel)) {
        probs = parseCpp(rel, src, { tcs: true });
      } else if (/^dsa\/codeForces\//.test(rel)) {
        probs = parseCpp(rel, src, { noNums: true });
        probs.forEach(p => { p.title = 'Codeforces ' + (base.match(/\d+[A-Z]?/i) || [''])[0] + (p.title === rel ? ' — Round Problem' : ' — ' + p.title); });
      } else if (/^dsa\/(study|summer)\//.test(rel)) {
        probs = parseCpp(rel, src, { noNums: true });
      } else if (/^dsa\/allquestion\.js$/.test(rel)) {
        probs = parseCpp(rel, src, { tcs: true });
        probs.forEach(p => p.approaches.forEach(a => {   // it is JavaScript, not C++
          if (a.langs.cpp) { a.langs.javascript = a.langs.cpp; delete a.langs.cpp; }
        }));
      } else {
        probs = parseCpp(rel, src);
      }
    } catch (e) { skipped.push({ file: rel, reason: 'parse error: ' + e.message }); continue; }
    if (!probs || !probs.length) { skipped.push({ file: rel, reason: 'no code found' }); continue; }
    probs.forEach(p => {
      p.file = rel; p.id = rel + '#' + String(p.id).split('#').pop();
      if (SCRAP_TITLE[rel]) probs.forEach(p => { p.title = SCRAP_TITLE[rel]; });
      p.topic = extraTopic(rel, base);
      p.tags = [...new Set([p.topic, ...p.tags])];
      p.extra = true;
      if (p.lc != null && p.lc >= 100 && p.lc <= 3999) p.tags = [...new Set([...p.tags, 'LC ' + p.lc])];
      else if (p.lc != null) { p.lc = null; p.tags = p.tags.filter(t => !/^LC \d+$/.test(t)); }
    });
    extraTotal += probs.length;
    allProblems.push(...probs);
  }

  /* ---- 3. merge duplicates (url / lc / title) ---- */
  const merged = mergeDuplicates(allProblems);

  /* ---- stats ---- */
  const withUrl = merged.filter(p => p.url).length;
  const withLc = merged.filter(p => p.lc).length;
  const withDiff = merged.filter(p => p.difficulty).length;
  const tagCounts = { Brute: 0, Better: 0, Optimal: 0 };
  let pyChunks = 0, javaChunks = 0, cppChunks = 0;
  for (const p of merged) for (const a of p.approaches) {
    if (a.tag) tagCounts[a.tag] = (tagCounts[a.tag] || 0) + 1;
    for (const l of Object.keys(a.langs)) {
      if (l === 'cpp') cppChunks++; else if (l === 'python') pyChunks++; else javaChunks++;
    }
  }
  const topics = [...new Set(merged.map(p => p.topic))];
  const noUrl = merged.filter(p => !p.url).map(p => `${p.title}  [${p.file}]`);

  report.push('================ DSA REVISION HUB — DISCOVERY REPORT ================');
  report.push('Scanned : ' + CPP_FILES.length + ' tuf files + ' + extraFiles.length +
              ' files from LeetcodeDaliy/ & dsa/  (' + extraTotal + ' raw segments, ' + skipped.length + ' skipped)');
  report.push('Excluded (non-problem artifacts): ' + EXCLUDED.join(', '));
  report.push('Problems after dedupe: ' + merged.length + '   |   with URL: ' + withUrl +
              '   |   with LC number: ' + withLc + '   |   with difficulty: ' + withDiff);
  report.push('Approach tags found: ' + JSON.stringify(tagCounts));
  report.push('Code chunks by language: C++=' + cppChunks + '  Python=' + pyChunks + '  Java=' + javaChunks);
  report.push('Topics (' + topics.length + '): ' + topics.join(', '));
  report.push('');
  report.push('--- Per-file breakdown ---');
  for (const pf of perFile) {
    if (pf.error) { report.push(`${pf.file}: ERROR ${pf.error}`); continue; }
    report.push(`${pf.file}  (${pf.count} problem${pf.count === 1 ? '' : 's'})`);
    for (const t of pf.problems) report.push('    • ' + t);
  }
  report.push('');
  report.push('--- Extra-directory problems (new cards) ---');
  merged.filter(p => p.extra).forEach(p => report.push(`    • [${p.topic}] ${p.title}  (${p.file}${p.difficulty ? ', ' + p.difficulty : ''})`));
  if (skipped.length) {
    report.push('');
    report.push('--- Skipped files ---');
    skipped.forEach(s => report.push('    ✗ ' + s.file + ' — ' + s.reason));
  }
  report.push('');
  report.push('--- Problems without a source URL (title inferred) ---');
  noUrl.forEach(t => report.push('    ' + t));
  report.push('');
  report.push('NOTE: Python/Java sections originally wrapped in /* ... */ block comments were');
  report.push('unwrapped for display (structural delimiters only). All code is otherwise verbatim.');

  const reportText = report.join('\n');
  fs.writeFileSync(path.join(__dirname, 'discovery-report.txt'), reportText);
  console.log(reportText);
  fs.writeFileSync(path.join(__dirname, 'problems.json'), JSON.stringify(merged, null, 1));

  /* sample print */
  console.log('\n--- SAMPLE PARSED PROBLEMS (first 3) ---');
  console.log(JSON.stringify(merged.slice(0, 3).map(p => ({
    title: p.title, topic: p.topic, lc: p.lc, difficulty: p.difficulty, source: p.source,
    url: p.url, approaches: p.approaches.map(a => ({
      tag: a.tag, note: a.note, langs: Object.fromEntries(Object.entries(a.langs).map(([k, v]) => [k, { tc: v.tc, sc: v.sc, firstLine: v.code.split('\n')[0] }]))
    }))
  })), null, 1));

  /* ---- generate final HTML ---- */
  const templatePath = path.join(__dirname, 'hub_template.html');
  const algosPath = path.join(__dirname, 'algos_data.js');
  if (!fs.existsSync(templatePath) || !fs.existsSync(algosPath)) {
    console.log('\n(template or algos_data.js missing — skipped HTML generation)');
    return;
  }
  const algos = require(algosPath);
  const meta = {
    generatedAt: new Date().toLocaleString('en-GB', { day: '2-digit', month: 'short', year: 'numeric', hour: '2-digit', minute: '2-digit' }),
    filesScanned: CPP_FILES.length + extraFiles.length,
    problemsCount: merged.length,
    topicsCount: topics.length,
    algosCount: algos.algorithms.length,
    suggestedCount: algos.suggested.length
  };
  const J = o => JSON.stringify(o).replace(/<\//g, '<\\/');
  let html = fs.readFileSync(templatePath, 'utf8');
  html = html.split('__PROBLEMS_JSON__').join(J(merged));
  html = html.split('__ALGOS_JSON__').join(J(algos.algorithms));
  html = html.split('__SUGGESTED_JSON__').join(J(algos.suggested));
  html = html.split('__META_JSON__').join(J(meta));
  html = html.split('__GENDATE__').join(meta.generatedAt);
  html = html.split('__NPROBLEMS__').join(String(merged.length));
  html = html.split('__NTOPICS__').join(String(topics.length));
  html = html.split('__NALGOS__').join(String(algos.algorithms.length));
  fs.writeFileSync(path.join(__dirname, 'dsa-revision.html'), html);
  console.log('\nWROTE dsa-revision.html  (' + (fs.statSync(path.join(__dirname, 'dsa-revision.html')).size / 1024).toFixed(1) + ' KB)');
}

main();
