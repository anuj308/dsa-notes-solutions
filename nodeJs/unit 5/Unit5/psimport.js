import pkg from "pg";
const { Pool } = pkg;

const pool = new Pool({
  user: "rabaab",
  host: "localhost",
  database: "parveen",
  password: "rabaab",
  port: 5432,
});

export default pool;