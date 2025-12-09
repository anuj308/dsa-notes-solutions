const fs = require("fs").promises;

// const writedata = async()=>{try{
//     await fs.writeFile("Example.txt", "New file is created", "utf-8");
//     console.log("file created");
// }
//     catch(err){
//         console.log(err);
//     }
// }
// writedata();

const data = async()=>{try{
    const data1 =await fs.readFile("Example.txt","utf-8");
console.log(data1);}
catch(err){
             console.log(err);
         }
        }
data();