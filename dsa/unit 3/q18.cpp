// Single File Programming Question
// Problem Statement



// In a bustling IT department, staff regularly submit helpdesk tickets to request technical assistance. Managing these tickets efficiently is vital for providing quality support.



// Your task is to develop a program that uses an array-based queue to handle and prioritize helpdesk tickets based on their unique IDs.



// Implement a program that provides the following functionalities:

// Enqueue Helpdesk Ticket: Add a new helpdesk ticket to the end of the queue. Provide a positive integer representing the ticket ID for the new ticket.
// Dequeue Helpdesk Ticket: Remove and process the next helpdesk ticket from the front of the queue. The program will display the ticket ID of the processed ticket.
// Display Queue: Display the ticket IDs of all the helpdesk tickets currently in the queue.
// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Enqueue the ticket ID into the queue. If the choice is 1, the following input is a space-separated integer, representing the ticket ID to be enqueued into the queue.

// Choice 2: Dequeue a ticket from the queue.

// Choice 3: Display the ticket IDs in the queue.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the queue:



// If the choice is 1:

// Insert the given ticket ID into the queue and display "Helpdesk Ticket ID [id] is enqueued." where [id] is the ticket ID that is inserted.
// If the queue is full, print "Queue is full. Cannot enqueue."
// If the choice is 2:

// Dequeue a ticket ID from the queue and display "Dequeued Helpdesk Ticket ID: " followed by the corresponding ID that is dequeued.
// If the queue is empty without any elements, print "Queue is empty."
// If the choice is 3:

// The output prints "Helpdesk Ticket IDs in the queue are: " followed by the space-separated ticket IDs present in the queue.
// If there are no elements in the queue, print "Queue is empty."
// If the choice is 4:

// Exit the program and print "Exiting the program"
// If any other choice is entered, print "Invalid option."



// Refer to the sample output for formatting specifications.

// Code constraints :
// Maximum number of helpdesk tickets stored in the queue is 5.

// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 101
// 1 202
// 1 203
// 1 204
// 1 205
// 1 206
// 3
// 2
// 3
// 4
// Output 1 :
// Helpdesk Ticket ID 101 is enqueued.
// Helpdesk Ticket ID 202 is enqueued.
// Helpdesk Ticket ID 203 is enqueued.
// Helpdesk Ticket ID 204 is enqueued.
// Helpdesk Ticket ID 205 is enqueued.
// Queue is full. Cannot enqueue.
// Helpdesk Ticket IDs in the queue are: 101 202 203 204 205
// Dequeued Helpdesk Ticket ID: 101
// Helpdesk Ticket IDs in the queue are: 202 203 204 205
// Exiting the program
// Input 2 :
// 2
// 1 105
// 5
// 4
// Output 2 :
// Queue is empty.
// Helpdesk Ticket ID 105 is enqueued.
// Invalid option.
// Exiting the program
// Input 3 :
// 1 105
// 3
// 2
// 3
// 2
// 4
// Output 3 :
// Helpdesk Ticket ID 105 is enqueued.
// Helpdesk Ticket IDs in the queue are: 105
// Dequeued Helpdesk Ticket ID: 105
// Queue is empty.
// Queue is empty.
// Exiting the program