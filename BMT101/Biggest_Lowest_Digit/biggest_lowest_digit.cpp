/*
 * Author: Nuri Melih Sensoy
 * Find the largest and the smallest digit in a number
 *
*/
#include <iostream>
#include <math.h>
using namespace std;

int countDigit(int number){
	int i=0;
	do{
		number = number/10;
		i++;
	}while(number > 0);
	
	return i;
}

int main(){
	int number;
	cout<<"Enter Number: ";
	cin>>number;

	int digit = countDigit(number);
	
	int biggest = number%10;
	int lowest = number%10;

	for(int i=digit; i>0; i--){
		int pow1 = pow(10, i);
		int pow2 = pow(10, i-1);
		int currentNumber = (number%pow1)/pow2;

		if(currentNumber > biggest){
			biggest = currentNumber;
		}

		if(currentNumber < lowest){
			lowest = currentNumber;
		}
		
	}

	cout<<"-----------------------------------"<<endl;
	cout<<"Number : "<<number<<endl;
	cout<<"Biggest : "<<biggest<<endl;
	cout<<"Lowest : "<<lowest<<endl;
	cout<<"-----------------------------------"<<endl;

	return 0;
}
