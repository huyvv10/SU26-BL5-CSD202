#include <iostream>
#include <queue>

using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
		Node() {
			this->data=0;
			this->left=nullptr;
			this->right=nullptr;
		};
		Node(int xData) {
			this->data=xData;
			this->left=nullptr;
			this->right=nullptr;
		}
};

class BSTree {
	public:
		Node *root;
		BSTree() {
			root=nullptr;
		}

		~BSTree() {
		}

		bool isEmpty() {
			return root==nullptr;
		}

		Node *insertNode(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				root=newNode;
				return root;
			}
			Node *cur=root;
			while (cur!=nullptr) {
				if (x==cur->data) {
					cout<<x<<" already existing in the tree."<<endl;
					break;
				}
				if (x<cur->data) {
					if (cur->left==nullptr) {
						cur->left=newNode;
						break;
					} else {
						cur=cur->left;
					}
				} else {
					if (cur->right==nullptr) {
						cur->right=newNode;
						break;
					} else {
						cur=cur->right;
					}
				}
			}
			return root;
		}

		void visit(Node *xRoot) {
			if (xRoot==nullptr) return;
			cout<<xRoot->data<<" ";
		}

		void pre_Order(Node *xRoot) {
			if (xRoot==nullptr) return;
			visit(xRoot);
			if (xRoot->left!=nullptr)
				pre_Order(xRoot->left);
			if (xRoot->right!=nullptr)
				pre_Order(xRoot->right);
		}
		void in_Order(Node *xRoot) {
			if (xRoot==nullptr) return;
			if (xRoot->left!=nullptr)
				in_Order(xRoot->left);
			visit(xRoot);
			if (xRoot->right!=nullptr)
				in_Order(xRoot->right);
		}
		void post_Order(Node *xRoot) {
			if (xRoot==nullptr) return;
			if (xRoot->left!=nullptr)
				post_Order(xRoot->left);
			if (xRoot->right!=nullptr)
				post_Order(xRoot->right);
			visit(xRoot);
		}

		//Breadth First Traversal
		void beadthFirstTraversal(Node *xRoot) {
			if (xRoot==nullptr) return;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				visit(cur);
				myQ.pop();
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}

		}
		//Count using Breadth First Traversal
		int countBFS(Node *xRoot) {
			int count=0;
			if (xRoot==nullptr) return 0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				count++;
				myQ.pop();
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}

		//Return number of nodes within the tree
		int countNode(Node *xRoot) {
			int count=0, l=0, r=0;
			if (xRoot!=nullptr) count++;
			if (xRoot->left!=nullptr)
				l=countNode(xRoot->left);
			if (xRoot->right!=nullptr)
				r=countNode(xRoot->right);
			return count+l+r;
		}

		//Count Internal nodes
		int countInternalNodes(Node *xRoot) {
			int count=0, l=0, r=0;
			if (xRoot!=nullptr)
				if (xRoot->left!=nullptr ||xRoot->right!=nullptr)
					count++;
			if (xRoot->left!=nullptr)
				l=countInternalNodes(xRoot->left);
			if (xRoot->right!=nullptr)
				r=countInternalNodes(xRoot->right);
			return count+l+r;
		}

		//Count External/Leaf nodes
		int countExternalNodes(Node *xRoot) {
			int count=0, l=0, r=0;
			if (xRoot!=nullptr)
				if (xRoot->left==nullptr && xRoot->right==nullptr)
					count++;
			if (xRoot->left!=nullptr)
				l=countExternalNodes(xRoot->left);
			if (xRoot->right!=nullptr)
				r=countExternalNodes(xRoot->right);
			return count+l+r;
		}
		//Count nodes which have two children
		int countNodesHaveTwoChildren(Node *xRoot) {
			int count=0;
			if (xRoot==nullptr) return 0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left!=nullptr && cur->right!=nullptr)
					count++;
				myQ.pop();
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}
		//Count nodes which only have a left child
		int countNodesHaveALeftChild(Node *xRoot) {
			int count=0;
			if (xRoot==nullptr) return 0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left!=nullptr && cur->right==nullptr)
					count++;
				myQ.pop();
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}
		//Count nodes which only have a right child
		int countNodesHaveARightChild(Node *xRoot) {
			int count=0;
			if (xRoot==nullptr) return 0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left==nullptr && cur->right!=nullptr)
					count++;
				myQ.pop();
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}

//		Node *deleteByCopying(Node *xRoot) {
//
//			return nullptr;
//		}
		void deleteByCopy(Node*& p) {
			if (p->left == nullptr) {
				Node* q = p;
				p = p->right;
				delete q;
			} else {
				//Find the maximum node in the left subtree (Predecessor)
				Node* curr = p->left;
				Node* parent = p;
				while (curr->right != nullptr) {
					parent = curr;
					curr = curr->right;
				}
				p->data = curr->data; // Copy data
				if (parent == p) parent->left = curr->left;
				else parent->right = curr->left;
				delete curr;
			}
		}

		void deleteByMerging(Node*& q) {
			if (q == nullptr) return;
			Node* nodeToDelete = q;

			if (q->left == nullptr) {
				q = q->right;
			} else {
				Node* p = q->left;
				while (p->right != nullptr) {
					p = p->right;
				}
				p->right = q->right;
				q = q->left;
			}
			delete nodeToDelete;
		}

//		Node *deleteByMerging(Node *xRoot) {
//
//			return nullptr;
//		}
};

int main() {
	BSTree myBST;
	myBST.root=myBST.insertNode(10);
	myBST.root=myBST.insertNode(7);
	myBST.root=myBST.insertNode(3);
	myBST.root=myBST.insertNode(8);
	myBST.root=myBST.insertNode(15);
	cout<<"Pre-Order\n";
	myBST.pre_Order(myBST.root);
	cout<<"\nInOrder\n";
	myBST.in_Order(myBST.root);
	cout<<"\nPostOrder\n";
	myBST.post_Order(myBST.root);
	cout<<"\nNumber of nodes: "<<myBST.countNode(myBST.root)<<endl;
	cout<<"\nNumber of nodes BFS: "<<myBST.countBFS(myBST.root)<<endl;
	cout<<"Breadth First Traversal"<<endl;
	myBST.beadthFirstTraversal(myBST.root);
	cout<<"\nNumber of internal nodes: "<<myBST.countInternalNodes(myBST.root)<<endl;
	cout<<"Number of external nodes: "<<myBST.countExternalNodes(myBST.root)<<endl;
	cout<<"Number of nodes have 2 children: "<<myBST.countNodesHaveTwoChildren(myBST.root)<<endl;
	return 0;
}
