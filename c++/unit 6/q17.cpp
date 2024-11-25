// Single File Programming Question
// Problem Statement



// Pranav is a professional wedding photographer. He wants to create a program using a function template that can calculate the total revenue earned from wedding photography bookings.



// The program should take an array of booking amounts as input and return the total revenue.



// Note: This kind of question will be helpful in clearing Mettyl recruitment.

// Input format :
// The first line of input consists of the number of wedding photography bookings, n.

// The second line of input consists of n space-separated booking amounts.

// Output format :
// The output displays the total amount for n bookings.

// Code constraints :
// n >= 1

// Sample test cases :
// Input 1 :
// 4
// 1200.0 1500.0 1800.5 950.75
// Output 1 :
// 5451.25
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// // Extra spaces and new line characters in the program output will result in the failure of the test case.

// not passinf test case

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

template <typename T>
T ans(const vector<T>& arr){
   return accumulate(arr.begin(),arr.end(),T(0));
}
int main(){
    
    int n;
    cin >> n;
        
    vector<double> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    double t = ans(arr);
    cout << fixed << setprecision(2) << t << endl;
    
    
    return 0;
}