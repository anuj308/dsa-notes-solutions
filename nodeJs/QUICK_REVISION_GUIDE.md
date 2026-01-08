# Node.js & Express.js - Quick Revision Guide (2-Hour Study)

## Table of Contents
1. Core Node.js Concepts
2. HTTP & Servers
3. Express.js Fundamentals
4. Routing & Controllers
5. Middleware
6. Database Integration
7. Socket.io (Real-time)
8. Viva Questions

---

## 1. CORE NODE.JS CONCEPTS

### 1.1 Modules & Require
**Concept:** Node.js uses CommonJS module system
```javascript
// Creating a module (maths.js)
module.exports = {
  add: (a, b) => a + b,
  subtract: (a, b) => a - b
};

// Using the module
const maths = require('./maths');
console.log(maths.add(5, 3)); // 8
```
**Key Points:**
- `module.exports` - export functionality
- `require()` - import modules
- Each file is a separate module with its own scope

---

### 1.2 Event Emitter
**Concept:** Implement publisher-subscriber pattern
```javascript
const EventEmitter = require('events');
const emitter = new EventEmitter();

// Listen to event
emitter.on('userLogin', (user) => {
  console.log(`${user} logged in`);
});

// Emit event
emitter.emit('userLogin', 'John');

// Remove listener
emitter.off('userLogin', callback);
```
**Key Methods:**
- `on(event, callback)` - listen to event
- `emit(event, args)` - trigger event
- `once(event, callback)` - listen once then remove
- `off(event, callback)` - remove listener

---

### 1.3 File System (fs)
**Synchronous vs Asynchronous:**
```javascript
const fs = require('fs');

// Synchronous (blocking)
const data = fs.readFileSync('file.txt', 'utf-8');

// Asynchronous with callback
fs.readFile('file.txt', 'utf-8', (err, data) => {
  if(err) console.log(err);
  else console.log(data);
});

// Promises
fs.promises.readFile('file.txt', 'utf-8')
  .then(data => console.log(data))
  .catch(err => console.log(err));

// Async/Await
async function readData() {
  const data = await fs.promises.readFile('file.txt', 'utf-8');
  return data;
}
```
**Common Methods:**
- `fs.readFile()` - read file asynchronously
- `fs.writeFile()` - write to file
- `fs.appendFile()` - append content
- `fs.unlink()` - delete file
- `fs.mkdir()` - create directory

---

### 1.4 Streams
**Concept:** Handle large data in chunks
```javascript
// Read stream
const readStream = fs.createReadStream('largefile.txt', {
  encoding: 'utf-8',
  highWaterMark: 16 * 1024 // 16KB chunks
});

readStream.on('data', (chunk) => {
  console.log(chunk);
});

readStream.on('end', () => {
  console.log('Reading complete');
});

// Write stream
const writeStream = fs.createWriteStream('output.txt');
readStream.pipe(writeStream);
```
**Stream Types:**
- **Readable** - read data from source
- **Writable** - write data to destination
- **Duplex** - both readable and writable
- **Transform** - modify data while streaming

---

### 1.5 Promises & Async-Await
```javascript
// Promise
function getData() {
  return new Promise((resolve, reject) => {
    setTimeout(() => resolve('Data'), 1000);
  });
}

getData().then(data => console.log(data));

// Async-Await (cleaner)
async function fetchData() {
  try {
    const data = await getData();
    console.log(data);
  } catch(err) {
    console.log(err);
  }
}
```

---

## 2. HTTP & SERVERS

### 2.1 Creating Basic Server
```javascript
const http = require('http');

const server = http.createServer((req, res) => {
  console.log(req.method); // GET, POST, etc
  console.log(req.url);    // '/path'
  console.log(req.headers); // request headers
  
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.write('Hello World');
  res.end();
});

server.listen(3000, () => {
  console.log('Server running on port 3000');
});
```

### 2.2 Request Body Parsing
```javascript
const http = require('http');
const querystring = require('querystring');

const server = http.createServer((req, res) => {
  if(req.method === 'POST') {
    let body = '';
    
    req.on('data', chunk => {
      body += chunk.toString();
    });
    
    req.on('end', () => {
      const data = querystring.parse(body);
      console.log(data);
      res.end('Data received');
    });
  }
});

server.listen(3000);
```

### 2.3 URL & Query Parameters
```javascript
const url = require('url');

const parsedUrl = url.parse('http://localhost:3000/path?name=john&age=25', true);
console.log(parsedUrl.pathname); // /path
console.log(parsedUrl.query);    // {name: 'john', age: '25'}
```

