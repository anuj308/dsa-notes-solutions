import pkg from "pg";
const { Client } = pkg;

const client = new Client({
  user: "rabaab",
  host: "localhost",
  database: "parveen",
  password: "",
  port: 5432
});

async function connectDB() {
  try {
    await client.connect();
    console.log("Connected to PostgreSQL");
  } catch (err) {
    console.error("Connection error", err);
  }
}

connectDB();
