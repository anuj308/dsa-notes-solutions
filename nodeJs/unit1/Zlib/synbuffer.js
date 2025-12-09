const zlib = require('zlib');

const input = Buffer.from('ghffgdfdghfhgfhjghyfhgfd!', 'utf8');

const compressed = zlib.gzipSync(input);
console.log('Compressed buffer:', compressed);

const decompressed = zlib.gunzipSync(compressed);
console.log('Decompressed text:', decompressed.toString());
