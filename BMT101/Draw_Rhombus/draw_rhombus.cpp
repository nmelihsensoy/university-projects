
/*
 *  Author: Nuri Melih Sensoy
 *  Draws rhombus and write random numbers inside
 * 
 *   A A A A A D A A A A A
 *   A A A A C B C A A A A
 *   A A A E C D C C A A A
 *   A A C D D C E B E A A
 *   A B C B C D E D B B A
 *   D D C E B B C C C D C
 *   A D B D E C B C E E A
 *   A A C D E D D C C A A
 *   A A A C E C D C A A A
 *   A A A A B E B A A A A
 *   A A A A A B A A A A A
 *
*/

#include<iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){
	int radius;
	cout<<"Enter Canvas Radius: ";
	cin>>radius;

	srand(time(0));
	char letters[4] = {'B', 'C', 'D', 'E'};
	
	int stars = 1;
	int spaces = radius-1;
	
    //Draw first half
	for(int row=0; row<radius; row++){
		for(int a=0; a<spaces; a++){
			cout<<"A ";
		}
		
		for(int b=0; b<stars; b++){
			cout<<letters[rand()%4+0]<<" ";
		}
		
		for(int a=0; a<spaces; a++){
			cout<<"A ";
		}
		
		stars+=2;
		spaces--;
		cout<<endl;
	}
	
    //Start second loop after 2 step for solve duplication problem
	stars += -4;
	spaces = 1;
	
    //Draw second half
    for(int row=0; row<radius-1; row++){
		for(int a=0; a<spaces; a++){
			cout<<"A ";
		}
		
		for(int b=0; b<stars; b++){
			cout<<letters[rand()%4+0]<<" ";
		}
		
		for(int a=0; a<spaces; a++){
			cout<<"A ";
		}
		
		stars-=2;
		spaces++;
		cout<<endl;
	}
	
	return 0;
}
