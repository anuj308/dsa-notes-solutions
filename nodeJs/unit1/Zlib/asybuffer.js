const zlib = require('zlib');

const input = Buffer.from('Hello Node.js Zlib Module!', 'utf8');

zlib.gzip(input, (err, compressed) => {
  if (err) throw err;
  console.log('Compressed buffer:', compressed);

  zlib.gunzip(compressed, (err, decompressed) => {
    if (err) throw err;
    console.log('Decompressed text:', decompressed.toString());
  });
});
