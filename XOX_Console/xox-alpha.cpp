/*
 * Author: Nuri Melih Sensoy
 * XOX Game in console
 *
*/
#include <iostream>
#include <math.h>
using namespace std;

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
    while(true){
        
        //Print Matrix
        printMatrix(matris, height, width);

        if(xox==true){
            cout<<endl;
            cout<<"X Wins!"<<endl;
            break;
        }

        cout<<"Move(Format:x y): ";
        cin>>x>>y;
        
        bool isValidMove = true;
        if(x<0 or y<0 or x>=height or y>=width and matris[height][width]!=0){
            isValidMove = false;
        }

        if(isValidMove){
            matris[y][x] = 1;

            int c1=0;
            int c2=0;
            int c3 = 0;
            int c4 = 0;
            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                    if(matris[y][j] == 1){
                        c1++;
                    }
                    
                    if(matris[i][x] == 1){
                        c2++;
                    }

                    if(i+j == 2){
                        if(matris[i][j] == 1){
                            c4++;
                        }
                    }
                    
                    if(i==j){
                        if(matris[i][j] == 1){
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
                }
            }    
        }
    }

    return 0;
}
