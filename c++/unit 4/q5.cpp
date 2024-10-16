// Single File Programming Question
// Problem Statement



// Ajay is working for a road construction company and wants to convert the given distance from kilometers to miles. So he is creating a program that converts a given distance in kilometers to miles using basic to class type conversion.



// Help him implement a Distance class with private member variables for kilometers and miles and a constructor that performs the conversion. The program should prompt the user for a distance in kilometers and then display the converted distance in kilometers and miles, both formatted with two digits after the decimal point.



// Formula:  miles = km * 0.621371

// Input format :
// The input consists of a double value representing the distance in kilometers.

// Output format :
// The first line of the output displays the distance in kilometers with two decimal places.

// The second line displays the distance in miles with two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1.0 ≤ distance in kilometers ≤ 100.0

// Sample test cases :
// Input 1 :
// 10.0
// Output 1 :
// Kilometers: 10.00 km
// Miles: 6.21 miles
// Input 2 :
// 35.4
// Output 2 :
// Kilometers: 35.40 km
// Miles: 22.00 miles
// Note :

#include <bits/stdc++.h>
using namespace std;

class Distance{
    private:
        float km;
        float miles;
        public:
        Distance(float k){
            this->km=k;
            this->miles=k*0.621371;
            cout << "Kilometers: " << fixed << setprecision(2) << km << "km" <<  endl;
            cout << "Miles: " << fixed << setprecision(2) << miles << "miles" <<  endl;
        }
};

int main(){
    float x;
    cin >> x;
    Distance d1(x);
    
    return 0;
}