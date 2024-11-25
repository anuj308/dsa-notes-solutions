
// Single File Programming Question
// Problem Statement



// Bibin Bala is working on a class that represents a geometric shape, particularly a circle. He ensures that the circle's radius should always be positive. To address situations where the user tries to set a negative radius, Bibin Bala plans to utilize exception handling in the C++ class concept by throwing a custom exception named NegativeRadiusException.

// Input format :
// The input consists of the radius of a circle (double).

// Output format :
// The output displays the radius of the circle.

// If the radius is a negative value, the output displays an error message indicating that a negative radius value is not allowed.



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// Radius of the circle <= 105

// Sample test cases :
// Input 1 :
// 50.25
// Output 1 :
// Radius set successfully: 50.25
// Input 2 :
// 0
// Output 2 :
// Exception caught.Error: Radius cannot be negative or zero.
// Input 3 :
// -89
// Output 3 :
// Exception caught.Error: Radius cannot be negative or zero.
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.



// all testcase did not pass don't know why while submitting in complie run it passed



#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class neg : public runtime_error{
  public:
    neg() : runtime_error("Exception caught.Error: Radius cannot be negative or zero."){}
};
int main(){
    
    double n;
    cin >> n;
    try{
        
    if(n<=0){
        throw neg();
    }
        
    cout << "Radius set successfully: " << fixed << setprecision(2) << n << endl;
    }
    catch(const neg &s){
        cout << s.what() << endl;
    }
    return 0;
}