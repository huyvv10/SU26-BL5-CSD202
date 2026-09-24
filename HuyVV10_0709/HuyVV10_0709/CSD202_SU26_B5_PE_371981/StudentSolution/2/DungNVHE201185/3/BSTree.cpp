/* This file contains 2 parts: (1) and (2)
   YOUR TASK IS TO COMPLETE THE PART  (2)  ONLY
 */
//PART (1)==============================================================
// -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
#include "BSTree.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

BSTree::BSTree() {
	root = nullptr;
}

bool BSTree::isEmpty() {
	return (root == nullptr);
}

void BSTree::clear() {
	root = nullptr;
}

void BSTree::visit(Node* p) {
	std::cout << "p.info: ";
	if (p != nullptr) std::cout << p->info.toString() << " ";
	std::cout << "\n";
}

void BSTree::fvisit(Node* p, std::ofstream& f) { /*throws Exception*/
	if (p != nullptr) f << p->info.toString() << " ";
}

void BSTree::breadth(Node* p, std::ofstream& f) { /*throws Exception*/
	if (p == nullptr) return;
	Queue q;
	q.enqueue(p);
	Node* r;
	while (!q.isEmpty()) {
		r = q.dequeue();
		fvisit(r, f);
		if (r->left != nullptr) q.enqueue(r->left);
		if (r->right != nullptr) q.enqueue(r->right);
	}
}

void BSTree::preOrder(Node* p, std::ofstream& f) { /*throws Exception*/
	if (p == nullptr) return;
	fvisit(p, f);
	preOrder(p->left, f);
	preOrder(p->right, f);
}

void BSTree::inOrder(Node* p, std::ofstream& f) { /*throws Exception*/
	if (p == nullptr) return;
	inOrder(p->left, f);
	fvisit(p, f);
	inOrder(p->right, f);
}

void BSTree::postOrder(Node* p, std::ofstream& f) { /*throws Exception*/
	if (p == nullptr) return;
	postOrder(p->left, f);
	postOrder(p->right, f);
	fvisit(p, f);
}

static std::vector<std::string> split_tokens(const std::string& s) {
	std::istringstream iss(s);
	std::vector<std::string> res;
	std::string t;
	while (iss >> t) res.push_back(t);
	return res;
}

static std::vector<int> split_ints(const std::string& s) {
	auto toks = split_tokens(s);
	std::vector<int> v;
	v.reserve(toks.size());
	for (auto& x: toks) {
		try {
			v.push_back(std::stoi(x));
		} catch (...) {
			// ignore bad tokens
		}
	}
	return v;
}

static std::vector<double> split_doubles(const std::string& s) {
	auto toks = split_tokens(s);
	std::vector<double> v;
	v.reserve(toks.size());
	for (auto& x : toks) {
		try {
			v.push_back(std::stod(x));
		} catch (...) {}
	}
	return v;
}

void BSTree::loadData(int k) { //do not edit this function
	std::ifstream fin("data.txt");
	if (!fin) return;
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(fin, line)) lines.push_back(line);

	// Tim “cum 3 dong” bat dau cho moc k.
	// Neu lines[k-1] la header dang "line ...", thi du lieu thuc bat dau o lines[k].
	auto starts_with_line = [](const std::string& s) {
		// bo khoang trang dau dong roi kiem tra "line "
		size_t i = s.find_first_not_of(" \t\r");
		return i != std::string::npos && s.compare(i, 5, "line ") == 0;
	};

	int idx = k - 1;                 // 0-based
	if (idx >= 0 && idx < (int)lines.size() && starts_with_line(lines[idx])) {
		idx += 1; // bo qua header, tro toi dong makers thuc
	}

	if (idx + 2 >= (int)lines.size()) return; // khong du 3 dong

	std::string la = lines[idx];       // ids
	std::string lb = lines[idx + 1];   // name
	std::string lc = lines[idx + 2];   // rating

	auto a = split_ints(la);           // ids
	auto b = split_tokens(lb);         // name
	auto c = split_doubles(lc);        // rating
	size_t n = std::min(a.size(), std::min(b.size(), c.size()));
	for (size_t i = 0; i < n; ++i)
		insert(a[i], b[i], c[i]);
}

//===========================================================================
//(2)===YOU CAN EDIT OR EVEN ADD NEW FUNCTIONS IN THE FOLLOWING PART========
//===========================================================================

