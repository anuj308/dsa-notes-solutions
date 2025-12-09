
import express from "express";
// import { nanoid } from "nanoid"; // small id generator (optional)

const app = express();
app.use(express.json());            // MUST be before routes

// In-memory "database"
let users = [
  { id: "1", name: "Alice", email: "alice@example.com" },
  { id: "2", name: "Bob",   email: "bob@example.com" }
];

// GET all
app.get("/users", (req, res) => {
  res.json(users);
});

// GET by id
app.get("/users/:id", (req, res) => {
  const u = users.find(x => x.id === req.params.id);
  if (!u) return res.status(404).json({ error: "User not found" });
  res.json(u);
});

// CREATE
app.post("/users", (req, res) => {
  const { name, email } = req.body || {};
  if (!name || !email) return res.status(400).json({ error: "name and email required" });
  // const id = nanoid ? nanoid(8) : String(Date.now());
  const newUser = { name, email };
  users.push(newUser);
  res.status(201).json(newUser);
});

// UPDATE (replace or partial)
app.put("/users/:id", (req, res) => {
  const { name, email } = req.body || {};
  const idx = users.findIndex(x => x.id === req.params.id);
  if (idx === -1) return res.status(404).json({ error: "User not found" });
  users[idx] = { ...users[idx], ...(name !== undefined ? {name} : {}), ...(email !== undefined ? {email} : {}) };
  res.json(users[idx]);
});

// DELETE
app.delete("/users/:id", (req, res) => {
  const idx = users.findIndex(x => x.id === req.params.id);
  if (idx === -1) return res.status(404).json({ error: "User not found" });
  const removed = users.splice(idx, 1)[0];
  res.json({ message: "Deleted", deleted: removed });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Server listening on http://localhost:${PORT}`));
