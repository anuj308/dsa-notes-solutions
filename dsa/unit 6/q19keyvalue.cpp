// Single File Programming Question
// Problem Statement



// You are assigned the task of developing a basic student database management system using a hash table with linear probing for collision resolution. Your program should facilitate the insertion of student records and allow efficient retrieval of student names based on their unique IDs.

// Input format :
// The first line of input consists of an integer N, representing the number of student records to insert.

// The following N lines consist of IDs and names of students, separated by space.

// The last line consists of an integer, representing the ID of the student name to be retrieved.

// Output format :
// The output prints a single line that says Student name: followed by the name of the student if found.

// If the student is not found, print Student name: Student not found.



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// HASH_SIZE = 1000

// 1 ≤ N ≤ 8

// 1 ≤ ID ≤ 10000

// Sample test cases :
// Input 1 :
// 3
// 101 Alice
// 202 Bob
// 303 Charlie
// 101
// Output 1 :
// Student name: Alice
// Input 2 :
// 2
// 123 John
// 456 Jane
// 789
// Output 2 :
// Student name: Student not found
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// Marks : 10
// Negative Marks : 0

#include <bits/stdc++.h>
using namespace std;

#define hashSize 1000

struct student{
    int id;
    string name;
    bool navl; //not  avaliable
};

int main(){
    int n;
    cin >> n;
  
    student hash[hashSize];
    for(int i=0;i<hashSize;i++){
        hash[i].navl = false;
    }
    for(int i=0;i<n;i++){
        int id;
        string name;
        cin >> id >> name;
        int index = id % hashSize;
        while(hash[index].navl){
            index = (index + 1) % hashSize;
        }
        hash[index].id = id;
        hash[index].name = name;
        hash[index].navl = true;
}

    int x;
    cin >> x;
    
   bool found = false;
        int hashed = x % hashSize;
        while(hash[hashed].navl){
            if(hash[hashed].id == x){
                cout << "Student name: " << hash[hashed].name << endl;
                found = true;
                break;
            }
            hashed = (hashed + 1) % hashSize;
        }
    
    
   if(!found){
        cout << "Student name: Student not found";
    }
    
    return 0;
}