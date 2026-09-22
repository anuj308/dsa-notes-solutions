
//let date = new Date("2000-04-12");
///let date = new Date("2000,04,12");
let date = new Date();


//GET
//Y-m-d
//timestamp
//console.log(date);
// console.log(date.toString())
// console.log(date.toDateString())
// console.log(date.toTimeString())
// console.log(date.toLocaleString())

// console.log(date.getFullYear());
// console.log(date.getMonth() + 1);
// console.log(date.getDate());
// console.log(date.getDay()); // sunday 0 monday 1 tuesday 2 ...
// console.log(date.getHours());
// console.log(date.getMinutes());
// console.log(date.getSeconds());

//SET
// date.setFullYear("2012")
// date.setMonth(0) // january 0 Feb 1....
// date.setDate(1)
// console.log(date.getFullYear());
// console.log(date.getMonth());
// console.log(date.getDate());

// let d1 = new Date("2027-02-14")
// let d2 = new Date("2026-02-14")

// if (d1 > d2) {
//     console.log("d1 is greater than d2")
// } else {
//     console.log("d2 is greater than d1")
// }

// let birthYear = 1996;
// let currentYear = new Date().getFullYear();
// let age = currentYear - birthYear;
// console.log(age);

let dateTime = new Date();
dateTime.setHours(11)
let hour = dateTime.getHours()
if (hour < 12) {
    console.log("Hello Gudmorning");
} else if (hour < 14) {
    console.log("Hello GudAfternoon");
} else if (hour < 16) {
    console.log("Hello Evening");
} else {
    console.log("Hello Gudnight");
}


