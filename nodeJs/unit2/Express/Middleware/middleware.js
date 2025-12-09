import express from 'express';

import morgan from 'morgan';



const ex =express();
// third party middleware
ex.use(morgan('dev'));

function agecheck(req,res,next){
    if(!req.query.age ||  req.query.age<18){
        res.send("You are not allowed to visit this page due to age restriction");
    }
    next();
}
 // application level middleware
 ex.use(agecheck);


//Route level middleware
 ex.get("/home/:country",countrycheck,(req,res)=>{
    res.send("Welcome to home page");
 })

 ex.get("/user/:country",(req,res)=>{
    res.send("Welcome to user page");
 })
 function countrycheck(req,res,next){
    console.log(req.params);
    if(req.params.country.toLowerCase()!=="india"){
        res.send("You are not allowed to visit this page due to country restriction");
    }
   next();
 }
//  ex.use(countrycheck);


// error handling middleware
function errorhandling(error,req,res,next){
    res.status(error.status || 500).send("try after sometime");
    next();
}

ex.get("/error",(req,res,next)=>{
    const err = new error('');
    err.status=404;
    next(err);
})

ex.use(errorhandling);






ex.listen(4000);