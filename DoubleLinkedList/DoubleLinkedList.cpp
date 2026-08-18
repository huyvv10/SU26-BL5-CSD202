#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *prev, *next;
		Node(){
			this->data=0;
			this->prev=nullptr;
			this->next=nullptr;
		};
		Node (int data){
			this->data=data;
			this->prev=nullptr;
			this->next=nullptr;
		}
};

class DoubleLinkedList{
	private: 
		Node *head, *tail;
	public:
		DoubleLinkedList(){
			head=tail=nullptr;
		}	
		
		~DoubleLinkedList(){
			Node *cur=head;
			while (cur!=nullptr){
				Node *temp=cur;
				cur=cur->next;
				delete temp;
			}			
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst(int x){
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;				
			}
		}
		
		void addLast(int x){
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->prev=tail;
				tail->next=newNode;
				tail=newNode;				
			}			
		}
		
		int countNodes(){
			int count=0;
			Node *cur=head;
			while (cur){
				count++;
				cur=cur->next;
			}
			return count;
		}
		//Insert x into the position pos. Do nothing if out of range.
		void addAtPos(int x, int pos){
			int n=countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0){
				addFirst(x); return;
			}
			if (pos==n){
				addLast(x); return;
			}
			Node *newNode = new Node(x);
			int i=0;
			Node *cur=head;
			while (i!=pos){
				cur=cur->next;
				i++;
			}
			newNode->next=cur;
			newNode->prev=cur->prev;
			cur->prev->next=newNode;
			cur->prev=newNode;			
		}
		void display(){
			Node *cur=head;
			while (cur!=nullptr){
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};
int main(){
	DoubleLinkedList myList;
	myList.addFirst(8);
	myList.addFirst(2);
	myList.addFirst(7);
	myList.addFirst(5);
	myList.addFirst(9);
	myList.display();
	myList.addLast(4);
	myList.addLast(3);
	myList.addLast(6);
	myList.display();
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;
	int x, pos;
	cout<<"Input x = "; cin>>x;
	cout<<"Input pos = "; cin>>pos;
	myList.addAtPos(x,pos);
	myList.display();
	
	return 0;
}
