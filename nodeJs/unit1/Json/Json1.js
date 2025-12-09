const jsonData = '{"name": "Parveen", "age": 10, "rollno": 30}';
const obj = JSON.parse(jsonData);   // Convert string → object
console.log(obj); 
console.log(obj.name);        // Output: Parveen
console.log(obj.age);  
console.log(obj.rollno);              

const newJson = JSON.stringify(obj, ["name"], 3); // Convert object → string
console.log(newJson);
 console.log(newJson.name); 