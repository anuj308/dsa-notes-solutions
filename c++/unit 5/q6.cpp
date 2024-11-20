// Single File Programming Question
// Problem Statement﻿



// Ram, a student studying mathematics, is developing a simple calculator program. He sometimes needs to add two numbers, and at other times, he needs to multiply three numbers, depending on the task he is working on.



// His task is to Create a class with two overloaded functions to handle addition and multiplication operations based on the number of input arguments. Write a program using function overloading to accomplish this task.



// Function Prototype

// fun1(int num1, int num2, int num3)

// fun1(int num1, int num2)

// Input format :
// The input consists of the number of elements N followed by the N elements separated by space.

// Output format :
// The output displays the sum if there are two integers or the product if there are three integers.

// If the number of elements is other than 2 or 3, then display the message as invalid input.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 2 ≤ N ≤ 3

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 3 1 2 3
// Output 1 :
// 6
// Input 2 :
// 2 14 56
// Output 2 :
// 70
// Input 3 :
// 4 67 89 43 21
// Output 3 :
// Invalid Input
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;

class cal{
    public:
       void fun1(int n1,int n2,int n3){
           cout << n1*n2*n3 << endl;
       }
       void fun1(int n1,int n2){
           cout << n1+n2 << endl;
       }
};

int main(){
    int n;
    cin >> n;
    
    cal c1;
    if(n == 2){
        int n1,n2;
        cin >> n1 >> n2;
        c1.fun1(n1,n2);
    }else if(n == 3){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        c1.fun1(n1,n2,n3);
    }else{
        cout << "Invalid Input" << endl;
    }
    
    return 0;
}