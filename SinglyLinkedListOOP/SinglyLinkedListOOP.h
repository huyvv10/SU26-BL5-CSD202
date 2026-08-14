#ifndef SINGLYLINKEDLISTOOP_H
#define SINGLYLINKEDLISTOOP_H
#include "Node.h"
#include "Car.h"

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		bool isEmpty();		
		void addFirst(Car x);
		void displayList();
		int countNodes();
};

#endif