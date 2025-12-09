import http from 'http';

http.createServer((req,res)=>{
     res.setHeader("Content-Type","text/html");
    // res.setHeader("Content-Type","text/plain");
   res.statusCode=200;
   res.statusMessage="Requested completed";

   res.writeHead(res.statusCode, res.statusMessage, {"Content-Type":"text/html"})
 
    
    // res.write("Hello how are you");
    
    // res.write("<h2>Hello! How are you ?</h2>")
    // res.write("<p>Hello! How are you ?</p>");
    res.write("<p>Hello! How are you ?</p>");
    res.write("<h1>Hello! How are you ?</h1>")

    res.write("<p>Status code is : </p>"+ res.statusCode);
    res.write("<p>Status Message is : </p>"+ res.statusMessage);
    res.write("<p>Content type is : </p>" + res.getHeader("Content-Type"));
    // console.log("Status of writable is : " + res.writable);
    // console.log("Status of writableEnded is : " + res.writableEnded);
    res.end();
    // console.log("Status of writable after end () is : " + res.writable);
    // console.log("Status of writableEnded after end()is : " + res.writableEnded);
   
}).listen(4005);