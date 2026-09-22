class Animal{
    constructor(name){
        this.name = name;
    }
    eat(){
        console.log(`${this.name} khana kha rha h`)
    }
}

class Dog extends Animal {
    bark(){
        console.log(`${this.name} barking`)
    }
}

const myDog = new Dog("Tommy");

myDog.eat();
myDog.bark();