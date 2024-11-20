// Single File Programming Question
// Problem Statement



// Maya is conducting a survey to analyze customer feedback ratings for a new product. She collects ratings from a number of customers and wants to sort these ratings using the heap sort algorithm to identify trends. Additionally, Maya is interested in calculating the median rating to understand the central tendency of customer satisfaction.



// Your task is to help Maya sort the ratings in ascending order using heap sort and then calculate and display the median value. Finally, present both the sorted ratings and the median in a clear format.

// Input format :
// The first line contains an integer n, representing the number of customer ratings.

// The second line contains n space-separated integers representing the customer ratings.

// Output format :
// The first line prints a single line containing the sorted ratings as space-separated integers.

// The second line prints a second line displaying the median rating formatted to two decimal places as a double value.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ ratings ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 9 5 2
// Output 1 :
// 2 5 9 
// Median: 5.00
// Input 2 :
// 6
// 17 7 5 10 11 22
// Output 2 :
// 5 7 10 11 17 22 
// Median: 10.50
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <iostream>
#include <iomanip>
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

// Function to calculate median of sorted array
double calculateMedian(int arr[], int n) {
    // If number of elements is odd
    if (n % 2 != 0) {
        return (double)arr[n/2];
    }
    
    // If number of elements is even
    // Take average of two middle elements
    return (double)(arr[n/2 - 1] + arr[n/2]) / 2.0;
}

// Function to print array in reverse order
void printArrayReverse(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Maximum possible size of array
    const int MAX_SIZE = 10;
    int ratings[MAX_SIZE];
    int n;

    // Input number of ratings
    cin >> n;

    // Input ratings
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    // Sort ratings using heap sort in descending order
    heapSort(ratings, n);

    // Print sorted ratings in reverse (descending) order
    printArrayReverse(ratings, n);

    // Calculate and print median
    double median = calculateMedian(ratings, n);
    cout << "Median: " << fixed << setprecision(2) << median << endl;

    return 0;
}