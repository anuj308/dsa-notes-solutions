// Single File Programming Question
// Problem Statement



// Raj, a mechanic, uses a linked list to track the cars waiting for repair. He needs to remove a car with a particular license plate number and also delete a car from a specific position in his list. Assist Raj by writing a program that allows him to perform these deletions based on given inputs.

// Input format :
// The first line of input consists of an integer N, the number of cars in the list.

// The second line contains N integers, each representing the license plate number of a car.

// The third line contains an integer R, the license plate number of the car to be removed.

// The fourth line contains an integer P, the position (0-based index) of the car to be removed.

// Output format :
// The output prints the updated list of license plate numbers after performing the deletions.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 3 ≤ N ≤ 10

// 1000 ≤ license plate number ≤ 9999

// R is present in the list.

// Sample test cases :
// Input 1 :
// 3
// 1111 2222 3333
// 1111
// 0
// Output 1 :
// 3333 
// Input 2 :
// 5
// 1011 1034 1900 8789 9899
// 9899
// 3
// Output 2 :
// 1011 1034 1900 
// Note :


#include <iostream>

using namespace std;

class Node {
public:
    int licensePlateNumber;
    Node* next;
    Node* prev;

    Node(int licensePlateNumber) {
        this->licensePlateNumber = licensePlateNumber;
        next = nullptr;
        prev = nullptr;
    }
};

class CarList {
public:
    Node* head;
    Node* tail;

    CarList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertCar(int licensePlateNumber) {
        Node* newNode = new Node(licensePlateNumber);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeCarByLicensePlateNumber(int licensePlateNumber) {
        Node* current = head;
        while (current != nullptr) {
            if (current->licensePlateNumber == licensePlateNumber) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void removeCarByPosition(int position) {
        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
        }
    }

    void printCarList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->licensePlateNumber << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    CarList carList;
    for (int i = 0; i < n; i++) {
        int licensePlateNumber;
        cin >> licensePlateNumber;
        carList.insertCar(licensePlateNumber);
    }
    int r, p;
    cin >> r >> p;
    carList.removeCarByLicensePlateNumber(r);
    carList.removeCarByPosition(p);
    carList.printCarList();
    return 0;
}