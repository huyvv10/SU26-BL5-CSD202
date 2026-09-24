#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void inputArr(int a[], int n){
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
}
void displayArr(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;  
}
bool isPrime(int n){
	if (n < 2){
		return false;
	}
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;	
}
int findFirstPosOfValue(int a[], int n){		
	int pos = -1;
	for(int i = 0; i < n; i++){
		if(a[i] >= 0 && a[i] % 2 == 0 ){
			pos = i; break;
		}
	}
	return pos;
}

int main() {
    // INPUT -- FIXED PART - STUDENT DO NOT EDIT ANYTHING BELOW
    system("cls"); // Clears console (works on Windows)
    int n; //number of data points
    if (!(cin >> n)) return 0;
    int a[n]; 
    // INPUT -- FIXED PART - STUDENT DO NOT EDIT ANYTHING ABOVE	
	//@STUDENT: WRITE YOUR OUTPUT HERE TO INPUT DATA FOR ARRAY arr AND PROCESS:
	inputArr(a,n); 
	
    
    // Fixed: Do not edit anything here.
    cout << "\nOUTPUT:\n";
    //@STUDENT: WRITE YOUR OUTPUT HERE TO DISPLAY PROCESSED DATA:
    displayArr(a,n); 
	cout<<"Not enough elements"<<endl; 
	cout<<"Not enough elements"<<endl; 
 
		


    //-- FIXED PART - DO NOT EDIT ANYTHING BELOW
    cout << "\n";
    system("pause");
    return 0;
}