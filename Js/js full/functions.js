message()
// console.log(4 + 5);
// console.log(1 + 5);
// console.log(7 + 5);
// console.log(9 + 5);
// console.log(10 + 5);
message()
function message() {
    console.log("Hello Gudnight")
}
//function declare
//function with parameters
function add(num1, num2 = 6) {
    // if (num1 == null || num2 == null) {
    //     console.log("please enter the numbers")
    // }

    if (!num1) {
        console.log("please enter the numbers")
    } else {
        let sum = num1 + num2;
        console.log(sum)
    }

}
//function call
//add(76) // arguments

// message()

// add(1, 2)

// add(6, 9)

function sum() {
    let add = 5 + 6;
    return add;
}

let addition = sum();
console.log(addition) 