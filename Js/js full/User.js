class User{
    constructor(username){
        this.username = username;
    }
    login(){
        console.log(`${this.username}  login krlia h`)
    }
}

class Student extends User{
    study(){
          console.log(`${this.username} study kar rha h..`)
    }
}

class Teacher extends User{
    teach(){
          console.log(`${this.username} teaching kar rha h..`)
    }
}

const myStudent = new Student("Rahul");
const myTeacher = new Teacher("Sharma Ji");
myStudent.login();
myStudent.study();
myTeacher.login();
myTeacher.teach();