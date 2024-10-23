// Single File Programming Question
// Problem Statement



// Ashok, a retail store manager wants to keep track of the items in inventory using a two-way linked list. Each item has an ID, name, quantity, and price. The manager needs to be able to insert new items at the beginning of the list and search for an item by its ID to check its presence. 



// Your task is to create a program to help Ashok manage the inventory and perform searches efficiently.



// Company Tags: Amazon

// Input format :
// The first line of input contains an integer n representing the number of items to be added to the inventory.

// The next n lines each contain:

// An integer representing the item ID.
// A string representing the item name.
// An integer representing the item quantity.
// A double value representing the item price.
// The last line contains an integer representing the ID of the item to be searched.

// Output format :
// Print a message indicating whether the item with the given ID is present in the list.



// Refer to the sample output for the exact format.

// Code constraints :
// 1 ≤ n ≤ 20

// Sample test cases :
// Input 1 :
// 3
// 101
// Pen
// 10
// 5.99
// 102
// Notebook
// 5
// 12.99
// 103
// Pencil
// 20
// 1.99
// 101
// Output 1 :
// Item with ID 101 is present in the list.
// Input 2 :
// 2
// 201
// Chair
// 8
// 49.99
// 202
// Table
// 3
// 99.99
// 203
// Output 2 :
// Item with ID 203 is not found in the list.
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the


#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int id;
    string name;
    int quantity;
    double price;
    Node* next;
    Node* prev;

    Node(int id, string name, int quantity, double price) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
        next = nullptr;
        prev = nullptr;
    }
};

class Inventory {
public:
    Node* head;

    Inventory() {
        head = nullptr;
    }

    void insertItemAtBeginning(int id, string name, int quantity, double price) {
        Node* newNode = new Node(id, name, quantity, price);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    bool searchItemById(int id) {
        Node* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    Inventory inventory;
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        int quantity;
        double price;
        cin >> id;
        cin.ignore();
        getline(cin, name);
        cin >> quantity >> price;
        inventory.insertItemAtBeginning(id, name, quantity, price);
    }
    int searchId;
    cin >> searchId;
    if (inventory.searchItemById(searchId)) {
        cout << "Item with ID " << searchId << " is present in the list." << endl;
    } else {
        cout << "Item with ID " << searchId << " is not found in the list." << endl;
    }
    return 0;
}