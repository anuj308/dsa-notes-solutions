// Single File Programming Question
// Problem Statement



// Shiv wants to develop a program that manages customer orders in a restaurant using a queue data structure. The restaurant can handle a limited number of orders at a time, and the orders will be stored in an array-based queue.



// Your task is to assist Shiv in implementing the queue data structure and the associated functions, which will provide the necessary operations to manage the queue of customer orders.



// The main functionalities of the queue include:

// Enqueue: Adding a customer order to the end of the queue.
// Get Front: Retrieve the details of the first customer order in the queue.
// Get Rear: Retrieve the details of the last customer order in the queue.
// Input format :
// The first line of input consists of an integer N, which represents the capacity of the queue.

// The second line consists of N space-separated integers, representing the customer orders.

// Output format :
// The output displays the front and rear elements in the queue, representing the first and last customer orders.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The customer order values are positive integers.

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// Output 1 :
// Front element: 10
// Rear element: 50
// Input 2 :
// 3
// 5 8 2
// Output 2 :
// Front element: 5
// Rear element: 2
// Note :

// You are using GCC
#include <iostream>

struct Queue {
    int* arr;        // array to store queue elements
    int front;       // front points to the front element in the queue
    int rear;        // rear points to the last element in the queue
    int capacity;    // maximum capacity of the queue
    int size;        // current size of the queue
};

void initializeQueue(Queue& q, int capacity) {
    q.capacity = capacity;
    q.front = 0;
    q.rear = 0;
    q.arr = new int[capacity];
    q.size = capacity;
}

bool isEmpty(const Queue& q) {
    return q.size == 0;
}

bool isFull(const Queue& q) {
    return q.size == q.capacity;
}

void enqueue(Queue& q, int item) {
    if(q.front == q.size){
        std::cout << "Queue full " << std::endl;
    }
    else{
        // cout << item;
        q.arr[q.rear]=item;
        q.rear++;
    }
    
}

int getFront(const Queue& q) {
    return q.arr[q.front];
}

int getRear(const Queue& q) {
    return q.arr[q.rear - 1];
}

int main() {
    int N;
    std::cin >> N;

    Queue queue;
    initializeQueue(queue, N); // Creating a queue of capacity N

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        enqueue(queue, num);
    }

    std::cout << "Front element: " << getFront(queue) << std::endl;
    std::cout << "Rear element: " << getRear(queue) << std::endl;

    delete[] queue.arr;

    return 0;
}