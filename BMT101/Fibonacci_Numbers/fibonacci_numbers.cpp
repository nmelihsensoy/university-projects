/*
 * Author: Nuri Melih Sensoy
 * Print first N fibonacci numbers
 *
*/
#include<iostream>
using namespace std;

int main(){
	
	int limit;
	int a=0, b=1;
	
	cout<<"N: ";
	cin>>limit;
	
	
	for(int i=1; i<=limit; i++){
		
		cout<<b<<" ";
		
		int c = a+b;
		a=b;
		b=c;
	}	
	
		
	return 0;
}

