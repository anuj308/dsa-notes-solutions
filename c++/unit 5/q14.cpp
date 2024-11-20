// Single File Programming Question
// Problem Statement



// Emma is working on a project that involves analyzing an array of integers to find elements that are divisible by both 3 and 5. If no such elements exist, the program should display 0. She needs to implement a program that efficiently extracts the relevant elements from the array using dynamic memory allocation. 



// Help Emma to complete this task.

// Input format :
// The first line of input consists of an integer N, representing the size of the array.

// The second line consists of N space-separated integers, representing the elements of the array.

// Output format :
// The output displays the elements that are divisible by both 3 and 5, separated by spaces.If no such number exists, 0 should be displayed.



// ﻿Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 15

// 0 ≤ elements of the array ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 15 30 10 45 6 9
// Output 1 :
// 15 30 45 
// Input 2 :
// 8
// 9 18 27 45 30 36 21 12
// Output 2 :
// 45 30 
// Input 3 :
// 10
// 75 120 90 99 25 50 15 3 5 6
// Output 3 :
// 75 120 90 15 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

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
    
    bool found = false;  // Flag to check if we found any divisible element
    
    // Step 4: Iterate through the array and check for divisibility by both 3 and 5
    for (int i = 0; i < N; ++i) {
        if (arr[i] % 15 == 0) {
            if (found) {
                cout << " ";  // Print a space before the next element
            }
            cout << arr[i];
            found = true;
        }
    }
    
    // Step 5: If no elements were found, output 0
    if (!found) {
        cout << 0;
    }
    
    // Step 6: Clean up the dynamically allocated memory
    delete[] arr;
    
    return 0;
}
