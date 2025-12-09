import express from "express";
const ex = express();

function agecheck(req, res, next){
    const age = Number(req.query.age);
    if(age<18){
        res.send("you are not allowed to visit from age check");
        return;
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
// ex.use(countrycheck);

ex.get("/user",(req,res)=>{
    res.send("Welcome ");
})
ex.get("/about/:country", countrycheck,(req,res)=>{ 
    res.send("About Page");
})

ex.listen(3000);