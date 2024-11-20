// Single File Programming Question
// Problem Statement



// Aiden is working on organizing his collection of unique integers, which represent the number of books he has in different categories. He wants to create a min heap out of these integers so that he can quickly access the category with the smallest number of books. Additionally, Aiden is curious about the sum of all even and odd numbers in his collection.



// Write a program that builds a min heap from Aiden's collection of numbers, displays the min heap, and calculates the sum of even and odd numbers separately.

// Input format :
// The first line contains an integer representing n representing the number of integers in Aiden's collection.

// The second line contains n space-separated integers representing the number of books in each category.

// Output format :
// The first line displays the min heap structure, where the smallest number of books is at the root.

// The second line displays the sum of all even numbers in the collection.

// The third line displays the sum of all odd numbers in the collection.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ no.of. books ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 2 4 1 5 9
// Output 1 :
// Min Heap: 1 4 2 5 9 
// Sum of even elements: 6
// Sum of odd elements: 15
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to heapify a subtree rooted with node i
void minHeapify(int arr[], int n, int i) {
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // Check if left child exists and is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // Check if right child exists and is smaller than current smallest
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not the root, swap and continue heapifying
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to insert a new element into the min heap
void insertElement(int heap[], int &size, int value, int &sumEven, int &sumOdd) {
    // Increase the size of the heap
    size++;
    heap[size - 1] = value; // Insert the new value at the end

    // Update the sums
    if (value % 2 == 0) {
        sumEven += value;
    } else {
        sumOdd += value;
    }

    // Fix the min heap property if it is violated
    int i = size - 1;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to display the min heap
void displayMinHeap(int heap[], int size) {
    cout << "Min Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << (i < size - 1 ? " " : "");
    }
    cout << endl;
}

// Function to calculate sum of even numbers
int sumOfEvenNumbers(int arr[], int n) {
    int evenSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        }
    }
    return evenSum;
}

// Function to calculate sum of odd numbers
int sumOfOddNumbers(int arr[], int n) {
    int oddSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            oddSum += arr[i];
        }
    }
    return oddSum;
}

int main() {
    const int MAX_SIZE = 100;  // Maximum size of the heap
    int heap[MAX_SIZE];
    int size = 0;              // Current size of the heap
    int sumEven = 0;          // Sum of even numbers
    int sumOdd = 0;           // Sum of odd numbers

    // Read number of elements
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Read elements into the heap
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, sumEven, sumOdd);
    }

    // Display the min heap
    displayMinHeap(heap, size);

    // Print sum of even and odd numbers
    cout << "Sum of even elements: " << sumEven << endl;
    cout << "Sum of odd elements: " << sumOdd << endl;

    return 0;
}