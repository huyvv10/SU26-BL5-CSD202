#include "MyList.h"
#include "Lib.h"
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
// ----------------- helpers noi bo cho loadData -----------------
static std::vector<std::string> readAllLines(const std::string &filename)
{
    std::ifstream fin(filename, std::ios::binary);
    std::vector<std::string> lines;
    std::string s;
    while (std::getline(fin, s))
    {
        if (!s.empty() && s.back() == '\r')
            s.pop_back();
        lines.push_back(s);
    }
    return lines;
}

//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
static std::vector<std::string> splitStr(const std::string &line)
{
    std::vector<std::string> out;
    std::istringstream iss(line);
    std::string tok;
    while (iss >> tok)
        out.push_back(tok);
    return out;
}

//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
static std::vector<int> splitInt(const std::string &line)
{
    std::vector<int> out;
    std::istringstream iss(line);
    int x;
    while (iss >> x)
        out.push_back(x);
    return out;
}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
static std::vector<float> splitFloat(const std::string &line)
{
    std::vector<float> out;
    std::istringstream iss(line);
    float x;
    while (iss >> x)
        out.push_back(x);
    return out;
}

// ----------------- MyList trien khai -----------------
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
MyList::MyList() : head(nullptr), tail(nullptr) {}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
bool MyList::isEmpty() const
{
    return head == nullptr;
}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
void MyList::clear()
{
    // don danh sach lien ket don
    Node *p = head;
    while (p)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
    head = tail = nullptr;
}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
void MyList::fvisit(Node *p, std::ostream &out) const
{
    if (p != nullptr)
    {
        out << p->info.toString() << " ";
    }
}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
void MyList::ftraverse(std::ostream &out) const
{
    Node *p = head;
    while (p != nullptr)
    {
        fvisit(p, out); // ghi thong tin node p vao stream
        p = p->next;
    }
    out << "\r\n";
}
//  -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
// This function loads data from data.txt file and using addLast() method to add nodes to the list
void MyList::loadData(int k)
{
    // this function call to addLast() method to add nodes to the list
    // data.txt: dong k (strings), k+1 (float), k+2 (ints) - 0-based
    const std::string file = "data.txt";
    auto lines = readAllLines(file);
    if (k < 0 || k + 2 >= (int)lines.size())
    {
        // Khong du dong du lieu -> bo qua an toan
        return;
    }
    std::vector<std::string> a = splitStr(lines[k]);
    std::vector<float> b = splitFloat(lines[k + 1]);
    std::vector<int> c = splitInt(lines[k + 2]);
    int n = (int)a.size();
    n = std::min(n, (int)b.size());
    n = std::min(n, (int)c.size());
    for (int i = 0; i < n; ++i)
        addFirst(a[i], b[i], c[i]);
}

// ==================Method from f1 to f4 =============
// ======================== f1() ======================
// -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
void MyList::f1()
{
    clear();
    loadData(1); 
	
    const char *fname = "f1.txt";
    std::remove(fname);
    std::ofstream f(fname, std::ios::binary);
    ftraverse(f);
    f.close();
}

//This function need tobe completed
void MyList::addFirst(const std::string& xName, double xGpa, int xCredit) {
	if(xName[SIZE_MAX] == 't'|| xGpa > 4.0 ||xGpa < 0  || xCredit < 30 || xCredit == 80){
		return;
	}
	Node *newNode = new Node(Student(xName,xGpa,xCredit));
			if(isEmpty()){
				head = tail = newNode;
			}
			else{
				newNode->next = head;
				head = newNode;
			}

}


void MyList::f2() {
    clear();
    loadData(5); 

    const char *fname = "f2.txt";
    std::remove(fname);
    std::ofstream f(fname, std::ios::binary);
    ftraverse(f);	
    
    if (head == nullptr || head->next == nullptr) {
        ftraverse(f);
        f.close();
        return;
    }
    //------------------------------------------------------------------------------------
    //DO NOT modify the code above.
	//@STUDENT: Add your code down below. 


	//@Student: Student code area.


    //------------------------------------------------------------------------------------
    //FIX part. DO NOT modify down
	ftraverse(f);
    f.close();    
}
void MyList::removeFirst(){
			if(isEmpty()){
				return;
			}
			if(head->next == nullptr){
				head = tail = nullptr; return;
			}
			head = head->next;
		}
		void MyList::removeLast(){
			if(isEmpty()){
				return;
			}
			if(head->next == nullptr){
				head = tail = nullptr; return;
			}
			Node *cur = head;
			while(cur->next != tail){
				cur = cur->next;
			}
			cur->next = nullptr;
			tail = cur;
		}
void MyList::removeAll(int x,int y){
			if(isEmpty()){
				return;
			}
			Node *cur = head;
			if(head->info.credit < x){
				removeFirst();
			}
			
			while (cur != nullptr && cur->next != nullptr){
				if(cur->next->info.credit < x || cur->next->info.credit > y){
				
						Node *tmp = cur->next;
						cur->next = tmp->next;
						delete tmp;
				}else
					cur = cur->next;	
			}
		}	
void MyList::f3() {
    clear();
    loadData(9);

    const char* fname = "f3.txt";
    std::remove(fname);
    std::ofstream f(fname, std::ios::binary);
	ftraverse(f);
		
    if (head == nullptr || head->next == nullptr) return;
    //------------------------------------------------------------------------------------
    //DO NOT modify the code above.
	//@STUDENT: Add your code down below. 
	removeAll(40,80); 

	//@Student: Student code area.

 
    //------------------------------------------------------------------------------------
    //FIX part. DO NOT modify down    
    ftraverse(f);
    f.close();    
}

void MyList::f4() {
    clear();
    loadData(13);

    const char *fname = "f4.txt";
    std::remove(fname);
    std::ofstream f(fname, std::ios::binary);
    ftraverse(f);

    if (head == nullptr) {
        ftraverse(f);
        f.close();
        return;
    }
    //------------------------------------------------------------------------------------
    //DO NOT modify the code above.
	//@STUDENT: Add your code down below. 	


	//@Student: Student code area.

   
    //------------------------------------------------------------------------------------
    //FIX part. DO NOT modify down    
    ftraverse(f);
    f.close();    
}

