#ifndef NODE_H
#define NODE_H
#include <Car.h>

class Node{
	public:
		Car data;
		Node *next;
		
		Node(Car _data);		
};

#endif