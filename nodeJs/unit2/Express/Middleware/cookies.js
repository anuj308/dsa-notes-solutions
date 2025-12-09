import express from 'express';

import cookieparser from 'cookie-parser';

import cookieSession from "cookie-session";

import session from 'express-session';




const ex = express();
// ex.use(cookieparser());


// ex.get("/setcookie",(req,res)=>{
//     res.cookie("username","Parveen",{
//         maxAge:1000*60,
       
//     });
//     res.cookie("age","50",{
//         maxAge:1000*60,
       
//     });
//     res.send("Cookie set");
// })

// ex.get("/signcookie",(req,res)=>{
//     res.cookie("username","Parveen",{
//         maxAge:1000*60,
//        signed:true
//     });
//     res.send("Signed Cookie set");
// })

// ex.get("/getcookie",(req,res)=>{
//     const user = req.cookies.username;
//     res.send("Cookie for username " + user);
// })


// ex.get("/deletecookie",(req,res)=>{
//     res.clearCookie('username');
//     res.send("cookie cleared");
// })


// ex.use(cookieSession(
//     {
//         name: "session",
//         keys: ["key1", "key2"],
//         maxAge:  60 * 1000  // 1 min
//     }
// ));


// ex.get("/setsession",(req,res)=>{
//     req.session.user="Raman";
//     res.send("Session set");

// })
// ex.get("/getsession", (req,res)=>{
//    ;
//     const count = req.session.count = (req.session.count || 0) + 1;
//     res.send(`Session values : ${req.session.user} and count is ${count}`)
// });


// ex.get("/deletesession",(req,res)=>{
//     req.session=null;
//     res.send("Session deleted successfully");
// })


ex.use(session({
    secret:"mysecret123",
    resave:true,
    saveUninitialized:true,
    cookie:{
        maxAge:1000*60
    }
}));

ex.get("/setes",(req,res)=>{
    req.session.user="Ram";
    res.send("Session created");
})

ex.get("/getes",(req,res)=>{
    const count = req.session.count = (req.session.count || 0) + 1;
    res.send(`User is : ${req.session.user} and count is ${count}`);
})

ex.get("/deles",(req,res)=>{
    req.session.destroy(()=>{
        res.clearCookie("connect.sid");
        res.send("Session deleted successfully!");
    });
  
    
})
ex.listen(3000);

