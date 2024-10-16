// Single File Programming Question
// Problem Statement



// Once upon a time in ancient Rome, there was a curious young mathematician named Marcus who loved studying Roman numerals. One day, he created a magical class called "RomanNumeral" that could convert these ancient symbols into modern decimal numbers.



// With the help of a unique type conversion operator, Marcus' class effortlessly transformed the mysterious Roman numerals into their equivalent decimal forms, unveiling the secrets of the past for all to understand and enjoy.



// Write a program to accomplish the above-given scenario.

// Input format :
// The input consists of a single line containing a valid Roman numeral as a string.

// Output format :
// The output displays a single line displaying the equivalent decimal number of the input Roman numeral.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ Roman numeral range ≤ 2000

// The input Roman numeral should be a valid Roman numeral. It should consist of the following Roman digits only: 'I', 'V', 'X', 'L', 'C', 'D', and 'M'.

// Sample test cases :
// Input 1 :
// VII
// Output 1 :
// Equivalent decimal number: 7
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// one test case did not pass from below one code check the difference why 
#include <bits/stdc++.h>
using namespace std;

class RomanNumeral{
    public:
        string value;
        RomanNumeral(string w){
            this->value = w;
        }
        operator int() const {
            int ans = 0;
            int prevalue = 0;
            for(int i=value.length() - 1; i>=0;i--){
                int temp = getValue(value[i]);
                if(temp<prevalue){
                    ans-=temp;
                }else{
                    ans+=temp;
                }
            }
            return ans;
        }
        int getValue(char c) const{
            switch(c){
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default : return 0;
            }
        }
};

int main(){
    string x;
    cin >> x;
    RomanNumeral r(x);
    int a = r;
    cout << "Equivalent decimal number: " << a;
    
    return 0;
}

// ai

#include <iostream>
#include <string>

using namespace std;

class RomanNumeral {
public:
    RomanNumeral(const string& roman) : roman_(roman) {}

    operator int() const {
        int decimal = 0;
        int prevValue = 0;

        for (int i = roman_.length() - 1; i >= 0; i--) {
            int currentValue = getValue(roman_[i]);
            if (currentValue < prevValue) {
                decimal -= currentValue;
            } else {
                decimal += currentValue;
            }
            prevValue = currentValue;
        }

        return decimal;
    }

private:
    string roman_;

    int  getValue(char c) const {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main()   
 {
    string romanNumeral;
    cin >> romanNumeral;

    RomanNumeral roman(romanNumeral);
    int decimal = roman;

    cout << "Equivalent decimal number: " << decimal << endl;

    return 0;
}