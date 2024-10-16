// Single File Programming Question
// Problem Statement



// Lena is a librarian managing a list of books in her library. Each book is represented by an integer ID. Lena needs to update her list by adding a new book ID to the beginning of the list, another ID to the end, and a third ID at a random position within the list. 



// Your task is to help Lena implement a function to perform these insertions and manage the book list efficiently.

// Input format :
// The first line of input consists of an integer N, the number of existing books in the list.

// The second line contains N integers, each representing the ID of a book.

// The third line contains an integer B, the ID of the book to be added at the beginning.

// The fourth line contains an integer E, the ID of the book to be added at the end.

// The fifth line contains an integer p, the position at which the third ID will be inserted (0-based index).

// The sixth line contains an integer R, the ID of the book to be added at p.

// Output format :
// The output prints the updated list of book IDs after performing the insertions.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ book ID ≤ 1000

// 0 ≤ p ≤ N

// Sample test cases :
// Input 1 :
// 3
// 100 200 300
// 10 
// 20
// 1
// 30
// Output 1 :
// 10 30 100 200 300 20 
// Input 2 :
// 5
// 101 102 103 104 105
// 200
// 300
// 4
// 400
// Output 2 :
// 200 101 102 103 400 104 105 300 
// Input 3 :
// 2
// 11 22
// 10 
// 20
// 2
// 30
// Output 3 :
// 10 11 30 22 20 
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

class BookList {
public:
    Node* head;
    Node* tail;

    BookList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int id) {
        Node* newNode = new Node(id);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int id, int position) {
        Node* newNode = new Node(id);
        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }
        if (current == nullptr) {
            insertAtEnd(id);
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev = newNode;
            if (newNode->prev == nullptr) {
                head = newNode;
            } else {
                newNode->prev->next = newNode;
            }
        }
    }

    void printList() {
        Node* current = head;
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
    BookList bookList;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        bookList.insertAtEnd(id);
    }
    int b, e, p, r;
    cin >> b >> e >> p >> r;
    bookList.insertAtBeginning(b);
    bookList.insertAtEnd(e);
    bookList.insertAtPosition(r, p);
    bookList.printList();
    return 0;
}