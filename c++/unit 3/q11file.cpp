// Single File Programming Question
// Problem Statement



// Saakshi wants to create a C++ program that takes two integer inputs 'a' and 'b' from the user. The program then writes all even numbers from 'a' to 'b' (inclusive) to a file named "even.txt," each on a separate line. Finally, it reads and displays the contents of "even.txt" to the console.

// Input format :
// The input consists of two space-separated integers: a and b.

// Output format :
// The output prints all the even numbers present from a to b(inclusive) in separate lines.

// Code constraints :
// -105 <= a < b <= 105

// Sample test cases :
// Input 1 :
// -8 9
// Output 1 :
// -8
// -6
// -4
// -2
// 0
// 2
// 4
// 6
// 8
// Input 2 :
// 0 16
// Output 2 :
// 0
// 2
// 4
// 6
// 8
// 10
// 12
// 14
// 16
// Note :


#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    
    int a,b;
    cin >> a >> b;
    
    ofstream file;
    file.open("even.txt",ios::in | ios::app);
    
    if(!file.is_open()){
        cout << "error on opening file\n";
    }
    int n=0;
    for(int i=a; i<=b; i++){
        if(i%2==0){
            file <<  i << endl;
            n++;
        }
    }
    file.close();
    
    ifstream inputFile("even.txt");
    
    int c=0;
    string h;
    while(getline(inputFile,h)){
        cout << h << endl;
    }
    inputFile.close();
    return 0;
}