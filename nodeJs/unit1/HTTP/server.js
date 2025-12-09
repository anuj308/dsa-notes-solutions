const http = require("http");

const server = http.createServer((req,res)=>{
    if(req.url==="/"){
        res.write("I am studying INT222");
        res.end();
    }
    if(req.url==="/intro"){
        res.write("Hello");
        res.end();
    }
}); //eventemitter


const PORT = 3000;
server.listen(PORT,()=>{
    console.log(`Listening on PORT ${PORT}`);
});