// Single File Programming Question
// Problem Statement



// Peter is developing a program to filter out non-Fibonacci numbers from a list of integers. He has created a class named NonFibonacciElements to achieve this task. Given an array of integers, write a program inside this class to identify and print all elements that are not Fibonacci numbers.

// Input format :
// The first line of input consists of an integer N, representing the number of elements in the array.

// The second line consists of N space-separated integers, representing the array elements.

// Output format :
// The output prints all elements from the input array that are not Fibonacci numbers, separated by a space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ array elements ≤ 1000

// Sample test cases :
// Input 1 :
// 7
// 1 5 3 8 9 13 4
// Output 1 :
// 9 4 
// Input 2 :
// 8
// 53 68 94 91 95 2 97 82
// Output 2 :
// 53 68 94 91 95 97 82 


#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int arrfibo[1000];
    int a=0;
    arrfibo[0]=a;
    int b=1;
    arrfibo[1]=b;
    int i= 2;
    int c=0;
    while(i<100){
        c=a+b;
        arrfibo[i]=c;
        a=b;
        b=c;
        i++;
    }
    i=0;
    // while(i<50){
    //     cout << arrfibo[i] << endl;
    //     i++;
    // }
    int arrans[n]={0};
    int r=0;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int fibo = arrfibo[0];
        int h=1;
        int equal =0;
        while(a>=fibo){
            if(a==arrfibo[h]){
                equal = 1;
            }
            h++;
            fibo=arrfibo[h];
        }
        if(equal==0){
            arrans[r]=a;
            r++;
        }
        equal = 0;
    }
    
    for(int e=0;e<r;e++){
        cout << arrans[e] << " ";
    }
    
    return 0;
}