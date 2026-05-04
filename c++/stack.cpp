#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int top = -1;
    int size;
    vector<int> arr;
    Stack(int s){
        arr = new int(s);
        size=s;
    }
    void push(int val){
        if(top==size-1) cout << "Stack is full" << endl;
        else{
            arr.push_back(val);
            top++;
        }
    }
    void isFull(){
        if(top==size-1) cout << "true";
        else cout  << "false";
    }

    void isEmpty(){
        if(top!=size-1) cout << "true";
        else cout << "false";
    }

    void peek(){
        if(top==-1) cout << "stack empty";
        else cout << arr[top];
    }

    void display(){
        if(top==-1) cout << "stack is empty";
        else {
            while(top!=-1){
                cout << arr[top] << " ";
                top--;
            }
        }
    }
};


int main(){

    Stack st(5);
    st.push(2);
    st.isEmpty();
    st.isFull();
    return 0;
}