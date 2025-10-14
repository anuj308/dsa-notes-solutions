## Learning Node Js from Colleage Classes 

## initialize a = 5
## declare let a;
## declare and initialize let a = 5;
# var
- can redeclare and change value
- when declare a variable with no value by default it undefined when printed.

# let 
- cannot redeclare in same block scope but in different scope 
- can change the value
- when declare a variable with no value by default it undefined when printed.

# const
- when declare have to initialize the value. otherwise error
- cannot chnage the value
- cannot redeclare

## every() - check if all elements pass a conditions
---
    console.log(arr.every(i => i%2==0)) // false
    console.log(even.every(i => i%2==0)) // true

## filter() - return elements that match a condition
---
    const res = arr.filter(i => i%2===0)
    console.log(res);

## forEach - execute for every index (no return like every)(difference)
---
    const arr = [1,3,4];
    arr.forEach(e => {
        console.log(e%2==0)
    });

## indexOf() - give the index of the value in array
--- 
    const arr = [1,3,4];
    console.log(arr.indexOf(3)) // 1
    console.log(arr.indexOf(10)) // -1

## array.form() -> create an array from iterable or string
---
    const str = 'aks'
    console.log(Array.from(str))

##  map() -> transform element and returns a new array
---
    const arr = [1,3,4];
    const narr = arr.map((w)=> w*2)
    console.log(narr); // [2,6,8]