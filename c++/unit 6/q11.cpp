// // 

// Single File Programming Question
// Problem Statement



// Mithu is a software developer working on a program to analyze a list of numbers. Write a code that prints the composite numbers from an integer array.



// Hint: Use the remove_copy_if() algorithm.

// Input format :
// The first line contains a single integer n, representing the number of integers in the array a.

// The second line contains n space-separated integers on a single line, representing the elements of the array a.

// Output format :
// If the input n is not within the valid range (1 to 15, inclusive), the output prints "-1".

// Otherwise, the output will display a single line containing the composite numbers (non-prime numbers) in the array a, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 15

// 1 <= a[i] <= 1000: Each element in the array a will be an integer within the range of 1 to 1000 (inclusive).

// Sample test cases :
// Input 1 :
// 9
// 4 5 12 65 89 57 584 52 111
// Output 1 :
// Composite numbers: 4 12 65 57 584 52 111 
// Input 2 :
// -2
// Output 2 :
// -1
// Code Size : 1024 kb
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    
    for(int i=2;i<x;i++){
        if(x%i==0){
            return true;
        }
    }
    return false;
}
int main(){
    
    int n;
    cin >> n;
    
    if(n<=0 || n>15){
        cout << "-1" << endl;
    }else{
        int arr[n];
        int ans[n];
        int p=0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]>1 && isPrime(arr[i])){
                ans[p]=arr[i];
                p++;
            }
        }
        
        cout << "Composite numbers: ";
        for(int k=0;k<p;k++){
            cout << ans[k] << " ";
        }
    }
    
    return 0;
}


// by chatgpt write ans with that function wATCH IT 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 0 and 1 are not prime
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Helper function to check if a number is composite
bool isComposite(int num) {
    return num > 1 && !isPrime(num); // Composite if not prime and greater than 1
}

int main() {
    int n;
    cin >> n;

    // Input validation for n
    if (n < 1 || n > 15) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Create a vector to store composite numbers
    vector<int> composites;

    // Use remove_copy_if to copy only composite numbers to the 'composites' vector
    remove_copy_if(arr.begin(), arr.end(), back_inserter(composites), isComposite);

    // Output the composite numbers
    cout << "Composite numbers: ";
    for (int num : composites) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