void BSTree::insert(int xId, const std::string& xName, double xRating) {
	if(xName.length() < 3 || xRating < 1.0 || xRating > 5.0){
		return;
	}
	Node* newNode = new Node(Product(xId,xName,xRating));

    if(isEmpty()){
        root = newNode;
        return;
    }

    Node* cur = root;

    while(cur != nullptr){

        // Kiểm tra ID trùng
        if(xId == cur->info.id){
            delete newNode;
            return;
        }

        if(xId < cur->info.id){

            if(cur->left == nullptr){
                cur->left = newNode;
                return;
            }
            else{
                cur = cur->left;
            }

        }
        else{

            if(cur->right == nullptr){
                cur->right = newNode;
                return;
            }
            else{
                cur = cur->right;
            }
        }
    }
}

// -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
//Do not edit this function. Your task is to complete insert() function above only.
void BSTree::f1() { /*throws Exception*/
	clear();
	loadData(1);
	std::string fname = "f1.txt";
	std::ofstream f(fname, std::ios::binary);
	inOrder(root,f);
	f << "\r\n";
}

void BSTree::f2() { /*throws Exception*/
	//=============================================================
	clear();
	loadData(5);
	std::string fname = "f2.txt";
	std::ofstream f(fname, std::ios::binary);

    // Line 1: Pre-order traversal toan bo cay
    preOrder(root, f);
    f << "\r\n";

	//------------------------------------------------------------------------------------
	/* You must keep statements pre-given in this function.
	   Your task is to insert statements here, just after this comment,
	   to complete the question in the exam paper. */
	// @STUDENT: WRITE YOUR OUTPUT HERE TO COMPLETE THE FUNCTION:
	
	
	
	//Output Line 2: post-order traversal
	//------------------------------------------------------------------------------------
	f << "\r\n";
}
void BSTree::deleteByCopy(Node*& p) {
			if (p == nullptr) return;

			if (p->left == nullptr) {
				Node* q = p;
				p = p->right;
				delete q;
			} else {
				// Find maximum in left subtree (predecessor)
				Node* curr = p->left;
				Node* parent = p;

				while (curr->right != nullptr) {
					parent = curr;
					curr = curr->right;
				}

				// Copy predecessor data into p
				p->info = curr->info;

				// Delete predecessor node
				if (parent == p) parent->left = curr->left;
				else parent->right = curr->left;

				delete curr;
			}
		}
void BSTree::f3() {
	clear();
	loadData(9); // Tai du lieu tu line 9
	std::string fname = "f3.txt";
	std::ofstream f(fname, std::ios::binary);

    // Line 1: Post-order truoc khi xoa
    postOrder(root, f);
	f << "\r\n";
	//------------------------------------------------------------------------------------
	/* You must keep statements pre-given in this function.
	   Your task is to insert statements here, just after this comment,
	   to complete the question in the exam paper. */
	// @STUDENT: WRITE YOUR OUTPUT HERE TO COMPLETE THE FUNCTION:
	Queue q;
    q.enqueue(root);

    Node* p = nullptr;
    Node* parent = nullptr;

    int count = 0;

    // Tim node thu 2 co 2 con bang BFS
    while (!q.isEmpty()) {

        p = q.dequeue();

        if (p->left != nullptr && p->right != nullptr) {

            count++;

            if (count == 1) {
                break;
            }
        }

        if (p->left != nullptr) {
            q.enqueue(p->left);
        }

        if (p->right != nullptr) {
            q.enqueue(p->right);
        }
    }

    // Tim node cha cua p
    if (p != root) {

        parent = root;

        while (parent != nullptr) {

            if (parent->left == p || parent->right == p) {
                break;
            }

            if (p->info.id < parent->info.id) {
                parent = parent->left;
            }
            else {
                parent = parent->right;
            }
        }
    }

    // Delete by Merging
    if (p != nullptr) {

        if (p == root) {
            deleteByCopy(root);
        }
        else if (parent->left == p) {
            deleteByCopy(parent->left);
        }
        else {
            deleteByCopy(parent->right);
        }
    }


	


	//------------------------------------------------------------------------------------
    // Line 2: Post-order sau khi xoa
    postOrder(root, f);
	f << "\r\n";
}

void BSTree::f4() {
	// p->info.price = avg;
	clear();
	loadData(13); // Tai du lieu tu line 13
	std::string fname = "f4.txt";
	std::ofstream f(fname, std::ios::binary);

    // Line 1: Breadth-First truoc khi update
    breadth(root, f);
	f << "\r\n";
	//------------------------------------------------------------------------------------
	/* You must keep statements pre-given in this function.
	   Your task is to insert statements here, just after this comment,
	   to complete the question in the exam paper. */
	// @STUDENT: WRITE YOUR OUTPUT HERE TO COMPLETE THE FUNCTION:


	//	@Student: Student code area

	//------------------------------------------------------------------------------------
    // Line 2: Breadth-First sau khi update
    breadth(root, f);
	f << "\r\n";
}

