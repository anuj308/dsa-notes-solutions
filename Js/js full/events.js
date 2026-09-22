
function message() {
    console.log("Hello event js");
}

// function message2() {
//     console.log("Hello event js 2");
// }

//normal anonyms func
let btn = document.getElementById("btn")
let input = document.getElementById("input")

// btn.addEventListener('click', function () {
//     console.log("hello js")
//     //btn.removeEventListener('click', message)
// })

// //named function
// btn.addEventListener('click', message)


//arrow func

// btn.addEventListener('click', () => {
//     console.log("hello js")
// })

// btn.addEventListener('click', function () {
//     //this.style.backgroundColor = "red"
//     btn.style.backgroundColor = "red"
//     btn.style.color = "blue"
// })


//Event object

// document.addEventListener("contextmenu", function (e) {
//     e.preventDefault()
//     console.log("right click disabled")
// })


// btn.addEventListener('click', function (event) {
//     console.log(event.target.innerText)
// })

// btn.addEventListener('dblclick', function (event) {
//     console.log(event.type)
// })

//Mouse event

// btn.addEventListener('mousedown', function () {
//     console.log("mousedown")
// })

// btn.addEventListener('mouseup', function () {
//     console.log("mouseup")
// })

// btn.addEventListener('mouseenter', function () {
//     btn.style.backgroundColor = "red"
//     console.log("mouseenter")
// })

// btn.addEventListener('mouseleave', function () {
//     btn.style.backgroundColor = ""
//     console.log("mouseenter")
// })


// btn.addEventListener('mouseover', function () {
//     btn.style.backgroundColor = "red"
//     console.log("mouseenter")
// })

// btn.addEventListener('mouseout', function () {
//     btn.style.backgroundColor = ""
//     console.log("mouseout")
// })


// document.addEventListener('mousemove', function (e) {
//     console.log(e.clientX, e.clientY)
// })

//keyboard event

// document.addEventListener('keyup', function () {
//     console.log("keyup")
// })


// document.addEventListener('keypress', function () {
//     console.log("keypress")
// })

// document.addEventListener('keypress', function (e) {
//     console.log(e.key)
// })

// document.addEventListener('keydown', function (e) {
//     console.log(e.key)
// })

// document.addEventListener('keypress', function (e) {
//     console.log(e.code)
// })

// document.addEventListener('keydown', function (e) {
//     if (e.ctrlKey) {
//         console.log("ctrl pressed")
//     } else {
//         console.log("ctrl not pressed")
//     }
// })


// document.addEventListener('keydown', function (e) {
//     if (e.shiftKey) {
//         console.log("shift pressed")
//     } else {
//         console.log("shift not pressed")
//     }
// })


// document.addEventListener('keydown', function (e) {
//     if (e.altKey) {
//         console.log("altkey pressed")
//     } else {
//         console.log("altkey not pressed")
//     }
// })

// document.addEventListener('keydown', function (e) {
//     if (e.ctrlKey && e.key === "s") {
//         console.log("save success")
//     } else {
//         console.log("not saved")
//     }
// })


// input.addEventListener('keydown', function (e) {
//     input.style.backgroundColor = "aqua"
//     console.log(e.key)
// })


// input.addEventListener('keyup', function (e) {
//     input.style.backgroundColor = ""

// })