// Single File Programming Question
// Problem Statement



// You are given T test cases, each consisting of two integers, 'a' and 'b'. Your task is to calculate 'a' raised to the power of 'b' and output the result for each test case.



// You need to implement the power() function that efficiently calculates the modular exponentiation of 'a' raised to the power of 'b', using recursion and modular arithmetic.



// Note: This kind of question will be helpful in clearing Infosys recruitment.

// Input format :
// The first line of input consists of an integer T, representing the number of test cases.

// Each of the following T lines contains two space-separated integers a and b, where a is the base, and b is the exponent.



// Output format :
// For each test case, the output prints a single integer on a new line, representing the result of 'a' raised to the power of 'b'.

// Code constraints :
// 1 ≤ T ≤ 10

// 0 ≤ a ≤ 200

// 0 ≤ b ≤ 10

// Sample test cases :
// Input 1 :
// 2
// 15 5
// 100 5
// Output 1 :
// 759375
// 10000000000
// Input 2 :
// 1
// 7 5
// Output 2 :
// 16807
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program ou
#include <bits/stdc++.h>
using namespace std;

long long power(long long a,long long b){
    
    if(b==1) return a;
    
    return a * power(a,b-1);
    
}


int main(){
    int n;
    cin >> n;
    
    long long aa[n];
    long long bb[n];
    for(int i=0;i<n;i++){
        cin >> aa[i];
        cin >> bb[i];
    }
    
    for(int i=0;i<n;i++){
        cout << power(aa[i],bb[i]) << endl;
    }
    
    return 0;
}