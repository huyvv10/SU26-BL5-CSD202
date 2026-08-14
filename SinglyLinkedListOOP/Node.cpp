#include "Node.h"
#include "Car.h"

Node::Node(Car _data){
	this->data=_data;
	this->next=nullptr;	
};