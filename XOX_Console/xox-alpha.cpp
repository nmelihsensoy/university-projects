/*
 * Author: Nuri Melih Sensoy
 * XOX Game in console
 *
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

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

int main(){

    int height = 3, width = 3;
    int matris[3][3];

    //Init Matrix
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            matris[i][j] = 0;


    //Game
    int x,y;
    bool xox = false;
    int turnCount = 0;
    int turnId = 1;
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
        
        if(turnCount%2 ==0){
            cout<<"X Move: (Format:x y): ";
            turnId=1;
        }else{
            cout<<"O Move: (Format:x y): ";
            turnId=2;
        }

        cin>>x>>y;
                
        if(x<0 or y<0 or x>=height or y>=width or matris[y][x]!=0){
            isValidMove = false;
        }

        if(isValidMove){
            matris[y][x] = turnId;

            int c1=0;
            int c2=0;
            int c3 = 0;
            int c4 = 0;
            int c5 = 9;
            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){

                    if(matris[i][j] == 0){
                        c5++;
                    }

                    if(matris[y][j] == turnId){
                        c1++;
                    }
                    
                    if(matris[i][x] == turnId){
                        c2++;
                    }

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
                    
                    if(c4==3)
                        xox = true;
            
                    if(c3==3)
                        xox = true;

                    if(c2==9)
                        xox = true;

                    if(c1==9)
                        xox = true;

                    if(c5==0){
                        xox = true;
                        turnId = 3;
                    }
                }
            }   
            turnCount++;   
        }
        cout<<endl;
    }

    return 0;
}
