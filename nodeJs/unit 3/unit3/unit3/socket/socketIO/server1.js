import express from 'express';
import http from 'http';
import path from 'path';
import {Server} from 'socket.io';
const ex =express();
ex.use(express.static(path.resolve("./user")));
const server = http.createServer(ex);
 const io = new Server(server);

 io.on('connection',(socket)=>{
   console.log("A new user connected ",socket.id);

   socket.on("user-message",(message)=>{
      console.log("A new user message",message);
      
      io.emit("server-message",message);
   });
 });

ex.get("/",(req,res)=>{
   res.sendFile("/user/index.html");
})
server.listen(4000);