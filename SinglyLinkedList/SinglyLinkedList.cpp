#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node *next;
		Node(int _data) {
			this->data=_data;
			this->next=nullptr;
		}
};

class SinglyLinkedList {
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList() {
			head=tail=nullptr;
		}

		~SinglyLinkedList() {
			Node *cur=head;
			while (cur!=nullptr) {
				Node *temp=cur;
				cur=cur->next;
				delete temp;
			}
			cout<<"Da thu hoi het bo nho"<<endl;
		}

		bool isEmpty() {
			return head==nullptr;
		}

		void addFirst(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}

		void addLast(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		int countNodes() {
			int count=0;
			Node *cur = head;
			while (cur!=nullptr) {
				count++;
				cur=cur->next;
			}
			return count;
		}
		//Insert x into the position pos
		void addAtPos(int x, int pos) {
			int n = countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0) {
				addFirst(x);
				return;
			}
			if (pos==n) {
				addLast(x);
				return;
			}
			Node *newNode = new Node(x);
			int i=0;
			Node *cur=head;
			while (cur!=nullptr) {
				if (i+1==pos) {
					newNode->next=cur->next;
					cur->next=newNode;
				}
				i++;
				cur=cur->next;
			}
		}

		void removeFirst() {
			//Check the list is empty or not
			if (isEmpty()) {
				cout<<"The list is empty."<<endl;
				return;
			}
			//If the list has only a node
			if (head->next==nullptr) {
				Node *temp=head;
				head=tail=nullptr;
				delete temp;
				return;
			}
			//The list has more than one node
			Node *temp=head;
			head=head->next;
			delete temp;
		}
		//Remove the last element of the list
		void removeLast() {
			//Check the list is empty or not
			if (isEmpty()) {
				cout<<"The list is empty."<<endl;
				return;
			}
			//If the list has only a node
			if (head->next==nullptr) {
				Node *temp=head;
				head=tail=nullptr;
				delete temp;
				return;
			}
			//The list has more than one node
			Node *cur = head;
			while (cur->next!=tail) {
				cur=cur->next;
			}
			Node *temp = tail;
			cur->next=nullptr;
			tail=cur;
			delete temp;
		}
		//Remove the first found element with value as x in the list
		void remove(int x) {
			if (head->data==x) {
				removeFirst();
				return;
			}
			Node *cur = head;
			while (cur!=nullptr) {
				if (cur->next->data==x) {
					if (cur->next==tail) {
						removeLast();
						return;
					}
					Node *temp = cur->next;
					cur->next=temp->next;
					delete temp;
					return;
				}
				cur=cur->next;
			}
		}
		//Remove all elements with value as x
		void removeAll(int x) {
			while (head!=nullptr && head->data==x) {
				removeFirst();
			}
			Node *cur = head;
			while (cur!=nullptr && cur->next!=nullptr) {
				if (cur->next->data==x) {
					if (cur->next==tail)
						removeLast();
					else {
						Node *temp=cur->next;
						cur->next=temp->next;
						delete temp;
					}
				} else
					cur=cur->next;
			}
		}

		//Remove the element at position pos
		void removeAtPos(int pos) {
			int n = countNodes();
			//Check out of range
			if (pos<0 || pos>=n) return;
			if (pos==0) {
				removeFirst();
				return;
			}
			if (pos==n-1) {
				removeLast();
				return;
			}
			int i=0;
			Node *cur=head;
			while (i+1!=pos) {
				cur=cur->next;
				i++;
			}
			Node *temp = cur->next;
			cur->next=temp->next;
			delete temp;
		}

		//Update node with new value as x at position pos
		void editAtPos(int x, int pos) {
			int n = countNodes();
			if (pos<0 || pos>=n) return;
			if (isEmpty()) return;
			int i=0;
			Node *cur=head;
			while (i!=pos) {
				cur=cur->next;
				i++;
			}
			cur->data=x;
		}

		//Return the maximum value in the list
		//Return -999 incase the list is empty.
		int getMaxValue() {
			if (isEmpty()) return -999;
			int max=head->data;
			Node *cur=head;
			while (cur!=nullptr) {
				if (cur->data>max)
					max=cur->data;
				cur=cur->next;
			}
			return max;
		}
		//Return the minimum value in the list
		//Return -999 incase the list is empty.
		int getMinValue() {
			if (isEmpty()) return -999;
			int min=head->data;
			Node *cur=head;
			while (cur!=nullptr) {
				if (cur->data<min)
					min=cur->data;
				cur=cur->next;
			}
			return min;
		}

		//Return the position first found x within the list
		//Return -1 incase find not found
		int getFirstPosOfNode(int x) {
			int pos=-1, i=0;
			Node *cur=head;
			while (cur!=nullptr) {
				if (cur->data==x) {
					pos=i;
					break;
				}
				cur=cur->next;
				i++;
			}
			return pos;
		}

