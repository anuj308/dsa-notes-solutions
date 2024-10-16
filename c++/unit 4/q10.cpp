// Single File Programming Question
// Problem statement



// A company maintains a database that has the details of all its employees.



// There are two levels of employees:

// Level 1 is the top management, which has a salary of more than 100 dollars,
// Level 2 is the staff, which has a salary of less than 100 dollars.


// Create a class named "Employee" with empId and salary as attributes. Create another class, "empLevel" that inherits Employee and categorizes the employee into various levels.



// Note: Use single inheritance.

// Input format :
// The input consists of employee ID and salary of the employee, separated by spaces.

// Employee ID should be of integer type and salary float type.

// Output format :
// The output displays the employee ID, salary, and level of the employee, in separate lines.

// Salary is rounded to two decimal places.



// Refer to the sample output for format specifications.

// Code constraints :
// 1 ≤ empId ≤ 10000

// 1 ≤ salary ≤ 100000

// Sample test cases :
// Input 1 :
// 253 5.6
// Output 1 :
// Employee ID: 253
// Salary: $5.60
// Level: 2
// Input 2 :
// 253 105.6
// Output 2 :
// Employee ID: 253
// Salary: $105.60
// Level: 1
// Input 3 :
// 450 100.0
// Output 3 :
// Employee ID: 450
// Salary: $100.00
// Level: 2
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
public:
    int empId;
    float slry;

    Employee(int empId, float slry)
    {
       cout << "Employee ID: " << empId << endl;
       cout << "Salary: $" << fixed << setprecision(2) << slry << endl; 
    }
};

class empLevel : public Employee
{
public:
    int level;

    empLevel(int empId, float slry) : Employee(empId, slry)
    {
        if(slry<=100.00){
            cout << "Level: 2" << endl; 
        }else{
            cout << "Level: 1" << endl;
        }
    }
};

int main()
{
    int empId;
    float slry;
    cin >> empId >> slry;
    empLevel el(empId, slry);
    // Type your code here
    return 0;
}
