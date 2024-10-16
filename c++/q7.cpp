// Single File Programming Question
// Problem Statement



// You are developing a text processing application that requires removing duplicate characters from a given string. Your task is to write a program that takes a string as input and removes all duplicate characters from it. 



// After removing the duplicate characters, the program should print the modified string. Write a program to implement this functionality using modifiers of string class. 

// Input format :
// The input consists of a string str.

// Output format :
// The output prints the updated string after removing the duplicates.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 < Length of the string < 100

// The characters are case-senstive.

// Sample test cases :
// Input 1 :
// ABABCDE
// Output 1 :
// ABCDE
// Input 2 :
// 123412Qq
// Output 2 :
// 1234Qq
// Input 3 :
// LAZY
// Output 3 :
// LAZY
// Note :

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string str;
    
    getline(cin,str);
    
    int t=0;
    int t1=0;
    string ans;
    int c=0;
    while(t<str.length()){
        char a = str[t];
        while(t1<ans.length()){
            if(a==ans[t1]){
                c++;
            }
            t1++;
        }
        if(c==0){
            ans.push_back(a);
        }
        t1=0;
        c=0;
        t++;
    }
    
    cout << ans;
   
    return 0;
}