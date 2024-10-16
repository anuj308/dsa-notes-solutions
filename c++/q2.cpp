// Single File Programming Question
// Problem Statement



// Jessica, a teacher, uses a grid to record student performance scores in various subjects. To get an overview, she needs to replace each score in a row with the product of scores in that row. Develop a program for her to update the grid so each element is the product of its row, with scores ranging from 1 to 9.

// Input format :
// The first line of input consists of an integer T, representing the number of test cases.

// For each test case:

// The first line contains two integers R and C, representing the number of rows and columns.
// The next R lines each contain C space-separated integers, where each integer is between 1 and 9, representing the scores in the grid.
// Output format :
// For each test case, print the updated matrix where each element in a row is replaced by the product of all elements in that row.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ T ≤ 10

// 1 ≤ R, C ≤ 5

// 1 ≤ scores ≤ 9

// Sample test cases :
// Input 1 :
// 2 
// 3 4
// 1 2 1 2
// 4 5 6 1
// 7 8 9 3
// 2 5
// 1 2 3 5 7
// 3 4 8 9 6
// Output 1 :
// 4 4 4 4 
// 120 120 120 120 
// 1512 1512 1512 1512 
// 210 210 210 210 210 
// 5184 5184 5184 5184 5184 
// Input 2 :
// 1
// 3 3 
// 4 6 8 
// 4 2 7 
// 7 3 9 
// Output 2 :
// 192 192 192 
// 56 56 56 
// 189 189 


#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int row[11];
    int col[11];
    int t=0;
    int arr[100][100];
    
    while(t<n){
    int n1,n2;
    cin >> n1;
    cin >> n2;
    row[t]=n1;
    col[t]=n2;
    int p=1;
    // cout << "start";
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin >> arr[i][j];
            p*=arr[i][j];
            // cout << p << " ";
        }
        // cout << "i" <<  i << "p" << p << endl;
        for(int u=0;u<n2;u++){
            // cout << "run " << " " << u << " " << endl;
            arr[i][u]=p;
            cout << arr[i][u] << " ";
        }
        cout << endl;
        p=1;
    }
    // cout << "end";
    t++;
    }
    return 0;
}