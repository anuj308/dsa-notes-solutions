// Single File Programming Question
// Problem Statement



// You are implementing a user registration system that validates email addresses. The email address must meet the following requirements to be considered valid:



// Valid Email Criteria:

// Starts with a Letter: The first character must be a letter (uppercase or lowercase).
// Contains '@' and '.' Symbols: There must be one '@' symbol followed by a '.' symbol.
// Correct Order: The '@' symbol must come before the '.' symbol.
// Valid Ending: The '.' symbol cannot be the last character.
// Input format :
// The input consists of a string representing the mail id.

// Output format :
// The output prints whether the given mail ID is valid or not.



// Refer to the sample input and output for the formatting specifications.

// Sample test cases :
// Input 1 :
// placement@gmail.com
// Output 1 :
// Email Id is Valid.
// Input 2 :
// abcd@gmail
// Output 2 :
// Exception Caught...
// Invalid Email Id!!!
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <bits/stdc++.h>
using namespace std;
bool isValid(string email){
    int n = email.length();
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++){
        if(c1==1){
            if(email[i]=='.'){
                c2=1;
            }
        }
        if(email[i]=='@'){
            c1=1;
        }
    }
    if(isalpha(email[0]) && c1 && c2 && email[n-1]!='.')
    {
        return true;
    }
    return false;
}
int main(){
    
    string email;
    cin >> email;
    if(isValid(email)){
        cout << "Email Id is Valid." << endl;
    }else{
        cout << "Exception Caught..." << endl;
        cout << "Invalid Email Id!!!" << endl;
    }
    return 0;
}