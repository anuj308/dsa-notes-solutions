Execution Context + Call Stack(JavaScript)
1. Execution Context

Execution Context woh environment hota hai jisme JavaScript code execute hota hai.

Har execution context ke 2 phases hote hain:

A.Creation Phase

let variables = 10;
function hello() {
    console.log(variables);
}
hello()

Variables memory me allocate hote hain.
Function declarations memory me store hoti hain.
this keyword set hota hai.

    B.Execution Phase

Code line - by - line execute hota hai.

Variables ko actual values assign hoti hain.

Functions call hote hain.

Types of Execution Context

Global Execution Context(GEC)
Sabse pehle create hota hai.
Sirf ek baar create hota hai.

Function Execution Context(FEC)

Har function call par naya context create hota hai.
 
2. Call Stack

Call Stack ek data structure hai jo track karta hai ki kaunsa function currently execute ho raha hai.

    Rule:

Function call → Stack me Push
Function complete → Stack se Pop
Example
function first() {
    console.log("First");
    second();
}

function second() {
    console.log("Second");
    third();
}

function third() {
    console.log("Third");
}

first();
Call Stack Flow
Global Execution Context
        ↓
first()
        ↓
second()
        ↓
third()

Stack:

| third() |
| second() |
| first() |
| Global |
    ------------

        After third() completes:

| second() |
| first() |
| Global |
    ------------

        After second() completes:

| first() |
| Global |
    -----------

        Finally:

| Global |
    ----------
        Output
First
Second
Third
Interview Definition

Execution Context: Environment where JavaScript code is executed.

Call Stack: LIFO(Last In First Out) stack that manages execution contexts and function calls during program execution.
