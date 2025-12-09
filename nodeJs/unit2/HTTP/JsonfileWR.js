import http from 'http'
import fs, { readFile } from 'fs'
import { error } from 'console';
const data= '{ "name" : "shivam", "age" : "20" , "course" : "CSE" }'

const server=http.createServer((req,res)=>{
    if (req.url=="/write"){
        fs.writeFile("shubham.json", data,(error)=>{
            if(error){
                res.write('file not created');
                res.end();
            }else{
                res.write('file created succesfully');
                res.end();
            }
        });
       
    }
    else if(req.url == '/read'){
        fs.readFile('shubham.json','utf-8', (error,data)=>{
            if(error){
                res.write("error in reading file");
                res.end();
            }
            else{
                 res.writeHead(200, {"Content-Type":"application/json"})
                res.write(data);
                res.end();
            }
        })

    }
    else{
        res.write('Invalid URL');
                res.end();
    }
})

server.listen(4002);