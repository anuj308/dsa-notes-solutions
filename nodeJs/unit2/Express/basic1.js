import express from "express";
const app =express();
app.get("/",(req,res)=>{
    // res.write("This is the first line");
    //  res.end("hello")
    res.send("hello");
});

//can redirect, will show redirect 
app.get("/about",(req,res)=>{
    res.redirect(200, "/user");

});

//can redirect, add upon the redirect page 
app.get("/home",(req,res)=>{
  res.redirect("/user");

});

app.get("/user",(req, res)=>{
    res.send("Data is coming from userpage here 123");
})

// create dynamic route
app.get("/user/:id/:name", (req, res)=>{
    // const id = req.params.id;
    // const name = req.params.name;
    const {id,name} = req.params;
    res.send(`welcome ${name} having id: ${id}`);
})

// b is optional here 0 or 1 (?)
app.get(/ab?cd/, (req, res) => {
    res.send("Matched /acd or /abcd");
  });
  
//   One or more (+)
  app.get(/ab*cd/, (req, res) => {
    res.send("Matched /abcd, /abbcd, /abbbcd, etc.");
  });
  
//   Zero or more (*)
  app.get(/^\/ab.*cd$/, (req, res) => {
    res.send("Matched /abcd, /abxcd, /abSOMETHINGcd");
  });
  
  //  Optional group (())
  app.get(/ab(cd)?e/, (req, res) => {
    res.send("Matched /abe or /abcde");
  });
  
  //  Regular expression route start with a
  app.get(/^\/a/, (req, res) => {
    res.send("Matched any route containing 'a' (like /apple or /ant)");
  });

//Regular expression in between  a
  app.get(/^.*a.*$/, (req, res) => {
    res.send("Matched any route containing 'a' (e.g. /apple, /cat, /data)");
  });
  
  //  Regex with start & end anchors
  app.get(/^\/[0-9]+$/, (req, res) => {
    const id = req.params[0];
    res.send(`Matched /users/ followed by numbers only, e.g. /users/123  passed id is ${id}`);
  });
  
  // Wildcard route (catch-all)
  app.get(/.*/, (req, res) => {
    res.send("This matches everything else — acts as a 404 or fallback");
  });
  
//   app.listen(3500, () => console.log("Server running on port 3500"));

app.get("/search",(req,res)=>{
    const keyword = req.query.keyword; 
    res.send(`Searching for ${keyword}`); 
});


app.listen(3000);