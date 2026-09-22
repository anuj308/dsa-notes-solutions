// function add(a,b,c){
//     return a+b+c;
// }
// console.log(add(2,4,5))

// function curryAdd(a){
//     return function(b){
//         return function(c){
//                return a+b+c;
//         }
//     }
// }
// console.log(curryAdd(2)(4)(5))

function multiply(a){
    return function(b){
        return a*b;
    }
}
 
let double = multiply(2);
console.log(double(5));
console.log(double(10));

function multiply(a,b){
    return a*b;
}

multiply(2,5);
multiply(2,10);
 