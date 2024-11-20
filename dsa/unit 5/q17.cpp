
// Single File Programming Question
// Problem Statement



// Liam is a data analyst who is working on optimizing a list of numbers for further analysis. He decides to create a min heap from the integers he collects, as it allows him to efficiently retrieve the smallest number at any time.



// After inserting the numbers into the min heap, he wants to visualize its structure and also find the maximum value among the elements.

// Input format :
// The first line contains an integer n, representing the number of integers Liam collected.

// The second line consists of n space-separated integers, which are the values Liam wants to insert into the min heap.

// Output format :
// The output consists of two parts:

// Display the elements of the min heap as integers separated by a space.
// Display the maximum value among the elements in the min heap in the format: "Maximum: <value>".


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 3 9 2 6 8
// Output 1 :
// 2 6 3 9 8 
// Maximum: 9
// Input 2 :
// 8
// 25 15 17 32 23 5 12 8
// Output 2 :
// 5 8 12 23 25 17 15 32 
// Maximum: 32
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of 

#include <iostream>
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

// Function to display min heap
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Function to find maximum value in the heap
int findMaxValue(int heap[], int size) {
    if (size == 0) return -1; // Return -1 if heap is empty

    int maxValue = heap[0];
    for (int i = 1; i < size; i++) {
        if (heap[i] > maxValue) {
            maxValue = heap[i];
        }
    }
    return maxValue;
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

    // Find and display maximum value
    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}