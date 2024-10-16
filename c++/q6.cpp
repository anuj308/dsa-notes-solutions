// Single File Programming Question
// Problem Statement



// Sam wants to create a class called WeatherForecast that contains weather information. The class should have attributes: country code (integer), and its temperature (float). He wants to implement member functions to add the weather information and display the country code having the lowest temperature. Help him write the code. Assume that the temperature is measured in Celcius.

// Input format :
// The first line consists of an integer N, representing the number of locations.

// The following lines consist of the country code (integer) and temperature (float value) separated by a new line for N locations.

// Output format :
// The output prints the country code with the lowest temperature.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ country code ≤ 104

// 0.0 ≤ temperature ≤ 100.0

// Sample test cases :
// Input 1 :
// 4
// 101
// 25.5
// 102
// 20.8
// 103
// 15.2
// 104
// 18.9
// Output 1 :
// 103

#include <bits/stdc++.h>
using namespace std;

class WeatherForecast{
    public:
        int country;
        float weather;
        
        void get(){
            float weather1;
            cin >> country;
            this->country=country;
            cin >> weather1;
            this->weather=weather1;
        }
};

int main(){
    int n;
    cin >> n;
    int t=0;
    
    WeatherForecast w1[n];
    while(t<n){
        w1[t].get();
        t++;
    }
    
    t=0;
    float low=999999999.0;
    int code;
    while(t<n){
        if(w1[t].weather<low){
            low = w1[t].weather;
            code = w1[t].country;
        }
        t++;
    }
    
    cout << code << endl;
    return 0;
}