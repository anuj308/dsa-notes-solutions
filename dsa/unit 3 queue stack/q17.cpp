// Single File Programming Question
// Problem Statement



// Meet Alex, a computer science student who loves solving programming challenges. 



// Today, Alex is tasked with creating a program to simulate a stack data structure using linked lists. 



// The objective is to provide a menu-driven interface for performing essential stack operations: 

// Push elements onto the stack
// Pop elements from the stack 
// Display the current stack contents


// Additionally, Alex needs to ensure that the program handles stack underflow conditions. Help him to accomplish the task.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the integer value onto the stack. If the choice is 1, the following input is a space-separated integer, representing the element to be pushed onto the stack.

// Choice 2: Pop the integer from the stack.

// Choice 3: Display the elements in the stack.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the stack:

// If the choice is 1, push the given integer to the stack and display the following: "[value] is pushed onto the stack"
// If the choice is 2, pop the integer from the stack and display the following: "[value] is popped from the stack"
// If the choice is 2, and if the stack is empty without any elements, print "Stack Underflow"
// If the choice is 3, print the elements in the stack in the format: "Elements in the stack: ", followed by the space-separated values.
// If the choice is 3, and there are no elements in the stack, print "Stack is empty"
// If the choice is 4, exit the program and display the following: "Exiting the program"
// If any other choice is entered, print "Invalid choice"


// Refer to the sample output for the exact text.

// Code constraints :
// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 6
// 1 7
// 3
// 2
// 4
// Output 1 :
// 6 is pushed onto the stack
// 7 is pushed onto the stack
// Elements in the stack: 7 6 
// 7 is popped from the stack
// Exiting the program
// Input 2 :
// 5
// 4
// Output 2 :
// Invalid choice
// Exiting the program
// Input 3 :
// 2
// 4
// Output 3 :
// Stack Underflow
// Exiting the program
// Input 4 :
// 3
// 4
// Output 4 :
// Stack is empty
// Exiting the program
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.