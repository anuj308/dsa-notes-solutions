// Single File Programming Question
// Problem Statement



// Suji is developing a program for a data analysis tool that requires reversing an array of integers and displaying both the original and reversed arrays.



// The program should dynamically allocate memory for the reversed array using the new operator. Write a program to accomplish this task.

// Input format :
// The first line contains an integer n, representing the size of the array.

// The second line contains n space-separated integers, representing the elements of the array.

// Output format :
// If n is positive:

// Print the original array in the format: "Original Array: a1 a2 a3 ... an".

// Print the reversed array in the format: "Reversed Array: an an-1 ... a1".



// If n is less than or equal to zero, Print: "Size should be positive".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 40

// 1 ≤ elements ≤ 103

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Original Array: 1 2 3 4 5 
// Reversed Array: 5 4 3 2 1 
// Input 2 :
// -4
// Output 2 :
// Size should be positive
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    if(n<=0){
        cout << "Size should be positive" << endl;
        return 0;
    }
    
    int* arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cout << "Original Array: ";
    for(int i=0;i<n;i++){
        cout  << arr[i] << " ";
    }
    cout  << endl;
    cout << "Reversed Array: ";
    for(int i=n-1;i>=0;i--){
        cout  << arr[i] << " ";
    }
    
    cout << endl;
    
    delete [] arr;
    return 0;
}