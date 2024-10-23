// Single File Programming Question
// Problem Statement



// Imagine you are a software developer working for a logistics company. Your task is to create a program that can efficiently sort a list of packages based on their weights using the Quick-Sort algorithm. Each package has a weight value associated with it.



// The program should take an array of package objects as input, where each object contains the weight of a package. The program should then sort the array in ascending order based on the weights of the packages.

// Input format :
// The first line of input consists of an integer N, representing the number of packages.

// The second line consists of N integers, representing the weight of the packages, separated by space.

// Output format :
// The output displays N integers representing the weights of the packages after they have been sorted in ascending order, separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 10

// 1 ≤ weight ≤ 100

// Sample test cases :
// Input 1 :
// 4
// 15 25 35 10
// Output 1 :
// 10 15 25 35 
// Input 2 :
// 3
// 120 60 80
// Output 2 :
// 60 80 120 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) 
{
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)  {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}