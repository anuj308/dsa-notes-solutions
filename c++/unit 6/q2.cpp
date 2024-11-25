// Single File Programming Question
// Problem Statement

// ﻿

// Write a program to validate a password based on certain criteria. 



// The program should check the length of the password must be at least 6 characters and ensure it contains at least one digit (0-9). If the password does not meet these criteria, an appropriate error message should be displayed.



// Implement the program using exception-handling mechanisms.

// Input format :
// The first line of input consists of a string representing the username.

// The second line consists of a string representing the password.

// Output format :
// If the password meets all the criteria, output "Password is correct"

// If the password is less than 6 characters long, output "Password must be at least 6 characters long."

// If the password does not contain at least one digit, output "Password must have at least One digit (0-9)"

// For all the exception that occurs, print "Caught by exception, invalid password format!", in the last line.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum length of the username is 50 characters.

// The maximum length of the password is 20 characters.

// Sample test cases :
// Input 1 :
// Santo
// san@12
// Output 1 :
// Password is correct
// Input 2 :
// Sona
// 1234
// Output 2 :
// Password must be at least 6 characters long.
// Caught by exception, invalid password format!
// Input 3 :
// HarishS
// harish
// Output 3 :
// Password must have at least One digit (0-9)
// Caught by exception, invalid password format!
// Input 4 :
// Ramesh
// @ramu
// Output 4 :
// Password must be at least 6 characters long.
// Caught by exception, invalid password format!
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

bool containDigit(string pass){
    for(char ch : pass){
        if(isdigit(ch)){
            return true;
        }
    }
    return false;
}
int main(){
    string name;
    string pass;
    getline(cin,name);
    getline(cin,pass);
    
    try {
    if(pass.length()<6){
        throw runtime_error("Password must be at least 6 characters long.");
    }
    
    if(!containDigit(pass)){
        throw runtime_error("Password must have at least One digit (0-9)");
    }
    
    cout << "Password is correct" << endl;
    return 0;
    }
    catch (const runtime_error& e){
        cout << e.what() << endl;;
        cout << "Caught by exception, invalid password format!" << endl;
    }
    return 0;
}