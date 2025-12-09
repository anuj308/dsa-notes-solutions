const http = require("http");
// http.createServer()-> create instance , 
// (req, res) -> req =object contains request data URL, headers, method, body 
// res= used to send data back to the client

const server = http.createServer((req,res)=>{
    //  client request for url 
    if(req.url==="/"){
        // Server response (sends data chunk)=> Writes data to the response stream.
        // You can call res.write() multiple times to send data in chunks.
        // The data is not yet finalized (the connection stays open).
        res.write("I am studying INT222");
        // Ends response and optionally send final data
        // sends one final message before closing.
        res.end(" \n end");
    }
     //  client request for url 
    if(req.url==="/intro"){
        res.setHeader("Content-Type","text/plain");
          // Server response (sends data chunk)
        res.write("Hello");
        res.end();
    }
}); //eventemitter


const PORT = 3000;
//starts the server on port 3000
server.listen(PORT,()=>{
    console.log(`Listening on PORT ${PORT}`);
});