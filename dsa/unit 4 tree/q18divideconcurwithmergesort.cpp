// Single File Programming Question
// Problem Statement



// Sam needs to sort an array of integers using the divide-and-conquer method. He wants to implement the merge sort algorithm, displaying the array after each iteration to track the sorting process. 



// Assist him in writing a program that divides the array, merges it back, and prints the array.

// Input format :
// The first line of input consists of an integer n, denoting the array size.

// The second line consists of n space-separated integers, representing the array of elements.

// Output format :
// The first line of output prints the given array.

// The following lines print the sorted array, after each iteration.

// The last line of output prints the final sorted array.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 0 ≤ array elements ≤ 50

// Sample test cases :
// Input 1 :
// 6
// 4 1 5 3 2 6
// Output 1 :
// Given Array
// 4 1 5 3 2 6 
// After iteration 1
// 1 4 5 3 2 6 
// After iteration 2
// 1 4 5 3 2 6 
// After iteration 3
// 1 4 5 2 3 6 
// After iteration 4
// 1 4 5 2 3 6 
// After iteration 5
// 1 2 3 4 5 6 
// Sorted Array
// 1 2 3 4 5 6 
// Input 2 :
// 8
// 8 1 7 2 6 3 5 4
// Output 2 :
// Given Array
// 8 1 7 2 6 3 5 4 
// After iteration 1
// 1 8 7 2 6 3 5 4 
// After iteration 2
// 1 8 2 7 6 3 5 4 
// After iteration 3
// 1 2 7 8 6 3 5 4 
// After iteration 4
// 1 2 7 8 3 6 5 4 
// After iteration 5
// 1 2 7 8 3 6 4 5 
// After iteration 6
// 1 2 7 8 3 4 5 6 
// After iteration 7
// 1 2 3 4 5 6 7 8 
// Sorted Array
// 1 2 3 4 5 6 7 8 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;

int rec = 0;

void conquer(int arr[], int l, int m, int r, int size) {
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[m+j+1];
    }
    i=0,j=0,k=l;
    while(i < n1 && j < n2){
        if(L[i]>R[j]){
            arr[k]=R[j];
            j++;
        }else{
            arr[k]=L[i];
            i++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
    
}

void divide(int arr[], int l, int r, int size) {
    if(r>l){
        
    int mid = (l+r)/2;
    divide(arr,l,mid,size);
    divide(arr,mid+1,r,size);
    conquer(arr,l,mid,r,size);
    rec++;
    cout << "After iteration " << rec << endl; 
    for(int i = 0;i <size;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    }
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Given Array" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    divide(arr, 0, n - 1, n);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}