#include <iostream>
using namespace std;
void inputArr(int a[], int n){
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
}

void displayArr(int a[], int n){
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}
//Check wherether n is a prime number or not
bool isPrime(int n){
	if (n<2) return false;
	for (int i=2; i*i<=n; i++)
		if (n%i==0) return false;
	return true;	
}

//Return the position theK of x in the array
//Return -1 in case find not found
int getPosPrimeTheK(int a[], int n, int theK){
	int pos=-1, count=0;
	if (theK<=0 || theK > n) return pos;
	for (int i=0; i<n; i++)
		if (isPrime(a[i])){
			count++;
			if (count==theK) {
				pos=i; break;
			}
		}
	return pos;
}

//Sort the array from the First Max to the second Min in ascending order
//The out of range keep unchange.
void sortAscInRage(int a[], int n, int pos1, int pos2){
	for (int i=pos1; i<pos2; i++)
		for (int j=pos2; j>i; j--)
			if (a[j-1] < a[j]){
				int temp=a[j]; a[j]=a[j-1]; a[j-1]=temp;
			}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	inputArr(a,n);
	cout<<"OUTPUT"<<endl;
	displayArr(a,n);
	int pos1, pos2;
	pos1=getPosPrimeTheK(a,n,2);
	pos2=getPosPrimeTheK(a,n,4);
	if (pos1<pos2 && pos2!=-1){
		sortAscInRage(a,n,pos1,pos2);
		displayArr(a,n);
	} else {
		cout<<"Error"<<endl;
	}
	return 0;
}
