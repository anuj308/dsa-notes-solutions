//Array  

// index->0=1,1=2,2=3,3=4,4=5 elements store index pe
// ->index start ->0 ->elements
// let arr = []; // empty array value elements ->values 
// let arr = new Array(1,2,3,4,5); 
// let arr = [1,2,3,4,5,6,7]; // ye wala use

// let arr = [1, 2, 3, 4, 5]; // number array/indexed array
// console.log(arr);
let arrString = ["youtube", "shubham", "channel"]; // string
// console.log(arrString);

// let arrmixed = ["youtube", 1, "channel", 5, true];
// console.log(arrmixed);

let arr = [1, 2, 3, 4, 5, 6, 7];

//console.log(arr[2]);

//console.log(arr.length);
// arr.push(80); // end se add
// arr.pop(); // remove element from end
// arr.unshift(100); // start se element add
// arr.shift();

// console.log(arr);
// console.log(arr.includes(7));
// console.log(arr.indexOf(3));
// console.log(arrString.join(","));
// console.log(arr.slice(3, 6));
// console.log(arr);
// console.log(arr.splice(1, 3));
// console.log(arr);

//2D array
// let data = [
//     //cols->0 cols->1
//     ["BMW", "AUDI"], // row -> 0
//     ["NISSAN", "TATA"] // row- >1
// ];

//[ROWS,COLS] access
//console.log(data[1][1]);

//3D Array // multidimensional array
let data = [
    //cols->0 cols->1
    [ //0
        ["BMW", "AUDI"],// 0
        ["NISSAN", "TATA"], //1
    ],
    [ //1
        ["Hyundai", "Porsche"],
        ["Mazda", "Toyota"],
    ],
];

//console.log(data[0][0][0]);

let arr1 = [1, 2, 3, 4, 5];
let arr2 = [6, 7, 8, 9, 10];
let str = "Shubham Youtube";
console.log(Array.isArray(arr1));
console.log(Array.from(str)); // elements index wise string to array convert
console.log(Array.of("shubham"));// single element of array

//let fullArray = arr1.concat(arr2);
///let fullArray = arr1.push(arr2);
// let fullArray = [...arr1, ...arr2]; //spread
// console.log(fullArray);





