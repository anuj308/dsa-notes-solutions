const EventEmitter = require("events");
const fs = require("fs");

const emitter = new EventEmitter();

// //  define the event
// emitter.on("greet",(a)=>{
//     console.log(`Hello ! ${a.name}, Welcome to the class ${a.clas}`);
// });

// //trigger the event
// emitter.emit("greet",{name:"Parveen",clas:"K23PA"});
const filepath = "events.json";
let eventcounts={
    "userlogin":0,
    "userpurchase":0,
    "profileUpdate":0,
    "userlogout":0
};
try{

if(fs.existsSync(filepath )){
    const data = fs.readFileSync(filepath, "utf-8");
        eventcounts = JSON.parse(data);
        //  console.log(count);
    }
    // const data = fs.readFile(filepath, "utf-8",(err,data)=>{
    //     if(err) throw err;
    //     else{
    //         eventcounts = JSON.parse(data);
    //     }
    // });
}
catch(err){
        console.error("Error reading event file:", err);
      }

function savecount(){
     fs.writeFileSync(filepath, JSON.stringify(eventcounts, null, 2));
    // fs.writeFile(filepath, JSON.stringify(eventcounts, null, 2), (err)=>{
    //     if(err) throw err;
    // });
}
emitter.on("summary",()=>{
    console.log(eventcounts);
});

emitter.on("userlogin",(name)=>{
    eventcounts["userlogin"]++;
    console.log(`${name} has logged in`);
    savecount();
});
emitter.on("userpurchase",(item)=>{
    eventcounts["userpurchase"]++;
    console.log(`${item} has purchased`);
    savecount();
});
emitter.on("profileUpdate",(update)=>{
    eventcounts["profileUpdate"]++;
    console.log(`${update} has been updated`);
    savecount();
});
emitter.on("userlogout",(name)=>{
    eventcounts["userlogout"]++;
    console.log(`${name} has logout `);
    savecount();
});

emitter.emit("userlogin","Parveen");
emitter.emit("userpurchase","Cake");
// emitter.emit("profileUpdate","email");
// emitter.emit("userlogout","Parveen");

emitter.emit("summary");





