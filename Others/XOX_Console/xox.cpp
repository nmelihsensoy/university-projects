/*
 * Author: Nuri Melih Sensoy
 * XOX Game in console
 *
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void startGame(int mode);
void mainMenu();
void printMatrix(int matris[][3], int height, int width);

int main(){

    mainMenu();

    return 0;
}


void mainMenu(){
    char choice = ' ';
    while(choice != 'q'){
        int menu;
        cout<<endl;
        cout<<"1-Player vs Player"<<endl;
        cout<<"2-Player vs Computer"<<endl;
        cout<<"3-Computer vs Computer"<<endl;
        cout<<"4-Exit"<<endl;
        cout<<endl;
        cout<<"Choice: ";
        cin>>menu;

        switch(menu){
            case 1:
                startGame(0);
            break;
            case 2:
                startGame(1);
            break;
            case 3:
                startGame(3);
            break;
            case 4:
                choice = 'q';
            break;
        }      
    }
    exit(1);
}

void printMatrix(int matris[][3], int height, int width){
    for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                switch(matris[i][j]){
                    case 0:
                        cout<<". ";
                    break;
                    case 1:
                        cout<<"X ";
                    break;
                    case 2:
                        cout<<"O ";
                    break;
                }
            }
            cout<<endl;
        }
}

void startGame(int mode){
    srand(time(NULL));
    int height = 3, width = 3;
    int matris[3][3];

    //Init Matrix
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            matris[i][j] = 0;

    //Game
    int x=0, y=0, turnCount=0, turnId = 1;
    bool xox = false;
    while(true){
        system(CLEAR);
        bool isValidMove = true;

        //Print Matrix
        printMatrix(matris, height, width);   

        if(xox==true){
            cout<<endl;
            if(turnId == 1){
                cout<<"X Wins!"<<endl;
            }else if(turnId == 2){
                cout<<"O Wins!"<<endl;
            }else if(turnId == 3){
                cout<<"Tied!"<<endl;
            }

            turnCount=0;
            break;
        }
        
        if(mode==0){
            if(turnCount%2==0){
                cout<<"X Move: (Format:x y): ";
                cin>>x>>y;
                turnId=1;
            }else{
                cout<<"O Move: (Format:x y): ";
                cin>>x>>y;
                turnId=2;
            }
        }else if(mode==1){
            if(turnCount%2==0){
                cout<<"X Move: (Format:x y): ";
                cin>>x>>y;
                turnId=1;
            }else{
                do{
                    x = rand()%3;
                    y = rand()%3;
                    if(matris[y][x] == 0){
                        break;
                    }
                }while(matris[y][x] == 0);
                turnId=2;
            }
        }else if(mode==3){
            if(turnCount%2==0){
                do{
                    x = rand()%3;
                    y = rand()%3;
                    if(matris[y][x] == 0){
                        break;
                    }
                }while(matris[y][x] == 0);
                turnId=1;
            }else{
                do{
                    x = rand()%3;
                    y = rand()%3;
                    if(matris[y][x] == 0){
                        break;
                    }
                }while(matris[y][x] == 0);
                turnId=2;
            } 
        }   
                
        if(x<0 or y<0 or x>=height or y>=width or matris[y][x]!=0){
            isValidMove = false;
        }

        if(isValidMove){
            matris[y][x] = turnId;

            int c1=0, c2=0, c3=0, c4=0, c5=9;
            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){

                    if(matris[i][j] != 0)
                        c5--;

                    if(matris[y][j] == turnId)
                        c1++;
                    
                    if(matris[i][x] == turnId)
                        c2++;

                    if(i+j == 2){
                        if(matris[i][j] == turnId){
                            c4++;
                        }
                    }
                    
                    if(i==j){
                        if(matris[i][j] == turnId){
                            c3++;
                        }
                    }
                    
                    //Inverse diagonal
                    if(c4==3){
                        xox = true;
                        break;
                    }

                    //Diagonal
                    if(c3==3){
                        xox = true;
                        break;
                    }

                    //Vertical
                    if(c2==9){
                        xox = true;
                        break;
                    }
                    
                    //Horizontal
                    if(c1==9){
                        xox = true;
                        break;
                    }

                    //Tied
                    if(c5==0){
                        xox = true;
                        turnId = 3;
                        break;
                    }
                }
            }
            turnCount++;               
        }
        cout<<endl;
    }
}