---

## 3. EXPRESS.JS FUNDAMENTALS

### 3.1 Basic Setup
```javascript
const express = require('express');
const app = express();

// Middleware to parse JSON
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Serve static files
app.use(express.static('public'));

// Basic route
app.get('/', (req, res) => {
  res.send('Hello World');
});

app.listen(3000, () => {
  console.log('Server running');
});
```

### 3.2 HTTP Methods
```javascript
// GET - retrieve data
app.get('/users/:id', (req, res) => {
  const id = req.params.id;
  res.json({ id: id, name: 'John' });
});

// POST - create data
app.post('/users', (req, res) => {
  const { name, email } = req.body;
  res.json({ message: 'User created', name, email });
});

// PUT - update data
app.put('/users/:id', (req, res) => {
  const { id } = req.params;
  const { name } = req.body;
  res.json({ message: 'User updated', id, name });
});

// DELETE - remove data
app.delete('/users/:id', (req, res) => {
  res.json({ message: 'User deleted' });
});

// PATCH - partial update
app.patch('/users/:id', (req, res) => {
  res.json({ message: 'User partially updated' });
});
```

### 3.3 URL Parameters & Query Strings
```javascript
// URL Parameters - /users/123
app.get('/users/:id', (req, res) => {
  console.log(req.params.id); // 123
});

// Query Strings - /users?page=1&limit=10
app.get('/users', (req, res) => {
  console.log(req.query.page);  // 1
  console.log(req.query.limit); // 10
});

// Multiple params - /posts/:postId/comments/:commentId
app.get('/posts/:postId/comments/:commentId', (req, res) => {
  console.log(req.params.postId, req.params.commentId);
});
```

---

## 4. ROUTING & CONTROLLERS

### 4.1 Router Pattern
```javascript
// routes/userRoutes.js
const express = require('express');
const router = express.Router();
const userController = require('../controllers/userController');

router.get('/', userController.getAllUsers);
router.get('/:id', userController.getUserById);
router.post('/', userController.createUser);
router.put('/:id', userController.updateUser);
router.delete('/:id', userController.deleteUser);

module.exports = router;
```

### 4.2 Controller Pattern
```javascript
// controllers/userController.js
const users = [];

exports.getAllUsers = (req, res) => {
  res.json(users);
};

exports.getUserById = (req, res) => {
  const user = users.find(u => u.id == req.params.id);
  res.json(user || { message: 'Not found' });
};

exports.createUser = (req, res) => {
  const user = { id: Date.now(), ...req.body };
  users.push(user);
  res.status(201).json(user);
};

exports.updateUser = (req, res) => {
  const user = users.find(u => u.id == req.params.id);
  if(user) {
    Object.assign(user, req.body);
    res.json(user);
  } else {
    res.status(404).json({ message: 'Not found' });
  }
};

exports.deleteUser = (req, res) => {
  const index = users.findIndex(u => u.id == req.params.id);
  if(index !== -1) {
    users.splice(index, 1);
    res.json({ message: 'Deleted' });
  } else {
    res.status(404).json({ message: 'Not found' });
  }
};
```

### 4.3 Using Routes in Server
```javascript
// server.js
const express = require('express');
const userRoutes = require('./routes/userRoutes');
const postRoutes = require('./routes/postRoutes');

const app = express();

app.use(express.json());
app.use('/api/users', userRoutes);
app.use('/api/posts', postRoutes);

app.listen(3000);
```

---

## 5. MIDDLEWARE

### 5.1 Middleware Basics
```javascript
// Execution order matters
const app = express();

// Middleware 1 - Parse JSON
app.use(express.json());

// Middleware 2 - Logging
app.use((req, res, next) => {
  console.log(`${req.method} ${req.url}`);
  next(); // Pass to next middleware
});

// Middleware 3 - Authentication
app.use((req, res, next) => {
  const token = req.headers.authorization;
  if(token) {
    next();
  } else {
    res.status(401).json({ message: 'Unauthorized' });
  }
});

// Route handler
app.get('/', (req, res) => {
  res.send('Hello');
});
```

### 5.2 Route-Specific Middleware
```javascript
const authMiddleware = (req, res, next) => {
  const token = req.headers.authorization;
  if(token === 'valid-token') {
    next();
  } else {
    res.status(401).send('Unauthorized');
  }
};

// Apply middleware only to specific routes
app.get('/public', (req, res) => {
  res.send('Public route');
});

app.get('/protected', authMiddleware, (req, res) => {
  res.send('Protected route');
});
```

