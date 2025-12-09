const fs = require("fs");
const EventEmitter = require("events");
const emitter = new EventEmitter();

const FILE_PATH = "eventCounts.json";

// Load saved event counts from file (if exists)
let eventCounts = {
  "user-login": 0,
  "user-logout": 0,
  "user-purchase": 0,
  "profile-update": 0,
};

try {
  if (fs.existsSync(FILE_PATH)) {
    const savedData = fs.readFileSync(FILE_PATH, "utf8");
    eventCounts = JSON.parse(savedData);
  }
} catch (err) {
  console.error("Error reading event file:", err);
}

// Helper function to save event counts persistently
function saveCounts() {
  fs.writeFileSync(FILE_PATH, JSON.stringify(eventCounts, null, 2));
}

// ------------------------
// Event Listeners
// ------------------------
emitter.on("user-login", (username) => {
  eventCounts["user-login"]++;
  console.log(`${username} logged in!`);
  saveCounts();
});

emitter.on("user-purchase", (username, item) => {
  eventCounts["user-purchase"]++;
  console.log(`${username} purchased ${item}!`);
  saveCounts();
});

emitter.on("profile-update", (username, field) => {
  eventCounts["profile-update"]++;
  console.log(`${username} updated their ${field}!`);
  saveCounts();
});

emitter.on("user-logout", (username) => {
  eventCounts["user-logout"]++;
  console.log(`${username} logged out!`);
  saveCounts();
});

emitter.on("summary", () => {
  console.log("Event Summary:", eventCounts);
});

// ------------------------
// Emit Events
// ------------------------
emitter.emit("user-login", "Parveen");
emitter.emit("user-purchase", "Parveen", "Laptop");
emitter.emit("profile-update", "Parveen", "email");
 emitter.emit("user-logout", "Parveen");

emitter.emit("summary");
