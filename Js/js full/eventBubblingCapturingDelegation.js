
// document.getElementById("parent").addEventListener('dblclick', function () {
//     console.log("parent event");
// })

// document.getElementById("child").addEventListener('click', function (e) {
//     e.stopPropagation()
//     console.log("child event");
// })


// document.getElementById("parent").addEventListener('click', function () {
//     console.log("parent event");
// }, true)

// document.getElementById("child").addEventListener('click', function (e) {
//     // e.stopPropagation()
//     console.log("child event");
// }, true)


document.getElementById("list").addEventListener("click", function (e) {
    console.log(e.target.innerText);
})

// list.addEventListener("click", function (e) {
//     console.log(e.target.innerText);
// })