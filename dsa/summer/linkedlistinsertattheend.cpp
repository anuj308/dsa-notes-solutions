// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1



class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newnode = new Node(x);
        if(head==NULL) return newnode;
        Node* mover = head;
        while(mover && mover->next!=NULL){
            mover=mover->next;
        }
        mover->next = newnode;
        
        return head;
    }
};