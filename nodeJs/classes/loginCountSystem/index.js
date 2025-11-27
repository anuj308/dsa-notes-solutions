const express = require('express');
const cookieSession = require('cookie-session');
const path = require('path');

const app = express();

// Middleware
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Cookie session setup
app.use(cookieSession({
    name: 'session',
    keys: ['secret-key-1', 'secret-key-2'], // Secret keys for signing cookies
    maxAge: 24 * 60 * 60 * 1000 // 24 hours
}));

// Serve static files
app.use(express.static(path.join(__dirname, 'public')));

// Dummy users database (in real app, use a database)
const users = {
    'admin': { password: 'admin123', loginCount: 0 },
    'user1': { password: 'password1', loginCount: 0 },
    'abc': { password: '123', loginCount: 0 }
};

// Middleware to check if user is authenticated
const isAuthenticated = (req, res, next) => {
    if (req.session && req.session.username) {
        next();
    } else {
        res.status(401).json({ message: 'Please login first' });
    }
};

// Routes
app.get('/', (req, res) => {
    // If already logged in, redirect to home
    if (req.session && req.session.username) {
        return res.redirect('/home');
    }
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.get('/home', isAuthenticated, (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'home.html'));
});

// Get session data for frontend
app.get('/session-data', isAuthenticated, (req, res) => {
    const username = req.session.username;
    const loginCount = users[username] ? users[username].loginCount : 0;
    res.json({ username, loginCount });
});

// Login route
app.post('/login', (req, res) => {
    const { username, password } = req.body;

    // Check if user exists and password matches
    if (users[username] && users[username].password === password) {
        // Increment login count
        users[username].loginCount++;

        // Set session data
        req.session.username = username;
        req.session.loginCount = users[username].loginCount;

        res.json({ 
            success: true, 
            message: 'Login successful!',
            username: username,
            loginCount: users[username].loginCount
        });
    } else {
        res.status(401).json({ 
            success: false, 
            message: 'Invalid username or password' 
        });
    }
});

// Logout route
app.post('/logout', (req, res) => {
    req.session = null; // Destroy session
    res.json({ success: true, message: 'Logged out successfully' });
});

// Get current login count
app.get('/login-count', isAuthenticated, (req, res) => {
    const username = req.session.username;
    res.json({ 
        username, 
        loginCount: users[username].loginCount 
    });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
})