// https://www.geeksforgeeks.org/problems/linked-list-insertion-at-beginning/1


class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node* newnode = new Node(x);
        
        newnode->next = head;
        
        return newnode;
    }
};