const fs= require("fs");
// const data=fs.readFile("Hi.txt", "utf-8", (err,data)=>{
//     if(err) console.log(err)
//     else console.log(data);
// });

// console.log("This line is written after read");
//  
    // else{
        // console.log("File successfully created");
    // }
// });

// appending the file


// fs.appendFile("example.txt","Hey There",(err)=>{
//     if(err) console.log(err)
//     else console.log("File appended sucessfully")
// });

fs.unlink("example.txt",(err)=>{
    if(err) console.log(err)
    else console.log("file is deleted sucessfully")
});