### 5.3 Error Handling Middleware
```javascript
// Place error handler at the end
app.get('/user/:id', (req, res, next) => {
  if(!req.params.id) {
    const err = new Error('ID is required');
    next(err);
  } else {
    res.send('User found');
  }
});

// Error handler (must have 4 parameters)
app.use((err, req, res, next) => {
  console.log(err.message);
  res.status(500).json({ error: err.message });
});
```

---

## 6. DATABASE INTEGRATION

### 6.1 MongoDB with Mongoose
```javascript
const mongoose = require('mongoose');

// Connect
mongoose.connect('mongodb://localhost:27017/mydb');

// Schema
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
  email: { type: String, unique: true },
  age: Number,
  createdAt: { type: Date, default: Date.now }
});

// Model
const User = mongoose.model('User', userSchema);

// CRUD Operations
// Create
const newUser = new User({ name: 'John', email: 'john@example.com' });
await newUser.save();

// Read
const users = await User.find();
const user = await User.findById(id);

// Update
await User.findByIdAndUpdate(id, { name: 'Jane' });

// Delete
await User.findByIdAndDelete(id);
```

### 6.2 PostgreSQL with Node
```javascript
const { Pool } = require('pg');

const pool = new Pool({
  user: 'postgres',
  password: 'password',
  host: 'localhost',
  port: 5432,
  database: 'mydb'
});

// Query
const result = await pool.query('SELECT * FROM users WHERE id = $1', [1]);

// Insert
const insertResult = await pool.query(
  'INSERT INTO users (name, email) VALUES ($1, $2) RETURNING *',
  ['John', 'john@example.com']
);
```

### 6.3 CRUD API Example with File System
```javascript
const fs = require('fs').promises;
const path = require('path');

const dataFile = path.join(__dirname, 'data.json');

async function readData() {
  try {
    const data = await fs.readFile(dataFile, 'utf-8');
    return JSON.parse(data || '[]');
  } catch {
    return [];
  }
}

async function writeData(data) {
  await fs.writeFile(dataFile, JSON.stringify(data, null, 2));
}

app.get('/items', async (req, res) => {
  const data = await readData();
  res.json(data);
});

app.post('/items', async (req, res) => {
  const data = await readData();
  const newItem = { id: Date.now(), ...req.body };
  data.push(newItem);
  await writeData(data);
  res.status(201).json(newItem);
});

app.put('/items/:id', async (req, res) => {
  const data = await readData();
  const item = data.find(i => i.id == req.params.id);
  if(item) {
    Object.assign(item, req.body);
    await writeData(data);
    res.json(item);
  } else {
    res.status(404).json({ message: 'Not found' });
  }
});

app.delete('/items/:id', async (req, res) => {
  let data = await readData();
  data = data.filter(i => i.id != req.params.id);
  await writeData(data);
  res.json({ message: 'Deleted' });
});
```

---

## 7. SOCKET.IO (REAL-TIME COMMUNICATION)

### 7.1 Basic Setup
```javascript
const express = require('express');
const http = require('http');
const socketio = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketio(server, {
  cors: { origin: '*' }
});

// Handle connections
io.on('connection', (socket) => {
  console.log('New user connected:', socket.id);
  
  // Emit to single client
  socket.emit('welcome', { message: 'Welcome!' });
  
  // Listen to client events
  socket.on('message', (data) => {
    console.log(data);
    
    // Broadcast to all users
    io.emit('messageToAll', data);
    
    // Send to all except sender
    socket.broadcast.emit('messageBroadcast', data);
  });
  
  // On disconnect
  socket.on('disconnect', () => {
    console.log('User disconnected');
    io.emit('userCount', io.engine.clientsCount);
  });
});

server.listen(3000);
```

### 7.2 Client-Side Socket.io
```html
<script src="https://cdn.socket.io/4.5.4/socket.io.min.js"></script>
<script>
  const socket = io();
  
  socket.on('welcome', (data) => {
    console.log(data.message);
  });
  
  socket.on('messageToAll', (data) => {
    console.log('Received:', data);
  });
  
  function sendMessage(msg) {
    socket.emit('message', { text: msg });
  }
</script>
```

---

## 8. VIVA QUESTIONS & ANSWERS

