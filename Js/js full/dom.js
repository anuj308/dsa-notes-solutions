//console.log(window)
//console.log(window.document)
//dom selectors

//access
let para = document.getElementById('para')
//let para2 = document.getElementById('para2')
//console.log(para)
//console.log(para.innerText)
//para.innerText = "Dom Started...";
//console.log(para.innerHTML)
//console.log(para.innerText)
//para.innerHTML = "Dom Started...";


let italic = document.getElementsByClassName('italic')

//collections
// console.log(italic[0].innerText)

// let p = document.getElementsByTagName('p')
// console.log(p[0].innerText)
// console.log(p[1].innerHTML)


//querySelector // first element
// let query = document.querySelector('p')
// let paraQ = document.querySelector('#para')
// let paraQ2 = document.querySelector('.italic')
//console.log(paraQ2)


//all elements fetch querySelectorAll
//let query = document.querySelectorAll('i')
//let query = document.querySelectorAll('#para')
//let query = document.querySelectorAll('.italic')
//console.log(query[0])

let items = document.querySelectorAll('.italic')

items.forEach((item) => {
    console.log(item.innerHTML)
})