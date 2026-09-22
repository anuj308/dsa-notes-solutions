class BankAccount{
    #balance = 0;

    constructor(balance){
        this.#balance = balance;
    }

    deposit(amount){
        this.#balance +=amount;
    }
    withdraw(amount){
        this.#balance -=amount;
    }
    getBalance(){
        return this.#balance;
    }
}

const account = new BankAccount(1000);

account.deposit(500);
account.withdraw(100);
//account.balance=200000;

console.log(account.getBalance());