// Single File Programming Question
// Problem Statement



// Nandhini is tasked with creating a program to calculate and display the speed of a car based on the distance covered and the time taken.



// Write a program with two classes: Vehicle as the base class and Car as the derived class, which inherits the properties from the Vehicle class for calculating the speed. The base class fetches the input as a float value, whereas the derived class calculates and prints the output as a float value.

// Input format :
// The input consists of two double values separated by a space.

// Distance travelled by the car
// The time taken to cover that distance
// Output format :
// The output displays a double value, showing the speed of the car in kilometres per hour, rounded off to two decimal points.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1.0 ≤ distance ≤ 10000.00

// Sample test cases :
// Input 1 :
// 15.0 5.0
// Output 1 :
// Speed of car: 3.00
// Input 2 :
// 100.23 96.0
// Output 2 :
// Speed of car: 1.04
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
#include <iomanip> 
using namespace std;

class Vehicle {
    public:
    double dist, tim;
    float calc(float d,float t){
        return d/t;
    }
};

class Car : public Vehicle {
    double spd;

public:
    void fetchData(float d,float t){
        spd = Vehicle::calc(d,t);
    }
    void display(){
        cout << "Speed of car: " << fixed << setprecision(2) << spd;
    }
};

int main() {
    float d,t;
    cin >> d;
    cin >> t;
    Car c;
    c.fetchData(d,t);
    c.display();
    
    return 0;
}