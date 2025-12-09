// const http = require('http');
import http from 'http';
import fs from 'fs';
const PORT = 4000;
const server = http.createServer((req,res)=>{
    if(req.url=="/htmlfile"){

   
    fs.readFile("Html/first.html", 'utf8',(err, data)=>{
        if(err){
            res.statusCode=404;
            res.statusMessage="File not found";
            res.write(res.statusCode + " and "+ res.statusMessage);
            res.end();
            return;
    }
    res.writeHead(200,{"Content-Type":"text/html"});
    res.write(data);
    res.end();
}
    );


}
else{
    res.statusCode=404;
            res.statusMessage="File not found";
            res.write(res.statusCode + " and "+ res.statusMessage);
            res.end();
            return;
}});

server.listen(PORT,()=>{
    console.log("Server running on port " + PORT);
});