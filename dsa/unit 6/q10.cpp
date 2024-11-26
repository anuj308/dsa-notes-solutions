// /Single File Programming Question
// Problem Statement



// Deva works at a bustling supermarket, and he's looking for an efficient way to manage the products on the store shelves.



// He wants to use a hash table with linear probing to keep track of the available slots on the shelves and optimize product placement. Help him write a program that manages the product slots using this approach.



// Example



// Input 

// 6 

// 5

// 15 30 9 21 12

// Output 

// 3 0 4 5 1 



// Explanation



// In the product code allocation process, key 15 is hashed to index 3, resulting in "3" as it's stored in an empty slot. Similarly, key 30 is placed in index 0, yielding "0." Key 9 and 21 both map to index 3, invoking linear probing. Key 9 finds a slot at index 4, resulting in "4," while key 21 is stored at index 5, producing "5." Lastly, key 12 is hashed to index 0, leading to linear probing, and it's managed at index 1, printing "1."



// Note



// A hash function to determine the initial index for each key in a hash table, utilizing the modulo operation (key%size).

// Input format :
// The first line of input consists of an integer N, representing the size of the hash table.

// The second line of input consists of an integer K, representing the number of product slots.

// The third line of input consists of K integers, representing the product slots, separated by a space.

// Output format :
// The output displays product slots as space-separated integers, each representing the hash index of a product slot.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ K ≤ 100

// Sample test cases :
// Input 1 :
// 6 
// 5
// 15 30 9 21 12
// Output 1 :
// 3 0 4 5 1 
// Input 2 :
// 10
// 5
// 123 456 789 321 654
// Output 2 :
// 3 6 9 1 4 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;
int SIZE = 100;

int calHash(int key, int size)
{
    return key % size;
}

int main() {
    int size;
    int n;
    
    cin >> size;
    cin >> n;
    int arr[size];
    
    int ans =0;
    int store[100];
    for(int i=0;i<100;i++){ // allway use loop in array for assign value
        store[i] = -1;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans = calHash(arr[i],size);
        
        // cout << store[ans] << ans << endl;
        while(store[ans]!=-1){
            ans = (ans + 1) % size; 
        }
        store[ans]=arr[i];
        
        cout << ans << " ";
    }
    return 0;
}
    