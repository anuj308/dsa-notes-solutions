// Single File Programming Question
// Problem statement



// Marc is working as a software developer for a scientific research institute, and his team is currently investigating various types of interesting numbers. One such type is the "Neon Number." A neon number is a special type of positive integer where the sum of the digits of its square is equal to the original number.



// Your task is to develop a program that can efficiently determine whether a given positive integer is a neon number or not,  while also implementing a virtual destructor for appropriate memory management.



// For Example,

// N = 9

// Then, 92=81 => 8+1=9

// So, 9 is a neon number.

// Input format :
// The input consists of an integer n.

// Output format :
// If the number is a Neon number, output: "n is a Neon Number".

// If the number is not a Neon number, output: "n is Not a Neon Number".

// If the input is invalid (not a positive integer), output: "Invalid".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// N ≤ 20

// Sample test cases :
// Input 1 :
// 8
// Output 1 :
// 8 is Not a Neon Number
// Input 2 :
// 1
// Output 2 :
// 1 is a Neon Number
// Input 3 :
// 6543
// Output 3 :
// Invalid
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
using namespace std;

class Main {
public:
   int n1;
   int ans=0;
    Main(int n){
       if(n<0 || n>20){
           cout << "Invalid" << endl;
       }else{
       n1 = n*n;
       while(n1>0){
           int x = n1%10;
           ans+=x;
           n1 = n1/10;
       }
       
       if(ans == n){
           cout << n << " is a Neon Number" << endl;
       }else{
            cout << n << " is Not a Neon Number" << endl;
       }}
    }
    virtual ~Main(){}
};

int main() {
    int n;
    cin >> n;
    Main obj(n);
    return 0;
}