#pragma once
#include "Product.h"

class Node {
	public:
		Product info;
		Node *left, *right;

		Node();
		Node(const Product& x);
};