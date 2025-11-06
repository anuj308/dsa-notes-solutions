const http = require("http");
const fs = require("fs");

const server = http
  .createServer((req, res) => {
    // if (req.url == `/readData`) {
    //   res.end("readdata url welcomes you ");
    // } else if (req.url == "/profile") res.send("profile url ");
    // else if (req.url === "/") {
    //   const userInfo = `{
    //         "name":"anuj",
    //     }`;
    //   fs.writeFile("data.json", userInfo, (err, data) => {
    //     if (err) console.log("error");
    //     else console.log("success");
    //   });
    //   fs.readFile("data.json", "utf8", (err, data) => {
    //     if (err) {
    //       res.writeHead(500, { "Content-Type": "text/plain" });
    //       res.end("Error reading file");
    //       return;
    //     }
    //     res.writeHead(200, { "Content-Type": "text/html" });
    //     res.end(`<pre>${data}</pre>`);
    //   });
    // } else {
    //   res.writeHead(404, { "Content-Type": "text/plain" });
    //   res.end("Not Found");
    // }

    if(req.url.startsWith("/home")){
        if(res.url = "/home/a") res.end("a")
        else if(res.url = "/home/b") res.end("b")
        res.end("end");
    }else res.end("invalid url")
  })
  .listen(3000);
