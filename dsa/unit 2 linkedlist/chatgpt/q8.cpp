// Single File Programming Question
// Problem Statement



// Jenna is organizing her bookshelf and wants to track the order of books she places on the shelf. She decides to use a two-way linked list for this purpose. Jenna can insert a book at the beginning of the shelf. Once all books are placed, she wants to reverse the order of the books on the shelf. 



// Write a program to help Jenna manage her bookshelf.

// Input format :
// The first line of input contains an integer n, representing the number of books Jenna places on the shelf.

// The second line contains n space-separated integers, representing the book IDs.

// Output format :
// The first line of output prints the original list.

// The second line prints the reversed list.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 25

// 1 ≤ books ID ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 12 34 65
// Output 1 :
// Original List: 65 34 12 
// Reversed List: 12 34 65 
// Input 2 :
// 6
// 12 34 56 78 31 45
// Output 2 :
// Original List: 45 31 78 56 34 12 
// Reversed List: 12 34 56 78 31 45 
#include <iostream>

using namespace std;

class Node {
public:
    int id;
    Node* next;
    Node* prev;

    Node(int id) {
        this->id = id;
        next = nullptr;
        prev = nullptr;
    }
};

class Bookshelf {
public:
    Node* head;

    Bookshelf() {
        head = nullptr;
    }

    void insertBookAtBeginning(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void reverseBookshelf() {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printBookshelf(const string& label) {
        Node* current = head;
        cout << label << ": ";
        while (current != nullptr) {
            cout << current->id << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Bookshelf bookshelf;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        bookshelf.insertBookAtBeginning(id);
    }
    bookshelf.printBookshelf("Original List");
    bookshelf.reverseBookshelf();
    bookshelf.printBookshelf("Reversed List");
    return 0;
}