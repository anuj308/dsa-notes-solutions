// Single File Programming Question
// Problem Statement



// John is a student who just received his test scores (floating-point numbers) for various subjects. He wants to organize his scores in descending order so that he can see his highest scores first. Can you help him write a program to sort his test scores in descending order?



// Your task is to write a program to sort John's test scores in descending order using the merge sort algorithm and a recursive function.

// Input format :
// The first line contains an integer, n, representing the number of test scores John has received.

// The next line contains n floating-point numbers separated by spaces, each representing John's test score.

// Output format :
// The output displays the sorted test scores in descending order, each rounded to two decimal places.



// Refer to the sample outputs for the exact format.

// Code constraints :
// 1 ≤ n ≤ 15

// 0.0 <= test score <= 100.0

// Sample test cases :
// Input 1 :
// 4
// 9.8 1.1 3.3 7.7
// Output 1 :
// Sorted Array:
// 9.80 7.70 3.30 1.10 
// Input 2 :
// 5
// 3.14 1.1 2.71 0.5 1.618
// Output 2 :
// Sorted Array:
// 3.14 2.71 1.62 1.10 0.50 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <stdio.h>

void merge(float arr[], int left, int mid, int right) {
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    float L[n1], R[n2];
    for(int i=0;i<n1;i++)
        L[i] = arr[left+i];
    for(int j=0;j<n1;j++)
        R[j] = arr[mid+1+j];
        
    i =0,j=0,k=left;
    
    while(i<n1 && j<n2){
        if(L[i]>=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
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

void mergeSort(float arr[], int left, int right) {
    int mid = (left+right)/2;
    if(left < right) {
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}