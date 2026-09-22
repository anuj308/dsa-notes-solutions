
let parent = document.querySelector('#parent')
let child = document.querySelector('.child')
//console.log(parent.children)
//console.log(parent.children[2])

// console.log(parent.firstElementChild)
// console.log(parent.lastElementChild)

// console.log(child)
// console.log(child.parentElement)
// console.log(child.nextElementSibling)

let container = document.querySelector('#container');

let ul = document.querySelector('#ul');

let element = document.createElement('h1')

let li = document.createElement('li')
let li2 = document.createElement('li')
li.innerText = "li 1"
li2.innerText = "li 2"
element.innerText = "This is h6 created by DOM";

//document.body.append(element)
//container.append(element)
//container.appendChild(element)
container.remove(element)
ul.appendChild(li)
ul.appendChild(li2)

ul.removeChild(li2)