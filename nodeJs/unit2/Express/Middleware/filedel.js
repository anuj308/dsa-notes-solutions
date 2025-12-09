import express from 'express';
import fs from 'fs';


const ex = express();
ex.use(express.urlencoded({extended:true}));

ex.get("/",(req,res)=>{
    res.sendFile("form.html",{root:"public"});
})
ex.post("/delete",(req,res)=>{
    const {filename} =req.body;
    // console.log(filename);
    fs.unlink(filename,(err)=>{
        if(err){
            res.send("Error found");
            return;
        }
        res.send("File deleted Successfully");
    })
})
ex.listen(4000);