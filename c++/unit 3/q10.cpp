// Single File Programming Question
// Problem Statement



// Ragul wants to write a program to calculate the sum of a series of numbers and store them in a file. He wants to take input from the user for the number of elements in the series and the values of each element. Calculate the sum of the numbers and store them in a file named "sample.txt".

// Input format :
// The first line of the input consists of n, representing the number of values to be given.

// The second line of the input consists of n space-separated integers.

// Output format :
// The output displays an integer representing the sum of the given integers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// 15
// Input 2 :
// 3
// 3 2 1
// Output 2 :
// 6
// Note :

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


int main(){
    int n,x;
    cin >> n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> x;
        sum+=x;
    }
    
    ofstream file;
    file.open("sample.txt",ios::app);
    file << sum;
    file.close();
    cout << sum;
    
    return 0;
}
