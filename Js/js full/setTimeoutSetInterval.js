function showMessage() {
    console.log("Welcome to JS");
}

//3000 // milliseconds = 3 sec
// setTimeout(showMessage, 3000);

// setTimeout(function showMessage() {
//     console.log("Welcome to JS");
// }, 3000);

// setTimeout(function () {
//     console.log("Welcome to JS");
// }, 3000);


// setTimeout(() => {
//     console.log("Welcome to JS")
// }, 3000);

// function showTime() {
//     console.log(new Date().toLocaleTimeString())
// }

// setInterval(showTime, 1000)


// console.log("start")
// setTimeout(() => {
//     console.log("Welcome to JS")
// }, 1000);
// console.log("ends")

// var count = 1;

// setInterval(function () {
//     console.log("Count:", count)
//     count++;
// }, 1000)

// var count = 1;

// let intervalID = setInterval(function () {
//     console.log("Count:", count)
//     if (count == 10) {
//         clearInterval(intervalID);
//         console.log("Interval count stopped")
//     }
//     count++;
// }, 1000)

// function startTimer() {
//     setTimeout(function () {
//         alert("Executed after 3 seconds")
//     }, 3000)
// }

var count = 0;
var intervalID;

function startCounter() {
    if (!intervalID) {
        intervalID = setInterval(function () {
            document.getElementById("count").innerText = count;
            count++;
        }, 1000)
    }
}

function stopCounter() {
    clearInterval(intervalID);
    intervalID = null;
}