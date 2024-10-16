// Single File Programming Question
// Problem Statement



// Ethan is driving his car with an initial velocity (in m/s) and suddenly accelerates at a constant rate (in m/s²) for a certain duration (in seconds). He wants to write a program that calculates and displays the final velocity of the car.



// Help Ethan calculate the final velocity by overloading the * operator in the Acceleration class.



// Formula: Final velocity = Initial velocity + (Acceleration * Time)

// Input format :
// The input consists of three space-separated double values:

// Initial velocity (in m/s)
// Acceleration (in m/s²)
// Time (in s)
// Output format :
// The output displays a double value representing the final velocity followed by " m/s", rounded to one decimal place.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1.0 ≤ Initial velocity ≤ 500.0

// 1.0 ≤ Acceleration ≤ 50.0

// 1.0 ≤ Time ≤ 50.0

// Sample test cases :
// Input 1 :
// 10.3 5.0 2.1
// Output 1 :
// 20.8 m/s
// Input 2 :
// 410.2 9.8 4.5
// Output 2 :
// 454.3 m/s
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class acceleration{
    public:
        double intialV;
        double acc;
        double timee;
        acceleration(double i,double a,double t): intialV(i), acc(a) , timee(t) {}
        void operator *() const {
            cout << fixed << setprecision(1) <<  (intialV + (acc*timee)) << " m/s";
        }
};

int main(){
    double i,a,t;
    cin >> i;
    cin >> a;
    cin >> t;
    
    acceleration a1(i,a,t);
    *a1;
    return 0;
}