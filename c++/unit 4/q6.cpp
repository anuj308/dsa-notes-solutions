// Single File Programming Question
// Problem Statement



// Senthil is working in a grocery store, and he wants to create a program for managing stock items. Help him implement a StockItem class with private member variables for item code, quantity, and price per unit.



// Use basic to class type conversion to enable the creation of a StockItem object by providing input for item code, quantity, and price per unit. The program should calculate and display the total price for the stock item and print its details in a specific format.



// Company Tag: TCS

// Input format :
// The first line of the input consists of an integer representing the item code.

// The second line consists of an integer representing the quantity.

// The third line consists of a double value representing the price per unit.

// Output format :
// The output displays "Total Price of the Stock: " followed by a double value, representing the total price of the stock with two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ item code ≤ 1000

// 1 ≤ quantity ≤ 1000

// 1 ≤ price per unit ≤107

// Sample test cases :
// Input 1 :
// 103
// 10
// 150.0
// Output 1 :
// Total Price of the Stock: 1500.00
// Input 2 :
// 999
// 42
// 1750.6
// Output 2 :
// Total Price of the Stock: 73525.20
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

// class 

int main(){
    int n1,n2;
    float n3;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    
    cout << "Total Price of the stock: " << fixed << setprecision(2) << n2*n3 << endl;
    
    return 0;
}