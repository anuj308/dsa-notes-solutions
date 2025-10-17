// const a = 1
// // a = 2 not possiable
// let b = 2
// b = 3
// console.log(b)

// let c = 'a'
// let d = 22
// let e = "ddd"
// let f = true
// let g;
// let h = 677777n
// let s = Symbol('fnudnfid')
// console.log(typeof(c))
// console.log(typeof(d))
// console.log(typeof(e))
// console.log(typeof(f))
// console.log(typeof(g))
// console.log(typeof(h))
// console.log(typeof(s))

// function add(a,b){
//     console.log(a+b)
// }
// add(2,3)

// const addd = (a,b)=>{
//     console.log(a+b)
// }
// add(2,3)

// let arr = [2,3]
// for(let i=0;i<arr.length;i++){
//     console.log(arr[i])
// }
// arr.forEach( e => console.log(e))
// for(let i in arr) console.log(i,arr[i])
    
// // arr.unshift(2)

// // shift
// arr.push(3)
// arr.pop()
// for(let i=0;i<2;i++){
//     console.log(arr[i])
// }

// const o = {
//     age:23,
//     name:'aks'
// }
// o.age=20
// console.log(o)

//  14 october 2025

// const name;
// console.log(name)
// let a;

// function b(){
//     const name = "anuj";
//     let a;
    
// }

// function aa(){
//     for(var i=1;i<=10;i++){
//         console.log(10 + '*' + i + '=' + 10*i);
//     }
// }
// aa()
// for(i=1;i<=10;i++){
//     console.log(10 + '*' + i + '=' + 10*i);
// }

// const add = (a,b) => a+b
// console.log(add(2,3))

// const arr = [1,3,4];
// const even =[2,4,6];

// const m = arr.concat(even);
// console.log(m)

// // check if all elements pass a conditions
// console.log(arr.every(i => i%2==0)) // false
// console.log(even.every(i => i%2==0)) // true

// //  foreach run for every element no return
// arr.forEach(e => {
//     console.log(e%2==0)
// });

// // filter() return elements that match a condition
// const res = arr.filter(i => i%2===0)
// console.log(res);

// //  index of
// console.log(arr.indexOf(3))
// console.log(arr.indexOf(10))

// //  array.form() -> create an array from iterable or string
// const str = 'aks'
// console.log(Array.from(str))

// //  map() -> transform element and returns a new array
// const narr = arr.map((w)=> w*2)
// console.log(narr);

// reduce() -> reduce array to single value

// question - sum of square of even number
// arr = [1,2,3,4,5,6,7,8]
// arr = arr.filter((e)=> e%2==0)
// console.log(arr)
// arr = arr.map((e)=> e*e)
// console.log(arr)
// const ans = arr.reduce((acc,cur)=> acc+cur)
// console.log(ans)

// const num1 = [10,25,45,60,70]
// const search = 45
// console.log(num1.indexOf(45))

// console.log(num1.every((e) => e>=0))

// for(let i=0;i<num1.length;i++){
//     if(num1[i]>25){
//         console.log(num1[i]);
//         break;
//     }
// }

// const students = [
//     {name:'aks',mark:98},
//     {name:'mks',mark:75},
//     {name:'ms',mark:65},
//     {name:'ps',mark:55},
//     {name:'rs',mark:45},
// ]
// // filter out student score less than 45
// const a1 = students.filter((s)=> s.mark<45)
// console.log(a1)
// // cal avg marks of the original array
// const a2 = students.reduce((acc,cur)=> acc+(cur.mark/students.length),0)
// console.log(a2)
// // check if all student pass (marks>=50)
// console.log(students.every((st)=> st.mark>=50))

//  destructuring is for array and object

const number = [10,20,30,40]
const [a,,,b,c=100] = number
console.log(a,b,c)

// rename
const person = {name:'aks',age:19,country:'India'}
const {name:n,age:ag} = person
console.log(n,ag)

// spread operator
const arr1 = [1,2,3]
const arr2 = [4,5,6]
const merge = [...arr1, ...arr2]
console.log(merge)

// rest operator
function sum(...nums){
    return nums.reduce((acc,cur)=> acc+cur)
}
console.log(sum(1,2,3,4))

const [first, ...rest] = [10,20,30,40];
console.log(first)
console.log(rest)

import printName from "./functions.mjs"
printName();