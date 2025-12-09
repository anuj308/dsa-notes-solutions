// It retrieves the value of a response header that you’ve previously set using res.setHeader().
// res.getHeader(name)
// name → header name (case-insensitive string)

// Returns: the header value if it exists, or undefined if not set.
import http from "http";

const server = http.createServer((req, res) => {
  res.setHeader("Content-Type", "text/html");
  res.setHeader("Connection", "close");

  res.write("<h2>HELLO</h2>");
  const contentType = res.getHeader("Content-Type");
  res.write("Content type is : " + contentType);

  if (res.writable) {
    res.write("Hello");
    console.log("Still writable");
  }

  res.end("end is called");


  res.on("finish", () => {
    console.log("→ finish fired write ended:", res.writableEnded);
  });

});

server.listen(4000, () => {
  console.log("Server running at http://localhost:4000");
});
