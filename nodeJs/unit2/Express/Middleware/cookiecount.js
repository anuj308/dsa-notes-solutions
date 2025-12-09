import express from "express";
import cookieParser from "cookie-parser";

const app = express();
app.use(cookieParser());

// Route whose visits should be counted
app.get("/home", (req, res) => {
    let count = 0;

    // If cookie already exists, read & increase
    if (req.cookies.homeVisit) {
        count = parseInt(req.cookies.homeVisit) + 1;
    } else {
        count = 1;
    }

    // Set updated cookie (expires in 1 day)
    res.cookie("homeVisit", count, {
        maxAge: 24 * 60 * 60 * 1000, // 1 day
        httpOnly: true
    });

    res.send(`You have visited the /home page ${count} times`);
});


// Default route
app.get("/", (req, res) => {
    res.send("Welcome! Go to /home to test visit counter.");
});

app.listen(3000);
