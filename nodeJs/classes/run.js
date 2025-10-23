// console.log(2);
// globalThis.console.log(2); // in 2020 
// global.console.log(2);

// console.log(module)
// console.log(process)

// console.log(__dirname)
// console.log(__filename)
// const path = require("path")
// const os = require("os")
// const filepath = path.join("folder","aks.txt")
// console.log(filepath)
// const parseData = path.parse(filepath)


// // os 
// console.log(os.platform())
// console.log(os.release())
// console.log(os.type())
// console.log(os.arch())
// console.log(os.cpus())
// console.log(os.freemem())
// console.log(os.homedir())
// console.log(os.tmpdir())
// console.log(os.tmpdir())


// fs
const fs = require("fs")
// fs.writeFileSync("hello.txt","hello")
// let a = fs.readFileSync("./hello.txt","utf-8")
// // console.log(a.toString())
// console.log(a)

// fs.appendFileSync("hello.txt","we are appended the data")
// a = fs.readFileSync("./hello.txt","utf-8")
// console.log(a)

// // fs.unlinkSync("hi.txt")

// fs.renameSync("hello.txt","newfile.txt")
// fs.renameSync("newfile.txt","hello.txt")

// fs.writeFile("hello.txt","this is with write file asyncronous","utf-8",(err)=>{
//     if(err) console.log("error in write operation")
//     else console.log("success in write operation")
// })

// console.log("---------")
// fs.appendFile("hello.txt","this is append but asynchronously","utf-8",(err)=>{
//     if(err) console.err("error in read operation")
//     else console.log("success append")
// })

// fs.readFile("hello.txt","utf-8",(err,data)=>{
//     if(err) console.err("error in read operation")
//     else console.log(data)
// })

// fs.unlink("hello.txt",(err)=>{
//     if(err) console.log("error in delete operation")
//     else console.log("success in delete operation")
// })


// promise

const p = require("fs/promises");
// const p = require("fs");

p.writeFile("hello.txt","Hello world","utf-8").then((data)=>{
    console.log("file write success")
}).catch((err)=>{
    console.log("file write error")
})

p.readFile("hello.txt","utf-8").then((data)=>{
    console.log(data)
}).catch((err)=>{
    console.log("file read error")
})

//  async and await

// const fs = require('fs/promises');

async function readFileAndWriteFile(readFilePath, writeFilePath, dataToWrite) {
    try {
        // Asynchronously read the file
        const data = await p.readFile(readFilePath, "utf-8");
        console.log('File content:', data);

        // Asynchronously write to another file
        await p.writeFile(writeFilePath, dataToWrite, "utf-8");
        console.log('File written successfully!');

        return data; 
    } catch (err) {
        console.error('An error occurred:', err);
        throw err; 
    }
}

// Call the async function
readFileAndWriteFile('hello.txt', 'hello.txt', 'Hello, Async/Await!')

