// const fs = require("fs");

// const readStream = fs.createReadStream("Hello.txt", "utf8");

// // 'data' event fires each time a chunk is read.
// readStream.on("data", (chunk)=>{
//     console.log('Received chunk:\n', chunk);
// });

// // 'end' fires when all data is read.
// readStream.on('end', () => {
//     console.log('Finished reading file.');
//   });
  
//   readStream.on('error', (err) => {
//     console.error('Error:', err);
//   });

  const fs = require('fs');

// Create a readable stream
const readStream = fs.createReadStream('input.txt', 'utf8');

readStream.on('data', (chunk) => {
  console.log('Received chunk:\n', chunk);
});

readStream.on('end', () => {
  console.log('Finished reading file.');
});

readStream.on('error', (err) => {
  console.error('Error:', err);
});