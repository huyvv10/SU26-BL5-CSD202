#pragma once
#include "Student.h"

struct Node {
	public:
    Student info;
    Node* next;
    
    Node();
    Node(const Student& x, Node* p);
    Node(const Student& x);
};
