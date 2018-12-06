/*
 * Author: Nuri Melih Sensoy
 * Finds password security level with using ascii codes
 *
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	char sifre[20];
	bool kucukHarf=false, buyukHarf=false, rakam=false, karakter=false;
	int seviye=0;
	int test[3];
	
	cout<<"Enter Password : ";
	cin>>sifre;
	if((strlen(sifre) < 8) or (strlen(sifre) > 12)){
		cout<<"Must be 8-12 character";
	}else{
		for(int i=0; i<strlen(sifre); i++){
			if(((int)sifre[i] >= 65) && ((int)sifre[i] <= 90)){
				buyukHarf = true;
			}
			
			if(((int)sifre[i] >= 97) && ((int)sifre[i] <= 122)){
				kucukHarf = true;	
			}
			
			if(((int)sifre[i] >= 48) && ((int)sifre[i] <= 57)){
				rakam = true;
			}
			
			if(((int)sifre[i] >= 40) && ((int)sifre[i] <= 47)){
				karakter = true;
			}
		}
		
		test[0] = buyukHarf;
		test[1] = kucukHarf;
		test[2] = rakam;
		test[3] = karakter;
		
		for(int i = 0; i<=3; i++){
			if(test[i] == 1){
				seviye++;
			}		
		}
		
		cout<< "Level: " << seviye;
		
	}
		
	return 0;
}

