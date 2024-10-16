// Single File Programming Question
// Problem Statement



// Nina, a vet, keeps track of various pets for checkups using a circular linked list. Each pet is represented by an integer code. Nina wants to traverse the list of pets, add a new pet to the end of the list, and remove a pet based on its code. Implement a solution to help Nina with these tasks.

// Input format :
// The first line of input consists of an integer N, the number of pets currently in the circular linked list.

// The second line contains N integers, each representing a pet code.

// The third line contains an integer M, the code of the new pet to be added to the end of the list.

// The fourth line contains an integer R, the code of the pet to be removed from the list.

// Output format :
// The first line of output prints the list of pet codes after inserting the new pet at the end.

// The second line prints the list of pet codes after removing the specified pet code.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ pet code ≤ 100

// R is present in the list.

// Sample test cases :
// Input 1 :
// 7
// 12 59 23 70 71 34 78
// 88
// 12
// Output 1 :
// 12 59 23 70 71 34 78 88 
// 59 23 70 71 34 78 88 
// Input 2 :
// 5
// 32 28 49 26 18
// 99
// 28
// Output 2 :
// 32 28 49 26 18 99 
// 32 49 26 18 99 

#include <iostream>

using namespace std;

class Node {
public:
    int petCode;
    Node* next;

    Node(int petCode) {
        this->petCode = petCode;
        next = nullptr;
    }
};

class PetList {
public:
    Node* head;
    Node* tail;

    PetList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertPet(int petCode) {
        Node* newNode = new Node(petCode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removePet(int petCode) {
        Node* current = head;
        Node* previous = nullptr;
        while (current->next != head && current->petCode != petCode) {
            previous = current;
            current = current->next;
        }
        if (current->petCode == petCode) {
            if (previous == nullptr) {
                head = current->next;
                tail->next = head;
            } else {
                previous->next = current->next;
            }
            delete current;
        }
    }

    void printPetList() {
        Node* current = head;
        do {
            cout << current->petCode << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PetList petList;
    for (int i = 0; i < n; i++) {
        int petCode;
        cin >> petCode;
        petList.insertPet(petCode);
    }
    int m, r;
    cin >> m >> r;
    petList.insertPet(m);
    petList.printPetList();
    petList.removePet(r);
    petList.printPetList();
    return 0;
}