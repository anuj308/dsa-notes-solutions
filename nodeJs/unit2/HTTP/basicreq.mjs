import http from 'http';

// const server = http.createServer((req, res) => {
//   // req is the IncomingMessage object
//   console.log(req.url);
// });
// server.listen(4500);

http.createServer((req, res) => {
    console.log("Method:", req.method);
    console.log("URL:", req.url);
    console.log("HTTP Version:", req.httpVersion);
    console.log("Headers:", req.headers.host);
  
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("Check your console for request details!");
  }).listen(4000, () => {
    console.log("Server running at http://localhost:4000");
  });

