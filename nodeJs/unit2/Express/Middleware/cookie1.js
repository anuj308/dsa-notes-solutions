import express from 'express';
import morgan from 'morgan';

import cookieParser  from 'cookie-parser';

import cookieSession from 'cookie-session';

import session from 'express-session';


const ex = express();
ex.use(morgan('dev'));
ex.use(express.json());
ex.get("/home",(req,res)=>{
    const users ={ "user":"Parveen", "rollno":123}
    setTimeout(()=>{res.json(users);}, 2000)
})
function errorhandling(error,req,res,next){
    res.status(500).send("try after sometime");
}
ex.get("/error",(req,res,next)=>{
    // res.send("hello");
    const error = new error();
    next(error);
});    
ex.use(errorhandling);

ex.use(cookieParser());

ex.get("/setck",(req,res)=>{

    const cookie_array={"username":"ram","age":12,"class":"k23pa"};
    res.cookie("MataData",JSON.stringify(cookie_array),{
        maxAge:1000*10
    });
    // res.cookie("age",123);
    res.send("cookie set");
})

ex.get("/getck",(req,res)=>{
    const user = req.cookies['user'];
    res.send(`cookie value for user is ${user}`);
})

ex.get("/delck",(req,res)=>{
    res.clearCookie("user");
    res.send("Cookie deleted");
})


ex.use(cookieSession(
    {
                name: "session",
                keys: ["key1", "key2"],
                maxAge:  60 * 1000  // 1 min
            }
));

ex.get("/sets",(req,res)=>{
    req.session.user="Raman";
    res.send("Session set");

})
ex.get("/gets", (req,res)=>{
    res.send(`Session values : ${req.session.user} `);
   
    // const count = req.session.count = (req.session.count || 0) + 1;
    // res.send(`Session values : ${req.session.user} and count is ${count}`)
});


ex.get("/dels",(req,res)=>{
    req.session=null;
    res.send("Session deleted successfully");
})


ex.use(session({
    secret:"mysecret123",
    resave:false,
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

