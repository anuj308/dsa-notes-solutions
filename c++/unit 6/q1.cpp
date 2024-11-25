// Single File Programming Question
// Problem Statement



// Mitha, a dedicated customer support executive, is faced with the challenge of validating mobile numbers provided by customers. To enhance the efficiency of this process, she envisions a program that not only takes a customer's mobile number as input but also ensures it is a valid 10-digit number containing only digits (0–9). 



// Mitha desires a robust solution that utilizes exception handling to provide customers with clear feedback regarding the validity of their entered mobile numbers.

// Input format :
// The input consists of a single line containing a string representing the customer's mobile number.

// Output format :
// The output prints in the following format:



// The first line of output displays the given mobile number.

// If the mobile number contains characters other than digits (0–9), the program should output "Invalid input".

// If the mobile number has less than or greater than 10 digits, the program should output: "The mobile number should have 10 digits".

// If the mobile number has exactly 10 digits and contains only digits, the program should output: "The entered mobile number is valid".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 <= Mobile number <= 9

// The mobile number should have exactly 10 digits.

// Sample test cases :
// Input 1 :
// 9856984256
// Output 1 :
// 9856984256
// The entered mobile number is valid
// Input 2 :
// 85658542
// Output 2 :
// 85658542
// The mobile number should have 10 digits
// Input 3 :
// abdc987654
// Output 3 :
// Invalid input
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// // Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

int main(){
    string no;
    getline(cin,no);
    
    int c = 0;
    int n = no.length();
    int f = 0;

    while(c<n){
        char x = no[c];
        if(x<'0' || x>'9'){
            cout << "Invalid input" << endl;
            f=1;
            break;
        }
        c++;
}
    if(f==0){
        cout << no << endl;
    }
    if(n!=10){
        cout << "The mobile number should have 10 digits" << endl;
    }

    if(c==10){
        cout << "The entered mobile number is valid" << endl;
    }
    
    return 0;
}
