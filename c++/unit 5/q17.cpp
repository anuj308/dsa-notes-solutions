// Single File Programming Question
// Problem Statement



// Rohith is designing a program that consists of a base class Expression with a pure virtual function evaluate().



// There are two derived classes PowerAB and PowerBA representing expressions of the form ab and ba respectively, where a and b are real numbers. The program takes the values of a and b as input and calculates and displays the power results for both types of expressions.



// Note: Use the pow function from the math library to calculate the power value.

// Input format :
// The input consists of two space-separated double values a and b.

// Output format :
// The first line of output prints the value of ab as a double-value, rounded off to two decimal places.

// The second line prints the value of ba as a double-value, rounded off to two decimal places.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1.0 ≤ a, b ≤ 10.0

// Sample test cases :
// Input 1 :
// 4.5 2.0
// Output 1 :
// 20.25
// 22.63
// Input 2 :
// 1.1 1.1
// Output 2 :
// 1.11
// 1.11
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// Marks : 10
// Negative Marks : 0

#include <iostream>
#include <cmath>  // For the pow function
#include <iomanip>  // For setting precision

using namespace std;

// Base class
class Expression {
public:
    virtual double evaluate() = 0;  // Pure virtual function
    virtual ~Expression() {}  // Virtual destructor
};

// Derived class to calculate a^b
class PowerAB : public Expression {
private:
    double a, b;
public:
    PowerAB(double a, double b) : a(a), b(b) {}
    double evaluate() override {
        return pow(a, b);  // Calculate a raised to the power of b
    }
};

// Derived class to calculate b^a
class PowerBA : public Expression {
private:
    double a, b;
public:
    PowerBA(double a, double b) : a(a), b(b) {}
    double evaluate() override {
        return pow(b, a);  // Calculate b raised to the power of a
    }
};

int main() {
    double a, b;
    
    // Input two space-separated doubles
    cin >> a >> b;
    
    // Create objects of derived classes
    PowerAB powerAB(a, b);
    PowerBA powerBA(a, b);
    
    // Output results with 2 decimal precision
    cout << fixed << setprecision(2);  // Set fixed-point notation with 2 decimal places
    cout << powerAB.evaluate() << endl;  // Output a^b
    cout << powerBA.evaluate() << endl;  // Output b^a
    
    return 0;
}

