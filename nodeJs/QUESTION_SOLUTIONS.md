# Comprehensive Solutions to Question Images (1–20)

This document provides complete solutions with explanations and short viva notes for each photo. Sections are organized by photo number.

---

## Photo 1 — Solutions

Q1(a) Basic Contact Management (Node.js + MongoDB)
- Approach: Express + Mongoose CRUD API storing contacts in MongoDB.
- Model:
```javascript
// models/Contact.js
const mongoose = require('mongoose');
const ContactSchema = new mongoose.Schema({
  name: { type: String, required: true },
  email: { type: String, required: true, unique: true },
  phone: String
});
module.exports = mongoose.model('Contact', ContactSchema);
```
- Routes:
```javascript
// server.js
const express = require('express');
const mongoose = require('mongoose');
const Contact = require('./models/Contact');
const app = express();
app.use(express.json());
mongoose.connect('mongodb://localhost:27017/contacts');

app.post('/contacts', async (req, res) => {
  const contact = await Contact.create(req.body);
  res.status(201).json(contact);
});
app.get('/contacts', async (req, res) => {
  res.json(await Contact.find());
});
app.put('/contacts/:id', async (req, res) => {
  res.json(await Contact.findByIdAndUpdate(req.params.id, req.body, { new: true }));
});
app.delete('/contacts/:id', async (req, res) => {
  await Contact.findByIdAndDelete(req.params.id);
  res.status(204).send();
});
app.listen(3000);
```
- Viva notes: CRUD stands for Create, Read, Update, Delete; use `express.json()` to parse bodies; `201 Created` for POST.

Q1(b) MongoDB query + frontend UI
- Query: Find products where `quantity < 10`.
```javascript
// Node/Mongo shell
db.products.find({ quantity: { $lt: 10 } })
```
- Frontend:
```html
<div id="list"></div>
<script>
  async function load() {
    const res = await fetch('/api/products?lowStock=true');
    const products = await res.json();
    document.getElementById('list').innerHTML = products.map(p => (
      `<div>${p.name} - ${p.quantity} <button onclick="remove('${p._id}')">Remove</button></div>`
    )).join('');
  }
  async function remove(id) {
    await fetch('/api/products/' + id, { method: 'DELETE' });
    load();
  }
  load();
</script>
```
- Back-end filter (example):
```javascript
app.get('/api/products', async (req, res) => {
  const filter = req.query.lowStock ? { quantity: { $lt: 10 } } : {};
  res.json(await Product.find(filter));
});
```
- Viva notes: `$lt` means “less than”; use query parameters for filters.

Q2(a) Constructor function with tax condition
```javascript
function Employee(name, salary) {
  this.name = name;
  this.salary = salary;
  this.isTaxable = function() { return this.salary >= 500000; } // example threshold
}
const e = new Employee('Alice', 420000);
console.log(e.name, e.isTaxable());
```
- Viva notes: `this` binds to new instance; constructor uses `new`.

Q2(b) Node server appending file contents based on URL
```javascript
const http = require('http');
const fs = require('fs');
const url = require('url');

http.createServer((req, res) => {
  const { pathname, query } = url.parse(req.url, true);
  if (pathname === '/append' && query.file && query.text) {
    if (!fs.existsSync(query.file)) {
      res.statusCode = 404; return res.end('File not found');
    }
    fs.appendFile(query.file, `\n${query.text}`, (err) => {
      if (err) { res.statusCode = 500; return res.end('Error'); }
      res.end('Appended');
    });
  } else {
    res.statusCode = 404; res.end('Invalid URL');
  }
}).listen(3000);
```
- Viva notes: `url.parse` gets path and query; always validate inputs.

Q3(a) Sum of n natural numbers and write result to file
```javascript
const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.question('Enter n: ', (n) => {
  const N = parseInt(n, 10);
  if (isNaN(N) || N < 1) { console.log('Invalid n'); rl.close(); return; }
  const sum = N * (N + 1) / 2; // formula
  fs.writeFileSync('result.txt', `Sum of first ${N} natural numbers = ${sum}`);
  console.log('Written to result.txt');
  rl.close();
});
```
- Viva notes: Formula O(1) vs loop O(n); `readline` for CLI input.

Q3(b) Merge two arrays and display
```javascript
const a = [1,2,3,4,5];
const b = [6,7,8,9,10];
const merged = [...a, ...b];
console.log(merged);
```
- Viva notes: Spread operator; alternative `a.concat(b)`.

