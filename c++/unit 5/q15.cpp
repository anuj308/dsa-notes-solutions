// Single File Programming Question
// Problem Statement



// Alice wants to design a program that identifies palindrome numbers within an array of integers. Create a program that accomplishes this task while dynamically managing memory allocation using new and delete.



// Note: It is assumed that at least one element in the array is a palindromic number.

// Input format :
// The first line of input consists of an integer N, representing the size of the array.

// The second line consists of N space-separated integers, representing the elements of the array.

// Output format :
// The output displays the palindrome numbers that are present in the array separated by space.



// Note: Beginning zeros are ignored while calculating the palindrome as shown in the sample test case #3.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ elements of the array ≤ 109

// Sample test cases :
// Input 1 :
// 5
// 121 12321 456 789 12121
// Output 1 :
// 121 12321 12121 
// Input 2 :
// 3
// 45678 1234321 987654
// Output 2 :
// 1234321 
// Input 3 :
// 3
// 111 010 100
// Output 3 :
// 111 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <iostream>
#include <string>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    string str = to_string(num);  // Convert the number to a string
    int left = 0, right = str.length() - 1;
    
    // Check if the string is the same forwards and backwards
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

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
    
    bool foundPalindrome = false; // Flag to track if we find any palindromes
    
    // Step 4: Iterate over the array and check for palindromes
    for (int i = 0; i < N; ++i) {
        if (isPalindrome(arr[i])) {
            if (foundPalindrome) {
                cout << " ";  // Print space before the next palindrome number
            }
            cout << arr[i];
            foundPalindrome = true;
        }
    }
    
    // Step 5: Clean up dynamically allocated memory
    delete[] arr;
    
    return 0;
}
