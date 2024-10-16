// Single File Programming Question
// Problem Statement



// Arjun is passionate about creating unique cylindrical art pieces. Develop a program that takes input for the radius and height of his sculptures and calculates the volume.



// Base class Circle: Contains a private attribute called radius, representing the radius of a circle.

// Privately inherited derived class Cylinder: It is inherited from the Circle class and has a private attribute named height, representing the height of the cylinder.

// volume() method inside the Cylinder class: To calculate the volume of the cylinder.



// Formula: Volume = 3.14 * radius * radius * height

// Input format :
// The input consists of two space-separated double values, which represent the radius and height of the cylinder.

// Output format :
// The output prints a double value, representing the volume of the cylinder, rounded to two decimal places.



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1.0 ≤ radius, height ≤ 50.0

// Sample test cases :
// Input 1 :
// 5.1 3.6
// Output 1 :
// 294.02
// Input 2 :
// 3.4 6.2
// Output 2 :
// 225.05
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class circle{
    private:
        double radius;
    public:
        void setRadius(double r){
            this->radius = r;
        }
        double getR(){
            return radius;
        }
};

class cylinder: public circle{
    private:
        double height;
    public:
        cylinder(double h) :  height(h) {}
        void volume(){
            cout << fixed << setprecision(2) << 3.14*getR()*getR()*height;
        }
};



int main(){
    double r,h;
    cin >> r;
    cin >> h;
    cylinder c1(h);
    c1.setRadius(r);
    c1.volume();
    return 0;
}