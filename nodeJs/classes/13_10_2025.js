const a = 1
// a = 2 not possiable
let b = 2
b = 3
console.log(b)

let c = 'a'
let d = 22
let e = "ddd"
let f = true
let g;
let h = 677777n
let s = Symbol('fnudnfid')
console.log(typeof(c))
console.log(typeof(d))
console.log(typeof(e))
console.log(typeof(f))
console.log(typeof(g))
console.log(typeof(h))
console.log(typeof(s))

function add(a,b){
    console.log(a+b)
}
add(2,3)

const addd = (a,b)=>{
    console.log(a+b)
}
add(2,3)

let arr = [2,3]
for(let i=0;i<arr.length;i++){
    console.log(arr[i])
}
arr.forEach( e => console.log(e))
for(let i in arr) console.log(i,arr[i])
    
// arr.unshift(2)
arr.push(3)
arr.pop()
for(let i=0;i<2;i++){
    console.log(arr[i])
}

const o = {
    age:23,
    name:'aks'
}
o.age=20
console.log(o)