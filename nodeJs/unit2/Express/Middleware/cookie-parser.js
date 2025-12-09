import express from "express";
import cookieParser from "cookie-parser";


const ex = express();

ex.use(cookieParser());

ex.get("/setcookie", (req, res) => {
    res.cookie("username", "Rabaab", {
      maxAge: 1000*2, // 1 sec
      httpOnly: true // cookie cannot be accessed by JS
    });
  
    res.send("Cookie has been set!");
  });

  ex.get("/getcookie", (req, res) => {
    const user = req.cookies.username;
    res.send("Cookie value: " + user);
  });

  ex.get("/clearcookie", (req, res) => {
    res.clearCookie("username");
    res.send("Cookie cleared!");
  });

ex.listen(4000);