
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
// Linked List after deletion: 12 23 43 


#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int packageID;          // Package ID
    Node* next;            // Pointer to the next node
};

// Function to create a new node
Node* createNode(int packageID) {
    Node* newNode = new Node();
    newNode->packageID = packageID;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new package at the end of the list
void insertAtEnd(Node* header, int packageID) {
    Node* newNode = createNode(packageID);
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
        cout << temp->packageID << " ";
        temp = temp->next;
    }
}

// Function to delete a package from a specified position
void deleteAtPosition(Node* header, int position) {
    if (position <= 0) return; // Invalid position

    Node* temp = header;
    // Traverse to the node just before the desired position
    for (int i = 1; i < position && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    // If the next node is null, the position is out of bounds
    if (temp->next == nullptr) return;

    Node* toDelete = temp->next; // Node to delete
    temp->next = toDelete->next;  // Bypass the node to delete
    delete toDelete;               // Free the memory
}

int main() {
    int n;
    cin >> n;

    // Create a header node
    Node* header = new Node();
    header->next = nullptr; // Initialize the header's next pointer to nullptr

    // Read package IDs and insert them into the list
    for (int i = 0; i < n; i++) {
        int packageID;
        cin >> packageID;
        insertAtEnd(header, packageID);
    }

    // Print the linked list before deletion
    cout << "Linked List before deletion: ";
    printList(header);
    cout << endl;

    // Read the position to delete
    int position;
    cin >> position;

    // Delete the package at the specified position
    deleteAtPosition(header, position);

    // Print the linked list after deletion
    cout << "Linked List after deletion: ";
    printList(header);
    cout << endl;

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
