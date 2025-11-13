import express from "express"
import path from "path";
import {fileURLToPath} from "url";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename)

const app = express();

// middleware for data
app.use(express.urlencoded({extended:true}))
app.use(express.json())

app.get("/",(req,res)=>{
    res.send("asd")
})
app.get("/user/:id/:name",(req,res)=>{
    const {name,id} = req.params;
    res.send(`user name ${name} and id ${id}`)
})
app.get("/home",(req,res)=>{
    res.send("home")
})

app.get(/^\/a.*$/, (req, res) => {
  res.send("matches any path starting with /a");
});

app.get(/abc*d/, (req, res) => {
  res.send("matches any path /abc*d/");
});

app.get("/search",(req,res)=>{
    const keyboard = req.query.keyboard;
    res.send(`searching for ${keyboard}`)
})

app.get("/form",(req,res)=>{
    res.sendFile(path.join(__dirname,"index.html"))
})

app.get("/form2",(req,res)=>{
    res.sendFile("index.html",{root:"public"})
})

app.post("/login",(req,res)=>{
    const {email,password} = req.body;
    console.log(email)
    // console.log(req)
    res.send("login sucess")
})
app.listen(4000)