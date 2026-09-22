// fetch("https://jsonplaceholder.typicode.com/users")
// .then((response)=>{
//     return response.json()
// }).then((data)=>{
//     console.log(data);
// }).catch((error)=>{
//     console.log(error)
// })

// async function getUsers(){
//   const response = await fetch("https://jsonplaceholder.typicode.com/users")
//   const data = await response.json();
//   console.log(data);
// }
// getUsers();

// fetch("https://jsonplaceholder.typicode.com/users",{

//     method: "POST",
//     headers:{
//         "content-type" : "application/json",
//     },

//     body: JSON.stringify({
//         id:11,
//         name: "Shubham",
//         username: "shub123"
//     })
// }).then(response => response.json())
// .then(data => console.log(data))
// .catch(error => console.log(error));

// async function createUser(){

//     const response = await fetch("https://jsonplaceholder.typicode.com/users",{
//     method: "POST",
//         headers:{
//             "content-type" : "application/json",
//         },

//         body: JSON.stringify({
//             id:11,
//             name: "Shubham",
//             username: "shub123"
//         })
//     })
//     const data = await response.json();
//     console.log(data);
    
// }

// createUser();


// async function getUsers(){
//   try{
//     const response = await fetch("https://jsonplaceholder.typicode.com/users")
  
//     if(!response.ok){
//         throw new error("user api failed to fetch data");
//     }
//     const data = await response.json();
//     console.log(data);
//   }catch(error){
//     console.log(error.message);
//   }
// }
// getUsers();



async function getUsers(){
  const response = await fetch("https://jsonplaceholder.typicode.com/users")
  const data = await response.json();
  
  let userList = document.getElementById("userList");
  data.forEach(users => {
    userList.innerHTML += `<li>${users.name} - ${users.email}</li>`;
  });
 
}

getUsers();