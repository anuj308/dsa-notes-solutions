// Single File Programming Question
// Problem Statement



// Emma is working with two sets of sensor data recorded in two separate grounded header linked lists. She wants to merge these two lists alternately to analyze the combined data more efficiently. 



// Help Emma by writing a program to merge the two grounded header linked lists alternately.



// Company Tags: TCS

// Input format :
// The first line of input consists of the number of elements n in the first list.

// The second line consists of n elements, separated by space.

// The third line consists of the number of elements m in the second list.

// The fourth line consists of m elements, separated by space.

// Output format :
// The output prints the merged linked list with nodes from both lists alternately.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 5
// 6 7 8 9 10
// Output 1 :
// 1 6 2 7 3 8 4 9 5 10 
// Input 2 :
// 4
// 12 26 34 48
// 4
// 56 59 64 78
// Output 2 :
// 12 56 26 59 34 64 48 78 


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createLinkedList(int n, int arr[]) {
    Node* head = new Node;
    head->data = arr[0];
    head->next = nullptr;

    Node* current = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* mergeAlternately(Node* list1, Node* list2) {
    Node* mergedHead = new Node;
    mergedHead->next = nullptr;

    Node* current = mergedHead;
    while (list1 != nullptr && list2 != nullptr) {
        current->next = list1;
        list1 = list1->next;
        current = current->next;

        current->next = list2;
        list2 = list2->next;
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedHead->next;
}

int main() {
    int n, m;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    Node* list1 = createLinkedList(n, arr1);
    Node* list2 = createLinkedList(m, arr2);

    Node* mergedList = mergeAlternately(list1, list2);
    printLinkedList(mergedList);

    return 0;
}