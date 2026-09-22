class Electronics{
    powerOn(){
        console.log("power on h");
    }
}

class Mobile extends Electronics {
    call(){
        console.log("calling...."); 
    }
}

class SmartPhone extends Mobile{
    browse(){
        console.log("browsing...."); 
    }
}

const myPhone = new SmartPhone();

myPhone.powerOn();
myPhone.call();
myPhone.browse();