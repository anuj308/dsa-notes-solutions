// Single File Programming Question
// Problem Statement



// Madhan is developing a contact management system for a mobile application. The system allows users to maintain a list of their contacts. Whenever a user adds a new contact, the system should add it at the end of the contact list.



// Write a program for Madhan to implement the code to perform insertion at the end using a grounded header linked list.



// Company Tags: TCS

// Input format :
// The first line of input consists of the size n of the contact list.

// The second line consists of n contact elements.

// Output format :
// The output represents the contact list with the contacts added at the end.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 1 ≤ contact elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// 1 2 3 4 5 
// Input 2 :
// 8
// 13 45 67 82 29 35 72 91
// Output 2 :
// 13 45 67 82 29 35 72 91 


// Single File Programming Question
// Problem Statement



// In a warehouse, a system keeps track of packages using a grounded header linked list where each node represents a package. Each package is added to the end of the list. Sometimes, packages need to be removed from specific positions in the list. 



// Your task is to implement this system which can add packages to the list, display the list, and remove a package from a specified position.

// Input format :
// The first line contains an integer, n, which represents the number of packages to be added to the list.

// The second line contains n integers, each representing the ID of a package.

// The third line contains an integer, position, which indicates the position of the package to be removed from the list (1-based index).

// Output format :
// The first line of output represents the elements before deletion and the next line represents the remaining elements in the linked list after deleting the particular value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 25

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// 2
// Output 1 :
// Linked List before deletion: 10 20 30 40 50 
// Linked List after deletion: 10 30 40 50 
// Input 2 :
// 5
// 12 23 43 56 89
// 5
// Output 2 :
// Linked List before deletion: 12 23 43 56 89 
// Linked List after deletion: 12 23 43 5


// Single File Programming Question
// Problem Statement



// Emma is working with two sets of sensor data recorded in two separate grounded header linked lists. She wants to merge these two lists alternately to analyze the combined data more efficiently. 



// Help Emma by writing a program to merge the two grounded header linked lists alternately.



// Company Tags: TCS

// Input format :
// The first line of input consists of the number of elements n in the first list.

// The second line consists of n elements, separated by space.

// The third line consists of the number of elements m in the second list.

// The fourth line consists of m elements, separated by space.

// Output format :
// The output prints the merged linked list with nodes from both lists alternately.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 5
// 6 7 8 9 10
// Output 1 :
// 1 6 2 7 3 8 4 9 5 10 
// Input 2 :
// 4
// 12 26 34 48
// 4
// 56 59 64 78
// Output 2 :
// 12 56 26 59 34 64 48 78 