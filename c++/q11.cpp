// Single File Programming Question
// Problem Statement



// Write a function isValidPhoneNumber that takes a phone number (string) as input and determines whether it is a valid phone number. The phone number format should be XXX-XXX-XXXX, where X represents a digit. The number is considered valid if the hyphens are in exact same positions and the length of the string is 12.

// Input format :
// The input consists of a phone number in the format XXX-XXX-XXXX, where X represents a digit.

// Output format :
// The output displays whether the entered string is a valid phone number or not.

// If the number is valid, the output displays the number without hyphens.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The phone number should be in the format XXX-XXX-XXXX, with a total length of 12 characters.

// Each X in the phone number should be a digit (0-9).

// No additional characters or spaces should be present in the input.

// Sample test cases :
// Input 1 :
// 123-456-7890
// Output 1 :
// Yes, the phone number is valid
// 1234567890
// Input 2 :
// 123-456-789
// Output 2 :
// No, the phone number is not valid
// Input 3 :
// 123456-7890
// Output 3 :
// No, the phone number is not valid

#include <bits/stdc++.h>
using namespace std;

void isValidPhoneNumber(string num){
    int l = num.length();
    int c=0;
        
    if(num[3]=='-' && num[7]=='-'){
        c++;
    }
        
    num.erase(3,1);
    num.erase(6,1);
    
    if(c==1 && l==12){
        cout << "Yes, the phone number is valid "  << endl << num ;
    }else{
        cout << "No, the phone number is not valid ";
    }
}

int main(){
    
    string num;
    getline(cin,num);
    
    isValidPhoneNumber(num);
    return 0;
}