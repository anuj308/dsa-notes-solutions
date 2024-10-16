// Single File Programming Question
// Problem Statement



// A teacher in a class implements a program that manages the coordinates of a point in a 2D plane. The program defines a class called Coordinates that stores the X and Y coordinates of the point and overloads the unary ++ operator to increment both X and Y by 1 unit. 



// Help the teacher write a program to take user input for the initial coordinates, apply the increment operator, and output the updated coordinates.

// Input format :
// The input consists of two space-separated integers representing the coordinates X and Y.

// Output format :
// After applying the decrement operation, the output displays the updated coordinates, separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ X, Y ≤ 100

// Sample test cases :
// Input 1 :
// 10 9
// Output 1 :
// 11 10
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class Coordinates{
    public:
        int x;
        int y;
        Coordinates(int x1,int y1){
            this->x=x1;
            this->y=y1;
        }
        void operator ++(){
            x++;
            y++;
            cout << x << " " << y << endl;
        }
};

int main(){
    int x,y;
    cin >> x;
    cin >> y;
    Coordinates c1(x,y);
    ++c1;
    
    return 0;
}