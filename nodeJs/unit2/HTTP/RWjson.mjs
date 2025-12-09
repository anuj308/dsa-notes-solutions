import http from 'http';
import fs from 'fs';

http.createServer((req, res) => {
  if (req.url === "/file") {
    const info = '{ "name": "Parveen", "rollno": "123" }';

    fs.writeFile("first.json", info, "utf8", (err) => {
      if (err) {
        res.writeHead(500, "Error happened", { "Content-Type": "text/plain" });
        res.write("Error encountered: " + err.message);
      } else {
        res.writeHead(200, "Done", { "Content-Type": "text/plain" });
        res.write("File created successfully!");
      }
      res.end();
    });
  } 
  
  else if (req.url === "/read") {
    fs.readFile("first.json", "utf8", (err, data) => {
      if (err) {
        res.writeHead(500, "Error happened", { "Content-Type": "text/plain" });
        res.write("Error encountered: " + err.message);
      } else {
        res.writeHead(200, "Done", { "Content-Type": "application/json" });
        res.write("File read successfully!\n\n");
        res.write(data);
      }
      res.end();
    });
  } 
  
  else {
    res.writeHead(404, "Not Found", { "Content-Type": "text/plain" });
    res.write("Page not found");
    res.end();
  }
}).listen(7700, () => {
  console.log(" Server running at http://localhost:7700");
});