Q4(a) Cookie form: set and delete
```html
<input id="fname" placeholder="First Name">
<input id="lname" placeholder="Last Name">
<button onclick="setCookie()">Set Cookie</button>
<button onclick="delCookie()">Delete Cookie</button>
<script>
  function setCookie() {
    const v = `${fname.value}-${lname.value}`;
    document.cookie = `user=${encodeURIComponent(v)}; path=/; max-age=86400`;
    alert('Cookie set');
  }
  function delCookie() {
    document.cookie = 'user=; path=/; max-age=0';
    alert('Cookie deleted');
  }
</script>
```
- Viva notes: `max-age=0` deletes; cookies are per-domain/path.

Q4(b) Socket.io periodic messaging with stop/resume
```javascript
// server.js
const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const app = express();
const server = http.createServer(app);
const io = new Server(server, { cors: { origin: '*' } });

io.on('connection', (socket) => {
  console.log('connected', socket.id);
});
server.listen(3000);
```
```html
<!-- client.html -->
<script src="https://cdn.socket.io/4.7.2/socket.io.min.js"></script>
<script>
  const socket = io('http://localhost:3000');
  let interval;
  function start() { interval = setInterval(() => socket.emit('message', 'wow server'), 3000); }
  function stop() { clearInterval(interval); }
  start();
  setTimeout(stop, 12000); // stop after 12s
  setTimeout(start, 17000); // resume after +5s
</script>
```
- Viva notes: `setInterval` vs `setTimeout`; emit vs broadcast.

Q5(a) HTTP module server with CRUD-like routing
```javascript
const http = require('http');
const server = http.createServer((req, res) => {
  const { method, url } = req;
  if (url.startsWith('/items')) {
    if (method === 'GET') { res.end('List items'); }
    else if (method === 'POST') { res.end('Create item'); }
    else if (method === 'PUT') { res.end('Update item'); }
    else if (method === 'DELETE') { res.end('Delete item'); }
    else { res.statusCode = 405; res.end('Method Not Allowed'); }
  } else { res.statusCode = 404; res.end('Not Found'); }
});
server.listen(3000);
```
- Viva notes: HTTP verbs map to CRUD; prefer Express for real apps.

Q5(b) MongoDB update quantity by product name + update UI
```javascript
// Mongo query
db.products.updateOne({ product: 'Apple' }, { $set: { quantity: 42 } })
```
```javascript
// Express route
app.put('/api/products/:name/quantity', async (req, res) => {
  const r = await Product.updateOne({ product: req.params.name }, { $set: { quantity: req.body.quantity } });
  res.json(r);
});
```
```html
<input id="name" placeholder="Product name">
<input id="qty" type="number" placeholder="Quantity">
<button onclick="updateQty()">Update</button>
<script>
  async function updateQty() {
    const name = document.getElementById('name').value;
    const qty = +document.getElementById('qty').value;
    await fetch(`/api/products/${encodeURIComponent(name)}/quantity`, {
      method: 'PUT', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ quantity: qty })
    });
    alert('Updated');
  }
</script>
```
- Viva notes: `$set` updates specific field; validate inputs.

Q5(c) Form submit using HTTP module (echo back)
```javascript
const http = require('http');
const querystring = require('querystring');
http.createServer((req, res) => {
  if (req.method === 'GET') {
    res.setHeader('Content-Type', 'text/html');
    res.end('<form method="POST"><input name="msg"><button>Submit</button></form>');
  } else if (req.method === 'POST') {
    let body = ''; req.on('data', c => body += c);
    req.on('end', () => { const data = querystring.parse(body); res.end('You sent: ' + data.msg); });
  } else { res.statusCode = 405; res.end('Method Not Allowed'); }
}).listen(3000);
```
- Viva notes: parse `application/x-www-form-urlencoded` manually; set proper headers.

Q5(d) Express GET vs POST route difference
```javascript
app.get('/users', (req, res) => { /* read-only retrieval */ });
app.post('/users', (req, res) => { /* creates new resource using req.body */ });
```
- Viva notes: GET is idempotent/safe; POST is not; GET uses query/params, POST uses body.

---

Additional photos (2–20) will follow similar structure: I will parse each image’s text and add precise solutions below. Let me know if you want me to prioritize specific photos first.

---

## Photo 2 — Solutions

Q1 Cookies: set, read, delete (Express)
- Use `cookie-parser` to simplify cookie handling.
```javascript
const express = require('express');
const cookieParser = require('cookie-parser');
const app = express();
app.use(cookieParser());

// Set cookie (e.g., sessionRole)
app.get('/setcookie', (req, res) => {
  res.cookie('sessionRole', 'student', { httpOnly: true, maxAge: 24*60*60*1000 });
  res.json({ message: 'Cookie set' });
});
// Read cookie
app.get('/readcookie', (req, res) => {
  res.json({ cookies: req.cookies });
});
// Delete cookie
app.get('/deletecookie', (req, res) => {
  res.clearCookie('sessionRole');
  res.json({ message: 'Cookie deleted' });
});
```
- Viva: Cookies persist small key/value pairs; `httpOnly` prevents JS access.

