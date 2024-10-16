// Single File Programming Question
// Problem Statement



// Develop a C++ program that reads an array of integers and stores alternate elements from the array in a file named 'alt.txt'. Later, the program retrieves and displays the contents of the file. The file should handle up to 100 elements only. 



// For example, if you have an array [10, 20, 30, 40, 50], the alternate elements would be [10, 30, 50] considering the elements in odd positions.



// Note: Use a structure to implement this.

// Input format :
// The first line consists of an integer representing the size of the array.

// The second line consists of space-separated integers representing the elements of the array.

// Output format :
// If size > 100; the output displays "Exceeding limit!" and terminates.

// Otherwise, the output displays the alternate elements of the array separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= size <= 100

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// Output 1 :
// 10 30 50 
// Input 2 :
// 105
// -31 -15 -126 100 -122 24 -118 29 -174 -93 -19 -175 88 -176 -28 60 91 -114 -84 -152 127 78 61 115 43 18 -95 101 -146 144 -172 -173 -65 13 28 -136 120 23 -60 -79 -37 136 -59 0 42 -38 -101 82 84 -178 83 -104 89 -43 -108 -64 129 97 137 111 109 141 -169 132 -113 -159 -35 106 25 37 7 112 35 21 -11 133 79 57 -89 52 131 51 -53 116 -111 92 -16 44 86 70 6 104 71 1 -72 30 121 149 -26 114 -25 -71 26 -139 47
// Output 2 :
// Exceeding limit!
// Input 3 :
// 8
// -152 -56 -166 20 -129 -42 40 -45
// Output 3 :
// -152 -166 -129 40 
// Note :

// You are using GCC
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct FileData {
    string fileName;
    int size;
    int arr[100]; 
};

int main() {
    FileData f;

    cin >> f.size;

    if (f.size > 100) {
        cout << "Exceeding limit!";
        return 0;
    }

    for (int i = 0; i < f.size; ++i)
        cin >> f.arr[i];

    f.fileName = "alt.txt";

    ofstream file(f.fileName);
    if (file.is_open()) {
        for(int i=0;i<f.size;i++){
            if(i%2==0){
                file << f.arr[i] << " ";
            }
        }
        file.close();
    }

    ifstream readFile(f.fileName);
    if (readFile.is_open()) {
        int num;
        while (readFile >> num) {
            cout << num << " ";
        }
        cout << endl;
        readFile.close();
    }

    return 0;
}