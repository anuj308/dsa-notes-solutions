import express from 'express';
import url from 'url';
import path from 'path';
const app = express();
app.get("/",(req,res)=>{
    // res.write("Hello");
    // res.end();
    // res.send("hello");
    // res.json("Hello");
    res.redirect(200,"/home");

});


// app.get(/abc/ab?c ,(req,res)=>{
//   // const enter = req.params;
//   // console.log(enter);
//   console.log(req.url);
//   // console.log(path);
//   res.send("hello");
// });


app.use(express.urlencoded({ extended: true })); // for form POSTs
app.use(express.json());      
app.get("/home",(req,res)=>{
    // res.set("Cache-Control", "no-store"); // disables caching
    res.send( `<h2>Data added successfully</h2>
    <p><strong>Username:</strong> ${name}</p>
    <p><strong>Email:</strong> ${email}</p>`);
});
app.get("/form", (req, res) => {
    res.sendFile("form.html", { root: "public" }, (err) => {
      if (err){

       res.status(404).send("File not found");
      }
    });
  });
  app.post("/submit", (req, res) => {
    
    const { name, email } = req.body; // get form data
    console.log("Received:", name, email);
    res.send(`
    <h2>Data added successfully</h2>
    <p><strong>Username:</strong> ${name}</p>
    <p><strong>Email:</strong> ${email}</p>
    <a href="/form">Go back</a>
  `);
});

app.put("/submit", (req, res) => {
    const { name, email } = req.body;
    res.json({
      message: "Data updated successfully",
      updatedData: { name, email },
    });
  });

  app.delete("/submit", (req, res) => {
    const { name, email } = req.body; // or use query parameters
    console.log("DELETE request received:", name, email);
    res.json({
      message: "Data deleted successfully",
      deletedData: { name, email },
    });
  });

  app.use((req, res) => res.status(404).send(`No route for ${req.method} ${req.url}`));


 app.listen(3000);