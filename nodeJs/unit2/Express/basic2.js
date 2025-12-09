import express from "express";
const app =express();

app.use(express.urlencoded({ extended: true })); // for form POSTs
app.use(express.json());    

app.get("/", (req, res)=>{
    console.log(req);
    console.log(res);
    res.send();
})

app.listen(3500);