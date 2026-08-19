#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *prev, *next;
		Node() {
			this->data=0;
			this->prev=nullptr;
			this->next=nullptr;
		};
		Node (int data) {
			this->data=data;
			this->prev=nullptr;
			this->next=nullptr;
		}
};

class DoubleLinkedList {
	private:
		Node *head, *tail;
	public:
		DoubleLinkedList() {
			head=tail=nullptr;
		}

		~DoubleLinkedList() {
			Node *cur=head;
			while (cur!=nullptr) {
				Node *temp=cur;
				cur=cur->next;
				delete temp;
			}
		}

		bool isEmpty() {
			return head==nullptr;
		}

		void addFirst(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}

		void addLast(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->prev=tail;
				tail->next=newNode;
				tail=newNode;
			}
		}

		int countNodes() {
			int count=0;
			Node *cur=head;
			while (cur) {
				count++;
				cur=cur->next;
			}
			return count;
		}
		//Insert x into the position pos. Do nothing if out of range.
		void addAtPos(int x, int pos) {
			int n=countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0) {
				addFirst(x);
				return;
			}
			if (pos==n) {
				addLast(x);
				return;
			}
			Node *newNode = new Node(x);
			int i=0;
			Node *cur=head;
			while (i!=pos) {
				cur=cur->next;
				i++;
			}
			newNode->next=cur;
			newNode->prev=cur->prev;
			cur->prev->next=newNode;
			cur->prev=newNode;
		}
		
		//Remove an element at the beginning of the list
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node *tmp = head;
				head=tail=nullptr;
				delete tmp;
			} else {
				Node *tmp=head;
				head=tmp->next;
				head->prev=nullptr;
				delete tmp;
			}
		}
		
		//Remove an element at the last of the list
		void removeLast(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node *tmp=head;
				head=tail=nullptr;
				delete tmp;
			} else {
				Node *tmp=tail;
				tail=tmp->prev;
				tail->next=nullptr;
				delete tmp;				
			}
		}
		//Remove an element with value as x first found from the left
		void removeValue(int x){
			Node *cur=head;
			while (cur!=nullptr && cur->data!=x){
				cur=cur->next;
			}
			if (cur==nullptr){
				cout<<"Find not found "<<x<<" in the list"<<endl;
				return;
			}
			if (cur->data==x){
				if (cur==head) {
					removeFirst(); return;
				}
				if (cur==tail){
					removeLast(); return;
				}
				Node *tmp=cur;
				cur->prev->next=tmp->next;
				cur->next->prev=tmp->prev;
				delete tmp;
			} 
		}
		
		//Remove x at the position pos
		void removeAtPos(int pos){
			int n=countNodes();
			if (pos<0 || pos>=n) return;
			if (pos==0){
				removeFirst(); return;
			}			
			if (pos==n-1){
				removeLast(); return;
			}
			int i=0;
			Node *cur=head;
			while (i!=pos){
				cur=cur->next;
				i++;
			}
			Node *tmp=cur;
			cur->prev->next=tmp->next;
			cur->next->prev=tmp->prev;
			delete tmp;			
		}
		
		//Update newValue to the element at the position pos
		void editAtPos(int newValue, int pos){
			
		}
		
		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};
int main() {
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
	cout<<"Input x = ";
	cin>>x;
	cout<<"Input pos = ";
	cin>>pos;
	myList.addAtPos(x,pos);
	myList.display();
//	cout<<"Remove first\n";
//	myList.removeFirst();
//	myList.display();
//	cout<<"Remove last\n";
//	myList.removeLast();
//	myList.display();
//	cout<<"Remove x"<<endl;
//	cout<<"Input a number to remove: "; cin>>x;
//	myList.removeValue(x);
//	myList.display();
	cout<<"Input position to remove: "; cin>>pos;
	myList.removeAtPos(pos);
	myList.display();
	return 0;
}
