import express from "express";
import pool from "./psimport.js";

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

/* ======================
   CREATE STUDENT
====================== */

app.get("/", (req, res) => res.json({ status: "ok" }));

const createTable = async () => {
    try {
      await pool.query(`
        CREATE TABLE IF NOT EXISTS records(
          id SERIAL PRIMARY KEY,
          name VARCHAR(100),
          age INT,
          course VARCHAR(100)
        )
      `);
      console.log("records table ready");
    } catch (err) {
      console.error("Error creating table:", err.message);
    }
  };
  
  
app.post("/records", async (req, res) => {
  try {
    const { name, age, course } = req.body;

    const result = await pool.query(
      "INSERT INTO records (name, age, course) VALUES ($1, $2, $3) RETURNING *",
      [name, age, course]
    );

    res.status(201).json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

/* ======================
   READ ALL STUDENTS
====================== */
app.get("/records", async (req, res) => {
  try {
    const result = await pool.query("SELECT * FROM records ORDER BY id");
    res.json(result.rows);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

/* ======================
   READ SINGLE STUDENT
====================== */
app.get("/records/:id", async (req, res) => {
  try {
    const { id } = req.params;

    const result = await pool.query(
      "SELECT * FROM records WHERE id=$1",
      [id]
    );

    if (result.rows.length === 0) {
      return res.status(404).json({ message: "Student not found" });
    }

    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

/* ======================
   UPDATE STUDENT
====================== */
app.put("/records/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const { name, age, course } = req.body;

    const result = await pool.query(
      "UPDATE records SET name=$1, age=$2, course=$3 WHERE id=$4 RETURNING *",
      [name, age, course, id]
    );

    if (result.rows.length === 0) {
      return res.status(404).json({ message: "Student not found" });
    }

    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

/* ======================
   DELETE STUDENT
====================== */
app.delete("/records/:id", async (req, res) => {
  try {
    const { id } = req.params;

    const result = await pool.query(
      "DELETE FROM records WHERE id=$1 RETURNING *",
      [id]
    );

    if (result.rows.length === 0) {
      return res.status(404).json({ message: "Student not found" });
    }

    res.json({ message: "Student deleted successfully" });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(PORT, async() => {
  console.log(`Server running on http://localhost:${PORT}`);
  await createTable();
});
