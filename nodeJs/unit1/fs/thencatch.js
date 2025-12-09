const fs = require("fs").promises;

// fs.writeFile("Hello.txt", "New file is created", "utf-8")
// .then(console.log("file created successfully"))
// .catch((err)=>console.log(err));
fs.readFile("Hi.txt","utf-8").then((data)=>console.log(data)).catch((err)=>console.log(err));