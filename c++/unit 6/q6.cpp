// Single File Programming Question
// Problem Statement



// Akshaya is developing a program to calculate the sum of elements in arrays of different data types. Create a program that calculates the sum of elements in two different arrays of integers and double-point numbers using a template function named arraySum. The program should first prompt the user to enter the size of the arrays, followed by the elements of the two arrays.



// The arraySum function should take two parameters: the array of any data type and the size of the array, and it should return the sum of all the elements in the array.



// The program should print the sum of elements in the integer array and the double-point array separately.

// Input format :
// The first line consists of an integer n, representing the size of the array.

// The second line consists of n space-separated integers, representing the array of integer values.

// The third line consists of n space-separated double values, representing the array of double values.

// Output format :
// The first line prints an integer, representing the sum of an integer array.

// The second line prints a double value, representing the sum of the double-point array.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 1000: The size of the arrays will be between 1 and 1000 (inclusive).

// For the integer array arr1, -109 <= arr1[i] <= 109

// For the floating-point array arr2, -109 <= arr2[i] <= 109

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 1.5 2.5 3.5 4.5 5.5
// Output 1 :
// 15
// 17.5
// Input 2 :
// 3
// 10 20 30
// 1.1 2.2 3.3
// Output 2 :
// 60
// 6.6
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include<iostream>
using namespace std;

template<class T>
T arraySum(T arr[], int n) {
    T sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int arr1[n];
    double arr2[n];

    
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

   
    for(int i=0; i<n; i++) {
        cin >> arr2[i];
    }

    cout << arraySum(arr1, n) << endl;
    cout << arraySum(arr2, n);

    return 0;
}