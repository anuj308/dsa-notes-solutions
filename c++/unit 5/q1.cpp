// Single File Programming Question
// Problem Statement



// Nikil is developing a text editor for a specialized system that requires dynamic string handling. The text editor should allow users to input characters and dynamically resize the memory to store the text. Write a program to accomplish this task.

// Input format :
// The input accepts characters from the user one by one. To stop appending characters, type '0'.

// Output format :
// The output displays the complete string and its length.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input string will not exceed 1000 characters.

// Sample test cases :
// Input 1 :
// Hello, this is a dynamic string handling example0
// Output 1 :
// Dynamic String: Hello, this is a dynamic string handling example
// String Length: 48
// Input 2 :
// The quick brown fox jumps over the lazy dog0
// Output 2 :
// Dynamic String: The quick brown fox jumps over the lazy dog
// String Length: 43
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// not done as required 

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string st;
    char ch;
    int* a = new int(1);
    while(true){
        ch = cin.get();
        
        if(ch == '0'){
            break;
        }
        
        st += ch;
    }
    cout << "Dynamic String: " << st << endl;
    cout << "String Length: " << st.length() << endl;
    delete a;
    return 0;
}