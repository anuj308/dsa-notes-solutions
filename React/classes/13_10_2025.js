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

// const number = [10,20,30,40]
// const [a,,,b,c=100] = number
// console.log(a,b,c)

// // rename
// const person = {name:'aks',age:19,country:'India'}
// const {name:n,age:ag} = person
// console.log(n,ag)

// // spread operator
// const arr1 = [1,2,3]
// const arr2 = [4,5,6]
// const merge = [...arr1, ...arr2]
// console.log(merge)

// // rest operator
// function sum(...nums){
//     return nums.reduce((acc,cur)=> acc+cur)
// }
// console.log(sum(1,2,3,4))

// const [first, ...rest] = [10,20,30,40];
// console.log(first)
// console.log(rest)



// Short answer: .mjs marks a file as an ES Module (ESM) for Node.js so the runtime knows to use import/export semantics instead of CommonJS require/module.exports.

// Why and when:

// Node historically used CommonJS (CJS) with require/module.exports. By default .js files were treated as CJS.
// .mjs explicitly signals “this file is an ES module” so Node parses it with import/export, top-level await, strict module scope, and static imports.
// Alternatively you can keep .js and set "type": "module" in package.json to treat .js as ESM project-wide.
// Use .cjs to force CommonJS in a package with "type": "module".
// Browsers don't need .mjs; they use <script type="module"> and file extension doesn't affect semantics there.
// Small examples:

// const [x,,y,,z=110,m] = [10,20,30,40]
// console.log(x,y,z,m)

// 1

// const colors = ["red","green","blue"];
// const [x,y] = colors;
// console.log(x,y)

// 2
// const person = {name:"Alice",age:25,city:"Delhi"}
// const {name,age:a,city} = person
// console.log(name,a,city)

// person.a = person.age
// console.log(person)

// 3 extract 1 and 3 th 
// const nums = [10,20,30]
// const [a,,b] = nums
// console.log(a,b)


// 4 destructure the array and collect remanining items
// const fruits = ["apple","banana","cherry","date"]
// const [a,b,...c] = fruits;
// console.log(a,b,c)

// 5  use rest operator in object
// const student = {name:"anuj",age:20,course:"CSE",city:"Rourkela"}
// const {name:x,...a} = student
// console.log(x,a)

// 6 use spread operator to add 11 in arr1 in front and 18 in a2 in last
// const a1 = [12,13,14];
// const a2 = [15,16,17];

// const anew1 = [11,...a1]
// const anew2 = [...a2,18]
// console.log(anew1,anew2)

// 7 combine two arrays using spread
// const a = [1,2]
// const b = [3,4]
// const c = [...a,...b]
// console.log(c)

//  8
// const a1 = [12,13,14];
// const a2 = [15,16,17];
// let c = [11]
// c = c.concat(a1)
// c = c.concat(a2)
// c = c.concat(18)
// console.log(c)

// 9 use spread to convert string "hello" into array of characters
// let str = "hello"

// const arrCh = [...str]
// console.log(arrCh)

// 10 what happens when you spread undefined or null
// give error - TypeError: a is not iterable
// let a ;
// // let a = null;
// // let a = [];
// const ar = [...a]
// console.log(ar)

// 11 
// const arr =  [10,20,30,40]
// const str1 = 
// const [x,,y,,z=110,m] = arr
// m = [...str1]
// console.log(x,y,z,m)

// 12
// import {pi} from "./functions.mjs"
// console.log(pi)

// import printName,{add,mul} from "./functions.mjs"
// printName('aks');
// console.log(add(2,3))
// console.log(mul(2,3))
