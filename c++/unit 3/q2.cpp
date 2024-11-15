// Single File Programming Question
// Problem Statement



// You are required to create a program that can perform basic arithmetic operations on complex numbers. A complex number consists of a real part and an imaginary part. The program should provide the following functionality:



// Create two instances of the Complex class using the default constructor, Complex c1 and Complex c2.
// Prompt the user to enter the real and imaginary parts for both c1 and c2 using the setvalue() method.
// Calculate the sum of c1 and c2 using the sum() method and store the result in a third instance of the Complex class, c3.
// Display the result of the addition using the display() method.
// Ensure that a destructor is called for each Complex object when it is destroyed.


// Company Tags: Wipro

// Input format :
// The input consists of two lines, consisting of the real and imaginary real parts of two complex numbers as float values, separated by space.

// Output format :
// The output displays "Sum of two complex numbers is X +Yi" where X is the real part and Y is the imaginary part of the result value as float values rounded to one decimal value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 0.0 ≤ real, imaginary parts ≤ 1000.0

// Sample test cases :
// Input 1 :
// 2.7 3.5 
// 3.2 1.6
// Output 1 :
// Sum of two complex numbers is 5.9 + 5.1i
// Input 2 :
// 1.0 2.0
// 3.0 2.0
// Output 2 :
// Sum of two complex numbers is 4.0 + 4.

#include <bits/stdc++.h>
using namespace std;

class Complex{
  public:
    float real;
    float imagi;
    Complex(){}
    void setValue(float r,float i){
        real = r;
        imagi = i;
    }
    void display(){
        cout << "Sum of two complex numbers is " << fixed << setprecision(1)<< real << " + " << imagi << "i" << endl;
    }
    void sum(Complex obj1, Complex obj2){
        real = obj1.real + obj2.real;
        imagi = obj1.imagi + obj2.imagi;
    }
    ~Complex(){}
};

int main(){
    float ci1, cr1, ci2, cr2;
    cin >> cr1;
    cin >> ci1;
    cin >> cr2;
    cin >> ci2;
    Complex c1;
    Complex c2;
    c1.setValue(cr1,ci1);
    c2.setValue(cr2,ci2);
    Complex c3;
    c3.sum(c1,c2);
    c3.display();
    
    return 0;
}