// Single File Programming Question
// Problem Statement



// Rithi is building a simple text editor that allows users to type characters, undo their typing, and view the current text. She has decided to implement this text editor using an array-based stack data structure.



// She has to develop a basic text editor with the following features:

// Type a Character (Push): Users can type a character and add it to the text editor.
// Undo Typing (Pop): Users can undo their typing by removing the last character they entered from the editor.
// View Current Text (Display): Users can view the current text in the editor, which is the sequence of characters in the buffer.
// Exit: Users can exit the text editor application.


// Write a program that simulates this text editor's undo feature using a character stack and implements the push, pop, and display operations accordingly.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the character onto the stack. If the choice is 1, the following input is a character, representing the character to be pushed onto the stack in the next line.

// Choice 2: Pop the character from the stack.

// Choice 3: Display the characters in the stack.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the stack:

// If the choice is 1, push the given character to the stack and display the character.
// If the choice is 2, undo the character from the stack and display the character that is removed.
// If the choice is 2, and if the stack is empty without any characters, print "Text editor buffer is empty. Nothing to undo."
// If the choice is 3, print the characters in the stack.
// If the choice is 3, and there are no characters in the stack, print "Text editor buffer is empty."
// If the choice is 4, exit the program.
// If any other choice is entered, print "Invalid choice"


// Refer to the sample output for the exact format.

// Code constraints :
// The maximum size of the stack is defined as 100.

// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 
// H
// 1 
// A
// 3
// 4
// Output 1 :
// Typed character: H
// Typed character: A
// Current text: A H 
// Input 2 :
// 1 
// H
// 1 
// E
// 3
// 2
// 3
// 4
// Output 2 :
// Typed character: H
// Typed character: E
// Current text: E H 
// Undo: Removed character E
// Current text: H 
// Input 3 :
// 3
// 4
// Output 3 :
// Text editor buffer is empty.
// Input 4 :
// 7
// 4
// Output 4 :
// Invalid choice
// Input 5 :
// 1 
// H
// 1 
// E
// 1 
// Y
// 3
// 2
// 2
// 2
// 2
// 4
// Output 5 :
// Typed character: H
// Typed character: E
// Typed character: Y
// Current text: Y E H 
// Undo: Removed character Y
// Undo: Removed character E
// Undo: Removed character H
// Text editor buffer is empty. Nothing to undo.
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.