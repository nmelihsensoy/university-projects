#include<iostream>
using namespace std;

int main(){
	int number, lowest, biggest, numberPrint;
	cout<<"Enter Number: ";
	cin>>number;
	
	numberPrint = number;
	lowest = number%10;
	biggest = number%10;
		
	while(number>0){
		int digit = number%10;
		if(digit > biggest){
			biggest = digit;
		}
		
		if(digit<lowest){
			lowest = digit;
		}

		number /= 10;
	}
	
	cout<<"-------------------"<<endl;
	cout<<"Number: "<<numberPrint<<endl;
	cout<<"Biggest: "<<biggest<<" Lowest: "<<lowest<<endl;
	cout<<"-------------------"<<endl;
	
	return 0;
}
