// Single File Programming Question
// Problem Statement



// Diego, a software engineer, is tasked with building a smart utility to process numbers based on whether they are even or odd. He wants to design the solution using object-oriented programming principles, specifically utilizing an abstract class and a pure virtual function.



// Diego needs to create an abstract class A that contains a pure virtual function print(). The derived class B will implement this function and additional methods to handle the logic for calculating the cube, square, sum, and difference of numbers.



// If the given number is even, calculate the sum of its cube and its square.
// If the given number is odd, calculate the difference between its cube and its square.
// The result should be displayed using a function defined in the derived class, overriding a pure virtual function from the abstract base class.
// Input format :
// The input consists of an integer.

// Output format :
// If the given number is even, displays an integer representing the sum of the cube and square of the number.

// If the given number is odd, displays an integer representing the difference between the cube and square of the number.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 100

// Sample test cases :
// Input 1 :
// 5
// Output 1 :
// 100
// Input 2 :
// 4
// Output 2 :
// 80
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// by chatgpt

#include <iostream>
#include <cmath>

using namespace std;

// Abstract class A
class A {
public:
    // Pure virtual function
    virtual void print() = 0;
};

// Derived class B from class A
class B : public A {
private:
    int n;  // The input number

public:
    // Constructor to initialize the number
    B(int num) : n(num) {}

    // Override the pure virtual function print() from class A
    void print() override {
        int square = n * n;
        int cube = n * n * n;

        if (n % 2 == 0) {
            // If number is even, calculate the sum of cube and square
            cout << (cube + square) << endl;
        } else {
            // If number is odd, calculate the difference between cube and square
            cout << (cube - square) << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    // Create an object of class B and call print()
    B b(n);
    b.print();

    return 0;
}
