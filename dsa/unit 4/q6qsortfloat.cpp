// Single File Programming Question
// Problem Statement



// Tao is the dean of a university and needs to rank students based on their GPA for the academic awards ceremony. To prepare the list, Tao has collected the GPAs of all students and wants to sort them in descending order so that the highest GPA is at the top.



// Help Tao by writing a program that reads the GPAs of the students and sorts them in descending order using the quicksort algorithm.

// Input format :
// The first line contains an integer n, representing the number of students.

// The second line consists of a floating-point number representing a student's GPA.

// Output format :
// The output displays the float-point numbers sorted list of GPAs in descending order, separated by spaces, with each GPA rounded to one decimal place.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1.0 ≤ GPA ≤ 10.0

// Sample test cases :
// Input 1 :
// 3
// 3.6 4.4 2.9 
// Output 1 :
// 4.4 3.6 2.9 
// Input 2 :
// 6
// 1.2 4.9 3.5 2.7 5.0 3.1
// Output 2 :
// 5.0 4.9 3.5 3.1 2.7 1.2 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

void swap(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}

int partition(float arr[], int low, int high) 
{
    float pivot = arr[high];
    int i = (low - 1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]>pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(float arr[], int low, int high) 
{
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main() {
    int numStudents;

    cin >> numStudents;

    float* gpa = new float[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cin >> gpa[i];
    }

    quickSort(gpa, 0, numStudents - 1);

    for (int i = 0; i < numStudents; i++) {
        cout << fixed << setprecision(1) << gpa[i] << " ";
    }

    delete[] gpa; 

    return 0;
}
