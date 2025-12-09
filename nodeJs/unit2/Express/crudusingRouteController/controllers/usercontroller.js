import { readUsers, writeUsers, nextId } from "../utils/fileHelpers.js";
import { validationResult } from "express-validator";

export const userDetails = async (req, res) => {
    const users = await readUsers();
  
    if (users.length === 0) {
      return res.send(`<h3>No user Found</h3>
             <p><a href="/form">Add user </a></p> `);
    }
  
    const rows = users.map(u => `
      <tr>
          <td>${u.id}</td>
          <td>${u.name}</td>
          <td>${u.email}</td>
          <td><a href="/user/${u.id}"><button>Details</button></a></td>
          <td><a href="/edit/${u.id}"><button>Edit</button></a></td>
          <td>
            <form action="/delete/${u.id}" method="post" onsubmit="return confirm('Delete user?')">
              <button type="submit">Delete</button>
            </form>
          </td>
      </tr>`).join("");
  
    res.send(`
      <table border="1" cellpadding="6">
        <tr>
          <th>ID</th><th>Name</th><th>Email</th><th colspan="3">Action</th>
        </tr>
        ${rows}
      </table>
      <p><a href="/form">Add new user </a></p>
    `);
  };
  
  export const showForm = (req, res) => {
    res.sendFile("form.html", { root: "public" });
  };
  
  export const submitForm = async (req, res) => {
    const errors = validationResult(req);
  
    if (!errors.isEmpty()) {
      const list = errors.array().map(e => `<li>${e.msg}</li>`).join("");
      return res.status(400).send(`
        <h3>Validation Error</h3>
        <ul>${list}</ul>
        <p><a href="/form">BACK</a></p>`);
    }
  
    const { name, email } = req.body;
    const users = await readUsers();
    const user = { id: nextId(users), name, email };
  
    users.push(user);
    await writeUsers(users);
  
    res.send(`
      <h1>data added successfully</h1>
      <table border="1" cellpadding="6">
          <tr><th>Id</th><th>Name</th><th>Email</th></tr>
          <tr><td>${user.id}</td><td>${user.name}</td><td>${user.email}</td></tr>
      </table>
      <p><a href="/usersdetails">Go Back</a></p>
    `);
  };
  
  export const singleUser = async (req, res) => {
    const id = req.params.id;
    const users = await readUsers();
    const user = users.find(u => u.id == id);
  
    res.send(`
      User Details
      <p>User ID : ${user.id}</p>
      <p>Username : ${user.name}</p>
      <p>User Email : ${user.email}</p>
      <p><a href="/usersdetails">Back</a></p>
    `);
  };
  
  export const editUserForm = async (req, res) => {
    const id = Number(req.params.id);
    const users = await readUsers();
    const user = users.find(u => u.id === id);
  
    if (!user) {
      return res.status(404).send("<h3>User not found</h3><a href='/usersdetails'>Back</a>");
    }
  
    res.send(`
      <h2>Edit User</h2>
      <form action="/update/${user.id}" method="post">
        <label>Username:</label><br>
        <input type="text" name="name" value="${user.name}" required><br><br>
        <label>Email:</label><br>
        <input type="email" name="email" value="${user.email}" required><br><br>
        <button type="submit">Update User</button>
      </form>
      <p><a href="/usersdetails">Cancel</a></p>
    `);
  };
  
  export const updateUser = async (req, res) => {
    const id = Number(req.params.id);
    const { name, email } = req.body;
  
    const users = await readUsers();
    const idx = users.findIndex(u => u.id === id);
  
    if (idx === -1) {
      return res.status(404).send("<h3>User not found</h3><a href='/usersdetails'>Back</a>");
    }
  
    users[idx] = { ...users[idx], name, email };
    await writeUsers(users);
  
    res.send(`
      <h2>User Updated Successfully</h2>
      <p><a href="/usersdetails">Back to User List</a></p>
    `);
  };
  
  export const deleteUser = async (req, res) => {
    const id = Number(req.params.id);
    let users = await readUsers();
  
    const before = users.length;
    users = users.filter(u => u.id !== id);
  
    if (users.length === before) {
      return res.status(404).send("<h3>User not found</h3><a href='/usersdetails'>Back</a>");
    }
  
    await writeUsers(users);
  
    res.send(`
      <h2>User Deleted Successfully</h2>
      <p><a href="/usersdetails">Back to User List</a></p>
    `);
  };