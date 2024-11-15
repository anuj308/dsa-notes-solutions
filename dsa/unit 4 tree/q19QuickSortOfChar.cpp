// Single File Programming Question
// Problem Statement



// Ravi is spending quality time with his children, teaching them about ascending order through a fun game. To make it more interactive, Ravi has decided to create a simple program that takes a list of characters and demonstrates how to arrange them in ascending order. 



// Guide Ravi by implementing this program using quick sort.

// Input format :
// The first line of input consists of an integer n, representing the number of characters.

// The next line consists of n space-separated characters (lowercase letters or uppercase letters).

// Output format :
// The output displays a single line containing the n characters sorted in ascending order with ASCII values, separated by spaces.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 26

// Sample test cases :
// Input 1 :
// 5
// s A a n h
// Output 1 :
// A a h n s 
// Input 2 :
// 6
// h g f d v a
// Output 2 :
// a d f g h v 
// Input 3 :
// 5
// h a p p y 
// Output 3 :
// a h p p y 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
#include <string>

using namespace std;

void swap(char *a,char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

int partition(char arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(char arr[], int low, int high) {
    if(high>low){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    
}

int main() {
    int n;
    cin >> n;

    char characters[n];

    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }

    return 0;
}