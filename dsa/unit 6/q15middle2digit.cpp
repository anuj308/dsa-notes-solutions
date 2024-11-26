// Single File Programming Question
// Problem Statement 



// Akil, a computer science student, is learning about hash tables and collision resolution techniques. He wants to implement a hash table with a size of 100 and use the mid-square hashing method to store a collection of keys. He's looking for a way to efficiently store these keys and resolve collisions using linear probing.



// Example

// Input 

// 5

// 80 65 40 60 98

// Output 

// Index 22: Key 65

// Index 40: Key 80

// Index 60: Key 40

// Index 61: Key 60

// Index 62: Key 98



// Explanation

// The mid-square hashing method is used to map each key to an index in a hash table of size 100.

// Collision occurs when two keys map to the same index. so linear probing is used to find the next available index.

// The final hash table stores the values as follows:

// Index 22: Key 65

// Index 40: Key 80 

// Index 60: Key 40 (collision resolved by linear probing)

// Index 61: Key 60 (collision resolved by linear probing)

// Index 62: Key 98 (collision resolved by linear probing)

// The output displays the index and the corresponding key values in the hash table after handling collisions.



// Note:

// The middle digits are found by dividing the key's square by 10 and then taking the remainder when divided by 100, then returning modulo to the table size (TABLE_SIZE).

// Input format :
// The first line of input consists of an integer, 'n', representing the number of keys Akil wants to store in the hash table.

// The second line of input consists of an integer 'key' representing the keys he wants to insert into the hash table.

// Output format :
// The output displays each line in the following format: "Index x: Key y" where 'x' is the index in the hash table and 'y' is the key.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:



// hash table size = 100

// 1 <= n<= 10

// 10 <= key <= 100

// Sample test cases :
// Input 1 :
// 5
// 80 65 40 60 98
// Output 1 :
// Index 22: Key 65
// Index 40: Key 80
// Index 60: Key 40
// Index 61: Key 60
// Index 62: Key 98
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;
#define TABLE_SIZE 100
int hashTable[TABLE_SIZE];// You are using GCC
void initializeHashTable() {
    for(int i=0;i< TABLE_SIZE;i++){
        hashTable[i] = -1;
    }
}

int midSquareHash(int key) {
    int square = key*key;
    int middleDigit = (square/10) % 100; // 100 so that we get 22 not 2 for 10
    int hashedIndex = middleDigit % TABLE_SIZE;
    return hashedIndex;
}

int linearProbe(int index) {
    
    while(hashTable[index] != -1){
        index = (index + 1 ) % TABLE_SIZE;
    }
    return index;
}



int main() {
    initializeHashTable();

    int n, key;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;

        int index = midSquareHash(key);

        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            int newIndex = linearProbe(index);
            hashTable[newIndex] = key;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }

    return 0;
}