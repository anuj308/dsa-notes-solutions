// file: server.js
import express from "express";
import path from "path";
import { fileURLToPath } from "url";
import { promises as fs } from "fs";

const app = express();
const PORT = 3000;



// --- Middleware ---
app.use(express.urlencoded({ extended: true })); // for HTML form posts
app.use(express.json());                          // for JSON bodies (Thunder Client etc.)



async function readUser() {
  try {
    const txt = await fs.readFile("user.json", "utf-8");
    return JSON.parse(txt);
  } catch (e) {
    // not found or invalid -> treat as no data
    return null;
  }
}
async function writeUser(obj) {
  await fs.writeFile("user.json", JSON.stringify(obj, null, 2), "utf-8");
}
async function deleteUser() {
  try {
    await fs.unlink("user.json");
    return true;
  } catch {
    return false;
  }
}

// --- Routes ---

// Home → link to create/read
app.get("/", (req, res) => {
  res.send(`
    <h1>User Demo</h1>
    <p><a href="/form">Create user</a></p>
    <p><a href="/data">View saved data</a></p>
  `);
});

// CREATE (show form)
app.get("/form", (req, res) => {
  res.sendFile("form.html", {root:"public"} );
});

// CREATE (handle POST)
app.post("/submit", async (req, res) => {
  const { name, email } = req.body || {};
  if (!name || !email) {
    res.status(400).send("Name and email are required. <a href=\"/form\">Back</a>");
    return;
  }
  await writeUser({ name, email });
  // show success + link to view
//   res.send(`
//     <h2>Data added successfully</h2>
//     <p><strong>Name:</strong> ${name}</p>
//     <p><strong>Email:</strong> ${email}</p>
//     <p>
//       <a href="/data">View Data</a> |
//       <a href="/edit">Edit</a> |
//       <form action="/delete" method="post" style="display:inline">
//         <button type="submit">Delete</button>
//       </form>
//     </p>
//   `);
res.send(`
    <h2>Data added successfully</h2>
    <p>
      <a href="/data">View Data</a> |
      <a href="/edit">Edit</a> |
      <form action="/delete" method="post" style="display:inline">
        <button type="submit">Delete</button>
      </form>
    </p>
  `);
});

// READ
app.get("/data", async (req, res) => {
  const user = await readUser();
  if (!user) {
    res.send(`
      <h2>No data found</h2>
      <p><a href="/form">Create one</a></p>
    `);
    return;
  }
  res.send(`
    <h2>Saved Data</h2>
    <p><strong>Name:</strong> ${user.name}</p>
    <p><strong>Email:</strong> ${user.email}</p>
    <p>
      <a href="/edit">Edit</a> |
      <form action="/delete" method="post" style="display:inline">
        <button type="submit">Delete</button>
      </form> |
      <a href="/form">Add New (overwrite)</a>
    </p>
  `);
});

// UPDATE (show prefilled edit form)
app.get("/edit", async (req, res) => {
  const user = await readUser();
  if (!user) {
    res.redirect("/form");
    return;
  }
  res.send(`
    <h2>Edit User</h2>
    <form action="/update" method="post">
      <label>Name</label><br/>
      <input name="name" value="${user.name}" minlength="3" maxlength="50" required /><br/><br/>
      <label>Email</label><br/>
      <input name="email" type="email" value="${user.email}" required /><br/><br/>
      <button type="submit">Save</button>
    </form>
    <p><a href="/data">Back</a></p>
  `);
});

// UPDATE (handle POST)
app.post("/update", async (req, res) => {
  const { name, email } = req.body || {};
  if (!name || !email) {
    res.status(400).send("Name and email are required. <a href=\"/edit\">Back</a>");
    return;
  }
  await writeUser({ name, email });
  res.send(`
    <h2>Data updated successfully </h2>
    <p><strong>Name:</strong> ${name}</p>
    <p><strong>Email:</strong> ${email}</p>
    <p><a href="/data">View</a></p>
  `);
});

// DELETE (from browser via POST)
app.post("/delete", async (_req, res) => {
  const ok = await deleteUser();
  res.send(ok
    ? `<h2>Data deleted </h2><p><a href="/form">Create new</a></p>`
    : `<h2>Nothing to delete</h2><p><a href="/form">Create new</a></p>`
  );
});

// DELETE (real DELETE method for clients like Thunder/Postman)
app.delete("/data", async (_req, res) => {
  const ok = await deleteUser();
  res.json({ deleted: ok });
});

// 404 fallback
app.use((req, res) => res.status(404).send(` Route not found: ${req.method} ${req.url}`));

// Start server
app.listen(PORT, () => {
  console.log(` http://localhost:${PORT}`);
  console.log(`➡️  Create:  GET /form`);
  console.log(`➡️  Read:    GET /data`);
  console.log(`➡️  Update:  GET /edit  -> POST /update`);
  console.log(`➡️  Delete:  POST /delete (browser) or DELETE /data (API)`);
});
