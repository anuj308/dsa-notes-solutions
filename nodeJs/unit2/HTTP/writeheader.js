const http = require("http");

const server = http.createServer((req, res) => {
  if (req.url === "/") {
    // Send a success response (200 OK)
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("Home Page Loaded Successfully!");
  } 
  else if (req.url === "/about") {
    // Send 200 OK
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("About Page");
  } 
  else {
    // Send 404 Not Found
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("404 - Page Not Found");
  }
});

server.listen(3000, () => {
  console.log("Server running on http://localhost:3000/");
});