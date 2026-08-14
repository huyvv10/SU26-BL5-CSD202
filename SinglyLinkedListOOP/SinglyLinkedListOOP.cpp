#include "iostream"
#include "SinglyLinkedListOOP.h"
#include "iomanip"

SinglyLinkedListOOP::SinglyLinkedListOOP() {
	head=tail=nullptr;
};

SinglyLinkedListOOP::~SinglyLinkedListOOP() {
};

bool SinglyLinkedListOOP::isEmpty() {
	return head==nullptr;
};

void SinglyLinkedListOOP::addFirst(Car x) {
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		newNode->next=head;
		head=newNode;
	}
};

//If name start with M, color = 4, price <10000 then do nothing
//Otherwise perform addLast.
void SinglyLinkedListOOP::addLast(Car x) {
	if (x.name[0]!='M') {
		Node *newNode = new Node(x);
		if (isEmpty()) {
			head=tail=newNode;
		} else {
			tail->next=newNode;
			tail=newNode;
		}
	}
};

void SinglyLinkedListOOP::displayList() {
	Node *cur=head;
	std::cout<<std::left<<std::setw(5)<<"ID"
			 <<std::setw(25)<<"NAME"
			 <<std::setw(6)<<"COLOR"
			 <<std::right<<std::setw(15)<<"PRICE"<<std::endl;	
	std::cout<<std::left<<std::setw(5)<<"__"
			 <<std::setw(25)<<"____"
			 <<std::setw(6)<<"_____"
			 <<std::right<<std::setw(15)<<"_____"<<std::endl;	
	while (cur) {
		cur->data.display2();
//		std::cout<<cur->data.display();
		cur=cur->next;
	}
};

int SinglyLinkedListOOP::countNodes() {
	Node *cur=head;
	int count=0;
	while (cur) {
		count++;
		cur=cur->next;
	}
	return count;
};

void SinglyLinkedListOOP::sortByPriceDesc(){
	
};
