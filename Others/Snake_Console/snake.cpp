/*
 * Author: Nuri Melih Sensoy
 * Console snake game
 *
*/
#include<iostream>
#include <time.h>    
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

const int height= 11;
const int width = 21;
int matrix[height][width];
int dirX, dirY, fruitX, fruitY;
int tailHeight;
int tailX[50], tailY[50];
int score = 0;
bool gameOver;
enum dirControl {STOP=0, UP, DOWN, LEFT, RIGHT};
dirControl dir;

void randomFruit(int x, int y){
    do{
        fruitX = 1 + rand()%(height-2);
        fruitY = 1 + rand()%(width-2);
        if(fruitX!=x and fruitY!=y)
            break;
    }while(fruitX==x and fruitY ==y);
    
}

void initGame(){
    srand (time(NULL));
    dirX = height/2;
    dirY = width/2;
    randomFruit(dirX, dirY);
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            matrix[i][j] = 0;
}



void drawGame(){
    system(CLEAR);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(i == dirX and j==dirY){
                cout<<"O ";
            }else if(i == fruitX and j == fruitY){
               cout<<"@ ";
            }else{
                bool backPrint = true;
                for(int t=0; t<tailHeight; t++){
                    if(i==tailX[t] and j==tailY[t]){
                        cout<<"o ";
                        backPrint = false;
                    }
                }

                if(backPrint)
                    if(i==0 or i==height-1 or j==0 or j==width-1)
                        cout<<"# ";
                    else
                        cout<<"  ";
            }
        }
        cout<<endl;    
    }
    cout<<"Score: "<<score<<endl;         
}

void gameInput(){
    char input;
    cout<<"Move: ";
    cin>>input;
    switch(input){
        case 'w':
            dir = UP;
        break;
        case 's':
            dir = DOWN;
        break;
        case 'a':
            dir = LEFT;
        break;
        case 'd':
            dir = RIGHT;
        break;
        case 'q':
            gameOver = true;
        break;
    }
}

void gameMain(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevX2, prevY2;

    tailX[0] = dirX;
    tailY[0] = dirY;

    for(int t=1; t<tailHeight; t++){
        prevX2 = tailX[t];
        prevY2 = tailY[t];

        tailX[t] = prevX;
        tailY[t] = prevY;

        prevX = prevX2;
        prevY = prevY2;
    }

    switch(dir){
        case UP:
            dirX--;
        break;
        case DOWN:
            dirX++;
        break;
        case LEFT:
            dirY--;
        break;
        case RIGHT:
            dirY++;
        break;
        default:
        break;
    }

    if(dirX<1)
        dirX = height-2;
        
    if(dirX>height-2)
        dirX = 1;

    if(dirY<1)
        dirY = width-2;

    if(dirY>width-2)
        dirY = 1;

    if(dirX == fruitX and dirY == fruitY){
        for(int t=0; t<tailHeight; t++) 
                randomFruit(tailX[t], tailY[t]);
    
        score += 10;
        tailHeight++;
    }

    for(int t=0; t<tailHeight; t++) 
        if(dirX == tailX[t] and dirY == tailY[t])
            gameOver = true;
}

int main(){
    initGame();
    while(!gameOver){
        drawGame();
        gameInput();
        gameMain();
    }
    
    return 0;
}