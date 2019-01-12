#include <iostream>
#include <time.h>
#include <stdlib.h>
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
    //Random
    srand(time(NULL));
    int twoFour[2] = {2, 4};

    //init matrix
    int score = 0;
    int matrix[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrix[i][j] = 0;
        }
    }

    //Random first numbers 
    int randomFirstX = rand()%4;
    int randomFirstY = rand()%4;
    matrix[randomFirstX][randomFirstY] = twoFour[rand()%2];

    int randomSecX = rand()%4;
    int randomSecY = rand()%4;
    matrix[randomSecX][randomSecY] = twoFour[rand()%2];


    //Game
    char menu;
    while(menu != 'q'){
    	system("cls");
        int moveDirI=1, moveDirJ=1, startLine=0;

        switch(menu){
            case 'w' :
                moveDirI = -1;
                moveDirJ = 0;
                startLine=3;
            break;
            case 'a' :
                moveDirI = 0;
                moveDirJ = -1;
            break;
            case 's' :
                moveDirI = +1;
                moveDirJ = 0;
            break;
            case 'd' :
                moveDirI = 0;
                moveDirJ = +1;
            break;
        }

        //do movement
        bool possible;
		bool newTile = false;	
        do{
        	possible = false;
			for(int i=0; i>=0 and i<4; i++){
			        for(int j=0; j>=0 and j<4; j++){
						int newI = i + moveDirI;
						int newJ = j + moveDirJ;
						bool move = true;
						
						if(newI <0 or newJ < 0 or newI >= 4 or newJ >=4 or 
							matrix[i][j] != matrix[newI][newJ] and matrix[newI][newJ] !=0){
							move = false;
						}
						
						if(move == true and matrix[i][j] != 0){
							matrix[newI][newJ] += matrix[i][j];
							matrix[i][j] = 0;
							possible = true;
							newTile = true;
						}
			        }
			    }
	    }while(possible);
	    
	    //Add new tile after move
	    int randomXGame;
	    int randomYGame;
		if(newTile and menu != '\0'){
			do{
				randomXGame = rand()%4;
				randomYGame = rand()%4;
				if(matrix[randomXGame][randomYGame] == 0){
					matrix[randomXGame][randomYGame] = twoFour[rand()%2];
				}					
			}while(matrix[randomXGame][randomYGame] == 0);
			
		}
		
        //Print Matrix
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                    if(matrix[i][j] == 0)
                        cout<<"0   ";
                    else{
                    	cout<<matrix[i][j];
                    	int dig = countDigit(matrix[i][j]);
                    	if(dig == 1){
                    		cout<< "   ";
						}else if(dig == 2){
							cout<< "  ";
						}else if(dig == 3){
							cout<< " ";
						}else if(dig == 4){
							cout<< "";
						}
					}
                    	          
                }
            cout<<endl;
        }
        
        //get menu selection
        cout<<"Controls: w,a,s,d // write and enter"<<endl;
        cout<<"Your Move: ";
        cin>>menu;
               
    }
        
            

    return 0;
}
