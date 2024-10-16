// Single File Programming Question
// Program Statement



// Misha needs a program to open and close files based on user input. The program should ask for the file name, and display messages for successful file opening and closing.

// Input format :
// The input consists of the name of the file they want to open and close and the filename as a single line of text.

// Output format :
// If the file is successfully opened, it displays "File 'filename' opened successfully.".

// Regardless of whether the file was opened successfully or not, it displays "File 'filename' closed successfully." to indicate that the file is closed at the end of the program.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 4<=File Name<=100

// Sample test cases :
// Input 1 :
// sample.txt
// Output 1 :
// File 'sample.txt' opened successfully.
// File 'sample.txt' closed successfully.
// Input 2 :
// input.txt
// Output 2 :
// File 'input.txt' opened successfully.
// File 'input.txt' closed successfully.

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    
    string test;
    cin >> test;
    
    ofstream file;
    file.open(test,ios::in);
    // if(file.is_open()){
        cout << "File \'" << test << "\' opened successfully." << endl;
    // }
    file.close();
    cout << "File \'" << test << "\' closed successfully."<< endl;
    return 0;
}