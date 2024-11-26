// Single File Programming Question
// Problem Statement



// Reema, a prospective computer science student, has developed a keen interest in data structures and algorithms. She has just been introduced to the concept of hash functions and is eager to build a basic hash table using the mid-square hashing method.



// Reema's assignment is to design a program that accepts a list of keys as input, employs the Mid-Square Hashing method (single digit 0–9) to hash these keys, and organizes them within a hash table (size 100). Her goal is to efficiently resolve any collisions by implementing linear probing.



// Example



// Input: 

// 6

// 13 15 16 17 18 19

// Output: 

// Index 2: Key 15

// Index 3: Key 18

// Index 5: Key 16

// Index 6: Key 13

// Index 7: Key 19

// Index 8: Key 17



// Explanation:



// The midSquareHash function is used to calculate the hash index for each key.

// For the key 13, the square is 169, and the middle digit is 6. So, hashIndex is set to 6 % 100 = 6.
// For the key 15, the square is 225, and the middle digit is 2. So, hashIndex is set to 2 % 100 = 2.
// For the key 16, the square is 256, and the middle digit is 5. So, hashIndex is set to 5 % 100 = 5.
// For the key 17, the square is 289, and the middle digit is 8. So, hashIndex is set to 8 % 100 = 8.
// For the key 18, the square is 324, and the middle digit is 2. So, hashIndex is set to 2 % 100 = 2. (Collision with key 15)
// For the key 19, the square is 361, and the middle digit is 6. So, hashIndex is set to 6 % 100 = 6. (Collision with key 13)


// Since there are collisions, linear probing is used to find the next available slot in the hash table.

// Key 15 is placed at index 2, Key 18 is placed at index 3, Key 16 is placed at index 5, Key 13 is placed at index 6, Key 19 is placed at index 7, and Key 17 is placed at index 8.

// Input format :
// The first line of input consists of an integer n, representing the number of keys to be inserted into the hash table.

// The second line of input consists of n integers representing the keys that Reema wants to hash.

// Output format :
// The output displays the value for each index in the hash table. Display the indices sorted in ascending order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases fall under the following constraints:

// table size = 100

// 1 <= keys <= 100


#include <iostream>
using namespace std;
// You are using GCC
int midSquareHash(int key, int tableSize, int r) {
    int square = key*key;
    int middleDigit = (square/10) % 10;
    int hashedIndex = middleDigit % tableSize;
    return hashedIndex;
}



int main() {
    int tableSize = 100;
    int numKeys;
    cin >> numKeys;
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        cin >> keys[i];
    }
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int hashIndex = midSquareHash(key, tableSize, 1);
        while (hashTable[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % tableSize;
        }
        hashTable[hashIndex] = key;
    }
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }
    return 0;
}