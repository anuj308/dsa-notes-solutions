// Single File Programming Question
// Problem Statement



// Harish has two lists of integers, one representing the number of items sold in two different months. He wants to merge these two lists and sort the combined data to understand overall sales trends. Harish decides to use a sorting algorithm that structures the data into a heap to simplify the sorting process.



// Your task is to help Harish by merging the two lists and then sorting the combined list in ascending order. Finally, display the sorted list of sales for Harish.

// Input format :
// The first line contains an integer n1, representing the number of items sold in the first month.

// The second line contains n1 space-separated integers representing the sales data for the first month.

// The third line contains an integer n2, representing the number of items sold in the second month.

// The fourth line contains n2 space-separated integers representing the sales data for the second month.

// Output format :
// The output prints a single line containing the combined and sorted sales data as space-separated integers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n1, n2 ≤ 10

// 1 ≤ sales lists ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 6 4 3 8 7
// 3
// 9 5 2
// Output 1 :
// 2 3 4 5 6 7 8 9 
// Input 2 :
// 5
// 3 9 2 6 8
// 5
// 17 7 5 10 11
// Output 2 :
// 2 3 5 6 7 8 9 10 11 17 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find largest among root, left child and right child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort in descending order
void heapSort(int arr[], int n) {
    // Build max heap
    // Start from last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to merge two arrays and sort in descending order
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    // Copy elements from first array
    for (int i = 0; i < n1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements from second array
    for (int i = 0; i < n2; i++) {
        result[n1 + i] = arr2[i];
    }

    // Sort the combined array using heap sort in descending order
    heapSort(result, n1 + n2);
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_SIZE = 20;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE];
    int n1, n2;

    // Input for first array
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for second array
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Merge and sort arrays
    mergeArrays(arr1, n1, arr2, n2, result);

    // Print merged and sorted array in descending order
    printArray(result, n1 + n2);

    return 0;
}