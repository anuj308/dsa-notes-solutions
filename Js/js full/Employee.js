class Employee {
    #salary;

    constructor(salary){
        this.#salary=salary;
    }

    get salary(){
        return this.#salary;
    }

    set salary(value){
        this.#salary = value;
    }
}
const emp = new Employee(30000);

emp.salary = 50000;

console.log(emp.salary);