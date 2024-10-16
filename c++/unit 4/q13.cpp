// Single File Programming Question
// Problem Statement



// Rahul is tasked with creating a program that manages geometric shapes, specifically circles and squares. The program uses three classes: Shape, Circle, and Square. Shape serves as a base class for all shapes, while Circle and Square inherit from it. Each class has constructors and destructors for shape management. Additionally, there are methods to calculate the area of each shape.



// In the main function, the program interacts with users to input shape details. It creates instances of Circle and Square based on user input and calculates and displays their respective areas.



// The program demonstrates object-oriented principles for shape modeling and properly executing constructors and destructors to manage shape lifecycle. Help him to accomplish the task.



// Formula:

// Area of circle = 3.14 * radius * radius

// Area of square = side * side

// Input format :
// The first line of the input consists of a string representing the name of the circle.

// The second line consists of a double value representing the radius of the circle.

// The third line consists of a string of a string representing the name of the square.

// The last line consists of a double value representing the side of the square.

// Output format :
// The output consists of multiple lines detailing the construction and destruction of the shapes.

// After the construction messages, print double points numbers representing the area of the circle in the format Area of shapeName1: area, rounded to two decimal places.

// Then print the double points numbers representing the area of the square in the format Area of shapeName2: area, rounded to two decimal places.

// The destruction messages follow after the area calculations.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// Length of string ≤ 20

// 1.0 ≤ radius of circle ≤ 20.0

// 1.0 ≤ side of square ≤ 20.0

// Sample test cases :
// Input 1 :
// circle1
// 2.0
// square1
// 4.0
// Output 1 :
// Shape Constructor: Creating a shape - circle1
// Circle Constructor: Creating a circle - circle1
// Shape Constructor: Creating a shape - square1
// Square Constructor: Creating a square - square1
// Area of circle1: 12.56
// Area of square1: 16.00
// Square Destructor: Destroying a square - square1
// Shape Destructor: Destroying a shape - square1
// Circle Destructor: Destroying a circle - circle1
// Shape Destructor: Destroying a shape - circle1
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the fa
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Shape {
public:
    string name;

    Shape(const string& shapeName) : name(shapeName) {
        cout << "Shape Constructor: Creating a shape - " << name << endl;
    }

    ~Shape() {
        cout << "Shape Destructor: Destroying a shape - " << name << endl;
    }
};

class Circle : public Shape {
public:
    double radius;

    Circle(const string& shapeName, double r) : Shape(shapeName), radius(r) {
        cout << "Circle Constructor: Creating a circle - " << name << endl;
    }

    ~Circle() {
        cout << "Circle Destructor: Destroying a circle - " << name << endl;
    }

    double area() {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
public:
    double side;

    Square(const string& shapeName, double s) : Shape(shapeName), side(s) {
        cout << "Square Constructor: Creating a square - " << name << endl;
    }

    ~Square() {
        cout << "Square Destructor: Destroying a square - " << name << endl;
    }

    double area() {
        return side * side;
    }
};

int main() {
    string circleName, squareName;
    double circleRadius, squareSide;

    cin >> circleName;
    cin >> circleRadius;
    cin >> squareName;
    cin >> squareSide;

    Circle circle(circleName, circleRadius);
    Square square(squareName, squareSide);

    cout << fixed << setprecision(2);
    cout << "Area of " << circle.name << ": " << circle.area() << endl;
    cout << "Area of " << square.name << ": " << square.area() << endl;

    return 0;
}