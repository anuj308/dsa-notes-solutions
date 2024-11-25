// Single File Programming Question
// Problem Statement



// Beula is working on a data analysis project where you need to determine the number of characters except for the input character in a given text. Write a program that prints the number of characters except for the input character without using loops.



// Hint: Use the count_if function template.

// Input format :
// The first line contains a string c (up to 50 characters) consisting of only uppercase, lowercase, and special characters.

// The second line contains a single character, ch, which is the character to be counted in the string c.

// Output format :
// The output consists of a single integer representing the count of occurrences of the character ch in the string c.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The length of the string c will be at most 50 characters.

// The character ch will be a valid ASCII character (uppercase or lowercase letter).

// The character is case-sensitive.

// Sample test cases :
// Input 1 :
// hello
// l
// Output 1 :
// 3
// Input 2 :
// applepie
// p
// Output 2 :
// 5
// Input 3 :
// world
// o
// Output 3 :
// 4
// Code Size : 1024 kb
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    
    string meg;
    char search;
    getline(cin,meg);
    cin >> search;
    
    int count = count_if(meg.begin(),meg.end(),[search](char c){ return search!=c; });
    
    cout << count << endl;
    return 0;
}