#include <iostream>
#include "Queue.h"

using namespace std;


Queue::Queue() {
	head=tail=nullptr;
}
Queue::~Queue() {
	while (!isEmpty()) {
		dequeue();
	}
}
bool Queue::isEmpty() {
	return head==nullptr;
}

//Insert an element x into the queue
void Queue::enqueue(int x) {
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		tail->next=newNode;
		tail=newNode;
	}
}

//Remove an element x at the beginning of the queue
void Queue::dequeue() {
	if (isEmpty()) return;
	if (head->next==nullptr) {
		head=tail=nullptr;
		return;
	}
	Node *tmp=head;
	head=tmp->next;
	delete tmp;
}

//Return the value at the beginning of the queue without remove it.
//Return -999 incase the queue is empty
int Queue::front() {
	if (isEmpty()) return -999;
	return head->data;
}

//Return the value at the end of the queue without remove it.
//Return -999 incase the queue is empty
int Queue::rear() {
	if (isEmpty()) return -999;
	return tail->data;
}

void Queue::display() {
	Node *cur = head;
	while (cur) {
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}

