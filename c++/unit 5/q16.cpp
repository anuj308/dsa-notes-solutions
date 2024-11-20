// Single File Programming Question
// Problem Statement



// Santhosh is designing a painting application that allows users to select a color and paint on a digital canvas. Your task is to enhance the painting application by adding a user-friendly menu that prompts the user to choose a color to paint on the canvas. The user can input either 'R' or 'r' to select the Red color or 'B' or 'b' to select the Blue color.



// Write a program to implement runtime polymorphism. The program should define a base class "Color" with a virtual function "paint" and two derived classes "RedPaint" and "BluePaint" that override the "paint()" function to paint with the respective colors.



// The program should use runtime polymorphism to create either a "RedPaint" or "BluePaint" object based on user input and call the "paint()" function to paint with the chosen color.



// Note: This kind of question will help in clearing Cocubes recruitment.

// Input format :
// The input consists of a single character representing the color to paint, where "R" or "r" represents the red color and "B" or "b" represents a blue color.

// Output format :
// The program should output the message "I'm Painting with Red Color." if the user inputs 'R' or 'r', or "I'm Painting with Blue Color."

// If the user inputs "B" or "b". If the user inputs any other character, the program should output "Invalid choice!" and terminate.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The user's input must be a single character.

// The user can only enter 'R', 'r', 'B', or 'b' to select a color.

// Any other character will be considered an invalid choice.

// Sample test cases :
// Input 1 :
// R
// Output 1 :
// I'm Painting with Red color.
// Input 2 :
// B
// Output 2 :
// I'm Painting with Blue color.
// Input 3 :
// M
// Output 3 :
// Invalid choice!
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;

// Base class
class Color {
public:
    virtual void paint() = 0;  // Pure virtual function
    virtual ~Color() {}         // Virtual destructor to allow proper cleanup of derived classes
};

// Derived class for Red color
class RedPaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Red color." << endl;
    }
};

// Derived class for Blue color
class BluePaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Blue color." << endl;
    }
};

int main() {
    char choice;
    
    // Input choice for the color
    cin >> choice;
    
    Color* color = nullptr;  // Pointer to base class
    
    // Dynamically create the object based on user input
    if (choice == 'R' || choice == 'r') {
        color = new RedPaint();  // Create a RedPaint object
    } else if (choice == 'B' || choice == 'b') {
        color = new BluePaint(); // Create a BluePaint object
    } else {
        cout << "Invalid choice!" << endl;
        return 0;  // Terminate if invalid input
    }
    
    // Call the paint function using runtime polymorphism
    color->paint();
    
    // Clean up dynamically allocated memory
    delete color;
    
    return 0;
}
