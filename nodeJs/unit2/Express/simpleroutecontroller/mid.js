import express from "express";

const ex = express();

function agecheck(req, res, next){
    // const age=Number(req.query.age);
    // if(age<18){
        if(!req.query.age||req.query.age<18){
        res.send("you are not allowed to visit this page");
    }
    next();
}

function countrycheck(req, res, next) {
    const country = req.params.country;
    if (!country || country.toLowerCase() !== "india") {
      return res.send("You are not allowed to visit from country check");
    }
    next();
  }
 ex.use(agecheck);
 ex.use(countrycheck);


ex.get("/user/:country",countrycheck,agecheck,(req, res)=>{
    res.send("Welcome user");
})
ex.get("/home",(req, res)=>{
    res.send("Welcome to home");
})

ex.get("/op",(req, res)=>{
    res.send("Welcome");
})

ex.listen(3000);