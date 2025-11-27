import express from "express"
import path from "path"
import { fileURLToPath } from "url";
import fs from "fs"
const app = express();

const filename = fileURLToPath(import.meta.url)
const dirname = path.dirname(filename)

app.use(express.urlencoded({extended:true}))
app.use(express.json())
app.use(express.static(dirname + "/public"))

app.get("/",(req,res)=>{
    res.sendFile(path.join(dirname,"/public/index.html"))
})

app.post("/store",(req,res)=>{
    const {fileName,content} = req.body;
    console.log("Data received:",fileName,content)
    fs.writeFileSync(fileName,content,(err,data)=>{
        if(err) res.send("Error creating file",err)
        else res.send("File created successfully")
    })

    res.send("File created successfully")
    // res.redirect
    res.end();
})

app.get("/read",(req,res)=>{
    const {fileName} = req.query;  // Use query params for GET request
    
    if(!fileName) {
        return res.status(400).send("File name is required");
    }
    
    try {
        const content = fs.readFileSync(fileName, 'utf-8');
        res.send(content);
    } catch(err) {
        res.status(500).send("Error reading file: " + err.message);
    }
})
app.listen(3000,()=>{
    console.log("Server running at http://localhost:3000")
})