// // 

// Single File Programming Question
// Problem Statement



// Lincoln, an engineering student, is working on a geometry project that involves calculating the areas of different shapes. He needs to create a C++ program using templates and abstract classes to achieve this. The program should prompt the user to select a shape type by entering 1 for Circle or 2 for Cube.



// Depending on the selection, the user will then be prompted to input the necessary dimension: the radius for the Circle or the side length for the Cube. The program will use class templates to define generic shapes and derive specific classes for Circle and Cube, each implementing methods to calculate and display the respective areas. 



// The Circle class will calculate the area based on the radius, while the Cube class will calculate the surface area based on the side length. The program will then output these details. Additionally, the program will handle invalid shape type selections by displaying an appropriate error message.



// Note: This kind of sample question is asked in the HCL requirement.

// Input format :
// The first line consists of an integer shapeType indicating the type of shape:

// 1 for Circle
// 2 for Cube


// If shapeType is 1 (Circle):

// The second line consists of a double value radius representing the radius of the circle.



// If shapeType is 2 (Cube):

// The second line consists of a double value side representing the side length of the cube.

// Output format :
// The output displays the following information:



// If shapeType is 1 (Circle):

// Print "Circle Details:" followed by:
// "Circle with radius: {radius}"
// "Area: {area}" (formatted to 4 decimal places)


// If shapeType is 2 (Cube):

// Print "Cube Details:" followed by:
// "Cube with side length: {side}"
// "Surface area: {area}" (formatted to the nearest integer)


// If an invalid shapeType is provided, the output prints "Invalid shape type selected."



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The radius, side length, coordinates, and translation values should be valid double values.

// The shape type should be either 1 (Circle) or 2 (Cube).

// Use M_PI for pi value.

// Sample test cases :
// Input 1 :
// 1
// 4.0
// Output 1 :
// Circle Details:
// Circle with radius: 4
// Area: 50.2655
// Input 2 :
// 2
// 5.0
// Output 2 :
// Cube Details:
// Cube with side length: 5
// Surface area: 150
// Input 3 :
// 3
// Output 3 :
// Invalid shape type selected.
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <bits/stdc++.h>
#include <cmath>
using namespace std;

template <typename T>
class shape{
    public:
        virtual T calArea() const = 0;
        virtual void display() const =0;
};

template<typename T>
class Circle : public shape<T>{
    public:
        T radius;
        Circle(T r) : radius(r){}
        T calArea() const override{
            return M_PI * radius * radius ;
        }
        void display() const override {
            cout << "Circle Details:" << endl;
            cout << "Circle with radius: " << radius << endl;
            cout << "Area: " << fixed << setprecision(4) << M_PI*radius*radius << endl;
        }
};

template<typename T>
class Cube : public shape<T>{
    public:
        T side;
        Cube(T r) : side(r){}
        T calArea() const override {
            return 6 * side * side ;
        }
        void display() const override{
            cout << "Cube Details:" << endl;
            cout << "Cube with side length: " << side << endl;
            cout << "Surface area: " << round(side*side*6) << endl;
        }
};

int main(){
    
    int n;
    double radius;
    int side;
    cin >> n;
    
    if(n==1){
        cin >> radius;
        Circle<double> circle(radius);
        circle.display();
    }else if(n==2){
        cin >> side;
        Cube<int> cube(side);
        cube.display();
    }else{
        cout << "Invalid shape type selected." << endl;
    }
    
    return 0;
}