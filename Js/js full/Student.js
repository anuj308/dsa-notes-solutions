class Student{
    //properties
    name = "Rahul";
    age = 20;

    //METHODS
    study(){
       console.log("Study"); 
    }
}
 const obj = new Student();
 const obj2 = new Student();
console.log(obj.name);
//console.log(obj.age);
obj.study();

console.log(obj2.age)