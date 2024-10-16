// Single File Programming Question
// Problem Statement



// Sri wants to write a program that calculates the sum of two numbers and stores the result in a file named "sum.txt". Sri needs to implement the program using file stream operations. If there is an error opening the file, the program displays an error message on the console.



// Note: Sri should ensure that the program has write permissions for the directory where it is executed to create and write to the "sum.txt" file.

// Input format :
// The input consists of two space-separated integers n1 and n2, representing the values.

// Output format :
// The first line displays the indicate the message "Sum successfully written to the file 'sum.txt'."

// The second line displays the sum of the given two input values.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n1, n2 ≤ 50000

// Sample test cases :
// Input 1 :
// 3 5
// Output 1 :
// Sum successfully written to the file 'sum.txt'.
// Sum: 8
// Input 2 :
// 100 23
// Output 2 :
// Sum successfully written to the file 'sum.txt'.
// Sum: 123

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


int main(){
    int x,y;
    cin >> x;
    cin >> y;
    ofstream ofile("sum.txt");
    int sum = x+y;
    ofile << sum;
    ofile.close();
    cout << "Sum successfully written to the file \'sum.txt\'.\n";
    cout << "Sum: " << sum;
    return 0;
}