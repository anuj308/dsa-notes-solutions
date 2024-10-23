// Single File Programming Question
// Problem Statement



// Sharon is developing a character editor for a simple text-based game. The editor allows users to maintain a singly linked list of characters representing a sequence of moves in the game. 



// Initially, users input a series of characters to create their move sequence. Later, they can insert a new character at a specific position within the sequence to alter their gameplay strategy, ensuring the list is updated and displayed correctly. Assist Sharon in the task.



// Company tags: TCS

// Input format :
// The first line contains an integer n, the number of initial characters.

// The second line consists of n characters, representing the initial move sequence.

// The last line contains a character and an integer pos, representing the new move to be added and its position(1-based) in the sequence.

// Output format :
// The first line displays "Current Linked List:" followed by the initial sequence of moves in the next line.

// The third line displays "Updated Linked List:" followed by the updated sequence of moves after inserting the new move at the specified position in the next line.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 6
// A B C D E F
// G 7
// Output 1 :
// Current Linked List:
// A B C D E F 
// Updated Linked List:
// A B C D E F G 
// Input 2 :
// 3
// A O B
// M 1
// Output 2 :
// Current Linked List:
// A O B 
// Updated Linked List:
// M A O B 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *next;
};

void insert_at_index(struct Node **head_ref,int index,char data){
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
        // cout << index << last->data << endl;
        newnode->next=last->next;
        last->next=newnode;
        // newnode->next=last
    }
}

void print(struct Node **head_ref){
    struct Node *last = *head_ref;
    
    while(last!=NULL){
        cout << last->data << " ";
        last=last->next;
    }
    cout << endl;
    
}

int main(){
    
    int n;
    char element;
    cin >> n;
    
    struct Node *head = NULL;
    
    for(int i=1;i<=n;i++){
        cin >> element;
        insert_at_index(&head,i,element);
    }
    
    cout << "Current Linked List:\n";
    print(&head);
    cout << "Updated Linked List:\n";
    int insertIndex;
    char insertChar;
    cin >> insertChar;
    cin >> insertIndex;
    insert_at_index(&head,insertIndex,insertChar);
    print(&head);
    return 0;
}