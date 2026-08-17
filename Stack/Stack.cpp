#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int _data){
			this->data=_data;
			this->next=nullptr;
		}
};

class Stack{
	private:
		Node *head;
		int top;
	public:
		Stack(){
			head=nullptr;
		}	
		~Stack(){
			while (!isEmpty()){
				pop();				
			}
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		//Insert an element into stack
		void push(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		//Read data at top of stack without remove
		int peek(){
			if(isEmpty()) return -999;
			return head->data;
		}
		
		//Remove an element at top of stack
		void pop(){
			if (isEmpty()) return;
			Node *temp=head;			
			head=temp->next;
			delete temp;
		}
};

//Apply Stack to convert x from decimal to binary
void DecToBin(int x){
	Stack myStk;
	if (x<0) return;
	if (x<2) {
		cout<<x<<endl;
		return;
	}
	while (x>0){
		int phanDu = x%2;
		myStk.push(phanDu);
		x = x/2;
	}
	while (!myStk.isEmpty()){
		cout<<myStk.peek();
		myStk.pop();
	}
	cout<<endl;
}
int main(){
	DecToBin(20);
	DecToBin(7);
	DecToBin(0);
	DecToBin(1);
	DecToBin(5);
	return 0;
}
