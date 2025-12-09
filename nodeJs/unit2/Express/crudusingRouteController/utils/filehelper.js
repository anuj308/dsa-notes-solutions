import { promises as fs } from "fs";

async function readusers(){
    try{
        const txt = await fs.readFile("data/users3.json", "utf-8");
        return JSON.parse(txt);
    }
    catch(err){
        return [];
    }
   

}
async function writeusers(users){
    fs.writeFile("data/users3.json", JSON.stringify(users, null, 2),"utf-8");

}

function nextId(users) {
    return users.length ? Math.max(...users.map(u => u.id || 0)) + 1 : 1;
  }
ex.get("/form",(req,res)=>{
    res.sendFile("form.html",{root:"public"});
})
