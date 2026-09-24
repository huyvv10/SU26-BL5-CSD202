#pragma once
#include <string>
#include <fstream>
#include <functional>
#include "Product.h"
#include "Node.h"
#include "Queue.h"

class BSTree {
	public:
		Node* root;

		BSTree(); // BSTree() {root=null;}

		bool isEmpty(); // return(root==null);
		void clear();   // root=null;

		void visit(Node* p);
		void fvisit(Node* p, std::ofstream& f) /*throws Exception*/;

		void breadth(Node* p, std::ofstream& f) /*throws Exception*/;
		void preOrder(Node* p, std::ofstream& f) /*throws Exception*/;
		void inOrder(Node* p, std::ofstream& f) /*throws Exception*/;
		void postOrder(Node* p, std::ofstream& f) /*throws Exception*/;

		void loadData(int k); //do not edit this function

		// Question 1
		void f1() /*throws Exception*/;
		void insert(int xId, const std::string& xName, double xRating);

		// Question 2
		void f2();

		// Question 3
		void f3();
		void deleteByCopy(Node*& p);

		// Question 4
		void f4();

};