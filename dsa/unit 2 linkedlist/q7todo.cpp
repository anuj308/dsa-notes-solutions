// Single File Programming Question
// Problem Statement



// Dharun is working on a program to manipulate linked lists. He wants to write a function that takes two linked lists as input, inserts nodes at the end, and deletes all the nodes from the first list that also appear in the second list. 



// Dharun needs your help implementing this function. The function should take two linked lists, list1, and list2, as input, where each list is represented by its head node.

// Input format :
// The first line contains an integer n, denoting the number of nodes in list1.

// The second line contains n space-separated integers, representing the values of the nodes in list1.

// The third line contains an integer m, denoting the number of nodes in list2.

// The fourth line contains m space-separated integers, representing the values of the nodes in list2.

// Output format :
// The first line of output displays "Before deletion: " followed by the elements of the first linked list before the deletion, separated by a space.

// The second line of output displays "After deletion: " followed by the elements of the first linked list after the deletion, separated by a space.

// If all elements in the first linked list are the same after deletion, the third line displays, "Elements in both lists are same".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n,m ≤ 100

// -5000 ≤ values of nodes ≤ 5000

// Sample test cases :
// Input 1 :
// 5
// 2 3 4 5 1
// 5
// 1 6 2 3 8
// Output 1 :
// Before deletion: 2 3 4 5 1 
// After deletion: 4 5 
// Input 2 :
// 5
// 1 2 3 4 5
// 5
// 1 2 3 4 5
// Output 2 :
// Before deletion: 1 2 3 4 5 
// After deletion: 
// Elements in both lists are same
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// not done this one work on it 


// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// bool valueExists(Node* second, int value) {
//     //Type your code here
    
// }

void deleteNodesInSecondList(struct Node **first,struct Node **second,int n1,int n2) { // this below is written by me which is not working
    struct Node *firstT = *first;
    struct Node *secondT = *second;
    struct Node *temp;
    struct Node *store;
    int t1=1;
    while(t1<=n1){
        int d1 = firstT->data;
        int t2=1;
        cout << d1 << " ";
        while(t2<=n2){
            int d2 = secondT->data;
            if(t1==1 && d1==d2){
                // temp = firstT;
                firstT = firstT->next;
                // delete temp;
                break;
            }
            // if(d1==d2){
            //     temp = store->next;
            //     store->next=store->next->next;
            //     delete temp;
            //     break;
            // }
            secondT=secondT->next;
            t2++;
        }
        secondT=*second;
        store= firstT;
        firstT=firstT->next;
        t1++;
    }
    
}

void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// bool areAllElementsSame(Node* head) {
    
    
// }

int main() {
    Node* first = nullptr;
    Node* second = nullptr;
    int size1, size2;

    cin >> size1;

    for (int i = 0; i < size1; i++) {
        int value;
        cin >> value;
        insertNode(&first, value);
    }

    cin >> size2;

    for (int i = 0; i < size2; i++) {
        int value;
        cin >> value;
        insertNode(&second, value);
    }

    cout << "First Linked List before deletion: ";
    displayLinkedList(first);

    deleteNodesInSecondList(&first,&second,size1,size2);

    cout << "First Linked List after deletion: ";
    displayLinkedList(first);

    // if (areAllElementsSame(first)) {
    //     cout << "All elements in the first linked list are the same.";
    // }

    // deleteLinkedList(first);
    // deleteLinkedList(second);

    return 0;
}
