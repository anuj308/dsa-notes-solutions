// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* newnode = new Node(x);
        int i=0;
        Node* mover = head;
        while(mover!=NULL){
            if(i==p){
                Node* nextnode = mover->next;
                mover->next = newnode;
                newnode->prev = mover;
                if(nextnode){
                    newnode->next = nextnode;
                    nextnode->prev = newnode;
                }
                return head;
            }
            i++;
            mover=mover->next;
        }
        
        return head;
    }
};