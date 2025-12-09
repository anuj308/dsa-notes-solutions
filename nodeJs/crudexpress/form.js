import express from 'express';
import {body, validationResult} from "express-validator"
import {promises as fs} from 'fs';


const ex = express();
ex.use(express.urlencoded({extended:true}));
ex.use(express.json());

async function readusers(){
    try{
        const data = await fs.readFile("data/user.json","utf-8");
        return JSON.parse(data);
    }
    catch(err){
        return [];
    }
}


async function writeusers(users){
    fs.writeFile("data/user.json",JSON.stringify(users, null, 2));

}

function nextId(users){
    return users.length ? Math.max(...users.map(u => u.id)) + 1 : 1; 
} 

ex.get("/userdetails", async(req,res)=>{
    const users = await readusers();
    if(users.length===0){
        res.send(`
        <h3>No user found</h3>
        <p><a href="/adduser">Add User</a></p>
        `);
    }

     const rows = users.map( u=> `<tr>
            <td>${u.id}</td>
            <td>${u.name}</td>
            <td>${u.email}</td>
            <td><button><a href="/user/${u.id}">Details</a></button></td>
            <td><button><a href="/edit/${u.id}">Edit</a></button></td>
            <td><form action="/delete/${u.id}" method="post" onsubmit="return confirm('Delete user?')">
                <button type="submit">Delete</button> 
            </form></td>
        </tr>
    `).join("");
    res.send(`<table border="1" cellpadding="6">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
            <th colspan="3">Action</th>
        </tr>
        <tr>
            ${rows}
        </tr>
        </table>
        <p><a href="/adduser">Add new user</a></p>
        `)
});
ex.get("/adduser",(req, res)=>{
    res.sendFile("form.html",{root:"public"});
  
})


ex.post("/submit",[
    body("name")
    .trim()
    .notEmpty().withMessage("Username is required")
    .isLength({min:3}).withMessage("Minimum 3 characters required for username"),

    body("email")
    .notEmpty().withMessage("Email is required")
    .isEmail().withMessage("@ and .com is required in email")
    .normalizeEmail(),
        
    ],async (req, res)=>{

        const errors = validationResult(req);
        if(!errors.isEmpty()){
            const list = errors.array().map( e=> `<li>${e.msg}</li>`).join("");
            res.status(400).send(`
                <h2>Validation Error</h2>
                <ul>${list}</ul>
                <p><a href="/adduser">BACK</a></p>

            `);
        }

        // console.log(req.body);
        const { name, email}=req.body;

        const users = await readusers();

        const user ={ id:nextId(users),name, email};

       
        users.push(user);
        await writeusers(users);



    
        res.send(`<h2>Data added </h2>
                <p>ID is :${user.id} </p>
                <p>Username is : ${user.name}</p>
                <p>Email is : ${user.email}</p>
                <p><a href="/userdetails">See Users Details</a></p>
        `)

        res.json({
            message:"Data added",
            Added_data:{name, email}
        });
});

ex.get("/user/:id", async(req, res)=>{
    const id = req.params.id;
    const users = await readusers();
   const user= users.find((u)=>u.id==id);
   res.send(`
            <h2>User Details</h2>
            <p>UserId is : ${user.id}</p>
            <p>Username is : ${user.name}</p>
            <p>Useremail is : ${user.email}</p>
            <p><a href="/userdetails">Back to Users</a></p>`)

});

ex.get("/edit/:id", async (req,res)=>{
    const id = Number(req.params.id); 
    const users = await readusers();
    const user = users.find((u)=>u.id==id);
    res.send( `
        <h2>Edit User</h2> 
        <form action="/update/${user.id}" "_method=PUT" method="post"> 
            <label>Username:</label><br> 
            <input type="text" name="name" value="${user.name}" required><br><br> 
            <label>Email:</label><br> <input type="email" name="email" value="${user.email}" required><br><br> 
            <button type="submit">Update User</button> 
        </form>
        <p><a href="/userdetails">Cancel</a></p> `
    ); 
});

ex.post("/update/:id", async(req, res)=>{
    const id = Number(req.params.id); 
    const { name, email } = req.body; 
    const users = await readusers(); 
    const idx = users.findIndex((u) => u.id === id); 

    users[idx] = { ...users[idx],name, email }; 
    await writeusers(users); 
    res.send( `<h2> User Updated Successfully</h2>
               <p><a href="/userdetails">Back to User List</a></p> 
    `); 

});

ex.post("/delete/:id",async(req,res)=>{
    const id = Number(req.params.id); 
    let users = await readusers(); 
    users = users.filter((u) => u.id !== id); 
    await writeusers(users); 
    res.send( `<h2>User Deleted Successfully</h2>
     <p><a href="/userdetails">Back to User List</a></p> 
    `); 
})

ex.listen(3000);