// const globalVar = "I'm a global";

// function outer() {
//     const outerVar = "I'm a outer";

//     function inner() {
//         const innerVar = "I'm a inner";
//         console.log(innerVar)
//         console.log(outerVar)
//         console.log(globalVar)
//     }
//     inner()
// }

// outer()

//closure

function outer() {
    let name = "Heavy Coding";

    function inner() {
        console.log(name)
    }
    return inner;
}
//save is value ko
let fn = outer();
//fn();

console.dir(fn)
