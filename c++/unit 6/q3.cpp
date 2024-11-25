// Single File Programming Question
// Problem Statement



// You are assigned to create a program that calculates the sum of positive numbers in an array provided by the user. The program should also handle exceptional situations when a negative number is encountered in the array. 



// Example



// Input:

// 5

// 1 2 3 4 5



// Output:

// The sum is: 15



// Explanation:

// Suppose the array inputs are 1, 2, 3, -4, 5. Here we got a negative number at an index value of 3 and the sum is "6" before the index of 3.

// Input format :
// The first line consists of an integer n, representing the size of an array.

// The second line consists of n space-separated integers, representing the array elements.

// Output format :
// The output prints the sum of the given array until a negative integer is encountered.

// If a negative integer is encountered, the output prints the message along with the index. (0-based indexing)



// Refer to the sample outputs for the formatting specifications.

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// The sum is : 15
// Input 2 :
// 5
// 1 2 3 -4 5
// Output 2 :
// Negative number found at index 3
// The sum is : 6
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// Marks : 10
// Negative Marks : 0
// image
// Fill your code here
// C++ (17)
// theme
// instruction
//     }


// Result
// 5/5 Testcases Passed#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    int neg = 0;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    for(int i=0; i<n;i++){
        if(arr[i]<0){
            cout << "Negative number found at index " << i << endl;
            break;
        }
        sum +=arr[i];
    }

    cout <<  "The sum is : " << sum << endl;
    
    return 0;
}
