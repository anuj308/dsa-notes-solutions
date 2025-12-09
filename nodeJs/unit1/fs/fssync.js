const fs = require("fs");
//    fs.writeFileSync("Hello.txt", " New data added","utf-8");

// fs.unlinkSync("Hello.txt");

 const data = fs.readFileSync("Hi.txt");
 console.log(data.toString());
 console.log("This line is written after read");

// const data = fs.readFileSync("Hello.txt", "utf-8");
// console.log(data);
// fs.appendFileSync("Hello.txt","\nUpdated content is here","utf-8");
// fs.renameSync("Hello.txt","Hi.txt");
