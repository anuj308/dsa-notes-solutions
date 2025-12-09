const fs = require("fs");

// const userdata = {
//     name:"Parveen",
//     class:"K23PA",
//     rollno:12,
//     country:"India"
// }
//  fs.writeFile("data.json", JSON.stringify(userdata,null, 2),(err)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log("data added to file");
// });

// fs.readFile("data.json", "utf-8", (err, data)=>{
//     if(err){
//         console.log(err);
//     }
//     const users = JSON.parse(data);
//     console.log(users.name);
// });

fs.readFile("data.json", "utf-8", (err, data)=>{
    if(err){
        console.log(err);
    }
    let users = JSON.parse(data);
    users.push({name:"Pavnoor", rollno:15});
    fs.writeFile("data.json",JSON.stringify(users,null,2), (err)=>{
        if(err){
            throw err;
        }
        console.log("user added successfully");
    });
     console.log(users);
});



// fs.readFile('data.json', 'utf8', (err, data) => {
//   if (err) throw err;
//   let users = JSON.parse(data);

//   users.push({ name: 'New User', class:"K23PA", rollno: 30, country:"India" });

//   fs.writeFile('data.json', JSON.stringify(users, null, 2), (err) => {
//     if (err) throw err;
//     console.log('User added successfully!');
//   });
// });