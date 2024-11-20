// Single File Programming Question
// Problem Statement



// Liam wants to create a program that identifies and counts the number of positive, negative, and zero elements in a dynamically allocated array. 



// Help Liam achieve this by designing a program using dynamic memory allocation.

// Input format :
// The first line of input consists of an integer N, representing the size of the array.

// The second line consists of N space-separated integers, representing the elements of the array.

// Output format :
// The first line of output displays the count of the positive elements in the array with the prefix "Positive count: "

// The second line displays the count of the positive elements in the array with the prefix "Negative count: "

// The third line displays the count of the positive elements in the array with the prefix "Zero count: "



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 100

// -200 ≤ elements of the array ≤ 200

// Sample test cases :
// Input 1 :
// 8
// 2 -1 0 3 -4 0 5 -7
// Output 1 :
// Positive count: 3
// Negative count: 3
// Zero count: 2
// Input 2 :
// 6
// 0 5 0 8 0 4
// Output 2 :
// Positive count: 3
// Negative count: 0
// Zero count: 3
// Input 3 :
// 5
// -1 -2 3 4 5
// Output 3 :
// Positive count: 3
// Negative count: 2
// Zero count: 0
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// by chatgpt

#include <iostream>
using namespace std;

int main() {
    int N;
    
    // Step 1: Input the size of the array
    cin >> N;
    
    // Step 2: Dynamically allocate memory for the array
    int* arr = new int[N];
    
    // Step 3: Input the elements into the array
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    // Step 4: Initialize counters for positive, negative, and zero elements
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;
    
    // Step 5: Iterate through the array and count positive, negative, and zero elements
    for (int i = 0; i < N; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }
    
    // Step 6: Output the counts in the specified format
    cout << "Positive count: " << positiveCount << endl;
    cout << "Negative count: " << negativeCount << endl;
    cout << "Zero count: " << zeroCount << endl;
    
    // Step 7: Free the dynamically allocated memory
    delete[] arr;
    
    return 0;
}
