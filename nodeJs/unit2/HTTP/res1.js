import http from "http";

http.createServer((req,res)=>{
res.setHeader("Content-Type","text/html");
  res.statusCode=200;
  res.statusMessage="Request Completed";
  res.writeHead(res.statusCode, res.statusMessage,{"Content-Type":"text/html"});
    res.write("\nStatus Code is : "+res.statusCode);
    res.write("\nStatus Message is : "+res.statusMessage);
    res.write("\nContent type  is : " +res.getHeader["Content-Type"]);
  res.write("<h2>Hello</h2>")


  res.write("Hello how are you?");
  res.write("\nWelcome to class of INT222 \n");

  res.end("\nhello");
 
}).listen(4007);