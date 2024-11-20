// Single File Programming Question
// Problem statement



// Alice is working on a simple calculator application that performs multiplication operations with two distinct data types: integers and doubles. The application will feature a class called Calculator, which includes two overloaded methods named multiply.



// One method will accept integer parameters, calculating the result using the formula 2 x a + 3b. The other method will accept double parameters, using the formula 2.5 x a + 1.5b for its calculations.



// The task is to develop a program that prompts the user to choose the type of multiplication (1 for integers or 2 for doubles) and input the relevant values, Using early binding, compute and display the result based on the chosen type.

// Input format :
// The first line contains an integer choice (1 or 2) indicating the type of multiplication.

// If the choice is 1, the second line contains two integers intA and intB, separated by a space.

// If the choice is 2, the second line contains two doubles doubleA and doubleB, separated by a space.

// Output format :
// If the choice is valid, output the result:

// For integers, output the result as an integer.
// For doubles, output the result formatted to two decimal places.
// If the choice is invalid, output: Invalid choice



// Refer to the sample output for specifications.

// Code constraints :
// choice will be either 1 or 2.

// 1 ≤ intA, intB ≤ 100

// 1 ≤ doubleA, doubleB ≤ 50

// Sample test cases :
// Input 1 :
// 1
// 2 3
// Output 1 :
// 31
// Input 2 :
// 2
// 2.0 3.0
// Output 2 :
// 8.38
// Input 3 :
// 3
// Output 3 :
// Invalid choice
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// by chatgpt

#include <iostream>
#include <iomanip> // For setting precision
#include <cmath>
using namespace std;

class Calculator {
public:
    // Method to multiply integers
    int multiply(int a, int b) {
        return 2 * a + pow(3,b);
    }

    // Method to multiply doubles
    double multiply(double a, double b) {
        return 2.5 * a + pow(1.5,b);
    }
};

int main() {
    int choice;
    cin >> choice;  // Read the user's choice

    Calculator calc; // Create an instance of Calculator

    if (choice == 1) {
        // If choice is 1, read two integers
        int intA, intB;
        cin >> intA >> intB;
        cout << calc.multiply(intA, intB) << endl;  // Call integer multiplication method
    }
    else if (choice == 2) {
        // If choice is 2, read two doubles
        double doubleA, doubleB;
        cin >> doubleA >> doubleB;
        // Call double multiplication method and print result formatted to two decimal places
        cout << fixed << setprecision(2) << calc.multiply(doubleA, doubleB) << endl;
    }
    else {
        // If choice is invalid, print "Invalid choice"
        cout << "Invalid choice" << endl;
    }

    return 0;
}
