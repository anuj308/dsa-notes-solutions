
let myName: string = "anuj"
// boolean,number
let noOfWheel: number = 10
let isStudent: boolean = false

type Food = string
type Address = {
    steet: string
    city: string
    country: string
}
// below can put comma, semicoln or nothing
type Person = {
    name: string
    age: number
    isStudent: boolean
    // address: Address // two ways
    address?: { // optional
        street: string
        city: string
        country: string
    }
}

let person: Person = {
    name: "anuj",
    age: 23,
    isStudent: false,
    address: {
        street: "ajsdn",
        city: "ak",
        country: "nf"
    }
}

let person1: Person = {
    name: "anuj",
    age: 23,
    isStudent: false,
    address: {
        street: "ajsdn",
        city: "ak",
        country: "nf"
    }
}