Q2 Mongoose `Course` schema + env connection + insert/find
```javascript
// models/Course.js
const mongoose = require('mongoose');
const CourseSchema = new mongoose.Schema({
  title: { type: String, required: true },
  instructor: String,
  topics: [String],
  createdAt: { type: Date, default: Date.now }
});
module.exports = mongoose.model('Course', CourseSchema);

// index.js
require('dotenv').config();
const Course = require('./models/Course');
(async () => {
  try {
    await mongoose.connect(process.env.MONGO_URL);
    const sample = await Course.create({ title: 'Node Basics', instructor: 'Jane', topics: ['modules','http'] });
    const found = await Course.findOne({ title: 'Node Basics' });
    console.log({ sample, found });
  } catch (err) {
    console.error('Error:', err.message);
  } finally {
    await mongoose.disconnect();
  }
})();
```
- Viva: Use `.env` for secrets; `create()` returns document; `findOne()` returns first match.

Q3 Protect `/admin` via middleware order and query key
```javascript
const express = require('express');
const app = express();

// 1) auth: require key=123
function auth(req, res, next) {
  if (req.query.key === '123') return next();
  res.status(401).json({ error: 'Unauthorized' });
}
// 2) roleCheck: example role from query
function roleCheck(req, res, next) {
  if (req.query.role === 'Super') return next();
  res.status(403).json({ error: 'Forbidden: role required' });
}
// 3) log: log access
function log(req, res, next) {
  console.log(`[ADMIN] ${req.method} ${req.url}`);
  next();
}

app.use('/admin', auth, roleCheck, log);
app.get('/admin/dashboard', (req, res) => res.json({ message: 'Welcome admin' }));
```
- Viva: Middleware executes in declared order; `401` vs `403` difference.

---

## Photo 3 — Solutions

Q5 Real-time chat (Socket.io): broadcast and user joined
```javascript
// server.js
const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const app = express();
const server = http.createServer(app);
const io = new Server(server, { cors: { origin: '*' } });

io.on('connection', (socket) => {
  io.emit('system', 'User joined');
  socket.on('chat', (msg) => {
    io.emit('chat', msg); // broadcast to all
  });
});
server.listen(3000);
```
- Viva: `io.emit` sends to all; `socket.broadcast.emit` excludes sender.

Q6 zlib compress/decompress
```javascript
const fs = require('fs');
const zlib = require('zlib');
// Compress data.bin -> data.bin.gz
fs.createReadStream('data.bin').pipe(zlib.createGzip()).pipe(fs.createWriteStream('data.bin.gz'));
// Decompress data.bin.gz -> data.unzip.bin
fs.createReadStream('data.bin.gz').pipe(zlib.createGunzip()).pipe(fs.createWriteStream('data.unzip.bin'));
```
- Viva: Streams avoid loading entire file; gzip vs deflate.

