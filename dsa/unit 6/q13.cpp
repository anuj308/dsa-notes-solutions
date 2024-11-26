// Single File Programming Question
// Problem Statement



// Roshene is a diligent student learning about hash tables and the quadratic probing method. She needs your help implementing a program that calculates her best mark using this method.



// Write a program to help Roshene find and display this information using quadratic probing to handle collisions in a hash table. Calculate a hash index for each mark using the modulo operation (% tableSize).

// Input format :
// The first line of input consists of an integer N, representing the number of marks Roshene has received.

// The second line consists of N integers, separated by spaces, representing the marks she received.

// Output format :
// The output displays the best mark and the index (0-based) in the hash table where the best mark is stored.



// Refer to the sample output for the exact text and format.

// Code constraints :
// tableSize = 10

// Sample test cases :
// Input 1 :
// 5
// 98 97 92 78 94
// Output 1 :
// Best Mark: 98, Index: 8
// Input 2 :
// 4
// 89 94 95 56
// Output 2 :
// Best Mark: 95, Index: 5
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.



#include <iostream>
using namespace std;
// You are using GCC
void readKeys(int keys[], int numKeys) {
    for(int i=0;i<numKeys;i++){
        cin >> keys[i];
    }
}

void initializeHashTable(int hashTable[], int tableSize) {
    for(int i=0;i<tableSize;i++){
        hashTable[i] = -1;;
    }
}

void insertKey(int hashTable[], int tableSize, int key) {
     
         int hashedIndex = key % tableSize;
         int i=1;
         while(hashTable[hashedIndex]!=-1){
             hashedIndex = (hashedIndex + i*i) % tableSize;
             i++;
         }
        hashTable[hashedIndex] = key;
    
    
}

void findBestMark(int hashTable[], int tableSize, int& bestMark, int& index) {
    bestMark = -999;
     
    for(int i=0;i<tableSize;i++){
        if(hashTable[i]>bestMark){
            bestMark = hashTable[i];
            index = i;
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

    for (int i = 0; i < numKeys; i++) {
        insertKey(hashTable, tableSize, keys[i]);
    }

    int bestMark, index;
    findBestMark(hashTable, tableSize, bestMark, index);
    cout << "Best Mark: " << bestMark << ", Index: " << index;

    return 0;
}