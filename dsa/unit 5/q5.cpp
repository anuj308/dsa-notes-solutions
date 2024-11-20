
// Input format :
// The first line contains an integer n, representing the number of elements John will input.

// The second line contains n space-separated integers, representing the values John enters.

// Output format :
// The first line displays the max heap in a single line, with elements separated by spaces.

// The second line displays the count of even elements in the heap.

// The third line displays the count of odd elements in the heap.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 1000

// Sample test cases :
// Input 1 :
// 6
// 75 24 63 56 19 53
// Output 1 :
// Max Heap: 75 56 63 24 19 53 
// Even elements count: 2
// Odd elements count: 4
// Input 2 :
// 5
// 85 60 20 56 70
// Output 2 :
// Max Heap: 85 70 20 56 60 
// Even elements count: 4
// Odd elements count: 1
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.




#include <iostream>
using namespace std;

// Maximum size of the heap
const int MAX_SIZE = 10;

// Function to swap two integers
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
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

// Function to insert an element into max heap and update even/odd counts
void insertIntoMaxHeap(int heap[], int &size, int value, int &evenCount, int &oddCount) {
    // Check if heap is full
    if (size >= MAX_SIZE) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }

    // Insert the new element at the end
    heap[size] = value;

    // Update even/odd counts
    if (value % 2 == 0) {
        evenCount++;
    } else {
        oddCount++;
    }

    int current = size;
    size++;

    // Fix the max heap property
    while (current > 0 && heap[(current - 1) / 2] < heap[current]) {
        // Swap with parent if the current element is larger
        swap(heap[current], heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Function to build max heap
void buildMaxHeap(int heap[], int &size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

// Function to print max heap
void printMaxHeap(int heap[], int size) {
    cout << "Max Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << (i < size - 1 ? " " : "");
    }
    cout << endl;
}

// Function to count even and odd numbers
void countEvenOdd(int heap[], int size, int &evenCount, int &oddCount) {
    evenCount = 0;
    oddCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (heap[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
}

int main() {
    // Heap array and size
    int heap[MAX_SIZE];
    int size = 0;
    
    // Variables to count even and odd numbers
    int evenCount = 0;
    int oddCount = 0;
    
    // Read number of elements
    int n;
    cin >> n;
    
    // Read and insert elements
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(heap, size, value, evenCount, oddCount);
    }
    
    // Ensure max heap property
    buildMaxHeap(heap, size);
    
    // Print max heap
    printMaxHeap(heap, size);
    
    // Print counts
    cout << "Even elements count: " << evenCount << endl;
    cout << "Odd elements count: " << oddCount << endl;
    
    return 0;
}