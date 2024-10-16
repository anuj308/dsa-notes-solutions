// Single File Programming Question
// Problem Statement



// A healthcare provider wants to analyze a list of patient records to determine if the sequence of records is a palindrome. A sequence is considered a palindrome if it reads the same forward and backwards. 



// You need to write a program using a two-way linked list to help the provider check if the given list of medical records is a palindrome.



// Company Tags: Capgemini

// Input format :
// The first line contains an integer n, representing the number of records.

// The second line contains n space-separated integers, each representing a medical record identifier.

// Output format :
// If the list of records is a palindrome, print "The patient's medical history is a palindrome".

// If it is not a palindrome, print "The patient's medical history is not a palindrome".



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 20

// 1 ≤ identifier ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 2 1
// Output 1 :
// The patient's medical history is a palindrome
// Input 2 :
// 5
// 1 2 3 4 5
// Output 2 :
// The patient's medical history is not 

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* prev = nullptr;
    Node* current = slow;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    current = head;
    while (prev != nullptr) {
        if (current->value != prev->value) {
            return false;
        }
        current = current->next;
        prev = prev->prev;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new Node(values[i]);
        current->next->prev = current;
        current = current->next;
    }
    if (isPalindrome(head)) {
        cout << "The patient's medical history is a palindrome" << endl;
    } else {
        cout << "The patient's medical history is not a palindrome" << endl;
    }
    return 0;
}