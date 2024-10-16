// Single File Programming Question
// Problem Statement



// Aaron is learning data structures, and his teacher gave him a task related to the queue data structure. The queue should be implemented as a linked list, where each node holds a customer's ID.



// He is required to implement a simple program that supports the following operations:

// Enqueue: Add a customer's ID to the end of the queue.
// Dequeue: Remove and return the customer's ID from the front of the queue.
// Display: Display the current customer IDs in the queue.


// Your task is to help Aaron implement the operations mentioned above.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Enqueue the customer ID into the queue. If the choice is 1, the following input is a space-separated integer, representing the customers' ID to be enqueued into the queue.

// Choice 2: Dequeue a customer ID from the queue.

// Choice 3: Display the customer IDs in the queue.

// Choice 4: Exit the queue

// Output format :
// The output displays messages according to the choice and the status of the queue:



// If the choice is 1:

// Insert the given customer ID into the queue and display "Customer ID X is enqueued" where X is the customer ID that is inserted.
// If the choice is 2:

// Dequeue a customer ID from the queue and display "Dequeued customer ID: " followed by the corresponding ID that is dequeued.
// If the queue is empty without any elements, print "Queue is empty".
// If the choice is 3:

// The output prints "Customer IDs in the queue are: " followed by the space-separated customer IDs present in the queue.
// If there are no elements in the queue, print "Queue is empty".
// If the choice is 4:

// Exit the program.
// If any other choice is entered, print "Invalid option".



// Refer to the sample output for the exact text and format.

// Code constraints :
// Choice: 1, 2, or 3.

// Sample test cases :
// Input 1 :
// 1 24
// 1 36
// 1 47
// 3
// 2
// 2
// 3
// 4
// Output 1 :
// Customer ID 24 is enqueued
// Customer ID 36 is enqueued
// Customer ID 47 is enqueued
// Customer IDs in the queue are: 24 36 47 
// Dequeued customer ID: 24
// Dequeued customer ID: 36
// Customer IDs in the queue are: 47 
// Input 2 :
// 1 54
// 1 36
// 3
// 2
// 2
// 2
// 3
// 4
// Output 2 :
// Customer ID 54 is enqueued
// Customer ID 36 is enqueued
// Customer IDs in the queue are: 54 36 
// Dequeued customer ID: 54
// Dequeued customer ID: 36
// Queue is empty
// Queue is empty
// Input 3 :
// 1 15
// 1 19
// 3
// 2
// 3
// 4
// Output 3 :
// Customer ID 15 is enqueued
// Customer ID 19 is enqueued
// Customer IDs in the queue are: 15 19 
// Dequeued customer ID: 15
// Customer IDs in the queue are: 19 
// Input 4 :
// 5
// 3
// 4
// Output 4 :
// Invalid option
// Queue is empty
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.