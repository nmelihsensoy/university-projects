/*
 * Author: Nuri Melih Sensoy
 * Finds Armstrong Numbers and Faktorion Numbers between 100-10000
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

int factorialCalc(int number){
	int fac = 1;
	for(int i=1; i<=number; i++){
		fac = fac * i;
	}
	
	return fac;	
}

/**
 * Returns 0,1,2
 * 0-Not Special
 * 1-Armstrong
 * 2-Faktorion
**/
int isSpecialNumber(int number){
	int digit = countDigit(number);
	int totalArmstrong = 0;
	int totalFaktorion = 0;
	
	for(int i=digit; i>0; i--){
		int pow1 = pow(10, i);
		int pow2 = pow(10, i-1);
		int currentNumber = (number%pow1)/pow2;
		
		totalArmstrong += pow(currentNumber, digit);
		totalFaktorion += factorialCalc(currentNumber);
	}
	
	if(totalArmstrong == number){
		return 1;
	}else if(totalFaktorion == number){
		return 2;
	}
	
	return 0;		
}

int main(){
	
	for(int i=100; i<=10000; i++){
		if(isSpecialNumber(i) == 1){
			cout<<i<<" Armstrong"<<endl;
		}else if(isSpecialNumber(i) == 2){
			cout<<i<<" Faktorion"<<endl;
		}
	}
		
	return 0;
}
