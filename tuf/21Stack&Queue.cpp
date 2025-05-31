#include <bits/stdc++.h>
using namespace std;

class Stack {
    
    public:
    int size;
    int topp;
    int *arr;
    Stack(int capacity) {
        size = capacity;
        topp=-1;
        arr = new int[size];
    }

    void push(int num) {
        if(topp==size-1) {
            return;
        }
        topp++;
        arr[topp]=num;
    }

    int pop() {
        if(topp==-1) return -1;
        int nu = arr[topp];
        topp--;
        return nu;
    }
    
    int top() {
        if(topp==-1) return -1;
        return arr[topp];
    }
    
    int isEmpty() {
        if(topp==-1) return 1;
        return 0;
    }
    
    int isFull() {
        if(topp==size-1) return 1;
        return 0;
    }
    
};
class Node{
    public:
    int val;
    Node *next;
    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class stackL{
    Node* top;
    int size;
    stackL(){
        this->top=NULL;
        this->size=0;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    int pop(){
        if(top==NULL) return -1;
        Node* temp = top;
        top = top->next;
        size--;
        int v = temp->val;
        delete temp;
        return v;
    }
    int size(){
        return size;
    }
    int top(){
        if(top==NULL) return -1;
        return top->val;
    }
};
class StackLL
{
    //Write your code here
Node* top;
int size;

public:
    StackLL()
    {
        top=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(top==NULL) return true;
        return false;
    }

    void push(int data)
    {
        if(top==NULL){
            Node* temp = new Node(data);
            top = temp;
            size++;
            return;
        }
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if(top==NULL) return;
        Node* temp = top;
        top=top->next;
        size--;
        delete temp;
    }

    int getTop()
    {
        if(top==NULL) return -1;
        return top->data;
    }
};
class QueueL{
    int size;
    Node* start;
    Node* end;
    QueueL(){
        size=0;
        start=NULL;
        end=NULL;
    }
    void push(int x){
        Node* temp = new Node(x);
        if(end==NULL){
            start = temp;
            end = temp;
        }else{
            end->next = temp;
            end=end->next;
        }
        size++;
    }
    int pop(){
        if(start==NULL) return -1;
        Node* temp = start;
        int v = temp->val;
        start = start->next;
        size--;
        delete temp;
        if(start==NULL){
            end=NULL;
        }
        return v;
    }
    int top(){
        if(start==NULL && end==NULL){
            return -1;
        }
        return start->val;
    }
};
/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

 void Queue::push(int x) {
    if(front==NULL && rear==NULL){
        Node* temp = new Node(x);
        front = temp;
        rear = temp;
        return;
    }
    Node* temp = new Node(x);
    rear->next = temp;
    rear=rear->next;
}

int Queue::pop() {
    if(front==NULL){
        return -1;
    }
    Node * temp = front;
    front = front->next;
    int v = temp->data;
    delete temp;
    if(front==NULL){
        rear=NULL;
    }
    return v;
}
class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxSize) {
    ( * this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) {
      start = 0;
      end = 0;
    } else
      end = (end + 1) % maxSize;
    arr[end] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }
  int pop() {
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else
      start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return currSize;
  }

};
class Queuee {

	int front, rear;
	vector<int> arr;

public:
	Queuee()
	{
		front = 0;
		rear = 0;
		// arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{	
		arr.push_back(e);
		rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(front==rear) return -1;
		int a = arr[front];
		front++;
		return a;
	}
};
class Queue {
    int start;
    int end;
    int size;
    int maxSize;
    int *arr;
public:
    Queue() {
        start=-1;
        end=-1;
        size=0;
        maxSize=10000;
        arr = new int[maxSize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return size==0;
    }

    void enqueue(int data) {
        if(end==-1){
            start=0;
            end=0;
        }else{
            end = (end + 1) % maxSize;
        }
        arr[end]=data;
        size++;
    }

    int dequeue() {
        if(isEmpty()){
            return -1;
        }
        int c = arr[start];
        if(size==1){
            start=-1;
            end=-1;
        }else
            start = (start + 1) % maxSize;
        size--;
        return c;
    }

    int front() {
        if(isEmpty()) return -1;
        return arr[start];
    }
};
//  stack using queue
class MyStack {
    public:
        queue<int> q;
        MyStack() {
            // queue<int> q;
        }
        
        void push(int x) { //O(n)
            q.push(x);
            if(q.size()>1){
                for(int i=0;i<q.size()-1;i++){
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        
        int pop() { // O(1)
            int p = q.front();
            q.pop();
            return p;
        }
        
        int top() { // O(1)
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
class MyQueue {
    public:
        stack<int> s1;
        stack<int> s2;
        MyQueue() {
        }
        
        void push(int x) { /// O(2n)
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }   
            s1.push(x);
            while(s2.size()){
                s1.push(s2.top());
                s1.pop();
            }
        }
        int pop() { // O(1)
            int v = s1.top();
            s1.pop();
            return v;
        }
        
        int peek() { // O(1)
            return s1.top();
        }
        
        bool empty() {
            return s1.size()==0;
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */
    class MinStack {
    public:
        stack<long long> st; // tc - O(1), sc - O(n)
        long long mini;
        MinStack() {
            mini = INT_MAX;
        }
        
        void push(int value) {
            long long val = value;
            if(st.empty()){
                mini = val;
                st.push(val);
            }else{
                if(val > mini) st.push(val);
                else {
                    st.push(2*val - mini);
                    mini = val;
                }
            }
        }
        
        void pop() {
            if(st.empty()) return;
                
            long long v = st.top();
            st.pop();
            if(v < mini){
                mini = 2*mini - v;
            }
        }
        
        int top() {
            long long v = st.top();
            if(v < mini) return mini;
            return v;
        }
        
        int getMin() {
            return mini;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
class MinStack {
    public:
        stack<pair<int,int>> st; // value, min
        MinStack() {
            
        }
        
        void push(int val) {
            if(st.size()==0){
                st.push({val,val});
            }else{
                st.push({val,min(val,st.top().second)});
            }
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
    #include <bits/stdc++.h>
    int priority(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
        if(c=='+' || c=='-') return 1;
        return -1;
    }
    string infixToPostfix(string exp){
        int n = exp.length();
        stack<char> st;
        string ans = "";
        int i = 0;
        while(i<n){
            char c = exp[i];
            if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
                ans+=c;
            }else if(c=='('){
                st.push(c);
            }else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans+= st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && priority(st.top())>=priority(c)){
                    ans+= st.top();
                    st.pop();
                }
                st.push(c);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    // https://www.naukri.com/code360/problems/infix-to-postfix_1382146?leftPanelTabValue=SUBMISSION
int main(){

    return 0;
} 