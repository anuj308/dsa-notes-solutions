import express from "express"
import path from "path"
import { fileURLToPath } from "url"

const app = express();

// Get current directory (needed for ES modules)
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// Middleware to parse form data (THIS WAS MISSING!)
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

// Serve static files from current directory
app.use(express.static(__dirname));

// GET route to serve index.html
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "index.html"));
});

// POST route for login
app.post("/login", (req, res) => {
    const { email, password } = req.body;
    
    console.log("Email:", email);
    console.log("Password:", password);
    
    // Validation
    if (!email || !password) {
        return res.send("All fields are required!");
    }
    if (password.length < 8) {
        return res.send("Password must be at least 8 characters!");
    }
    
    // Success response
    res.send(`Login successful for ${email}`);
});



app.listen(3000, () => {
    console.log("Server running at http://localhost:3000");
});