Q7 Signup route validation
```javascript
const express = require('express');
const app = express();
app.use(express.json());
const isEmail = (e) => /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(e);
const strongPw = (p) => p.length >= 8 && /[A-Z]/.test(p) && /[a-z]/.test(p) && /\d/.test(p);

app.post('/signup', (req, res) => {
  const { email, password } = req.body;
  const errors = [];
  if (!isEmail(email)) errors.push('Invalid email');
  if (!strongPw(password)) errors.push('Weak password');
  if (errors.length) return res.status(400).json({ errors });
  res.status(201).json({ message: 'Signup ok' });
});
```).pipe(fs.createWr
- Viva: Return `400` for validation errors; never store plain passwords.

Q8 Mongoose Book CRUD (insert + list)
```javascript
const mongoose = require('mongoose');
const BookSchema = new mongoose.Schema({ title: String, author: String, price: Number, tags: [String] });
const Book = mongoose.model('Book', BookSchema);
(async () => {
  await mongoose.connect('mongodb://localhost:27017/books');
  await Book.create({ title: 'JS Guide', author: 'MDN', price: 299, tags: ['js','web'] });
  const all = await Book.find();
  console.log(all);
  await mongoose.disconnect();
})();
```
- Viva: Arrays in schema via `[String]`; `find()` returns cursor/doc array.

Q9 Extract query parameter and return JSON
```javascript
app.get('/search', (req, res) => {
  const q = req.query.q || '';
  res.json({ query: q });
});
```
- Viva: Use `req.query` for query strings.

Q10 Products API: GET static, POST body
```javascript
app.get('/products', (req, res) => {
  res.json([{ name: 'Pen', price: 10 }, { name: 'Notebook', price: 50 }]);
});
app.post('/products', (req, res) => {
  console.log('New product:', req.body);
  res.status(201).json({ received: req.body });
});
```
- Viva: `201 Created` for POST; body requires `express.json()`.

---

## Photo 4 — Solutions

Q8(a) Session-based authentication
```javascript
const express = require('express');
const session = require('express-session');
const app = express();
app.use(express.json());
app.use(session({ secret: 's3cret', resave: false, saveUninitialized: false }));

app.post('/login', (req, res) => {
  const { user, pass } = req.body;
  if (user === 'admin' && pass === 'admin') { req.session.user = { name: 'admin', role: 'Super' }; return res.json({ ok: true }); }
  res.status(401).json({ error: 'Invalid credentials' });
});
function requireAuth(req, res, next) { if (req.session.user) return next(); res.status(401).json({ error: 'Login required' }); }
app.get('/private', requireAuth, (req, res) => res.json({ message: 'Welcome', user: req.session.user }));
```
- Viva: Sessions persist server-side state; cookie holds session id.

Q8(b) Update product price by name (authorized users via session)
```javascript
app.put('/products/:name/price', requireAuth, async (req, res) => {
  const r = await Product.updateOne({ name: req.params.name }, { $set: { price: req.body.price } });
  res.json(r);
});
// Frontend form example
// <input id="name"><input id="price" type="number"><button onclick="upd()">Update</button>
// function upd(){ fetch('/products/'+name.value+'/price',{ method:'PUT', headers:{'Content-Type':'application/json'}, body: JSON.stringify({ price:+price.value })}); }
```
- Viva: Guard with auth middleware; use `$set`.

Q9(a) Store form inputs to Excel (XLSX)
```javascript
// npm i xlsx
const XLSX = require('xlsx');
app.post('/excel', (req, res) => {
  const rows = [req.body];
  const wb = XLSX.utils.book_new();
  const ws = XLSX.utils.json_to_sheet(rows);
  XLSX.utils.book_append_sheet(wb, ws, 'Sheet1');
  XLSX.writeFile(wb, 'data.xlsx');
  res.json({ saved: true });
});
```
- Viva: Convert JSON to sheet; write workbook to file.

Q9(b) zlib compression/decompression explanation
- Compression reduces size; gzip commonly used; decompression restores bytes. See Q6 code.

Q10(a) Socket.io send box + store in MongoDB
```javascript
// server.js
const Message = mongoose.model('Message', new mongoose.Schema({ text: String, at: { type: Date, default: Date.now } }));
io.on('connection', (socket) => {
  socket.on('send', async (text) => {
    console.log('MSG:', text);
    await Message.create({ text });
    io.emit('chat', text);
  });
});
```
```html
<!-- client.html -->
<input id="box"><button onclick="send()">Send</button>
<script src="https://cdn.socket.io/4.7.2/socket.io.min.js"></script>
<script>
  const socket = io('http://localhost:3000');
  function send(){ socket.emit('send', document.getElementById('box').value); }
  socket.on('chat', (m)=> console.log('Chat:', m));
</script>
```
- Viva: Persist messages for history; emit to update all clients.

Q10(b) Async callback demonstration
```javascript
console.log('A');
setTimeout(() => console.log('B (later)'), 0);
console.log('C');
// Output order: A, C, then B — shows event loop defers callback.
```
- Viva: Event loop queues callbacks; microtasks vs macrotasks.

---

## Photo 5 — Solutions

Q1 Create directory using `path` + `fs`
```javascript
const fs = require('fs');
const path = require('path');
const dir = path.join(__dirname, 'newDir');
if (!fs.existsSync(dir)) fs.mkdirSync(dir); // creates directory
```
- Viva: `path.join` builds OS-safe paths; `fs.mkdirSync` creates directory.

Q2 Simple form echo using HTTP module
```javascript
const http = require('http');
const querystring = require('querystring');
http.createServer((req, res) => {
  if (req.method === 'GET') {
    res.setHeader('Content-Type', 'text/html');
    res.end('<form method="POST"><input name="val"><button>Submit</button></form>');
  } else if (req.method === 'POST') {
    let body = ''; req.on('data', c => body += c);
    req.on('end', () => { const d = querystring.parse(body); res.setHeader('Content-Type','text/html'); res.end(`<p>${d.val}</p>`); });
  }
}).listen(3001);
```
- Viva: `application/x-www-form-urlencoded` parsing via `querystring`.

Q3 Paragraph hover change (CSS)
```html
<p id="p">Hover me</p>
<style>
  #p { font-family: Arial; transition: all .2s; }
  #p:hover { font-style: italic; font-weight: bold; color: purple; }
  </style>
```
- Viva: `:hover` pseudo-class applies on mouseover.

Q4 Express downloads endpoint
```javascript
const express = require('express');
const app = express();
app.get('/downloads', (req, res) => {
  res.download('sample.pdf'); // ensure file exists
});
app.listen(3002);
```
- Viva: `res.download()` sets headers for attachment.

Q5 Express middleware demo + readable stream
```javascript
const express = require('express');
const fs = require('fs');
const app = express();
// middleware
app.use((req, res, next) => { console.log(req.method, req.url); next(); });
// readable stream
app.get('/read', (req, res) => {
  res.setHeader('Content-Type', 'text/plain');
  fs.createReadStream('data.txt').pipe(res);
});
app.listen(3003);
```
- Viva: Middleware runs before handlers; streams pipe directly to response.

Q6 Socket.io periodic wow server (stop/resume)
```javascript
// client
const socket = io('http://localhost:3000');
let intv; function start(){ intv = setInterval(()=>socket.emit('wow','wow server'), 2000); }
function stop(){ clearInterval(intv); }
start(); setTimeout(stop, 12000); setTimeout(start, 17000);
```
- Viva: Use `setInterval` and `clearInterval` for periodic emission.

Q7 JS event handling demo
```html
<button id="btn">Click</button>
<script>
document.getElementById('btn').addEventListener('click', () => alert('Clicked'));
document.addEventListener('keydown', e => console.log('Key:', e.key));
</script>
```
- Viva: `addEventListener` attaches listeners; event object carries details.

Q8 Links app with support chat message
```javascript
const express = require('express');
const app = express();
app.get('/', (req, res) => res.send('<a href="/home">Home</a> <a href="/contact">Contact Us</a> <a href="/support">Support</a>'));
app.get('/support', (req, res) => res.send('Hi How can I help you?'));
app.listen(3004);
```
- Viva: Simple route mapping displays support message.

Q9 EventEmitter: write and rename file
```javascript
const fs = require('fs');
const EventEmitter = require('events');
const em = new EventEmitter();
em.on('write', () => fs.writeFileSync('note.txt', 'Hello'));
em.on('rename', () => fs.renameSync('note.txt', 'renamed.txt'));
em.emit('write'); em.emit('rename');
```
- Viva: Emitting events triggers IO actions.

---

## Photo 6 — Solutions

Q1 Express app: text file + download via `download()`
```javascript
const express = require('express');
const fs = require('fs');
const app = express();
fs.writeFileSync('student.txt', 'Reg: 1, Name: Alex, Grade: A');
app.get('/download', (req, res) => res.download('student.txt'));
app.listen(3005);
```
- Viva: `download()` infers filename; ensure file path correct.

Q2 Arithmetic ops in middleware
```javascript
const express = require('express');
const app = express();
function ops(req, res, next){
  const n = +req.query.n || 0; req.result = { inc: n+1, dec: n-1, sq: n*n }; next();
}
app.get('/calc', ops, (req, res) => res.json(req.result));
app.listen(3006);
```
- Viva: Pass computed values via `req` object.

Q3 Cookies set/show/clear via cookie-parser
```javascript
const cookieParser = require('cookie-parser');
app.use(cookieParser());
app.get('/set', (r,s)=>{ s.cookie('role','student'); s.send('set'); });
app.get('/show', (r,s)=> s.json(r.cookies));
app.get('/clear', (r,s)=>{ s.clearCookie('role'); s.send('cleared'); });
```
- Viva: `clearCookie` deletes; cookies are per-domain/path.

Q4 Express-validator chain
```javascript
// npm i express-validator
const { body, validationResult } = require('express-validator');
app.post('/student',
  body('name').isLength({ min:1 }),
  body('reg').isLength({ min:3, max:12 }),
  body('roll').isInt(),
  body('mobile').isMobilePhone('en-IN'),
  body('mail').isEmail(),
  (req,res)=>{ const errors = validationResult(req); if(!errors.isEmpty()) return res.status(400).json({ errors: errors.array() }); res.json({ ok:true }); }
);
```
- Viva: `validationResult` aggregates errors.

Q5 HTTP prime check
```javascript
const http = require('http');
const url = require('url');
const isPrime = n => n>1 && [...Array(n-2).keys()].every(i => (n % (i+2)) !== 0);
http.createServer((req,res)=>{
  const q = url.parse(req.url,true).query; const n = +q.n; res.end(isPrime(n)?'Prime':'Not Prime');
}).listen(3007);
```
- Viva: Avoid heavy loops for large n; simple check is fine for small inputs.

Q6 HTTP Fibonacci nth
```javascript
const fib = n => { let a=0,b=1; for(let i=0;i<n;i++){ [a,b]=[b,a+b]; } return a; };
http.createServer((req,res)=>{ const n=+url.parse(req.url,true).query.n; res.end(String(fib(n))); }).listen(3008);
```
- Viva: Iterative approach O(n), constant space.

---

## Photo 7 — Solutions

Q1 HTTP Armstrong number
```javascript
const arm = n => { const s = String(n); return s.split('').reduce((a,d)=>a+Math.pow(+d, s.length),0) === +n; };
http.createServer((req,res)=>{ const n=+url.parse(req.url,true).query.n; res.end(arm(n)?'Armstrong':'No'); }).listen(3009);
```
- Viva: Armstrong checks sum of digits to power of length.

Q2 Parse URL to get filename
```javascript
http.createServer((req,res)=>{ const u=url.parse(req.url,true); res.end('File: ' + (u.query.file || 'none')); }).listen(3010);
```
- Viva: Use `url.parse` and `u.query`.

Q3 Socket.io: log student details + broadcast even visitor count
```javascript
let count = 0; io.on('connection',(socket)=>{ count++; console.log('Student connected', socket.id); if(count%2===0) io.emit('visitors', count); });
```
- Viva: Maintain server-side count; emit when even.

Q4 Socket.io: emit even numbers every 2s, goodbye on disconnect
```javascript
io.on('connection',(socket)=>{
  let i=2; const t=setInterval(()=>{ socket.emit('even', i); i+=2; }, 2000);
  socket.on('disconnect',()=>{ clearInterval(t); console.log('Thank you'); });
});
```
- Viva: Cleanup intervals on disconnect.

Q5 MongoDB Employee collection
```javascript
const Employee = mongoose.model('Employee', new mongoose.Schema({ empid:Number, name:String, dept:String, city:String, salary:Number }));
await Employee.insertMany([{empid:1,name:'A',dept:'IT',city:'Pune',salary:60000}, {empid:2,name:'B',dept:'HR',city:'Delhi',salary:45000}]);
const rich = await Employee.find({ salary: { $gt: 50000 } }); console.log(rich);
```
- Viva: `$gt` filter; `insertMany` bulk insert.

Q6 Readable stream student.txt to client
```javascript
app.get('/student', (req,res)=>{ res.setHeader('Content-Type','text/plain'); fs.createReadStream('student.txt').pipe(res); });
```
- Viva: Streams are efficient for large files.

---

## Photo 8 — Solutions

Q1 Form validations: username, password & confirm
```html
<form onsubmit="return validate()">
  <input id="user" placeholder="username">
  <input id="pass" type="password" placeholder="password">
  <input id="conf" type="password" placeholder="confirm">
  <button>Submit</button>
</form>
<script>
function validate(){
  const u=user.value, p=pass.value, c=conf.value; const err=[];
  if(u.length<6) err.push('Username min 6');
  if(p.length<5 || !/[0-9]/.test(p) || !/[!@#$%^&*]/.test(p)) err.push('Weak password');
  if(p!==c) err.push('Password & Confirm Password does not match');
  if(err.length){ alert(err.join('\n')); return false; } return true;
}
</script>
```
- Viva: Client-side checks improve UX; server must revalidate.

Q1(B) Node events implementation
```javascript
const EventEmitter = require('events'); const em = new EventEmitter(); em.on('login', u=>console.log(u,'logged in')); em.emit('login','alice');
```
- Viva: `on` to listen; `emit` to trigger.

Q2 Phone and password validations
```javascript
function validate(){ const phone=pn.value, p=pw.value; const e=[]; if(!/^\d{10}$/.test(phone)) e.push('Phone must be 10 digits'); if(p.length<8||!/\d/.test(p)||!/[^\w]/.test(p)||!/[A-Z]/.test(p)) e.push('Weak password'); if(e.length){ alert(e.join('\n')); return false;} return true; }
```
- Viva: Regex ensures exact digits; complexity rules for password.

Q2(B) Node event listeners
```javascript
em.once('ready', ()=>console.log('ready once')); em.emit('ready'); em.emit('ready');
```
- Viva: `once` fires only once.

Q3 DateTime & Reset buttons; read file demo
```html
<input id="t"><button onclick="t.value=new Date().toString()">DateTime</button><button onclick="t.value=''">Reset</button>
```
```javascript
const fs=require('fs'); const c=fs.readFileSync('demo.txt','utf-8'); if(!c) console.log('File is empty'); else console.log(c);
```
- Viva: `readFileSync` simple; handle empty content.

Q4 Image hover enlarge + button popup; zlib compress/decompress
```html
<img id="img" src="cat.png" style="width:150px;transition:.2s"> <button onclick="alert('Task completed')">Done</button>
<style>#img:hover{ transform: scale(1.2); }</style>
```
```javascript
fs.createReadStream('f.bin').pipe(zlib.createGzip()).pipe(fs.createWriteStream('f.bin.gz'));
fs.createReadStream('f.bin.gz').pipe(zlib.createGunzip()).pipe(fs.createWriteStream('f.out.bin'));
```
- Viva: CSS transform scales; gzip/gunzip pair.

Q5 Five mouse events
```html
<div id="box" style="width:100px;height:100px;background:#ddd"></div>
<script>
box.addEventListener('click',()=>console.log('click'));
box.addEventListener('dblclick',()=>console.log('dblclick'));
box.addEventListener('mouseenter',()=>console.log('enter'));
box.addEventListener('mouseleave',()=>console.log('leave'));
box.addEventListener('contextmenu',e=>{e.preventDefault();console.log('right-click');});
</script>
```
- Viva: Prevent default to block context menu.

Q5(B) Connect to local MongoDB and insert 5 documents
```javascript
await mongoose.connect('mongodb://localhost:27017/testdb');
const Coll = mongoose.model('Item', new mongoose.Schema({ name:String }));
await Coll.insertMany([{name:'a'},{name:'b'},{name:'c'},{name:'d'},{name:'e'}]);
```
- Viva: Ensure MongoDB is running; use `insertMany`.

Q6 Dropdown colors change background
```html
<select onchange="document.body.style.background=this.value">
  <option value="red">red</option>
  <option value="green">green</option>
  <option value="blue">blue</option>
</select>
<script>document.querySelector('select').addEventListener('change', function(){ alert('Selected: '+this.value); });</script>
```
- Viva: `onchange` event; modify `style.background`.

---

## Photo 9 — Solutions

Q1 Express: sendFile student info
```javascript
fs.writeFileSync('student.txt','Reg:2, Name:Bob, Grade:B');
app.get('/file', (req,res)=> res.sendFile(path.join(__dirname,'student.txt')));
```
- Viva: `sendFile` requires absolute path.

Q2 Cookies show/clear
```javascript
app.get('/show', (r,s)=> s.json(r.cookies));
app.get('/reset', (r,s)=>{ s.clearCookie('role'); s.send('reset'); });
```
- Viva: Use cookie-parser.

Q3 Express-validator fields
```javascript
app.post('/validate', body('name').notEmpty(), body('reg').isLength({min:3}), (req,res)=>{ const err=validationResult(req); if(!err.isEmpty()) return res.status(400).json(err.array()); res.json({ok:true}); });
```
- Viva: Chain validators per field.

Q4 HTTP prime + Fibonacci similar to Photo 6.

Q5 Armstrong and URL parsing similar to Photo 7.

---

## Photo 10 — Solutions

Q1 Socket.io student details + even visitor count (repeat)
```javascript
let count=0; io.on('connection', s=>{ count++; console.log('Student connected id=',s.id); if(count%2===0) io.emit('visitors',count); });
```

Q2 Socket.io even numbers and goodbye (repeat)
```javascript
io.on('connection', s=>{ let i=2; const t=setInterval(()=>s.emit('even',i),2000); s.on('disconnect',()=>{ clearInterval(t); console.log('Thank you'); }); });
```

Q3 MongoDB Employee CRUD (repeat)
```javascript
await Employee.insertMany([...]); const r=await Employee.find({ salary: { $gt: 50000 } });
```

Q4 Readable stream student.txt to client (repeat)
```javascript
app.get('/student', (r,s)=> fs.createReadStream('student.txt').pipe(s));
```

Q5 Writable stream primes up to 100
```javascript
const ws = fs.createWriteStream('primes.txt');
function isPrime(n){ if(n<2) return false; for(let i=2;i*i<=n;i++){ if(n%i===0) return false; } return true; }
for(let n=2;n<=100;n++){ if(isPrime(n)) ws.write(n+'\n'); }
ws.on('finish', ()=> console.log('Task Completed')); ws.end();
```
- Viva: Writable streams buffer writes; always `end()`.

---

## Photo 11 — Solutions

- Express app: accept number, compute increment/decrement/square in middleware, respond to click.
- Create `student.txt`, serve via `sendFile()` on button click.
- Cookies: set/show/clear via `cookie-parser`.
- Validations: `express-validator` chain, show warnings.
- HTTP module: prime check, Fibonacci nth — see Photo 6 code.

---

## Photo 12 — Solutions

- Armstrong number via HTTP server — see Photo 7.
- Parse URL query for filename; return filename — see Photo 7.
- Socket.io: log student details, broadcast even visitor count — see Photo 7.
- Socket.io: emit even numbers every 2s, thank you on disconnect — see Photo 7.
- MongoDB Employees: create DB/collection, insert many, query `$gt` salary — see Photo 7.
- Readable stream `student.txt` to client — see Photo 7.

---

## Photo 13 — Solutions

- Form validations for username/password/confirm with alerts — see Photo 8 Q1.
- Node events demo — `EventEmitter` listen/emit — see Photo 8 Q1(B).
- Phone/password validation — see Photo 8 Q2.
- Node event listeners (`once`) — see Photo 8 Q2(B).
- DateTime/Reset buttons and file empty/read — see Photo 8 Q3.
- Image hover enlarge + Zlib compress/decompress — see Photo 8 Q4.
- Five mouse events — see Photo 8 Q5.
- MongoDB insert 5 docs — see Photo 8 Q5(B).
- Dropdown colors alert and change background — see Photo 8 Q6.

---

## Photo 14 — Solutions

- Express middleware arithmetic ops — see Photo 6 Q2.
- `sendFile()` student info — see Photo 9 Q1.
- Cookies set/show/clear — see Photo 6 Q3.
- `express-validator` chain — see Photo 6 Q4.
- HTTP prime and Fibonacci — see Photo 6 Q5/Q6.

---

## Photo 15 — Solutions

- Armstrong and URL parsing — see Photo 7 Q1/Q2.
- Socket.io even visitor count — see Photo 7 Q3.
- Socket.io even numbers and disconnect message — see Photo 7 Q4.
- MongoDB Employees — see Photo 7 Q5.
- Readable stream to client — see Photo 7 Q6.

---

## Photo 16 — Solutions

- SocketChan/Server: display user details on server; thank-you message to client on termination — same as Photo 7 patterns.
- MongoDB Students: collection fields (Sid, Name, Subject, Branch, Mark), insert many, sort by marks and display — use `find().sort({ mark: 1 })`.
- Writable stream: primes up to 100 into file; log "Task Completed" — see Photo 10 Q5.

---

## Photo 17 — Solutions

- Create new directory — see Photo 5 Q1.
- Form echo via HTTP — see Photo 5 Q2.
- Paragraph hover style change — see Photo 5 Q3.
- Express downloads endpoint — see Photo 5 Q4.
- Express middleware demo; readable stream — see Photo 5 Q5.
- Socket.io wow server periodic stop/resume — see Photo 5 Q6.
- JS event handling basic demo — see Photo 5 Q7.
- Links with support chat message — see Photo 5 Q8.
- EventEmitter write and rename file — see Photo 5 Q9.

---

## Photo 18 — Solutions

- Express: create text file, add student info, `download()` — see Photo 6 Q1.
- Arithmetic ops middleware — see Photo 6 Q2.
- Cookies set/show/clear — see Photo 6 Q3.
- Express-validator chain — see Photo 6 Q4.
- HTTP prime — see Photo 6 Q5.
- HTTP Fibonacci — see Photo 6 Q6.

---

## Photo 19 — Solutions

- Armstrong number HTTP server — see Photo 7 Q1.
- Parse URL filename from query — see Photo 7 Q2.
- Socket.io: log student details; broadcast even visitor count — see Photo 7 Q3.
- Socket.io: emit even numbers; "Thank you" on disconnect — see Photo 7 Q4.
- MongoDB Employees — see Photo 7 Q5.
- Readable stream — see Photo 7 Q6.

---

## Photo 20 — Solutions

- Username/password/confirm validations — see Photo 8 Q1.
- Node events demo — see Photo 8 Q1(B).
- Phone/password validations — see Photo 8 Q2.
- Event listeners — see Photo 8 Q2(B).
- DateTime/Reset and file empty/read — see Photo 8 Q3.
- Image hover enlarge and zlib compress/decompress — see Photo 8 Q4.
- Mouse events demo — see Photo 8 Q5.
- MongoDB insert 5 docs — see Photo 8 Q5(B).
- Dropdown colors change — see Photo 8 Q6.

