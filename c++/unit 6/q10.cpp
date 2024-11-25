// Single File Programming Question
// Problem Statement



// Usha is a university administrator responsible for managing the admission process for medical colleges. She needs a program that allows her to keep track of details for three medical colleges and handle student admissions. 

// Write a program using class templates with inheritance.



// The program should have the following functionalities:



// Choice 1: Display Medical College Details: Usha should be able to view the name, establishment year, total seats, and available seats for each medical college.

// Choice 2: Admit Students to the MBBS Course: Usha should be able to admit a specified number of students to the MBBS course at a selected medical college. The program should check if there are enough available seats and display the number of seats remaining after admission.

// Choice 3: Exit: Usha should be able to exit the program when she is done managing the admissions.



// Note: This kind of question will be helpful in clearing TCS recruitment.

// Input format :
// The first input block consists of the details of three medical colleges. For each college, the input is:

// Name (a string): The name of the college (can include spaces).
// Year (an integer): The year the college was established.
// Total Seats (an integer): Total available seats for the college.
// Total MBBS Seats (an integer): The number of MBBS seats (not used directly in the provided functionality).

// The next input is an integer representing a choice:

// Choice 1: Display details of the colleges.
// Choice 2: Admit a specified number of students to the first college.
// Choice 3: Exit the program.
// Any other choice results in an "Invalid choice" message and exits the program.
// If Choice 2 is selected, an additional input is provided, representing the number of students to admit.

// Output format :
// The output displays appropriate messages based on the user's input choices.

// For option 1, it should display the details of all three medical colleges.

// For option 2, it should display the number of students admitted and the updated available seats in the college1.

// For option 3, it should display exiting the program.

// If the user enters an invalid choice, it should display an error message.

// In the last line, output displays the endline for the first option.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The establishment year of each college should be a positive integer.

// The total number of seats and total MBBS seats in each college should be positive integers greater than zero.

// The number of students to admit should be a positive integer.

// Usha can only choose options 1, 2, or 3 as her input choices. Any other input should be considered invalid.

// Sample test cases :
// Input 1 :
// ABC Medical College
// 2022
// 100
// 80
// XYZ Medical College
// 2019
// 120
// 90
// PQR Medical College
// 2020
// 150
// 100
// 1
// Output 1 :
// Medical College Details:
// ABC Medical College 2022 100 100
// XYZ Medical College 2019 120 120
// PQR Medical College 2020 150 150
// Input 2 :
// ABC Medical College
// 2022
// 100
// 80
// XYZ Medical College
// 2019
// 120
// 90
// PQR Medical College
// 2020
// 150
// 100
// 2
// 50
// Output 2 :
// 50 students admitted to ABC Medical College
// Available Seats: 50
// Input 3 :
// ABC Medical College
// 2022
// 100
// 80
// XYZ Medical College
// 2019
// 120
// 90
// PQR Medical College
// 2020
// 150
// 100
// 4
// 3
// Output 3 :
// Invalid choice
// Exiting the program
// Input 4 :
// ABC Medical College
// 2022
// 100
// 80
// XYZ Medical College
// 2019
// 120
// 90
// PQR Medical College
// 2020
// 150
// 100
// 2
// 110
// Output 4 :
// Not enough seats available in ABC Medical College
// Cannot admit 110 students.
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// // Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MedicalCollege {
public:
    //Type your code here
    MedicalCollege(string n,int y,T ts, T as) : name(n), year(y),totalSeats(ts), availableSeats(as)  {}
    
    void admitStudents(int n){
        if(n>availableSeats){
            cout << "Not enough seats available in " << name << endl;
            cout << "Cannot admit " << n << " students." << endl;
        }else{
            totalSeats-=n;
            cout << n << " students admitted to " << name << endl;
            cout << "Available Seats: " << totalSeats << endl;
        }
    }
    void displayDetails(){
        cout << name << " " << year << " " << totalSeats << " " << totalSeats << endl;
    }
    T getTotalSeats() const { 
        return totalSeats;
    }

private:
    string name;
    int year;
    T totalSeats;
    T availableSeats;
};

template <typename T>
class MBBSMedicalCollege : public MedicalCollege<T> {
public:
    MBBSMedicalCollege(string n,int y,T ts,T as) : MedicalCollege<T>(n,y,ts,as) {}
    // void displayDetails() const override{
    //     MedicalCollege<T>::displayDetails();
    // }
private:
    T totalMBBSSeats;
};

int main() {
    string college1Name, college2Name, college3Name;
    int college1Year, college2Year, college3Year;
    int college1TotalSeats, college2TotalSeats, college3TotalSeats;
    int college1TotalMBBSSeats, college2TotalMBBSSeats, college3TotalMBBSSeats;

    getline(cin, college1Name);
    cin >> college1Year;
    cin >> college1TotalSeats;
    cin >> college1TotalMBBSSeats;

    cin.ignore(); // Clear the newline character left in the buffer

    getline(cin, college2Name);
    cin >> college2Year;
    cin >> college2TotalSeats;
    cin >> college2TotalMBBSSeats;
    
    cin.ignore(); // Clear the newline character left in the buffer

    getline(cin, college3Name);
    cin >> college3Year;
    cin >> college3TotalSeats;
    cin >> college3TotalMBBSSeats;

    MBBSMedicalCollege<int> college1(college1Name, college1Year, college1TotalSeats, college1TotalMBBSSeats);
    MBBSMedicalCollege<int> college2(college2Name, college2Year, college2TotalSeats, college2TotalMBBSSeats);
    MBBSMedicalCollege<int> college3(college3Name, college3Year, college3TotalSeats, college3TotalMBBSSeats);

    while (true) {

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Medical College Details:" << endl;
            college1.displayDetails();
            college2.displayDetails();
            college3.displayDetails();
            return 0;
        } else if (choice == 2) {
            int numStudents;
            cin >> numStudents;
            college1.admitStudents(numStudents);
            return 0;
        } else if (choice == 3) {
            cout << "Exiting the program";
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
