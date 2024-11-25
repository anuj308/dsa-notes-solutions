// Single File Programming Question
// Problem Statement



// Ashwin is tasked with writing a program to calculate the dot product of two vectors of varying data types: integers and double values. The program should prompt the user to enter the size of the vectors (number of elements) and then ask for the elements of both vectors.



// After obtaining the input, the program should compute the dot product for both types of vectors and display the results separately. Write a program to accomplish this task.



// Note: This kind of question will help in clearing HCL recruitment.

// Input format :
// The first line of the input represents the number of elements n.

// The second line contains n space-separated integers representing the elements of the first vector, v1.

// The third line contains n space-separated integers representing the elements of the second vector, v2.

// The fourth line contains n space-separated double values representing the elements of the third vector, v3.

// The fifth line contains n space-separated double values representing the elements of the fourth vector, v4.

// Output format :
// The output prints the dot product of an integer and double value vectors in separate lines.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1<=n<=100

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// 4 5 6
// 1.5 2.5 3.5
// 4.5 5.5 6.5
// Output 1 :
// Dot product of integer vectors: 32
// Dot product of double value vectors: 43.25
// Input 2 :
// 2
// 2 4
// 1 3
// 1.25 2.5
// 2.5 1.25
// Output 2 :
// Dot product of integer vectors: 14
// Dot product of double value vectors: 6.25
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr1[2][n];
    double arr2[2][n];
    
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> arr1[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> arr2[i][j];
        }
    }
    int ans1=0;
    double ans2=0.0;
    
    for(int k=0;k<n;k++){
        ans1+= arr1[0][k]*arr1[1][k];
        ans2+= arr2[0][k]*arr2[1][k];
    }
    
    cout << "Dot product of integer vectors: " << ans1 << endl;
    cout << "Dot product of double value vectors: " << ans2 << endl;
    return 0;
}