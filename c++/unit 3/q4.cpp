// Single File Programming Question
// Problem Statement



// Create a Vehicle class that uses a parameterized constructor to initialize the registration number, make, model, and year of manufacture. Implement a method called displayDetails to print these attributes. Ensure that the class can handle string inputs for the vehicle details.

// Input format :
// The input consists of four lines, each containing:

// A string representing the registration number.
// A string representing the make of the vehicle.
// A string representing the model of the vehicle.
// An integer representing the year of manufacture.
// Output format :
// The output prints the following, each containing the details of a vehicle in the following format:

// Registration Number: [registration number]

// Make: [make]

// Model: [model]

// Year of Manufacture: [year of manufacture]



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1900 ≤ year of manufacture ≤ 2100

// Sample test cases :
// Input 1 :
// KA-01-HH-1234
// Toyota
// Corolla
// 2022
// Output 1 :
// Registration Number: KA-01-HH-1234
// Make: Toyota
// Model: Corolla
// Year of Manufacture: 2022
// Note :


#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    string renu;
    string make;
    string model;
    int yom;
    Vehicle(string r,string m,string mo,int y){
        renu = r;
        make = m;
        model = mo;
        yom = y;
    }
    void displayDetails(){
        cout << "Registration Number: " << renu << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year of Manufacture: " << yom << endl;
     }
};

int main(){
    int y;
    string regis,make,model;
    getline(cin,regis);
    getline(cin,make);
    getline(cin,model);
    cin >> y;
    
    Vehicle v1(regis,make,model,y);
    v1.displayDetails();
    return 0;
}