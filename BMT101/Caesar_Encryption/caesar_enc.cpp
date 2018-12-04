/*
 * Author: Nuri Melih Sensoy
 * Simple Caesar Cipher Encryption
 *
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char text[100], cryptedText[100];
	int key;
	
	while(true){
		int userChoice;
		cout<<"1-Encryption"<<endl << "2-Decryption"<<endl;
		cout<<"Your Choice: ";
		cin>>userChoice;
		
		if(userChoice == 1){
			cout<< "Enter text: ";
			cin>>text;
			
			cout<< "Enter key: ";
			cin>>key;
			
			for(int i=0; i<strlen(text); i++){
				cryptedText[i] = char(int(text[i] + key));		
			}
			
			cout<<"Crypted Text: " << cryptedText<<endl;
			cout<<"Public Key: " << key<<endl;
			break;
		}else if(userChoice == 2){
			cout<< "Enter text: ";
			cin>>text;
			
			cout<< "Enter key: ";
			cin>>key;
			
			for(int i=0; i<strlen(text); i++){
				cryptedText[i] = char(int(text[i] - key));		
			}
			
			cout<<"Uncrypted Text: " << cryptedText<<endl;
			break;
		}	
		
	}
		
	return 0;
}
