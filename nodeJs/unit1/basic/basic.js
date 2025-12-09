// function a(){
//     console.log("Hello");
// }
// a();

// function add(a,b)
// {
//     return a+b;
// }
// console.log(add(4,5));

// for(let i=10;i>=1;i--){
//     console.log(2 * i )
// }

// const students = ["std1","std2","std3"]
// console.log(students);
// ((num1,num2)=>(console.log(num1+num2)))(2,3);
// students.push("std5");
// // for(let i=0;i<students.length;i++){
// //     console.log(students[i])
// // }
// console.log(" ")
// students.unshift("std6");
// // for(let i=0;i<students.length;i++){
// //     console.log(students[i])
// // }

// // console.log(" ")
// students.shift();
// // for(let i=0;i<students.length;i++){
// //     console.log(students[i])
// // }

// console.log(" ")
// students.pop();
// // for(let i=0;i<students.length;i++){
// //     console.log(students[i])
// // }

// let arr = [1,2,3];

// arr.splice(1,1);
// // console.log(arr);


// const data =
// {
//     name:"Komal",
//     1:20,
//     course:"Btech CSE"
// };

// // console.log(data.name);
// // console.log(data.course);
// data.name="Amar";
// // console.log(data);
// delete data.age;

// // console.log(data);
// data.city="jalandhar";
// // console.log(data);
// // console.log(data['city']);
// // console.log(data.city);
// // console.log(data['1']);
// // console.log(data.1);



let arr = [1,34,67,23,90];
// arr.forEach( function(arr){
//     console.log(arr);
// });
for(let i of arr){
    console.log(i+" index");
    console.log(arr[i]);
}