### **Question 1: What is Node.js?**
**Answer:** Node.js is a JavaScript runtime built on Chrome's V8 engine that allows running JavaScript outside the browser. It's single-threaded, event-driven, and uses non-blocking I/O operations for high scalability.

**Key Features:**
- Event-driven architecture
- Non-blocking I/O
- Built on V8 engine
- Fast execution

---

### **Question 2: What's the difference between synchronous and asynchronous code?**
**Answer:**
- **Synchronous:** Code executes line by line, blocking until completion
- **Asynchronous:** Code doesn't wait for operation to complete, uses callbacks, promises, or async-await

```javascript
// Synchronous - BLOCKS
const data = fs.readFileSync('file.txt');

// Asynchronous - NON-BLOCKING
fs.readFile('file.txt', (err, data) => {
  console.log(data);
});
```

---

### **Question 3: What is Express.js?**
**Answer:** Express is a minimal web framework for Node.js that simplifies building web applications and APIs. It provides routing, middleware support, and request-response handling.

**Key Features:**
- Easy routing
- Middleware support
- Templating engines
- Error handling
- Static file serving

---

### **Question 4: Difference between app.use() and app.get()?**
**Answer:**
- **app.use():** Middleware that runs for ALL requests (GET, POST, etc.)
- **app.get():** Route handler only for GET requests to specific path

```javascript
app.use(logger); // Runs for every request

app.get('/users', handler); // Only for GET /users
```

---

### **Question 5: What are middlewares?**
**Answer:** Middlewares are functions that have access to request, response, and next middleware. They can modify request/response or end the cycle.

**Order of execution:**
1. Request comes in
2. Middleware 1 → next()
3. Middleware 2 → next()
4. Route handler
5. Response sent

---

### **Question 6: What is req.params vs req.query?**
**Answer:**
- **req.params:** URL parameters (`:id`)
- **req.query:** Query strings (`?page=1&limit=10`)

```javascript
// req.params
app.get('/users/:id', (req, res) => {
  console.log(req.params.id); // From URL path
});

// req.query
app.get('/search', (req, res) => {
  console.log(req.query.keyword); // From ?keyword=value
});
```

---

### **Question 7: How to handle errors in Express?**
**Answer:** Using error handling middleware with 4 parameters (err, req, res, next)

```javascript
app.get('/user/:id', (req, res, next) => {
  if(!req.params.id) {
    next(new Error('ID required'));
  } else {
    res.send('User found');
  }
});

// Error handler (MUST be last)
app.use((err, req, res, next) => {
  res.status(500).json({ error: err.message });
});
```

---

### **Question 8: What are streams in Node.js?**
**Answer:** Streams allow reading/writing data in chunks instead of loading entire file in memory. This is efficient for large files.

**Types:**
- Readable: Reading data
- Writable: Writing data
- Duplex: Both read and write
- Transform: Modify while streaming

```javascript
fs.createReadStream('large.txt')
  .pipe(fs.createWriteStream('copy.txt'));
```

---

### **Question 9: What is the event emitter?**
**Answer:** EventEmitter allows objects to emit events and listen to them.

```javascript
const EventEmitter = require('events');
const emitter = new EventEmitter();

emitter.on('userLogin', (user) => {
  console.log(`${user} logged in`);
});

emitter.emit('userLogin', 'John');
```

---

### **Question 10: What's the difference between require() and import?**
**Answer:**
- **require():** CommonJS, synchronous, returns module
- **import:** ES6, asynchronous, used in modern Node.js

```javascript
// CommonJS
const express = require('express');

// ES6 (requires "type": "module" in package.json)
import express from 'express';
```

---

### **Question 11: How to create a REST API?**
**Answer:** Use HTTP methods on endpoints with proper status codes

```javascript
// GET - Retrieve
app.get('/users/:id', (req, res) => {
  res.json({ id: req.params.id });
});

// POST - Create (201 status)
app.post('/users', (req, res) => {
  res.status(201).json(newUser);
});

// PUT - Update (200 status)
app.put('/users/:id', (req, res) => {
  res.json(updatedUser);
});

// DELETE - Remove (204 status)
app.delete('/users/:id', (req, res) => {
  res.status(204).send();
});
```

---

### **Question 12: What is CORS?**
**Answer:** Cross-Origin Resource Sharing allows requests from different domains.

```javascript
const cors = require('cors');
app.use(cors());

// Or specific origin
app.use(cors({
  origin: 'http://localhost:3000',
  methods: ['GET', 'POST']
}));
```

---

