#pragma once
#include "Node.h"
#include <iostream>

class MyList {
public:
    Node *head, *tail;

    MyList();
    bool isEmpty() const;
    void clear();
    void addFirst(const std::string& xName, double xGpa, int xCredit); // f1

    void fvisit(Node* p, std::ostream& out) const;    
    void ftraverse(std::ostream& out) const;
    void loadData(int k); // Load data method
	void removeAll(int x,int y);
	void removeFirst();
	void removeLast();
    void f1();
	void f2(); 
    void f3(); 
    void f4(); 
};