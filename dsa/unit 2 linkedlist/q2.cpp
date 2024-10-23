// Single File Programming Question
// Problem Statement



// Imagine you are developing a contact management application where users can maintain a singly linked list of names. 



// Initially, users can enter a sequence of names to form a list of contacts. Later, they can insert a new name at a specific position within the list to rearrange their contacts, ensuring the list is updated and displayed correctly.

// Input format :
// The first line of input consists of an integer n, representing the number of initial names.

// The next n lines each contain a single name, representing the initial list of contacts.

// The last line consists of a name and an integer pos, representing the new contact to be added and its position in the list.

// Output format :
// The output prints the updated list of contacts after inserting the new contact at the specified position.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ length of each name ≤ 100

// Sample test cases :
// Input 1 :
// 4
// John
// Alice
// Bob
// Emma
// Michael 3
// Output 1 :
// John Alice Michael Bob Emma 
// Input 2 :
// 3
// Emma
// Daniel
// Sophia
// Charlotte 1
// Output 2 :
// Charlotte Emma Daniel Sophia 

#include <bits/stdc++.h>
using namespace std;

struct Node{
  string data;
  struct Node *next;
};

void insert_at_index(struct Node **head_ref,int index, string data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    newnode->data=data;
    newnode->next=NULL;
    if(index==1){
        newnode->next=*head_ref;
        *head_ref=newnode;
        return;
    }else{
        int t=1;
        while(t!=index-1){
            last=last->next;
            t++;
        }
        newnode->next=last->next;
        last->next=newnode;
        // cout << last->data << " ";
    }
}

void print(struct Node **head_ref){
    struct Node *last = *head_ref;
    while(last!=NULL){
        cout << last->data << " ";
        last=last->next;
    }
}

int main(){
    int n;
    cin >> n;
    string element;
    
    struct Node *head = NULL;
    for(int i=1;i<=n;i++){
        cin >> element;
        insert_at_index(&head,i,element);
    }
    int n1;
    string add;
    
    cin >> add >> n1;
    
    // cout << add << " "  << endl;
    // cout <<  n1  << "  " << endl;
    
    insert_at_index(&head,n1,add);
    print(&head);
    
    return 0;
}