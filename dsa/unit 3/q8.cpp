// Single File Programming Question
// Problem Statement



// Imagine you are given a series of integers, and your task is to process them using a queue data structure. 



// Implement a program to perform the following operations:

// Initialize an empty queue.
// Read an integer N from the standard input. This integer represents the number of elements to be processed.
// Read N integers from the standard input and enqueue them into the queue one by one.
// Calculate the sum of all the elements in the queue.
// Output the sum to the standard output.
// Input format :
// The first line of input consists of an integer N, representing the number of elements in the queue.

// The second line consists of N space-separated integers, each representing an element of the queue.

// Output format :
// If the queue is empty, print "Queue is empty." on a new line.

// Otherwise, print the sum of the numbers in the queue.



// Refer to the sample output for formatting specifications.

// Code constraints :
// -100 ≤ element ≤ 100

// The maximum capacity of the queue is 100.

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// 15
// Input 2 :
// 3
// 10 -20 30
// Output 2 :
// 20
// Input 3 :
// 0
// Output 3 :
// Queue is empty.
// Note :
// You are using GCC
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int frontIdx;
    int rearIdx;
    int count;

public:
    Queue() {
        frontIdx = 0;
        rearIdx = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int element) {
        arr[rearIdx]=element;
        rearIdx++;
        count++;
        // cout << rearIdx << endl;
    }

    void dequeue() {
        frontIdx--;
        count--;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return frontIdx;
    }
        int rear() {
        if (isEmpty()) {
            return -1;
        }

        return rearIdx;
    }
    
    int getElement(int index){
        return arr[index];
    }

};

void findQueueSum(Queue& q) {
    int sum =0;
    // cout << q.front() << " " << q.rear() << endl;
    if(q.front()==q.rear()){
        cout << "Queue is empty.\n";
    }else{
        
    for(int i= q.front();i<q.rear();i++){
        sum+=q.getElement(i);
    }
    cout <<  sum;
    }
        
}

int main() {
    Queue q;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        q.enqueue(element);
    }

    // if (q.isEmpty()) {
    //     cout << "Queue is empty." << endl;
    //     // cout << 0 << endl;
    // } else {
    findQueueSum(q);
        // cout << sum << endl;
    // }

    return 0;
}