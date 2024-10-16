// Single File Programming Question
// Problem Statement



// You are given a class Arithmetic that represents complex numbers. The class has two private data members: number1 and number2, representing the complex number's real and imaginary parts, respectively. Your task is to implement the following:



// Overload the binary addition (+) operator to add two complex numbers.
// Overload the binary subtraction (-) operator to subtract two complex numbers.


// Write a program that reads two complex numbers, performs addition and subtraction using the overloaded operators, and prints the results.



// Company Tag: TCS

// Input format :
// The first line consists of space-separated float values representing the real and imaginary parts of the first complex number.

// The second line consists of space-separated float values representing the real and imaginary parts of the second complex number.

// Output format :
// The first line displays float values representing the addition of the complex numbers.

// The second line displays float values representing the subtraction of the complex numbers.



// The output should be round off 2 decimal points.



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// -105 < real and imaginary values < 105

// Sample test cases :
// Input 1 :
// 4.5 7.8
// 1.2 3.1
// Output 1 :
// 5.70 + 10.90i
// 3.30 + 4.70i
// Input 2 :
// -4.9 -8.5
// 5.3 -5.5
// Output 2 :
// 0.40 - 14.00i
// -10.20 - 3.00i
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class Complex{
    public:
        float real;
        float imag;
        Complex(float r=0.0,float i=0.0){
            this->real=r;
            this->imag=i;
        }
        Complex operator + (Complex &obj){
            Complex temp;
            temp.real = real + obj.real;
            temp.imag = imag + obj.imag;
            return temp;
        }
        Complex operator - (Complex &obj){
            Complex temp;
            temp.real = real - obj.real;
            temp.imag = imag - obj.imag;
            return temp;
        }
        void print(){
            if(imag<0){
                imag = imag - 2*imag;
                cout << fixed << setprecision(2) << real << " - " << imag << "i" << endl;
            }else{
                cout << fixed << setprecision(2) << real << " + " << imag << "i" << endl;
            }
        }
};

int main(){
    float ci1,cr1,ci2,cr2;
    cin >> cr1;
    cin >> ci1;
    cin >> cr2;
    cin >> ci2;
    Complex c1(cr1,ci1);
    Complex c2(cr2,ci2);
    Complex add,sub;
    add = c1 + c2;
    sub = c1 - c2;
    add.print();
    sub.print();
    return 0;
}