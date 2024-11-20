// Single File Programming Question
// Problem Statement



// Emma is a mathematics enthusiast who wants to analyze prime numbers for her research. She collects several integers and aims to create a max heap that only includes the prime numbers from her collection.



// After inserting the prime numbers into the max heap, she wants to visualize the max heap structure to understand the hierarchy of these numbers.



// Note

// A prime number is a natural number greater than one that has no positive divisors other than one and itself.

// Input format :
// The first line contains an integer n, representing the number of integers Emma collected.

// The second line consists of n space-separated integers, which are the values Emma wants to analyze.

// Output format :
// The output consists of two parts:

// If any prime numbers were inserted into the max heap, display them as integers separated by a space.
// If a number is not prime, print a message in the format: "<value> is not a prime number".


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 3 2 4 5
// Output 1 :
// 1 is not a prime number
// 4 is not a prime number
// Max Heap: 5 2 3 
// Input 2 :
// 6
// 17 7 5 11 13 19
// Output 2 :
// Max Heap: 19 13 17 7 11 5 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.





#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

// Function to heapify a subtree rooted with node i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to insert a value into max heap
void insertIntoMaxHeap(int arr[], int *n, int value) {
    // Add the new element at the end
    arr[*n] = value;
    (*n)++;

    // Heapify from the last non-leaf node to the root
    int i = *n / 2 - 1;
    while (i >= 0) {
        maxHeapify(arr, *n, i);
        i--;
    }
}

// Function to print max heap
void printMaxHeap(int arr[], int n) {
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    // Input size of array
    int n;
    cin >> n;

    // Input array
    int input[10];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // Array to store prime numbers
    int primeNumbers[10];
    int primeCount = 0;

    // Check and separate prime numbers
    for (int i = 0; i < n; i++) {
        if (isPrime(input[i])) {
            insertIntoMaxHeap(primeNumbers, &primeCount, input[i]);
        } else {
            cout << input[i] << " is not a prime number" << endl;
        }
    }

    // Print max heap if prime numbers exist
    if (primeCount > 0) {
        printMaxHeap(primeNumbers, primeCount);
    } else {
        // No prime numbers found
        cout << "No prime numbers";
    }

    return 0;
}