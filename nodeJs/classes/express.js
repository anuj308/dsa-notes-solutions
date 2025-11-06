// Express js is a framework
// express validator

import express from "express"
const app = express();

app.get("/home",(req,res)=>{
    res.send("home")
})
// app.post("/home",(req,res)=>{
//     res.send("home")
// })

app.listen(3000)