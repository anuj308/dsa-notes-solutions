// const http = require('http');
import http from 'http';

const roll = 30;
const name = "Parveen";
http.createServer((req, res)=>{
    // res.setHeader("Content-Type","text/html");

// res.setHeader("Content-Type","text/plain");
    if(req.url==="/"){
        res.writeHead(200, {"Content-Type":"text/html"});
    res.write(`<html>
    <head>
    <title>HTML CODE</title>
    </head>
    <body>
    <h2>Hello How are you?</h2>
    <h3>Welcome </h3>
    <h2>${roll}</h2>
    // <h2>` +roll+`</h2>
    <h2>`+new Date()+`</h2>
    </body></html>`);
    res.write("Welcome! How are you?");
 
    res.write("Hello World");
    res.end(" \n hello");}
    if(req.url==="/hello"){
        res.setHeader("Content-Type","text/plain");
        res.statusCode=200;
        res.statusMessage="route find successfully";
        res.write("Welcome to Home page");
        res.write(name);
        res.end();
    }
    if(req.url==="/new"){
        res.setHeader("Content-Type","text/plain");

    const contentType = res.getHeader('Content-Type');
  res.write(`Current header: Content-Type = ${contentType}\n`);

  // End the response
  res.end(`Status: ${res.statusCode} ${res.statusMessage}`);
}

}).listen(9000);