// Single File Programming Question
// Problem Statement



// Daniel has a singly linked list and wants to delete the middle node from the list. If there are two middle nodes (in the case of an even number of nodes), the second one should be considered the middle node and deleted. Otherwise, the single middle node is deleted. Write a program to help Daniel delete this middle node.



// For example, if the given linked list is 1->2->3->4->5 then the linked list should be modified to 1->2->4->5.

// For example, if the given linked list is 1->2->3->4->5->6, then it should be modified to 1->2->3->5->6.



// Company Tags: CTS

// Input format :
// The first line of input consists of an integer n, representing the number of elements in the linked list.

// The second line contains n space-separated integers, each representing an element of the linked list.

// Output format :
// The first line of output displays "Original Linked List: " followed by the elements of the linked list before deletion.

// The second line displays "Updated Linked List: " followed by the elements of the linked list after deletion of the middle node.



// Refer to the sample output for format specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// -50000 ≤ values of nodes ≤ 50000

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Original Linked List: 1 2 3 4 5 
// Updated Linked List: 1 2 4 5 
// Input 2 :
// 6
// 1 2 3 4 5 6
// Output 2 :
// Original Linked List: 1 2 3 4 5 6 
// Updated Linked List: 1 2 3 5 


// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteMiddleNode(Node **head,int n) {
    struct Node *last = *head;
    struct Node *temp;
    int del =n/2;
    // cout << del << endl;
    int t=1;
    while(t<=del){
        // cout << t << " ";
        if(t==del){
            temp = last->next;
            last->next=last->next->next;
            delete temp;
        }
        last=last->next;
        t++;
    }
    
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    cout << "Original Linked List: ";
    displayList(head);

    deleteMiddleNode(&head,size);

    cout << "Updated Linked List: ";
    displayList(head);

    Node* temp = head;
    while (head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }

    return 0;
}