### **Question 13: How to validate user input?**
**Answer:** Check and sanitize input in middleware or route handlers

```javascript
const validateUser = (req, res, next) => {
  const { name, email } = req.body;
  
  if(!name || !email) {
    return res.status(400).json({ error: 'Missing fields' });
  }
  
  if(!email.includes('@')) {
    return res.status(400).json({ error: 'Invalid email' });
  }
  
  next();
};

app.post('/users', validateUser, (req, res) => {
  // User is valid
  res.json({ message: 'User created' });
});
```

---

### **Question 14: What is Socket.io and why use it?**
**Answer:** Socket.io enables real-time, bidirectional communication between client and server using WebSockets.

**Use Cases:**
- Live chat
- Notifications
- Collaborative apps
- Real-time dashboards

```javascript
io.on('connection', (socket) => {
  socket.emit('message', 'Hello');
  socket.on('reply', (data) => {
    io.emit('broadcast', data);
  });
});
```

---

### **Question 15: What is package.json?**
**Answer:** Configuration file containing project metadata, dependencies, scripts, and version info.

```json
{
  "name": "my-app",
  "version": "1.0.0",
  "description": "My Node app",
  "main": "server.js",
  "scripts": {
    "start": "node server.js",
    "dev": "nodemon server.js"
  },
  "dependencies": {
    "express": "^4.18.0"
  },
  "devDependencies": {
    "nodemon": "^2.0.0"
  }
}
```

---

### **Question 16: What is nodemon?**
**Answer:** Development tool that automatically restarts the application when files change.

```bash
npm install -D nodemon
```

```json
{
  "scripts": {
    "dev": "nodemon server.js"
  }
}
```

---

### **Question 17: How to handle file uploads?**
**Answer:** Use libraries like `multer` for handling multipart form data

```javascript
const multer = require('multer');
const upload = multer({ dest: 'uploads/' });

app.post('/upload', upload.single('file'), (req, res) => {
  console.log(req.file);
  res.json({ filename: req.file.filename });
});
```

---

### **Question 18: What is JSON?**
**Answer:** JavaScript Object Notation - lightweight data format for exchanging data.

```json
{
  "name": "John",
  "age": 30,
  "email": "john@example.com",
  "skills": ["Node.js", "Express", "MongoDB"]
}
```

---

### **Question 19: How to read and write JSON files?**
**Answer:** Parse and stringify JSON data

```javascript
// Read
const data = JSON.parse(fs.readFileSync('data.json', 'utf-8'));

// Write
fs.writeFileSync('data.json', JSON.stringify(data, null, 2));
```

---

### **Question 20: What is callback hell and how to avoid it?**
**Answer:** Deeply nested callbacks making code hard to read. Use promises or async-await.

```javascript
// Callback Hell (Bad)
fs.readFile('file.txt', (err, data) => {
  processData(data, (err, result) => {
    saveData(result, (err) => {
      console.log('Done');
    });
  });
});

// Async-Await (Good)
async function process() {
  const data = await fs.promises.readFile('file.txt');
  const result = await processData(data);
  await saveData(result);
  console.log('Done');
}
```

---

## QUICK MEMORY TIPS

### Must Remember Patterns:
1. **Basic Server:** `http.createServer()` → `listen(port)`
2. **Express Setup:** `app.use()` → `app.METHOD(path, handler)`
3. **Middleware:** Always call `next()` to pass control
4. **Routes:** `req.params` (path), `req.query` (string), `req.body` (JSON)
5. **Error Handling:** 4-parameter middleware `(err, req, res, next)`
6. **Async:** Use `async/await` instead of callbacks
7. **JSON:** `JSON.parse()` and `JSON.stringify()`
8. **File Operations:** Use `fs.promises` for cleaner code

### Common HTTP Status Codes:
- **200:** OK
- **201:** Created
- **204:** No Content
- **400:** Bad Request
- **401:** Unauthorized
- **404:** Not Found
- **500:** Server Error

### Common Mistakes to Avoid:
1. ❌ Forgetting `next()` in middleware
2. ❌ Not handling errors
3. ❌ Blocking operations in synchronous code
4. ❌ Not validating user input
5. ❌ Missing response after request
6. ❌ Synchronous file operations on large files

---

**Study Tips:**
- Read code examples multiple times
- Practice writing code from scratch
- Test each concept with a simple project
- Review viva questions before interview
- Focus on "why" not just "what"

**Estimated Reading Time:** 1.5-2 hours
**Best Practice:** Code along while reading!
