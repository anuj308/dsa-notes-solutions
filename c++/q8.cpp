// Single File Programming Question
// Problem Statement



// Dharun is a teacher and has just finished grading the exams of his students. He wants to analyze the performance of his students by finding the smallest difference between the scores of any two students. Help him write the formula that will help him calculate this smallest difference so that he can generate the report for the same using pointer arithmetic.



// Function Name: int findSmallestDifference - This function calculates and returns the smallest difference between any two students' scores.



// Example



// Input:

// 5

// 100 89 95 56 66



// Output:

// 5



// Explanation:

// Here the smallest difference between any two scores (100 and 95), which in this case is 5. This indicates that the closest scores among the students differ by a margin of 5 points.



// Company Tags: TCS 

// Input format :
// The first line of input consists of the number of students, n as an integer.

// The second line of input consists of n space-separated integers representing the scores.

// Output format :
// The output displays the smallest difference between any two scores.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 2 ≤ n ≤ 10

// 0 ≤ scores ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 100 89 95 56 66
// Output 1 :
// 5
// Input 2 :
// 3
// 99 100 90
// Output 2 :
// 1

// one testcase failed

#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+n);
    
    int t=0;
    int ans=9999999;
    while(t<n){
        int sub = arr[t+1]-arr[t];
        if(ans>sub){
            ans =sub;
        }
        t++;
    }
    
    cout << ans;
    return 0;
}