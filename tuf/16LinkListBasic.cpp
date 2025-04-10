#include <bits/stdc++.h>
using namespace std;

class SingleNode {
public:
    int data;
    SingleNode* next;

    // Default constructor
    SingleNode()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    SingleNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

 //  this function take array and return head of the linklist
SingleNode* constructLLSingle(vector<int>& arr) {
    // code here
    SingleNode* head = new SingleNode(arr[0]);
    int n = arr.size();
    SingleNode* mover = head;
    for(int i=1;i<n;i++){
        SingleNode* temp = new SingleNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

SingleNode* print(SingleNode* head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}

SingleNode* removeHead(SingleNode* head){
    if(head==NULL) return head;
    SingleNode* temp = head;
    head = temp->next;
    delete temp;
    return head;
}

SingleNode* removeTail(SingleNode* head){
    if(head==NULL || head->next == NULL) return head;

    SingleNode* temp = head;
    while(temp->next->next == NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

SingleNode *insertAtEnd(SingleNode *head, int x) {
    if(head == NULL){
        SingleNode* temp = new SingleNode(x);
        return temp;
    }
    SingleNode* mover = head;
    while(mover->next != NULL){
        mover = mover->next;
    }
    SingleNode* temp = new SingleNode(x);
    mover->next = temp;
    return head;
}
void deleteNode(SingleNode* node) {
        
    node->data = node->next->data;
    SingleNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}
int getCount(struct SingleNode* head) {
    if(head==NULL) return 0;
    SingleNode* mover = head;
   int c=1;
   while(mover->next!=NULL){
       c++;
       mover= mover->next;
   }
   return c;
}
bool searchKey(int n, SingleNode* head, int key) {
    // Code here
    SingleNode* mover = head;
    
    while(mover->next!=NULL){
        if(mover->data == key) return true;
        mover=mover->next;
    }
    if(mover->data == key) return true;
    return false;
}

// double linklist
class Node {
    public:
      int data;
      Node *next;
      Node *prev;
  
      Node(int val) {
          data = val;
          this->next = NULL;
          this->prev = NULL;
      }
  };
Node* constructDLL(vector<int>& arr) { // arr to linklist
        
    Node* head = new Node(arr[0]);
    Node* moverp = head;
    int n = arr.size();
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        temp->prev = moverp;
        moverp->next = temp;
        moverp = temp;
    }
    return head;
}
Node *addNode(Node *head, int pos, int data) {
    if(head==NULL && pos==0){
        Node* temp = new Node(data);
        return temp;
    }
    if(head==NULL && pos!=0){
        return head;
    }
    int c = 0;
    Node* mover = head;
    while(mover!=NULL){
        if(c==pos){
            Node* temp = new Node(data);
            if(mover->next !=NULL) temp->next = mover->next;
            if(mover->next !=NULL) mover->next->prev = temp;
            mover->next = temp;
            temp->prev = mover;
            break;
        }
        if(mover->next==NULL) break;
        mover = mover->next;
        c++;
    }
    return head;
}
Node* deleteNode(Node* head, int x) {
    // Your code here
    if(head==NULL || x<1) return head;

    if(x==1){ // for first node
        Node* temp = head;
        head = head->next;
        if(head!=NULL) head->prev = NULL;
        delete temp;
        return head;
    }
    int c=1;
    Node* mover = head;
    while(mover->next!=NULL){
        if(c==x-1){
            Node* temp = mover->next;
            mover->next = mover->next->next;
            if(mover->next!=NULL) mover->next->prev = mover;
            delete temp;
            break;
        }
        mover=mover->next;
        c++;
    }
    return head;   
}
DLLNode* reverseDLL(DLLNode* head) { // reverse a double linklist , tc- O(2N) , sc - O(N)
    // Your code here
    DLLNode* temp =  head;
    vector<int> arr;
    while(temp->next!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    arr.push_back(temp->data);
    temp = head;
    while(temp->next!=NULL){
        int d = arr.back();
        temp->data = d;
        arr.pop_back();
        temp=temp->next;
    }
    int d = arr.back();
    temp->data = d;
    arr.pop_back();
    return head;
}



int main(){

    return 0;
}
 