		//Update new value x to a node right before the first max
		//Do nothing if first max is at the beginning of the list
		void f1Update(int newValue) {
			int pos=getFirstPosOfNode(getMaxValue());
			if (pos<=0) return;
			editAtPos(newValue, pos-1);
		}

		//Return the position the-K of x within the list
		//Return -1 incase find not found or out of the range.
		int getPosTheK(int x, int theK) {
			int n=countNodes(), pos=-1;
			if (isEmpty()) return pos;
			if (theK<0 || theK>=n) return pos;
			int i=0, count=0;
			Node *cur=head;
			while (cur!=nullptr) {
				if (cur->data==x) {
					count++;
					if (count==theK) {
						pos=i;
						break;
					}
				}
				i++;
				cur=cur->next;
			}
			return pos;
		}

		//Sort the list in Ascending order
		void sortAsc() {
			for (Node *cur=head; cur!=nullptr; cur=cur->next)
				for (Node *cur2=cur->next; cur2!=nullptr; cur2=cur2->next)
					if (cur->data > cur2->data) {
						int temp = cur->data;
						cur->data=cur2->data;
						cur2->data=temp;
					}
		}
		//Sort the list in Descending order
		void sortDesc() {
			for (Node *cur=head; cur!=nullptr; cur=cur->next)
				for (Node *cur2=cur->next; cur2!=nullptr; cur2=cur2->next)
					if (cur->data < cur2->data) {
						int temp = cur->data;
						cur->data=cur2->data;
						cur2->data=temp;
					}
		}

		void sortInRangeAsc(int pos1, int pos2) {
			if (pos1>pos2) {
				int temp=pos1; pos1=pos2; pos2=temp;
			}
			int i=0,j=0;
			Node *cur=head, *cur2=head;
			while (i!=pos1&&cur!=nullptr) {
				cur=cur->next;
				i++;
			}
			for (cur, i=pos1; i<pos2; cur=cur->next, i++)
				for (cur2=cur->next, j=i+1; j<=pos2; cur2=cur2->next, j++)
					if (cur->data > cur2->data) {
						int temp = cur->data; cur->data=cur2->data;
						cur2->data=temp;
					}

		}

		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};

int main() {
	SinglyLinkedList myList;
	myList.addFirst(6);
	myList.addFirst(2);
	myList.addFirst(5);
	myList.addFirst(2);
	myList.addFirst(9);
	myList.addFirst(2);
	myList.addFirst(9);
	myList.addFirst(7);
	myList.addFirst(5);
	myList.display();
	myList.addLast(4);
	myList.addLast(8);
	myList.addLast(3);
	myList.addLast(2);
	myList.display() ;
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;
	int x, pos;
//	cout<<"Input x = "; cin>>x;
//	cout<<"Input pos = "; cin>>pos;
//	myList.addAtPos(x,pos);
//	myList.display();
//	cout<<"Remove First"<<endl;
//	myList.removeFirst();
//	myList.display();
//	cout<<"Remove Last"<<endl;
//	myList.removeLast();
//	myList.display();
//	cout<<"Remove x"<<endl;
//	myList.remove(0);
//	myList.display();
//	cout<<"Remove all"<<endl;
//	myList.removeAll(2);
//	myList.display() ;
//	cout<<"Remove at pos"<<endl;
//	cout<<"Input pos to remove: "; cin>>pos;
//	myList.removeAtPos(pos);
//	myList.display();
//	cout<<"Update x at pos"<<endl;
//	cout<<"Input new value: "; cin>>x;
//	cout<<"Input position to edit: "; cin>>pos;
//	myList.editAtPos(x, pos);
//	myList.display();
//	cout<<"The maximum value: "<<myList.getMaxValue()<<endl;
//	cout<<"Input new value to edit the node right before max: "; cin>>x;
//	myList.f1Update(x);
//	myList.display();
//	cout<<"Input new value to search its position: "; cin>>x;
//	int theK;
//	cout<<"Input position the-k: "; cin>>theK;
//	int newPos = myList.getPosTheK(x,theK);
//	if (newPos>0)
//		cout<<"The position the-"<<theK<<" of "<<x<<" is: "<<newPos<<endl;
//	else
//		cout<<"Find not found the-"<<theK<<" of "<<x<<endl;
//	cout<<"Sort in Asc"<<endl;
//	myList.sortAsc();
////	myList.sortDesc();
//	myList.display();
//	int pos1 = myList.getPosTheK(myList.getMaxValue(),1);
//	int pos2 = myList.getPosTheK(myList.getMinValue(),3);
//	myList.sortInRage(pos1,pos2);
//	myList.display();

	//Sort in range in Asc from first max to third min
	int pos1, pos2;
	pos1 = myList.getPosTheK(myList.getMaxValue(),1);
	pos2 = myList.getPosTheK(myList.getMinValue(),3);
	myList.sortInRangeAsc(pos1, pos2);
	myList.display();

	return 0;
}
