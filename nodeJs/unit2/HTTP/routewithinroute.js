import http from "http";

const PORT = 4900;

const server = http.createServer((req,res)=>{
    if(req.url=="/"){
        res.write("Default URL is called");
        res.end();
    }
    else if(req.url.startsWith("/home")){
        if(req.url=="/home/Parveen"){
            res.write("Welcome Parveen");
            res.end();
        }
        res.write("Welcome to home page");
        res.end();
    }
    else if(req.url=="/about"){
        res.write("Data is coming from about page");
        res.end();
    }
    else{
        res.write("Some other URL is called");
        res.end();
    }









    // res.write("default url is : " + req.url)
    // res.write("\ndefault method is : " + req.method)
    // res.write("\nHeaders data: " + JSON.stringify(req.headers,null, 3))
    // res.write("\nHost name is : "+req.headers["host"]);
    // res.write("\nlanguage  : "+req.headers["accept-language"]);
    // res.end();
});

server.listen(PORT,()=>{
    console.log(`Server is listening on http://localhost:${PORT}`);
});