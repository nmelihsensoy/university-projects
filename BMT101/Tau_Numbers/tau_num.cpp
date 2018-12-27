/*
 * Author: Nuri Melih Sensoy
 * Finds Tau Numbers Numbers between 1000-9999
 *
*/
#include<iostream>
using namespace std;

bool isTauNumber(int number){
	int counter = 0;
	for(int i=1; i<=number; i++){
		if(number%i == 0){
			counter++;
		}
	}
	
	if(sayi%counter == 0){
		return true;
	}
	
	return false;
}

void Tau(){
	for(int i=1000; i<=9999; i++){
		if(isTauNumber(i)){
			cout<<i<<" tau number"<<endl;
		}
	}
}

int main(){
	Tau();
	return 0;
}
