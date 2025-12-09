import http from "http"
import fs from "fs"
import queryString from "querystring"
const PORT=3200;
const server=http.createServer((req,res)=>{
if(req.url=="/"){
    fs.readFile("Html/form.html","utf-8",(err, data)=>{
        if(err){
            res.end("There is error");
            return;
        }
        else{
            res.writeHead(200,{"Content-Type":"text/html"})
            res.write(data);
            res.end();
            return;
        }
    }
    )  
}
else if(req.url=="/submit" ){
    let cdata =[];
    req.on('data',(chunk)=>{
        cdata.push(chunk);
    });

    req.on('end',()=>{
        let rdata= Buffer.concat(cdata).toString();
        let reddata = queryString.parse(rdata);
        console.log(reddata.name);
        console.log(reddata.email);
      
    //   console.log(rdata);
    const data1 = `Entered username is : ${reddata.name || ""}\n` +
    `Entered email is : ${reddata.email || ""}\n`;
    fs.writeFileSync("Userdetail.txt",data1,"utf-8")
    
    })
    
 
    res.end("Data added successfully");
    return;
}
else if(req.url === "/adddata" && req.method === "GET") {
    try {
      const data = fs.readFileSync("Userdetail.txt", "utf-8"); // blocking, fine for demo
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.end("File content:\n" + data);
    } catch (err) {
      res.writeHead(404, { "Content-Type": "text/plain" });
      res.end("No data found");
    }
    return;
  }
        
    

else{
    res.end("Invalid URL");
}
})
server.listen(PORT);