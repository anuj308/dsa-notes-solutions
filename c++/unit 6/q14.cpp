// Single File Programming Question
// Problem Statement



// Reby is developing a program that simulates a simple list of numbers. The program allows users to input 'n' integers and store them in a vector. After that, the user enters a position ('pos') to access the element at that position in the vector. To handle potential errors, you have to implement exception handling for accessing elements in the vector.



// Note: This kind of question will help in clearing HCL recruitment.

// Input format :
// The first line consists of an integer n, representing the total number of inputs.

// The second line consists of n space-separated integers.

// The third line consists of an integer, representing the position to fetch.

// Output format :
// The output displays the element fetched from the given position (0-based indexing).

// The program will display an appropriate error message if the given position is not within the range.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// n > 0

// 0 <= position <= n-1

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// 2
// Output 1 :
// 30
// Input 2 :
// 5
// 10 20 30 40 50
// 6
// Output 2 :
// Exception occurred!
// Not possible to fetch index 6
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    
    if(x<0 || x>=n){
        cout << "Exception occurred!" << endl;
        cout << "Not possible to fetch index " << x;
    }else{
        cout << arr[x] ;
    }
    return 0;
}