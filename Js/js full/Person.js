class Person{
    constructor(name="No name",age=0){
        this.name = name;
        this.age  = age;
    }

    display(){
        console.log(`${this.name} and ${this.age}`)
    }
}
const obj = new Person("Shubham",23);

// console.log(obj.name)
// console.log(obj.age) 
obj.display();

const obj2 = new Person();

// console.log(obj2.name)
// console.log(obj2.age)

obj2.display();