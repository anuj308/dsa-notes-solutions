// const fs = require('fs');

//  //Copy content from input.txt to output.txt
// const readStream = fs.createReadStream('input.txt');
// const writeStream = fs.createWriteStream('output.txt');

// readStream.pipe(writeStream);

// console.log('File copied using stream!');

const fs = require('fs');
const readStream = fs.createReadStream('input.txt');
const writeStream = fs.createWriteStream('output.txt');

readStream.on('pipe', () => console.log(' Piping started!'));
readStream.on('unpipe', () => console.log('Piping stopped!'));

readStream.pipe(writeStream);

setTimeout(() => {
  readStream.unpipe(writeStream);
  console.log('Unpiped manually after 1 second');
}, 4);

// console.log(process);
// console.log(module);


