#include <iostream>
#include <algorithm>
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

void displayArrReverse(int a[], int n){
	for (int i=n-1; i>=0; i--)
		cout<<a[i]<<" ";
	cout<<endl;		
}

int getMax(int a[], int n){
	int max = a[0];
	for (int i=1; i<n; i++)
		if (a[i]>max) max = a[i];
	return max;	
}
int getMin(int a[], int n){
	int min = a[0];
	for (int i=1; i<n; i++)
		if (a[i]<min) min = a[i];
	return min;	
}

//Count numbers of maximum value in the array
int countMax(int a[], int n){
	int max, count=0;
	max = getMax(a,n);
	for (int i=0; i<n; i++)
		if (a[i]==max) count++;
	return count;	
}
//Count numbers of element k in the array
int countValue(int a[], int n, int k){
	int count=0;	
	for (int i=0; i<n; i++)
		if (a[i]==k) count++;
	return count;	
}

bool isPrime(int n){
	if (n<2) return false;
	for (int i=2; i*i<=n; i++)
		if (n%i==0) return false;
	return true;	
}

//Count numbers of prime number in the array
int countPrime(int a[], int n){
	int count=0;	
	for (int i=0; i<n; i++)
		if (isPrime(a[i])) count++;
	return count;	
}
//Sort the array in ascending order
void sortAsc(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if (a[j] < a[j-1]) {
				int temp=a[j]; a[j]=a[j-1]; a[j-1]=temp;
			}
}
//Sort the array in descending order
void sortDesc(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if (a[j] > a[j-1]) {
				int temp=a[j]; a[j]=a[j-1]; a[j-1]=temp;
			}
}

void mySort(int a[], int n){
	sort(a,a+n);
}
//Return the position first found x in the array
//Return -1 in case find not found.
int findFirstPosOfValue(int a[], int n, int x){
	int pos=-1;
	for (int i=0; i<n; i++)
		if (a[i]==x) {
			pos=i; break;
		}
	return pos;	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	inputArr(a,n);
	cout<<"OUTPUT"<<endl;
	displayArr(a,n);
	displayArrReverse(a,n);
	cout<<"Maximum value of the array: "<<getMax(a,n)<<endl;	
	cout<<"Minimum value of the array: "<<getMin(a,n)<<endl;	
	cout<<"Number of maximum elements: "<<countMax(a,n)<<endl;	
	cout<<"Number of maximum elements: "<<countValue(a,n, getMax(a,n))<<endl;	
	cout<<"Number of minimum elements: "<<countValue(a,n, getMin(a,n))<<endl;	
	cout<<"Number of primes: "<<countPrime(a,n)<<endl;
//	sortAsc(a,n);
//	displayArr(a,n);
//	sortDesc(a,n);
//	displayArr(a,n);
	mySort(a,n);
	displayArr(a,n);
	cout<<"Input searching number: ";
	int x;
	cin>>x;
	if (findFirstPosOfValue(a,n,x)!=-1)
		cout<<"The position first found "<<x<<": "<<findFirstPosOfValue(a,n,x)<<endl;
	else
		cout<<"Find not found "<<x<<" in the array."<<endl;	
	return 0;
}
