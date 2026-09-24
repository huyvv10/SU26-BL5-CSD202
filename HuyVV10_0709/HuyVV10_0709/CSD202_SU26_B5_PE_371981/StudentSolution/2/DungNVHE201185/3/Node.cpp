#include "Node.h"

Node::Node()
	: info(), left(nullptr), right(nullptr){}

Node::Node(const Product& x) 
	: info(x), left(nullptr), right(nullptr) {}
