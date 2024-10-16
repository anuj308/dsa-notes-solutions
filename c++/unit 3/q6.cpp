// Single File Programming Question
// Problem Statement



// Queency wants to write a program that takes user input to store a name in a file and then opens and prints the name from the file. Queency needs to implement the program using file stream operations.



// File name: gfg.data

// Input format :
// The input consists of the name as a string.

// Output format :
// The output displays the input name.

// Code constraints :
// 1 ≤ Length of the name ≤ 100

// Sample test cases :
// Input 1 :
// John
// Output 1 :
// John
// Input 2 :
// Hussain
// Output 2 :
// Hussain
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string nam,out;
    getline(cin,nam);
    
    ofstream my_file("gdg.data");
    my_file << nam;
    my_file.close();
    
    ifstream my_files("gdg.data");
    getline(my_files,out);
    cout << out;
    my_files.close();
    
    return 0;
}