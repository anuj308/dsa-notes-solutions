const EventEmitter = require("events");
const emitter = new EventEmitter();

function NumberLoop(num) {
  setTimeout(function() {
    for (let i = 1; i <= num; i++) {
      emitter.emit("ProcessingBegin", i);
      console.log("Number processed is " + i);
      emitter.emit("ProcessingEnd", i);
    }
  }, 2000);
  return emitter;
}

let numloop = NumberLoop(5);

numloop.on("ProcessingBegin", function(data) {
  console.log("Starting the process for " + data);
});

numloop.on("ProcessingEnd", function(data) {
  console.log("Completed the process for " + data);
});
