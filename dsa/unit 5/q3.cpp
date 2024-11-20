

// Single File Programming Question
// Problem Statement



// Anu has recently taken up gardening and wants to keep track of the heights of the plants she grows. She decides to use a max heap data structure to maintain the heights, ensuring that the tallest plant is always at the top.



// As she plants new ones, she inserts their heights into the heap and occasionally checks the current maximum height. After planting, she wants to see the heights in the max heap, along with the squared values of each height to calculate the total area they might cover.

// Input format :
// The first line contains an integer n, representing the number of elements.

// The second line contains n space-separated integers, each representing the heights of the plants.

// Output format :
// The first line should display the elements of the max heap in level order.

// The second line should display the squared values of each element in the max heap, also in the same order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ height ≤ 150

// Sample test cases :
// Input 1 :
// 5
// 10 20 5 15 25
// Output 1 :
// 25 20 5 15 10 
// 625 400 25 225 100 
// Input 2 :
// 3
// 30 12 18
// Output 2 :
// 30 12 18 
// 900 144 324 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.



#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to heapify a subtree rooted with node i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to build max heap
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    // Maximum possible size of heap
    const int MAX_SIZE = 16;  // n + 1 (max n is 15)
    int arr[MAX_SIZE];

    // Read number of elements
    int n;
    cin >> n;

    // Read plant heights
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build max heap from initial heights
    buildMaxHeap(arr, n);

    // Print max heap elements
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i < n - 1 ? " " : "");
    }
    cout << endl;

    // Print squared values of max heap elements
    for (int i = 0; i < n; i++) {
        cout << arr[i] * arr[i] << (i < n - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}