class Phone {
    constructor(brand){
        this.brand = brand;
    }
    call(){
      console.log(`${this.brand} call ho rhi h `)
    }
}

class SmartPhone extends Phone{
    constructor(brand,model){
        super(brand)
        this.model = model;
    }

    browseInternet(){
              console.log(`${this.brand} ${this.model} internet chala rha h`)

    }
}

const myPhone = new SmartPhone("Apple","iphone 17");
myPhone.call();
myPhone.browseInternet();