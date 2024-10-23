// Single File Programming Question
// Problem Statement



// A company wants to analyze the performance of its sales team by reviewing the sales figures from the most recent months. Each month's sales data is entered into a singly linked list, with each node representing a month's sales. 



// Write a program that computes the sum of sales for the last m months from this linked list data.

// Input format :
// The first line consists of an integer n, representing the number of months' sales data.

// The second line consists of n space-separated integers, representing the sales data for each month.

// The third line consists of an integer m, representing the number of most recent months to sum up.

// Output format :
// The output prints the sum of sales for the last m months.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 0 ≤ sales data ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 3 1 0 4 30 12
// 3
// Output 1 :
// 46
// Input 2 :
// 10
// 7 4 1 2 5 8 0 3 6 9
// 5
// Output 2 :
// 26

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void insert_at_index(struct Node **head_ref,int data,int index){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    newnode->data=data;
    newnode->next=NULL;
    
    if(index==1){
        newnode->next=*head_ref;
        *head_ref=newnode;
    }else{
        int t=1;
        while(t!=index-1){
            last=last->next;
            t++;
        }
        newnode->next=last->next;
        last->next=newnode;
    }
}

void sumA(struct Node **head_ref,int no,int n){
    struct Node *last=*head_ref;
    int t=1;
    int ans=0;
    int start = n-no+1; 
    // cout << start;
    while(t<=n){
        // cout << last->data << " ";
        int add = last->data;
        if(t>=start){
            ans+=add;
            // cout << t << start << " ";
        }
        last=last->next;
        t++;
    }
    cout << ans;
}

int main(){
    int n,element;
    cin >> n;
    struct Node *head=NULL;
    for(int i=1; i<=n;i++){
        cin >> element;
        insert_at_index(&head,element,i);
    }
    int n1;
    cin >> n1;
    
    sumA(&head,n1,n);
    
    return 0;
}