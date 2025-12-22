// import net from "net";

// const server = net.createServer((socket) => {
//   console.log("Client connected");

//   socket.write("Hello Client");

//   socket.on("data", (data) => {
//     console.log("Received:", data.toString());
//   });

//   socket.on("end", () => {
//     console.log("Client disconnected");
//   });
// });

// server.listen(3000);



import net from "net";

const server = net.createServer((socket) => {
  console.log("Client connected");

  socket.on("data", (data) => {
    console.log("Received:", data.toString());

    const body = "Hello from raw TCP HTTP!";
    const response =
      "HTTP/1.1 200 OK\r\n" +
      "Content-Type: text/plain\r\n" +
      `Content-Length: ${body.length}\r\n` +
      "Connection: close\r\n" +
      "\r\n" +
      body;

    socket.write(response);
    socket.end();
  });

  socket.on("end", () => {
    console.log("Client disconnected");
  });
});

server.listen(3000, () => {
  console.log("TCP server listening on port 3000");
});