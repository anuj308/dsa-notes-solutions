import http from 'http';
import fs from 'fs';
import querystring, { stringify } from 'querystring';

http.createServer((req,res)=>{
    if(req.url=="/"){
        // open the form on browser
        fs.readFile("html/user1.html", "utf-8",(err, data)=>{
            if(err){
                res.end("File not found");
                return;
            }
            else{
                res.writeHead(200,{"Content-Type":"text/html"})
                res.write(data);
                res.end();
            }
        })
    }
    // called when form submitted
    else if(req.url=="/submit"){
        let rdata=[];
        //data in fs in chunk form (stream) 
        // store the chunk data to array rdata
        req.on('data',(chunk)=>{
            rdata.push(chunk);
        })
        req.on('end',()=>{
            //default data is in buffer form 
            console.log(rdata);
            //Convert buffer data to string format
            let readdata = Buffer.concat(rdata).toString();
             console.log(readdata);
             //getting specified data as username and email
            const finaldata = querystring.parse(readdata);
            console.log(finaldata);
        
        // data content, want to write on txt file
        const data1 = `Entered username is : ${reddata.name || ""}\n` +
        `Entered email is : ${reddata.email || ""}\n`;
            // txt file created and data is added
        fs.writeFile("user2.txt", writedata, (err)=>{
            if(err){
                console.log("error found");
            }});
       
            // creating a JSON file and data is added
        fs.writeFile("user2.json", JSON.stringify(finaldata, null, 2), (err)=>{
            if(err){
                console.log("error");
            }
        });
        
    });
        res.end("Data added Successfully");
    }
    //Want to read the data from txt file
    else if(req.url=="/text"){
        fs.readFile("user2.txt","utf-8",(err,data)=>{
            if(err){
                res.end("File not found");
            }
            else{
                res.write(data);
                res.end();
            }
        })
    }
    // Want to read the data from Json file
    else if(req.url=="/json"){
        fs.readFile("user2.json","utf-8",(err,data)=>{
            if(err){
                res.end("File not found");
            }
            else{
                res.writeHead(200, {"Content-Type":"application/json"})
                res.write(data);
                res.end();
            }
        })
    }
    // handle all other URL`s
    else{
        res.end("Invalid URL")
    }
    
}).listen(3000);