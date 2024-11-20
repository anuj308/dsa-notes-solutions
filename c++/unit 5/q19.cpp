// Single File Programming Question
// Problem Statement



// Emily is an ice cream shop owner who wants to calculate the volume of different ice cream shapes to manage her inventory better. She decides to create a class hierarchy to represent various ice cream shapes, where the base class is Icecream.



// This class has a pure virtual function named Quantity, which will be overridden in derived classes to compute the volume of the respective shapes. Emily uses late binding to ensure that the correct method is called at runtime based on the user’s choice of ice cream shape.



// Note: 

// Sphere Ice Cream Volume = (4/3) * pi * r³

// Cone Ice Cream Volume = (1/3) * pi * r² * h

// Use M_PI for pi and use late binding.

// Input format :
// The input consists of an integer choice indicating the type of ice cream shape:

// for a spherical ice cream.
// for a conical ice cream.
// If the choice is 1, an integer r (radius) is provided.

// If the choice is 2, two space-separated integers r (radius) and h (height) are provided.



// Note: The input type should be an integer.

// Output format :
// The output should be the volume of the selected ice cream shape, rounded to two decimal points.

// If the input choice is invalid, the output should be: Invalid choice



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 ≤ r, h ≤ 1000

// Sample test cases :
// Input 1 :
// 1
// 4
// Output 1 :
// 268.08
// Input 2 :
// 2
// 4 5
// Output 2 :
// 83.78
// Input 3 :
// 4
// Output 3 :
// Invalid choice
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Base class with a pure virtual function
class Icecream {
public:
    virtual double Quantity() const = 0; // Pure virtual function
    virtual ~Icecream() {} // Virtual destructor for proper cleanup
};

// Derived class for spherical ice cream
class SphereIcecream : public Icecream {
private:
    double radius;
public:
    SphereIcecream(double r) : radius(r) {}

    double Quantity() const override {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
};

// Derived class for conical ice cream
class ConeIcecream : public Icecream {
private:
    double radius, height;
public:
    ConeIcecream(double r, double h) : radius(r), height(h) {}

    double Quantity() const override {
        return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
    }
};

int main() {
    int choice;
    cin >> choice;

    Icecream* icecream = nullptr;

    if (choice == 1) {
        // For spherical ice cream, read radius
        double r;
        cin >> r;
        icecream = new SphereIcecream(r); // Dynamically create a SphereIcecream object
    }
    else if (choice == 2) {
        // For conical ice cream, read radius and height
        double r, h;
        cin >> r >> h;
        icecream = new ConeIcecream(r, h); // Dynamically create a ConeIcecream object
    }
    else {
        // If the choice is invalid
        cout << "Invalid choice" << endl;
        return 0;
    }

    // Calculate and output the volume using the Quantity() method
    cout << fixed << setprecision(2) << icecream->Quantity() << endl;

    // Clean up dynamically allocated memory
    delete icecream;

    return 0;
}
