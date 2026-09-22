class Salary{
    calculate(){
        console.log("Salary Calculation")
    }
}

class Developer extends Salary{
    calculate(){
        console.log("Developer Salary = 40000 ")
    }
}

class Manager extends Salary{
    calculate(){
        console.log("Manager Salary = 100000 ")
    }
}

class Intern extends Salary{
    calculate(){
        console.log("Intern Salary = 7000 ")
    }
}

const emp = [new Developer(),new Manager(),new Intern()];

emp.forEach(employee => employee.calculate())

