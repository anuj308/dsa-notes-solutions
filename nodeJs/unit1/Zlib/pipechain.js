const fs = require('fs');
const zlib = require('zlib');

const readStream = fs.createReadStream('input.txt');
const writeStream = fs.createWriteStream('input.txt.gz');
const gzip = zlib.createGzip();

readStream
  .pipe(gzip)
  .pipe(writeStream)
  .on('finish', () => console.log('Compression completed successfully!'));
