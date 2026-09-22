//sync
// function add(a, b) {
//     return a + b;
// }

// function calculate(a, b, add) {
//     console.log(add(4, 6))
// }

// calculate(4, 6, add)

// function add(a, b) {
//     return a + b;
// }

// setTimeout(function () {
//     console.log(add(1, 5))
// }, 2000);

// button.addEventlistner("click",function(){

// });

setTimeout(function () {
    console.log(1)
    setTimeout(function () {
        console.log(2)
        setTimeout(function () {
            console.log(3)
            setTimeout(function () {
                console.log(4)
                setTimeout(function () {
                    console.log(5)
                }, 1000);
            }, 1000);
        }, 1000);
    }, 1000);
}, 1000);