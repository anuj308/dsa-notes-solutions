// Single File Programming Question
// Problem Statement



// Jake maintains a linked list of his gym members, each represented by a unique membership number. Jake needs to check if a particular membership number is part of his list of active members. Write a solution to help Jake find out if the membership number exists in his linked list.

// Input format :
// The first line of input consists of an integer N, the number of active gym members in the list.

// The second line contains N integers, each representing a unique membership number of an active gym member.

// The third line contains an integer M, representing the membership number that Jake needs to check in the list.

// Output format :
// The output prints "Membership number M is active" if the membership number exists in the list.

// Otherwise, the output prints "Membership number M is not in the list".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ membership number ≤ 1000

// Sample test cases :
// Input 1 :
// 2
// 889 911
// 977
// Output 1 :
// Membership number 977 is not in the list
// Input 2 :
// 3
// 100 200 300
// 100
// Output 2 :
// Membership number 100 is active
// Note :


#include <iostream>

using namespace std;

class Node {
public:
    int membershipNumber;
    Node* next;

    Node(int membershipNumber) {
        this->membershipNumber = membershipNumber;
        next = nullptr;
    }
};

class GymMembers {
public:
    Node* head;

    GymMembers() {
        head = nullptr;
    }

    void insertMember(int membershipNumber) {
        Node* newNode = new Node(membershipNumber);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool searchMember(int membershipNumber) {
        Node* current = head;
        while (current != nullptr) {
            if (current->membershipNumber == membershipNumber) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printResult(int membershipNumber, bool found) {
        if (found) {
            cout << "Membership number " << membershipNumber << " is active" << endl;
        } else {
            cout << "Membership number " << membershipNumber << " is not in the list" << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    GymMembers gymMembers;
    for (int i = 0; i < n; i++) {
        int membershipNumber;
        cin >> membershipNumber;
        gymMembers.insertMember(membershipNumber);
    }
    int m;
    cin >> m;
    bool found = gymMembers.searchMember(m);
    gymMembers.printResult(m, found);
    return 0;
}