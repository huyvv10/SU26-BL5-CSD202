#include <iostream>
#include "SinglyLinkedListOOP.h"
using namespace std;
int main(){
	SinglyLinkedListOOP myList;
	
	myList.addFirst(Car("T01", "Toyota camry 2.0", 4, 55000.5));
	myList.addFirst(Car("M01", "Mazda CX5", 1, 35000.0));
	myList.addFirst(Car("V01", "VinFast VF9", 6, 65000.5));
	myList.displayList();
	cout<<endl;
	myList.addLast(Car("V02","VinFast VF6", 3, 22000.8));
	myList.addLast(Car("M03","Misumitsi xxx", 4, 52000.8));
	myList.displayList();
	cout<<"Sort list by price in descending order"<<endl;
	myList.sortByPriceDesc();
	myList.displayList();
	
	
	return 0;
}
