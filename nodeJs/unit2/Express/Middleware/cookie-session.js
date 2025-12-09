import express from "express";
import cookieSession from "cookie-session";

const app = express();

app.use(cookieSession({
    name: "session",
    keys: ["key1", "key2"],
    maxAge: 24 * 60 * 60 * 1000  // 24 hours
}));

app.get("/set", (req, res) => {
    req.session.user = "Alice";
    res.send("Cookie-session set!");
});

app.get("/get", (req, res) => {
    res.send(`Session value: ${req.session.user || "No session"}`);
});

app.get("/count", (req, res) => {
    req.session.count = (req.session.count || 0) + 1;
    res.send(`Visited ${req.session.count} times.`);
});

app.get("/logout", (req, res) => {
    req.session = null;  // delete session
    res.send("Session cleared!");
});

app.listen(3000);

