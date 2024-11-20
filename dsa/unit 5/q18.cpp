// Single File Programming Question
// Problem Statement



// Tao is developing a program to manage a min-heap data structure for a small application. The program should enable Tao to insert elements, remove the root node, find the maximum value in the heap, and calculate the sum and average of all nodes in the heap.



// The program must ensure that the min-heap property is maintained throughout these operations.

// Input format :
// The first line contains an integer n, representing the number of elements to be inserted into the min-heap.

// The second line consists of n space-separated integers, representing which are the values to be inserted into the heap.

// Output format :
// The output displays the following format:

// Print the elements of the min-heap in order, separated by spaces, on a single line.
// Print the value of the root node after removing it.
// Print the maximum value present in the heap after the removal operation.
// Print the sum of all remaining nodes in the heap.
// Print the average of all remaining nodes in the heap, rounded to two decimal places.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 10

// Sample test cases :
// Input 1 :
// 5
// 6 4 3 7 8
// Output 1 :
// Min Heap: 3 6 4 7 8 
// Root node: 3
// Maximum value: 8
// Sum of nodes: 25
// Average of nodes: 6.25
// Input 2 :
// 5
// 3 9 2 6 8
// Output 2 :
// Min Heap: 2 6 3 9 8 
// Root node: 2
// Maximum value: 9
// Sum of nodes: 26
// Average of nodes: 6.50
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to perform min heapify
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find smallest among root, left child, and right child
    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If smallest is not root, swap and continue heapifying
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Function to insert element into min heap
void insertElement(int heap[], int &size, int value, int capacity) {
    // Check if heap is full
    if (size >= capacity) return;

    // Insert new element at the end
    heap[size] = value;
    int current = size;
    size++;

    // Restore min heap property
    while (current > 0 && heap[(current - 1) / 2] > heap[current]) {
        swap(heap[(current - 1) / 2], heap[current]);
        current = (current - 1) / 2;
    }
}

// Function to remove and return root (minimum element)
int removeRoot(int heap[], int &size) {
    if (size <= 0) return -1;

    // Store the root value to return
    int root = heap[0];

    // Replace root with last element
    heap[0] = heap[size - 1];
    size--;

    // Restore min heap property
    minHeapify(heap, size, 0);

    return root;
}

// Function to find maximum value in the heap
int findMaxValue(int heap[], int size) {
    if (size == 0) return -1;

    int maxValue = heap[0];
    for (int i = 1; i < size; i++) {
        if (heap[i] > maxValue) {
            maxValue = heap[i];
        }
    }
    return maxValue;
}

// Function to calculate sum of nodes
int calculateSum(int heap[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += heap[i];
    }
    return sum;
}

// Function to display min heap
void displayMinHeap(int heap[], int size) {
    cout << "Min Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_CAPACITY = 10;
    int heap[MAX_CAPACITY];
    int size = 0;

    // Read number of elements
    int n;
    cin >> n;

    // Read and insert elements
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, MAX_CAPACITY);
    }

    // Build min heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }

    // Display min heap
    displayMinHeap(heap, size);

    // Remove root and display
    int root = removeRoot(heap, size);
    cout << "Root node: " << root << endl;

    // Find and display maximum value
    int maxValue = findMaxValue(heap, size);
    cout << "Maximum value: " << maxValue << endl;

    // Calculate and display sum
    int sum = calculateSum(heap, size);
    cout << "Sum of nodes: " << sum << endl;

    // Calculate and display average
    double average = static_cast<double>(sum) / size;
    cout << fixed << setprecision(2) << "Average of nodes: " << average << endl;

    return 0;
}