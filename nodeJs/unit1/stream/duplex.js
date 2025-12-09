// const duplex = require('stream');
// duplex.on('input.txt', (chunk) => console.log('Reading:', chunk.toString()));
// duplex.write('Node.js Streams');
// duplex.end();
const { Duplex } = require('stream');

const duplex = new Duplex({
  // Define how data is read
  read(size) {
    this.push('Hello ');
    this.push('World!');
    this.push(null); // no more data
  },

//   Define how data is written
  write(chunk, encoding, callback) {
    console.log('Writing:', chunk.toString());
    callback(); // must call to signal completion
  }
});

// Listening to data event (reading part)
duplex.on('data', (chunk) => {
  console.log('Reading:', chunk.toString());
});

// Writing some data
duplex.write('Node.js Streams');
duplex.end();
