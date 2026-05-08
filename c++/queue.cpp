#include <iostream>
using namespace std;

class CircularQueue{
public:
	int front;
	int rear;
	int MAX;
	int* cirQ;

	CircularQueue(){
		front=-1;
		rear=-1;
		cout << "Enter size of CircularQueue"<< endl;
		cin >> MAX;
		cirQ = new int[MAX];
		cout << "CircularQueue memory allocated" << endl;
	}

	void enqueue(int data){
		cout << front << " " << rear << endl;
		if((front==0 && rear==MAX-1) || (rear+1)%MAX==front){
			cout << "overflow" <<endl;
		}else if(front==-1 && rear==-1){
			front=0;
			rear=0;
			cirQ[rear]=data;
			cout << "added " << cirQ[rear] << endl;
		}else{
			rear=(rear+1)%MAX;
			cirQ[rear]=data;
			cout << "added " << cirQ[rear] << endl;
		}
	}
	void pop(){
		if((front==-1)){
			cout << "Underflow" << endl;
		}
		else{
			cout << "Element deleted " << cirQ[front] << endl;
			if(front==rear){
				front = -1;
				rear = -1;
			}else front = (front+1)%MAX;
		}
	}
};

int main(){
	CircularQueue cq;
	cq.enqueue(1);
	cq.enqueue(1);
	cq.enqueue(1);
	cq.pop();
	cq.pop();
	cq.enqueue(1);
	cq.enqueue(1);
	cq.pop();
	return 0;
}