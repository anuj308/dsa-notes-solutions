// crud1.js
import express from "express";
import { MongoClient, ObjectId } from "mongodb";
import dotenv from "dotenv";

dotenv.config();
const app = express();
app.use(express.json());
// app.use(express.static("public"));


// Configuration
const MONGO_URI = process.env.MONGO_URI || "mongodb://localhost:27017";
const DB_NAME = process.env.DB_NAME || "Parveen";
const PORT = process.env.PORT || 3000;

let usersCollection;
let mongoClient; // keep reference to client so we can close on shutdown

// Connect once at startup and reuse the connection
async function connectDB() {
  try {
    mongoClient = new MongoClient(MONGO_URI); // no useNewUrlParser/useUnifiedTopology
    await mongoClient.connect();
    const db = mongoClient.db(DB_NAME);
    usersCollection = db.collection("k23pb");
    console.log(`Connected to MongoDB: ${MONGO_URI} (DB: ${DB_NAME})`);
  } catch (err) {
    console.error("Failed to connect to MongoDB:", err);
    throw err;
  }
}
connectDB().catch(err => {
  // If connection fails, exit so nodemon shows the error and waits for changes
  process.exit(1);
});

// Helper
function isValidObjectId(id) {
  return ObjectId.isValid(id);
}

// Routes (same as before)

// Health
app.get("/", (req, res) => res.json({ status: "ok" }));

// CREATE
app.post("/users", async (req, res) => {
  try {
    const { name, email } = req.body || {};
    if (!name || !email) return res.status(400).json({ error: "name and email required" });

    const doc = { name: name.trim(), email: email.trim(), createdAt: new Date() };
    const result = await usersCollection.insertOne(doc);
    const inserted = await usersCollection.findOne({ _id: result.insertedId });
    res.status(201).json(inserted);
  } catch (err) {
    console.error("POST /users error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// READ all
app.get("/users", async (req, res) => {
  try {
    const users = await usersCollection.find().sort({ createdAt: -1 }).toArray();
    res.json(users);
  } catch (err) {
    console.error("GET /users error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// READ by id
app.get("/users/:id", async (req, res) => {
  try {
    const { id } = req.params;
    if (!isValidObjectId(id)) return res.status(400).json({ error: "Invalid id" });

    const user = await usersCollection.findOne({ _id: new ObjectId(id) });
    if (!user) return res.status(404).json({ error: "User not found" });
    res.json(user);
  } catch (err) {
    console.error("GET /users/:id error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// UPDATE (PUT)
app.put("/users/:id", async (req, res) => {
  try {
    const { id } = req.params;
    if (!isValidObjectId(id)) return res.status(400).json({ error: "Invalid id" });

    const { name, email } = req.body || {};
    if (name === undefined && email === undefined) {
      return res.status(400).json({ error: "Provide at least one field: name or email" });
    }

    const update = { $set: {} };
    if (name !== undefined) update.$set.name = name.trim();
    if (email !== undefined) update.$set.email = email.trim();
    update.$set.updatedAt = new Date();

    const result = await usersCollection.findOneAndUpdate(
      { _id: new ObjectId(id) },
      update,
      { returnDocument: "after" }
    );

    if (!result.value) return res.status(404).json({ error: "User not found" });
    res.json(result.value);
  } catch (err) {
    console.error("PUT /users/:id error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// PATCH (partial update)
app.patch("/users/:id", async (req, res) => {
  try {
    const { id } = req.params;
    if (!isValidObjectId(id)) return res.status(400).json({ error: "Invalid id" });

    const allowed = ["name", "email"];
    const set = {};
    for (const key of allowed) {
      if (req.body[key] !== undefined) {
        set[key] = typeof req.body[key] === "string" ? req.body[key].trim() : req.body[key];
      }
    }

    if (Object.keys(set).length === 0) return res.status(400).json({ error: "No updatable fields provided" });

    set.updatedAt = new Date();

    const result = await usersCollection.findOneAndUpdate(
      { _id: new ObjectId(id) },
      { $set: set },
      { returnDocument: "after" }
    );

    if (!result.value) return res.status(404).json({ error: "User not found" });
    res.json(result.value);
  } catch (err) {
    console.error("PATCH /users/:id error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// DELETE
app.delete("/users/:id", async (req, res) => {
  try {
    const { id } = req.params;
    if (!isValidObjectId(id)) return res.status(400).json({ error: "Invalid id" });

    const result = await usersCollection.deleteOne({ _id: new ObjectId(id) });
    if (result.deletedCount === 0) return res.status(404).json({ error: "User not found" });
    res.json({ success: true });
  } catch (err) {
    console.error("DELETE /users/:id error:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// Graceful shutdown to close Mongo client
process.on("SIGINT", async () => {
  console.log("Shutting down...");
  try {
    if (mongoClient) await mongoClient.close();
  } catch (e) { /* ignore */ }
  process.exit(0);
});

app.listen(PORT, () => console.log(`Server listening on http://localhost:${PORT}`));
