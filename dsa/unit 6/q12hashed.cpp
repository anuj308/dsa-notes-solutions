// Single File Programming Question
// Problem Statement



// Aaron, a computer science student, is working on a project that involves implementing a hash table using the division method for linear probing and resolving collisions.



// He needs to create a program that will efficiently store customer IDs in a hash table with a fixed size of 10. His program must handle cases where multiple customer IDs might map to the same index in the table due to the hash function.

// Input format :
// The first line of input consists of an integer N, representing the number of customers.

// The second line of input consists of N space-separated integers, representing the customer IDs.

// Output format :
// The output display for each slot in the hash table, if it's occupied by a customer ID, prints the following line:

// "Table number: [X]: Customer ID [Y]"

// where, X is the index number (0 to 9), Y is the customer ID stored in that index. Print it in the ascending order of the index.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// table size = 10

// 1 <= customer ID <= 1000

// Sample test cases :
// Input 1 :
// 5
// 102 201 210 310 410
// Output 1 :
// Table number 0: Customer ID 210
// Table number 1: Customer ID 201
// Table number 2: Customer ID 102
// Table number 3: Customer ID 310
// Table number 4: Customer ID 410
// Input 2 :
// 6
// 120 115 102 203 110 130
// Output 2 :
// Table number 0: Customer ID 120
// Table number 1: Customer ID 110
// Table number 2: Customer ID 102
// Table number 3: Customer ID 203
// Table number 4: Customer ID 130
// Table number 5: Customer ID 115
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;
// You are using GCC
int divisionMethod(int key, int tableSize) {
    return key%tableSize;
}

void readKeys(int keys[], int numKeys) {
    for(int i=0;i<numKeys;i++){
        cin >> keys[i];
    }
}

void initializeHashTable(int hashTable[], int tableSize) {
     for(int i=0;i<tableSize;i++){
            hashTable[i] = -1;
    }
}

void insertKeys(int hashTable[], int tableSize, int keys[], int numKeys) {
    
    for(int i=0;i<numKeys;i++){
        int hashedIndex = divisionMethod(keys[i],tableSize);
        
        while(hashTable[hashedIndex]!=-1){
            hashedIndex = (hashedIndex + 1)%tableSize;
        }
        hashTable[hashedIndex]=keys[i];
    }
}

void printHashTable(int hashTable[], int tableSize) {
    
    for(int i=0;i<tableSize;i++){
        if(hashTable[i]!=-1){
            cout << "Table number " << i << ": Customer ID " << hashTable[i] << endl;
        }
    }
}
int main() {
    const int tableSize = 10;
    int numKeys;
    cin >> numKeys;

    int keys[numKeys];
    readKeys(keys, numKeys);

    int hashTable[tableSize];
    initializeHashTable(hashTable, tableSize);

    insertKeys(hashTable, tableSize, keys, numKeys);
    
    printHashTable(hashTable, tableSize);

    return 0;
}