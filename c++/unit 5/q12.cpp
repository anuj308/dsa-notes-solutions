// Single File Programming Question
// Problem Statement



// Meet Alice, a financial advisor who helps clients make informed investment decisions. She has developed a system to calculate the returns on various types of investments, including stocks and bonds.



// To streamline her analysis, she implemented an abstract class called Investment, which includes a pure virtual function calculateReturns() for calculating the return on investment. Alice also created concrete classes Stock and Bond that inherit from the abstract class Investment. The return is calculated using the following formula:



// Returns = (Final Value − Initial Investment) × 100



// Alice wants to input the initial investment and final value for both stocks and bonds. After calculating the returns, she wants to display the type of investment along with the initial investment, final value, and the calculated returns.

// Input format :
// The first line contains two space-separated double-point numbers:

// The initial investment amount for the stock.
// The final value of the stock.
// The second line contains two space-separated double-point numbers:

// The initial investment amount for the bond.
// The final value of the bond.
// Output format :
// For each investment (stock and bond), the output should display the following sentences:

// "Type: Stock" or "Type: Bond"

// "Initial Investment: [initial investment amount]" as a double, formatted by a two decimal points.

// "Final Value: [final value]" as a double, formatted by a two decimal points.

// "Returns: [calculated returns]" as a double, formatted by a two decimal points.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0.0 ≤ amount for stock and bond ≤ 10000.0

// 0.0 ≤ value for stock and bond ≤ 10000.0

// Sample test cases :
// Input 1 :
// 1000.00 1500.87
// 4500.65 5000.30
// Output 1 :
// Type: Stock
// Initial Investment: 1000.00
// Final Value: 1500.87
// Returns: 50.09

// Type: Bond
// Initial Investment: 4500.65
// Final Value: 5000.30
// Returns: 11.10
// Input 2 :
// 110.87 120.65
// 350.92 480.10
// Output 2 :
// Type: Stock
// Initial Investment: 110.87
// Final Value: 120.65
// Returns: 8.82

// Type: Bond
// Initial Investment: 350.92
// Final Value: 480.10
// Returns: 36.81
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// by chatgpt

#include <iostream>
#include <iomanip>

using namespace std;

// Abstract class Investment
class Investment {
public:
    virtual void calculateReturns() = 0;  // Pure virtual function to calculate returns
    virtual void display() = 0;           // Pure virtual function to display the investment details
};

// Derived class Stock
class Stock : public Investment {
private:
    double initialInvestment;
    double finalValue;

public:
    Stock(double init, double final) : initialInvestment(init), finalValue(final) {}

    // Implementing the calculateReturns function
    void calculateReturns() override {
        double returns = ((finalValue - initialInvestment) / initialInvestment) * 100;
        cout << "Type: Stock" << endl;
        cout << "Initial Investment: " << fixed << setprecision(2) << initialInvestment << endl;
        cout << "Final Value: " << fixed << setprecision(2) << finalValue << endl;
        cout << "Returns: " << fixed << setprecision(2) << returns << endl;
    }

    // Display investment details for Stock
    void display() override {
        calculateReturns();  // Calls the function to calculate and display the returns
    }
};

// Derived class Bond
class Bond : public Investment {
private:
    double initialInvestment;
    double finalValue;

public:
    Bond(double init, double final) : initialInvestment(init), finalValue(final) {}

    // Implementing the calculateReturns function
    void calculateReturns() override {
        double returns = ((finalValue - initialInvestment) / initialInvestment) * 100;
        cout << "Type: Bond" << endl;
        cout << "Initial Investment: " << fixed << setprecision(2) << initialInvestment << endl;
        cout << "Final Value: " << fixed << setprecision(2) << finalValue << endl;
        cout << "Returns: " << fixed << setprecision(2) << returns << endl;
    }

    // Display investment details for Bond
    void display() override {
        calculateReturns();  // Calls the function to calculate and display the returns
    }
};

int main() {
    double stockInitial, stockFinal;
    double bondInitial, bondFinal;

    // Input for Stock
    cin >> stockInitial >> stockFinal;
    // Input for Bond
    cin >> bondInitial >> bondFinal;

    // Create Stock and Bond objects
    Stock stock(stockInitial, stockFinal);
    Bond bond(bondInitial, bondFinal);

    // Display the details for Stock and Bond
    stock.display();
    bond.display();

    return 0;
}
