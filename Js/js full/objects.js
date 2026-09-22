//key value ka pair hota h or  {} create hota h 

//Syntax 
// let objName = {
//     key1: value1,
//     key2: value2,
// }

// let user = {
//     name: "shubham",
//     "channel name": "heavy coding",
//     age: 30,
//     country: "India"
// }

//dot notation
// console.log(user);
// console.log(typeof user);
// console.log(user.name);
// console.log(user.age);
// console.log(user.country);
//bracket notation
//console.log(user['channel name']);

// let student = {
//     name: "shubham",
//     greetings: function () {
//         console.log("Hello ", this.name);
//     }
// }

//this keywords
///student.age = 21; // add
//Object.freeze(student);   //iske baad kuch perform nhi hoga
// Object.seal(student); //isme sirf update hoga
// student.age = 25; // update 
// student.city = "Delhi";
// delete student.age; // delete
// console.log(student);

//student.greetings();

// nested object
let employee = {
    empID: 101,
    empName: "Shubham",
    address: {
        state: "Delhi",
        city: "New Delhi",
        pincode: 110098
    }
}
//console.log(employee.empID);
//console.log(employee.address.city);

// array of object
// array as an object
// let users = [
//     {
//         name: "shubham",
//         age: "20"
//     },
//     {
//         name: "mukesh",
//         age: "40"
//     }
// ];

// console.log(users[0].name);
// console.log(users[1].age);



let user = {
    name: "shubham",
    "channel name": "heavy coding",
    age: 30,
    country: "India"
}

console.log(Object.keys(user));
console.log(Object.values(user));
console.log(Object.entries(user));

// for (let key in user) {
//     console.log(key, ':', user[key])
// }

//api data sample
let apiResponse = {
    success: true,
    message: "data fetched successfully",
    data: {
        id: 101,
        name: "shubham"
    }
}