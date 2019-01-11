#include <iostream>
#include <math.h>
using namespace std;

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
        int moveDirI, moveDirJ;

        switch(menu){
            case 'w' :
                moveDirI = -1;
                moveDirJ = 0;
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
        for(int i=0; i>=0 and i<4; i++){
                    for(int j=0; j>=0 and j<4; j++){
                            int newI = i + moveDirI;
                            int newJ = j + moveDirJ;
                            bool move = true;

                            if(newI <0 or newJ < 0 or newI >= 4 or newJ >=4 or 
                            matrix[i][j] != matrix[newI][newJ] and matrix[newI][newJ] !=0){
                                move = false;
                            }
                            
                            if(move == true){
                                matrix[newI][newJ] += matrix[i][j];
                                matrix[i][j] = 0;
                            }       
                        }
                }

        //Print Matrix
        cout<<"-------"<<endl;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                    if(matrix[i][j] == 0)
                        cout<<"0 ";
                    else
                        cout<<matrix[i][j]<<" ";
                }
            cout<<endl;
        }
        cout<<"-------"<<endl;
        
        //get menu selection
        cout<<score<<" ";
        cout<<"sec: ";
        cin>>menu;
    }
        
            

    return 0;
}
