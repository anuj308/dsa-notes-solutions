// https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1



/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x==1) return head->next;
        
        Node* mover = head;
        int i = 1;
        while(mover!=NULL){
            if(i==(x-1)){
                
                mover->next = mover->next->next;
                break;
            }
            i++;
            mover=mover->next;
        }
        
        return head;
    }
};