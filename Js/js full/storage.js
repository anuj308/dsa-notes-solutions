
// localStorage.setItem("username","Shubham");
// localStorage.setItem("password","1234567");


// const user = localStorage.getItem("username");

// localStorage.clear();
//console.log(user);
//console.log(localStorage.getItem("password"));

//localStorage.removeItem("password")

//console.log(localStorage.getItem("password"));


// sessionStorage.setItem("token","abc123")

//sessionStorage.removeItem("token")



// sessionStorage.clear();

// console.log(sessionStorage.getItem("token"));

const user = {
    name:"heavycoding",
    platform:"Youtube"
}

localStorage.setItem("userDetails",JSON.stringify(user))
sessionStorage.setItem("userDetails",JSON.stringify(user))

const userData =  JSON.parse(localStorage.getItem("userDetails"));
const userData2 =  JSON.parse(sessionStorage.getItem("userDetails"));

console.log(userData);

console.log(userData2);