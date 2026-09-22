// Array / Object Destructuring
// Rest Operators
// Spread Operators
 
// const colors = ["Red","Yellow","Green"];

// // const first = colors[0];
// // const second = colors[1];
// // const third = colors[2];
// // console.log(second);

// const [first,second,third] = colors;
// console.log(third);


// const numbers = [10];

// const [a,b=20]= numbers;

// console.log(a)
// console.log(b)

// const user = {
//     name:"Shubham",
//     age:20,
// }

// const user = {
//     name:"Shubham"
// }
//const {name,age} = user;
//const {name:userName,age} = user;
// const name = user.name;
// const age = user.age;
// const {name,city="Delhi"} = user;
// console.log(city)

 
// const numbers = [10,20,30,40,50];

// const [first,...others] = numbers;

// console.log(first);
// console.log(others);

// const user = {
//     name:"Shubham",
//     age:"20",
//     city:"Delhi",
//     gender:"M"
// }

// const {name,...details} = user;
// console.log(name);
//   console.log(details);


// const arr1 = [1,2,3];

// const arr2 = [...arr1];
// console.log(arr2);

// const frontend = ["HTML","CSS"];
// const backend = ["PHP","JS","Java"];

// const fullstack = [...frontend,...backend];

// console.log(fullstack);

// const basic = {
//     name:"Shubham",
// }

// const address = {
//     city:"Delhi"
// }

// const user = {...basic,...address};

// console.log(user);


// function student(name,age,...others){
//     console.log(name);
//     console.log(age);
//     console.log(others);
// }

// student("shubham",20,"HTML","CSS","PHP");

function sum(a,b,c){
    console.log(a+b+c)
}
const numbers = [10,20,30];
sum(...numbers)