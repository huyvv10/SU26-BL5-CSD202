#pragma once
#include "Node.h"

class Queue{
	private:
		Node *head, *tail;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		
		//Insert an element x into the queue
		void enqueue(int x);
		
		//Remove an element x at the beginning of the queue
		void dequeue();
		
		//Return the value at the beginning of the queue without remove it.
		//Return -999 incase the queue is empty
		int front();
		
		//Return the value at the end of the queue without remove it.
		//Return -999 incase the queue is empty
		int rear();
		void display();
};