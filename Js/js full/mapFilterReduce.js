const numbers =[1,2,3,4,5];
 
//const result = numbers.map(num => num * 2)

//const result = numbers.filter(num => num > 2) 

const result = numbers.reduce((total,num)=>{
    return total+num;
},0)

console.log(result)
 