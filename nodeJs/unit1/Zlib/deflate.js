const fs = require('fs');
const zlib = require('zlib');

// Step 1: Compress input.txt → input.txt.deflate
const compressStream = fs.createReadStream('input.txt')
  .pipe(zlib.createDeflate());

const deflateFile = fs.createWriteStream('input.txt.deflate');

compressStream.pipe(deflateFile);

deflateFile.on('finish', () => {
  console.log(' Compression finished!');

  // Step 2: Decompress input.txt.deflate → output.txt
  const decompressStream = fs.createReadStream('input.txt.deflate')
    .pipe(zlib.createInflate())
    .pipe(fs.createWriteStream('output.txt'));

  decompressStream.on('finish', () => {
    console.log('Decompression finished! File restored as output.txt');
  });

  decompressStream.on('error', (err) => {
    console.error('Decompression error:', err);
  });
});

// deflateFile.on('error', (err) => {
//   console.error('Compression error:', err);
// });

