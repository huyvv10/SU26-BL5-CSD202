#include "SinglyLinkedListOOP.h"

SinglyLinkedList::SinglyLinkedList() {
	head=tail=nullptr;
};

SinglyLinkedList::~SinglyLinkedList() {
};

bool SinglyLinkedList::isEmpty() {
	return head==nullptr;
};

void SinglyLinkedList::addFirst(Car x) {
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		newNode->next=head;
		head=newNode;
	}
};

void SinglyLinkedList::displayList() {
	Node *cur=head;
	while (cur) {
		cur->data->display();
		cur=cur->next;
	}
};

int SinglyLinkedList::countNodes() {
	Node *cur=head;
	int count=0;
	while (cur) {
		count++;
		cur=cur->next;
	}
	return count;
};
