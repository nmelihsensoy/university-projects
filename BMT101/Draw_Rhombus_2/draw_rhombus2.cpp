/*
 * Author: Nuri Melih Sensoy
 * Draws rhombus and write random numbers inside of sections
 * 
 *   X X X X X * Y Y Y Y Y
 *   X X X X * * * Y Y Y Y
 *   X X X * c * e * Y Y Y
 *   X X * b d * g g * Y Y
 *   X * c b a * e h h * Y
 *   * * * * * * * * * * *
 *   Z * p p n * k l k * T
 *   Z Z * o m * k i * T T
 *   Z Z Z * p * j * T T T
 *   Z Z Z Z * * * T T T T
 *   Z Z Z Z Z * T T T T T 
 * 
*/

#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

int main(){

	int radius=11; //Canvas size

	char letters1[4] = {'a', 'b', 'c', 'd'};
	char letters2[4] = {'e', 'f', 'g', 'h'};
	char letters3[4] = {'m', 'n', 'o', 'p'};
	char letters4[4] = {'i', 'j', 'k', 'l'};
	srand(time(0));

	for(int y=0; y<radius; y++){
		for(int x=0; x<radius; x++){
			if(y<5 and x<5){
				if(y == 5-x){
					cout<<"* ";
				}else if(y > 5-x){
					cout<<letters1[rand()%4+0]<< " ";
				}else{
					cout<<"X ";
				}
			}else if(y<5 and x>5){
				if(y == x-5){
					cout<<"* ";
				}else if(y > x-5){
					cout<<letters2[rand()%4+0]<< " ";
				}else{
					cout<<"Y ";
				}
			}else if(y>5 and x<5){
				if(y == 5+x){
					cout<<"* ";					
				}else if(y > 5+x){
					cout<<"Z ";
				}else{
					cout<<letters3[rand()%4+0]<< " ";		
				}
			}else if(y>5 and x>5){
				if(y == 15-x){
					cout<<"* ";	
				}else if(y > 15-x){
					cout<<"T ";	
				}else{
					cout<<letters4[rand()%4+0]<< " ";
				}
			}else{
				cout<<"* ";
            }
		}
		
		cout<<endl; //End line
	}
	
	return 0;
}
