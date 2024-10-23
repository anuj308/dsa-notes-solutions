// Single File Programming Question
// Problem Statement



// Sara has a series of sales data recorded in a singly linked list. She wants to left-shift the list by k nodes to better analyze the sales patterns. 



// Help Sara implement a program to left-shift her sales data linked list by k nodes.

// Input format :
// The first line of input contains an integer N, representing the number of nodes.

// The second line consists of N space-separated integers, representing the sales data values.

// The last integer k represents the number of nodes by which the list should be left-shifted.

// Output format :
// The output prints the updated linked list after left-shifting by k nodes.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 25

// 1 ≤ data values ≤ 150

// Sample test cases :
// Input 1 :
// 5
// 2 4 7 8 9
// 3
// Output 1 :
// 8 9 2 4 7 
// Input 2 :
// 8
// 1 2 3 4 5 6 7 8
// 4
// Output 2 :
// 5 6 7 8 1 2 3 4 


// You are using GCC

// it did not pass 2 test cases

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    if (head == NULL)
        head = createNode(data);
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(data);
    }
    return head;
}

struct Node* leftShiftLinkedList(struct Node  **head, int k,int n) {
    struct Node *last = *head;
    struct Node *last1 = *head;
    struct Node *store = *head;
    struct Node *newHead;
    int t=1;
    while(last->next!=NULL){
        if(t==(k+1)){
            newHead=last;
        }
        last=last->next;
        t++;
    }
    last->next=store;
    t=1;
    while(t<=k){
        if(t==k){
            last1->next=NULL;
        }
        last1=last1->next;
        t++;
    }
    return newHead;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N, k;
    scanf("%d", &N);

    struct Node* head = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    scanf("%d", &k);

    head = leftShiftLinkedList(&head, k,N);

    printList(head);

    return 0;
}