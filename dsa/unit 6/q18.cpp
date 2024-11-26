
// 5
// Answered
// 3/5
// Bookmarked
// 0/5
// Skipped
// 0/5
// Not Viewed
// 2/5
// Saved in Server
// 3/5
// View More
// Question No : 3 / 5
// bookmarkIcon
// Single File Programming Question
// Problem Statement



// Write a code to implement Quadratic probing in Hashing.



// If the slot hash(x) % S is full, then we try (hash(x) + 1*1) % S.

// If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S.

// If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S.



// This process is repeated for all the values of i until an empty slot is found.

// Input format :
// The first line of input consists of the size of the array.

// The second line of input consists of the array of elements separated by space.

// The last line of input consists of the size of the hashtable.

// Output format :
// The output prints the space separated array elements after implementing the conditions mentioned in the problem statement.



// Refer to the sample input and output for formatting specifications.

// Sample test cases :
// Input 1 :
// 7
// 50 700 76 85 92 73 101
// 7
// Output 1 :
// 700 50 85 73 101 92 76 
// Input 2 :
// 4
// 76 101 50 700
// 3
// Output 2 :
// 50 76 101 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// only two tescase passed 


#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin >> n;
    int keys[n];
    for(int i=0;i<n;i++){
        cin >> keys[i];
    }
    int tableSize;
    cin >> tableSize;
    int store[tableSize];
    
    for(int i=0;i<tableSize;i++){//inialisize the table
        store[i]=-1;
    }
    
    for(int i=0;i<tableSize;i++){
        int hashedIndex = keys[i] % tableSize;
        int c=1;
        int hashed=hashedIndex;
        while(store[hashed]!=-1){
            hashed = (hashedIndex + c * c) % tableSize;
            c++;
        }
        store[hashed] = keys[i];
    }

    for(int i=0;i<tableSize;i++){
        if(store[i]!=-1){
            cout << store[i] << " ";
        }
    }
    return 0;
}