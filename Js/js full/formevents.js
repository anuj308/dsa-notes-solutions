
// function focused() {
//     let text1 = document.getElementById("text1")
//     text1.style.backgroundColor = "red"

//     console.log("focus");

// }

// function blurr() {
//     let text1 = document.getElementById("text1")
//     text1.style.backgroundColor = ""
//     console.log("blur");

// }


// let text1 = document.querySelector('#text1')

// let para = document.querySelector('#para')

// let choose = document.querySelector('#choose')

// text1.addEventListener('focus', function () {
//     text1.style.backgroundColor = "blue"
// })

// text1.addEventListener('blur', function () {
//     text1.style.backgroundColor = ""
// })

// text1.addEventListener('input', function () {
//     para.innerText = text1.value
// })


// function selectCar(element) {
//     console.log(element.value);
// }

// function selectCar(value) {
//     console.log(value);
// }


// choose.addEventListener('change', function () {
//     console.log(choose.value);
// })


// let myForm = document.querySelector('#myForm')

// myForm.addEventListener('submit', function (e) {
//     e.preventDefault()
// })

let text = document.querySelector('#text1')

text.addEventListener('invalid', function (e) {
    alert("hello this field is required")
})