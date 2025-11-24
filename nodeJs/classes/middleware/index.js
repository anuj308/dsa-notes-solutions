import express from "express"

const app = express()

app.use(express.json())
app.get("/home",(req,res)=>{
    const users = {
        "user":"aks",
        "rollno":123
    }
    res.send(users)
})


function errorHandler(err, req, res, next) {
    console.error(err.stack);
    res.status(500).send('Something broke!');
}

app.use(errorHandler);

app.get("/error",(req,res,next)=>{
    const r = error()
    next(r);
})

app.use((req, res, next) => {
    console.log(`Request Method: ${req.method}, Request URL: ${req.url}`);
    // res.send("Error not found")
    next();
});

app.get("/setck",(req,res)=>{
    const user = req.cookies('user');
    res.cookie();
    res.send("cookie set");
})
app.listen(3000)

