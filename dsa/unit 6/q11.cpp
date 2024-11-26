// Single File Programming Question
// Problem Statement



// Emma is working on a project where she needs to hash subject names for efficient data organization. She has designed a custom hash function and wants to test it using different subject names. 



// Your task is to implement the hash function and help Emma determine the hash values for various subject names.



// Note

// hashValue = (hashValue * 37) + ch, where 'ch' represents the integer value of the character.
// hashValue% HASH_TABLE_SIZE is an operation involving the modulo operator (%).
// Input format :
// The input consists of strings containing the subject name, separated by a line.

// The input continues until Emma enters 'exit' as a string, indicating the end of the input.

// Output format :
// For each input subject name (excluding 'exit'), the program should output its corresponding hash value calculated using the hash function.

// Each hash value should be printed on a new line.

// Code constraints :
// Hash table size = 1000

// Length of the string = 50 characters

// Each input string consists of lowercase and uppercase letters

// Sample test cases :
// Input 1 :
// Maths
// Science
// exit
// Output 1 :
// 505
// 806
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <iostream>
#include <string>
using namespace std;
#define HASH_TABLE_SIZE 1000
// You are using GCC
unsigned int customHash(string key) {
    unsigned int hashVal=0;
    for(auto c : key){
        hashVal = hashVal*37 + c;
    }
    return hashVal%HASH_TABLE_SIZE;
}

int main() {
    
    string text;
    while(true){
        
        cin >> text;
        if(text=="exit"){
            break;
        }
        cout << customHash(text) << endl;
        
    }
        return 0;
}