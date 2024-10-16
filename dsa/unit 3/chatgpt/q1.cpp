
// Single File Programming Question
// Problem Statement



// You are tasked with implementing a program to simulate multiple queues using linked lists. The program should allow enqueue and dequeue operations on the queues and display the contents of each queue. 



// The program should prompt the user for the number of queues (k) and the total number of customers (n). Then, for each customer, the program should prompt for the item and the queue number the customer wants to join. 



// After enqueuing all the customers, the program should print the contents of each queue in order, indicating the queue number and the items in each queue.

// Input format :
// The input begins with two integers k and n separated by a newline character.

// Then, n lines follow, each containing two integers: item and queueNumber, separated by space.

// Output format :
// The output consists of k lines.

// Each line represents a queue and contains the elements in that queue after dequeuing, separated by space.



// Refer to the sample output for the exact text and format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n, k ≤ 20

// 1 ≤ item ≤ 100

// Sample test cases :
// Input 1 :
// 2
// 5
// 1 0
// 2 1
// 3 0
// 4 1
// 5 0
// Output 1 :
// Queue 0: 1 3 5 
// Queue 1: 2 4 
// Input 2 :
// 3
// 8
// 10 2
// 20 1
// 30 0
// 40 2
// 50 1
// 60 0
// 70 2
// 80 0
// Output 2 :
// Queue 0: 30 60 80 
// Queue 1: 20 50 
// Queue 2: 10 40 70 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result // You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

Queue* createQueue() {
    Queue* queue = new Queue();
    queue->front = nullptr;
    queue->rear = nullptr;
    return queue;
}

void enqueue(Queue* queue, int item) {
    Node* newNode = new Node{item, nullptr};
    if(queue->rear){
        queue->rear->next= newNode;
    }else{
        queue->front = newNode;
    }
    queue->rear = newNode;
    
}

int dequeue(Queue* queue) {
    if(!queue->front){
        return -1;
        
    }
    Node* temp = queue->front;
    int item = queue->front->data;
    queue->front = queue->front->next;
    if(!queue->front){
        queue->rear = nullptr;
    }
    delete temp;
    return item;
}

void freeQueue(Queue* queue) {
    Node* curr = queue->front;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete queue;
}

int main() {
    int k, n;
    std::cin >> k >> n;

    Queue** queues = new Queue*[k];
    for (int i = 0; i < k; i++) {
        queues[i] = createQueue();
    }

    int item, qn;
    for (int i = 0; i < n; i++) {
        std::cin >> item >> qn;
        enqueue(queues[qn], item);
    }

    for (int i = 0; i < k; i++) {
        std::cout << "Queue " << i << ": ";
        while (queues[i]->front != nullptr) {
            int dequeued = dequeue(queues[i]);
            std::cout << dequeued << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < k; i++) {
        freeQueue(queues[i]);
    }
    delete[] queues;

    return 0;
}