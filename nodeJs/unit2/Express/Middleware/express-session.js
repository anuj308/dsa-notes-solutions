import express from "express";
import session from "express-session";

const app = express();

app.use(session({
    // secret: "mySecret123",
    // resave: false,
    // saveUninitialized: true,
    cookie: {
        maxAge: 1000 * 60 * 60 // 1 hour
    }
}));

app.get("/set", (req, res) => {
    req.session.user = "Rahul";
    res.send("Session created!");
});

app.get("/get", (req, res) => {
    res.send(`Session Data: ${req.session.user || "No session"}`);
});

app.get("/counter", (req, res) => {
    req.session.count = (req.session.count || 0) + 1;
    res.send(`You visited ${req.session.count} times.`);
});

app.get("/logout", (req, res) => {
    req.session.destroy(() => {
        res.clearCookie("connect.sid");
        res.send("Logged out & session cleared.");
    });
});

app.listen(3000);
