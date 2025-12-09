import http from "http";
const PORT =3003;
const server =http.createServer((req,res)=>{
    if(req.url=="/"){
    res.write("Default url is : "+req.url);
    res.write("\nDefault method is : "+req.method);
    // res.write("\nDefault header is : "+JSON.stringify(req.headers,null,3));
    res.write("\nHostname is : "+ req.headers.host);
    res.write("\nHttpvbersion is : "+req.httpVersion);
    res.end("\nHello");
    }
    else if(req.url=="/home"){
        res.write("Data coming from home page")
        res.end("\nHello");
    }
    else if(req.url=="/contact"){
        res.write("Data coming from contact page")
        res.end("\nHello");
    }
    else if(req.url=="/home/about"){
        res.write("Data coming from about page")
        res.end("\nHello");
    }
    else{
        res.write("URL is not correct")
        res.end();
    }
   
});

server.listen(PORT,()=>{
    console.log(`Server is listening on http://localhost:${PORT}`)
})