// Single File Programming Question
// Problem Statement



// You are provided with a collection of numbers, each represented by an array of integers. However, there's a unique scenario: within this array, one element occurs an odd number of times, while all other elements occur an even number of times. Your objective is to identify and return the element that occurs an odd number of times in this arrangement.



// Utilize mid-square hashing by squaring elements and extracting middle digits for hash codes. Implement a hash table for efficient integer occurrence tracking.



// Note: Hash function: squared = key * key.



// Example



// Input:

// 7

// 2 2 3 3 4 4 5



// Output:

// 5



// Explanation

// The hash function and the calculated hash indices for each element are as follows:

// 2 -> hash(2*2) % 100 = 4

// 3 -> hash(3*3) % 100 = 9

// 4 -> hash(4*4) % 100 = 16

// 5 -> hash(5*5) % 100 = 25



// The hash table records the occurrence of each element's hash index:

// Index 4: 2 occurrences

// Index 9: 2 occurrences

// Index 16: 2 occurrences

// Index 25: 1 occurrence



// Among the elements, the integer 5 occurs an odd number of times (1 occurrence) and satisfies the condition of the problem. Therefore, the program outputs 5.

// Input format :
// The first line of input consists of an integer N, representing the size of the array.

// The second line consists of N space-separated integers, representing the elements of the array.

// Output format :
// The output prints a single integer representing the element that occurs an odd number of times.

// If no such element exists, print -1.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ array elements ≤ 150

// Sample test cases :
// Input 1 :
// 7
// 2 2 3 3 4 4 5
// Output 1 :
// 5
// Input 2 :
// 15
// 11 22 33 44 55 66 77 11 22 33 44 55 66 77 88
// Output 2 :
// 88
// Input 3 :
// 10
// 3 3 4 4 5 5 6 6 7 7
// Output 3 :
// -1
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100w


// You are using GCC
unsigned int hash(int key, int tableSize) {
    int squared = key * key;
    int numDigits = 0;
    int temp = squared;

    //Type your code here


    int middleDigits = (numDigits / 2);
    int divisor = 1;
    for (int i = 0; i < middleDigits; i++) {
        divisor *= 10;
    }
    return (squared / divisor) % tableSize;
}

int getOddOccurrence(int arr[], int size) {
    //Type your code here
}


int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", getOddOccurrence(arr, n));

    return 0;
}