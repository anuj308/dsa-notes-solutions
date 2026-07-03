// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* mover = head;
        
        while(mover!=NULL){
            if(mover->data==key) return true;
            mover=mover->next;
        }
        return false;
    }
};