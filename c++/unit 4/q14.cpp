// Single File Programming Question
// Problem Statement



// Aria is working with a pair of numbers X and Y for her math project. She needs a program to calculate the addition and subtraction of the negated values of X and Y.



// Help her create a program that takes X and Y as input, negates them using the - operator overloading, and then calculates and prints the addition and subtraction of the negated values.



// For Example:

// Assume that X = 10 and Y = 20. The negated values are X = -10 & Y = -20.

// Addition: (-10) + (-20) = -30
// Subtraction: (-10) - (-20) = 10
// Input format :
// The input consists of two space-separated integers: X and Y.

// Output format :
// The output displays two space-separated integers:

// Addition of the negated values X and Y
// Subtraction of the negated values X and Y


// Refer to the sample output for formatting specifications.

// Code constraints :
// -1000 ≤ X, Y ≤ 1000

// Sample test cases :
// Input 1 :
// 10 20
// Output 1 :
// -30 10
// Input 2 :
// -5 -6
// Output 2 :
// 11 -1
// Input 3 :
// 498 967
// Output 3 :
// -1465 469
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class number{
    public:
        int value;
        number(int v) : value(v){}
        number operator-() const {
            return (-value);
        }
        int getValue() const {
            return value;
        }
};


int main(){
    int n1,n2;
    cin >> n1;
    cin >> n2;
    
    number x1(n1);
    number x2(n2);
    
    number nx1 = -x1;
    number nx2 = -x2;
    
    int add = nx1.getValue() + nx2.getValue();
    int sub = nx1.getValue() - nx2.getValue();
    
    cout << add << " " << sub << endl; 
    return 0;
}