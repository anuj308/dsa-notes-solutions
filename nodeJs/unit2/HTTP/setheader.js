const http = require("http");

const server = http.createServer((req, res)=>{
    if(req.url==="/"){
        res.setHeader("Content-Type","text/plain");
          // Server response (sends data chunk)
         res.write("Hello");
        res.end();
    }
    if(req.url==="/intro"){
        res.setHeader("Content-Type","text/html");
        res.write('<h1>Hello</h1>');
        res.end("h1 heading");
    }

    
}); //eventemitter



const PORT = 8000;
//starts the server on port 8000
server.listen(PORT,()=>{
    console.log(`Listening on PORT ${PORT}`);
});


// 200	OK (successful request)
// 201	Created
// 400	Bad Request
// 404	Not Found
// 500	Internal Server Error