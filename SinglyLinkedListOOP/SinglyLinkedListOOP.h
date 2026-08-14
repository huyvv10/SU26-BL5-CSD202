#ifndef SINGLYLINKEDLISTOOP_H
#define SINGLYLINKEDLISTOOP_H
#include "Node.h"
#include "Car.h"

class SinglyLinkedListOOP{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedListOOP();
		~SinglyLinkedListOOP();
		
		bool isEmpty();		
		void addFirst(Car x);
		void addLast(Car x);
		void displayList();
		int countNodes();
		void sortByPriceDesc();
		
};

#endif