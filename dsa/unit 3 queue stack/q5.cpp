// Single File Programming Question
// Problem Statement



// Imagine you are designing an event registration system for a conference. As part of the system, you need to implement a queue data structure using an array that stores only the even numbers representing the registration IDs of the participants. 



// The queue will be used to keep track of the order in which participants register for the event.

// Input format :
// The first line of input consists of an integer n, representing the number of participants to register.

// The second line consists of n integers, representing the registration IDs of the participants.

// Output format :
// The output prints only the even number registration IDs of the participants in the order they registered, separated by space.

// For odd registration IDs, print "Invalid element [element], only even numbers can be enqueued".



// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum size of the queue is 100.

// Sample test cases :
// Input 1 :
// 6
// 2 4 6 8 10 12
// Output 1 :
// 2 4 6 8 10 12 
// Input 2 :
// 4
// 14 36 55 48
// Output 2 :
// Invalid element 55, only even numbers can be enqueued
// 14 36 48 
// Input 3 :
// 5
// 45 67 24 65 78
// Output 3 :
// Invalid element 45, only even numbers can be enqueued
// Invalid element 67, only even numbers can be enqueued
// Invalid element 65, only even numbers can be enqueued
// 24 78 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of th

// You are using GCC
#include <iostream>

const int MAX_SIZE = 100;

struct EvenNumberQueue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(EvenNumberQueue& q) {
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(const EvenNumberQueue& q) {
    return q.front == -1;
}

bool isFull(const EvenNumberQueue& q) {
    return q.rear == MAX_SIZE - 1;
}

void enqueue(EvenNumberQueue& q, int data) {

        if(data%2!=0){
            std::cout << "Invalid element " << data << ", only even number can be enqueued\n";
        }else{
        q.rear++;
        q.queue[q.rear]=data;
        }
    
}

void display(const EvenNumberQueue& q) {
    for(int i = q.front;i<=q.rear;i++){
        std::cout << q.queue[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    EvenNumberQueue queue;
    initializeQueue(queue);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        enqueue(queue, element);
    }

    display(queue);

    return 0;
}