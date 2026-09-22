
// const number = new Set([10,20,20,30,40,40,50]);
// console.log(number);

// const set = new Set();

// set.add(10);
// set.add(20);
// set.add(20);
// set.add(30);
// console.log(set.has(80));
// console.log(set);
// console.log(number.size);

// const arr = [1,2,2,3,4,4,5,5,6];

// const uniqueArr = [...new Set(arr)];

// console.log(uniqueArr);

const id1 = Symbol("id");
const id2 = Symbol("id");

 console.log(id1===id2);

 const id = Symbol("id");

 const user = {
    name:"Shubham"
 }
 user[id] = 101;
 
 console.log(user[id])

 user.id = 500;

  console.log(user[id])