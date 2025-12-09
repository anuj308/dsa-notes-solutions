const fs = require('fs');

// Create a writable stream
const writeStream = fs.createWriteStream('output.txt');

writeStream.write('Hello Node.js Streams!\n');
writeStream.write('Writing more data...');
writeStream.end('Done writing.');

writeStream.on('finish', () => {
  console.log('All data written successfully.');
});

writeStream.on('error', (err) => {
  console.error('Error:', err);
});