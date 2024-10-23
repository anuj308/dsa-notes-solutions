// Single File Programming Question
// Problem Statement



// Shakthi is assigned to design and implement a program that simulates a customer queue system for a business. The program should allow users to enqueue customer IDs, dequeue customer IDs and display the current customer queue.



// Implement the queue using linked lists for Shakthi to manage the customers in line at the counter.

// Input format :
// The input consists of integer values, each representing an action to be taken:

// Option 1: Enqueue a new customer with a given customer ID. If option 1 is chosen, then the next line of input is the customer ID, which is a positive integer.

// Option 2: Dequeue the customer at the front of the line.

// Option 3: Display the current customer IDs in the line.

// Option 0: Exit the program.



// Any option other than 1, 2, 3, or 0 will be considered invalid.

// Output format :
// The program provides appropriate outputs based on the choice:



// When enqueuing a customer (option 1), the program outputs the customer ID that is added to the line in the format:

// "Customer ID [value] is enqueued"



// When dequeuing a customer (option 2), the program outputs the customer ID that is dequeued in the format:

// "Dequeued customer ID: [value]"

// If a dequeue operation is attempted when the queue is empty, the program outputs "Queue is empty"



// When displaying the customer IDs (option 3), the program shows the customer IDs currently in the line in the format:

// "Customer IDs in the queue are: " followed by the queue elements.

// If display operation is attempted when the queue is empty, the program outputs "Queue is empty"



// Print "Exiting program" while exiting the program.



// If the user provides any option other than 1, 2, 3, 0 then the program outputs "Invalid option"



// Refer to the sample output for the exact text and format.

// Code constraints :
// Each customer is represented by a unique customer ID, which is a positive integer.

// Sample test cases :
// Input 1 :
// 1
// 3
// 1
// 5
// 1
// 9
// 2
// 3
// 0
// Output 1 :
// Customer ID 3 is enqueued
// Customer ID 5 is enqueued
// Customer ID 9 is enqueued
// Dequeued customer ID: 3
// Customer IDs in the queue are: 5 9 
// Exiting program
// Input 2 :
// 1
// 10
// 1
// 20
// 3
// 2
// 3
// 0
// Output 2 :
// Customer ID 10 is enqueued
// Customer ID 20 is enqueued
// Customer IDs in the queue are: 10 20 
// Dequeued customer ID: 10
// Customer IDs in the queue are: 20 
// Exiting program
// Input 3 :
// 1
// 5
// 3
// 2
// 3
// 9
// 0
// Output 3 :
// Customer ID 5 is enqueued
// Customer IDs in the queue are: 5 
// Dequeued customer ID: 5
// Queue is empty
// Invalid option
// Exiting program
// Input 4 :
// 2
// 0
// Output 4 :
// Queue is empty
// Exiting program
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// i am doing this with array because i know that only now
// do in future sampale code

// You are using GCC
// #include <iostream>

// struct Node {
//     int customerID; 
//     Node* next;
// };

// struct Queue {
//     Node* front;
//     Node* rear;
// };

// void initializeQueue(Queue* q) {
//     q->front = nullptr;
//     q->rear = nullptr;
// }

// bool isEmpty(Queue* q) {
//     return q->front == nullptr;
// }

// void enqueue(Queue* q, int customerID) { 
//     q.rear++:
//     q.
    
// }

// bool dequeue(Queue* q, int& customerID) { 
//     //Type your code here
    
// }

// void display(Queue* q) {
//     //Type your code here
    
// }

// int main() {
//     Queue q;
//     int customerID;
//     int option;

//     initializeQueue(&q);

//     while (true) {
//         if (!(std::cin >> option)) {
//             break;
//         }

//         switch (option) {
//             case 1:
//                 if (!(std::cin >> customerID)) {
//                     break;
//                 }

//                 enqueue(&q, customerID);
//                 std::cout << "Customer ID " << customerID << " is enqueued" << std::endl;
//                 break;

//             case 2:
//                 if (dequeue(&q, customerID)) {
//                     std::cout << "Dequeued customer ID: " << customerID << std::endl;
//                 } else {
//                     std::cout << "Queue is empty" << std::endl;
//                 }
//                 break;

//             case 3:
//                 display(&q);
//                 break;

//             case 0:
//                 std::cout << "Exiting program" << std::endl;
//                 return 0;

//             default:
//                 std::cout << "Invalid option" << std::endl;
//                 break;
//         }
//     }

//     return 0;
// }


// done in arrry 

// You are using GCC
#include <iostream>

struct Queue {
    int front;
    int rear;
    int* arr;
};

void initializeQueue(Queue& q) {
    q.front = 0;
    q.rear = 0;
    q.arr = new int[9999];
}

bool isEmpty(Queue& q) {
    return q.front == q.rear;
}

void enqueue(Queue& q, int customerID) { 
    q.arr[q.rear]=customerID;
    q.rear++;
    std::cout << "Customer ID " << customerID << " is enqueued\n";
    
}

bool dequeue(Queue& q, int customerID) { 
    if(q.rear==q.front){
        std::cout << "Queue is empty\n";
    }
    else{
    std::cout << "Dequeued customer ID: " << q.arr[q.front] << std::endl;
    q.front++;
    }
}

void display(Queue& q) {
    if(q.rear==q.front){
        std::cout << "Queue is empty\n";
    }else{
        
    std::cout << "Customer IDs in the queue are: ";
    for(int i = q.front;i<q.rear;i++){
        std::cout << q.arr[i] << " ";
    }
    std::cout << std::endl;
    }
}

int main() {
    Queue q;
    int customerID;
    int option;

    initializeQueue(q);

    while (true) {
        if (!(std::cin >> option)) {
            break;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> customerID)) {
                    break;
                }

                enqueue(q, customerID);
                break;

            case 2:
                dequeue(q, customerID);
                break;

            case 3:
                display(q);
                break;

            case 0:
                std::cout << "Exiting program" << std::endl;
                return 0;

            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    return 0;
}