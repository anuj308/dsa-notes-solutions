// Single File Programming Question
// Problem Statement



// Imagine you are organizing a game where you need to keep track of the scores of players and also quickly find out the highest score among them. 



// You have a stack-based system to manage the scores, where each operation can be one of the following:

// Push Score: Add a new score to the top of the stack.
// Pop Score: Remove the most recent score from the top of the stack.
// Get Maximum Score: Retrieve the highest score currently in the stack.
// Print Scores: Display all the scores currently in the stack, from the most recent to the oldest.


// Implement the task using arrays.

// Input format :
// The input consists of a choice in the menu for interacting with the stack. The choices are as follows:

// 1: Push an element onto the stack. The next input is the element to push, separated by a space.

// 2: Pop the top element from the stack.

// 3: Find and print the maximum element in the stack.

// 4: Print all elements currently in the stack.

// 5: Exit the program.

// Output format :
// The program performs various actions based on the user's choices and prints messages accordingly.

// If an element is pushed onto the stack, no specific message is printed.
// If an element is popped from the stack, no specific message is printed unless the stack is empty, in which case it prints "Stack is empty"
// If the maximum element in the stack is queried, it prints "Maximum element: " followed by the maximum element in the stack. If the stack is empty when querying the maximum, it prints "Maximum element: -1".
// If the elements in the stack are printed, they are separated by spaces. If the stack is empty, it prints, "Stack is empty"
// If an invalid choice is made, it prints "Invalid choice"


// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum size of the stack is 10.

// Sample test cases :
// Input 1 :
// 1 25
// 1 43
// 2
// 1 15
// 1 74
// 1 39
// 1 50
// 2 
// 3
// 4
// 5
// Output 1 :
// Maximum element: 74
// 39 74 15 25 
// Input 2 :
// 1 2
// 1 4
// 6
// 2
// 2
// 2
// 3
// 4
// 5
// Output 2 :
// Invalid choice
// Stack is empty
// Maximum element: -1
// Stack is empty
// Input 3 :
// 1 23
// 2
// 3
// 4
// 5
// Output 3 :
// Maximum element: -1
// Stack is empty

// one testcase did not pass

#include <iostream>
using namespace std;

#define SIZE 999
void push(int);
void pop();
void display();
void max();

int stack[SIZE];
int top=-1;

int main(){
    int choice,value;
    while(1){
        cin >> choice;
        switch(choice){
            case 1: cin >> value;
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: max();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}

void push(int v){
    if(top== SIZE - 1){
        cout << "stack overflow"<< endl;
    }else{
        top++;
        stack[top]=v;
    }
}
void pop(){
    if(top==-1){
        cout << "Stack is empty" << endl;
    }else{
        top--;
    }
}
void display(){
    if(top==-1){
        cout << "Stack is empty" << endl;
    }else{
        int i;
        for(i=top;i>=0;i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
void max(){
    int max=-1;
    if(top==-1){
        cout << "Maximum element: " << max << endl;
    }
    else{
        int i;
        for(i=top;i>=0;i--){
            if(stack[i]>max){
                max = stack[i];
            }
        }
        cout << "Maximum element: " << max << endl;
    }
    
}