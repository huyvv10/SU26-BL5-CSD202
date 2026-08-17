#include "Node.h"

Node::Node(){
	this->data=0;
}

Node::Node(int _data) {
	this->data=_data;
	this->next=nullptr;
}