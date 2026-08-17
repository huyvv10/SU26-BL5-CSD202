#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	Queue myQ;
	myQ.enqueue(6);
	myQ.enqueue(2);
	myQ.enqueue(9);
	myQ.enqueue(7);
	myQ.display();
	cout<<endl;
	cout<<myQ.front()<<" ";
	myQ.dequeue();
	cout<<myQ.front()<<" ";
	myQ.dequeue();
	cout<<myQ.front()<<" ";
	myQ.dequeue();	
	cout<<endl;
	myQ.display();

	return 0;
}
