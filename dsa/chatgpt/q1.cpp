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


#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;                // Contact element (can be a string if required)
    Node* next;             // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node* header, int data) {
    Node* newNode = createNode(data);
    Node* temp = header;

    // Traverse to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* header) {
    Node* temp = header->next; // Start from the first actual node
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    // Create a header node
    Node* header = new Node();
    header->next = nullptr; // Initialize the header's next pointer to nullptr

    // Read contact elements and insert them into the list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtEnd(header, value);
    }

    // Print the contact list
    printList(header);

    // Free the allocated memory
    Node* current = header;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
