/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "resistor_calculator.cpp"
 * 
 * Resistor Color Code Calculator
*/

#include <iostream>
#include <math.h> //pow
using namespace std;

//Cross platform clear command
//not necessary
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

char resistor[6];
double toleranceValue[10] = {1, 2, 3, 4, 0.5, 0.25, 0.10, 0.05, 5, 10};
char menuText[256] = " 0 - Siyah \n 1 - Kahverengi\n 2 - Kirmizi\n 3 - Turuncu\n 4 - Sari\n 5 - Yesil\n 6 - Mavi\n 7 - Mor\n 8 - Gri\n 9 - Beyaz\n A - Altin\n G - Gumus\n ";

//Resistor input handling
//just getting the input and set resistor array value to received colors id
void resInput(int band){
    char bandChoice;
    bool isValid = true;
    for(int i=0; i<band; i++){
        system(CLEAR); //for better look
        cout<<"######################"<<endl;
        cout<<menuText;
        cout<<"######################"<<endl;
        if(!isValid)
            cout<<"Gecersiz deger girdiniz."<<endl;
    
        cout<<i+1<<". bandin rengi: ";
        cin>>bandChoice;

        if((((int)bandChoice>=48) && ((int)bandChoice<=57)) || (bandChoice == 'A') || (bandChoice == 'G')){
            resistor[i] = bandChoice;
            isValid = true;
        }else{
            isValid = false;
            i--;
        }
    }
}

//Prints calculation
void printResult(double value, double tolerance){
    cout<<endl;
    cout<<value<<" Ohm = "<< value/1000 <<"kOhm"<<" %"<<tolerance<<" tolerans"<<endl;
    cout<<value-(value*tolerance)/100<<" Ohm - "<<value+(value*tolerance)/100<<" Ohm araliginda"<<endl;
    cout<<endl;
}

//Multiplier and Tolerance Char Handling
//mode 0: tolerance, 1 = multiplier
double charHandling(char c, int mode){
    double toInt = c - '0'; // char to integer conversion with " -'0' " 

    if(mode == 0){
        //'A' for gold and 'G' for silver handling
        if(toInt == 17) //A
            toInt -= 9; //17-9 = 8, means 8. element of toleranceValue array
        else if(toInt == 23) //G
            toInt -= 14;//23-14 = 9, means 9. element of toleranceValue array

    }else if(mode == 1){
        //'A' for gold and 'G' for silver handling
        if(toInt == 17) //A
            toInt = pow(10, -1);
        else if(toInt == 23) //G
            toInt = pow(10, -2); 
        else
            toInt = pow(10, toInt);
    }

    return toInt;
}

//Resistor calculation
//calculate the resistor value by by received colors
void resistorCalc(int band){
    int number;
    double multiplier;
    int tolerance;
    double value; 

    resInput(band); //Getting the input

    if(band == 4){
        multiplier = charHandling(resistor[2], 1); //third digit is multiplier
        number = (resistor[0]-'0')*10 + resistor[1]-'0'; //first 2 digit for 4 band
        tolerance = charHandling(resistor[3], 0); //fourth digit is tolerance band

    }else if(band == 5){
        multiplier = charHandling(resistor[3], 1); //fourth digit is multiplier
        number = (resistor[0]-'0')*100 + (resistor[1]-'0')*10 + resistor[2]-'0'; //first 3 digit for 4 band
        tolerance = charHandling(resistor[4], 0); //fifth digit is tolerance band
    }

    value = number*multiplier;
    printResult(value, toleranceValue[tolerance]);
}   

void userMenu(){
    int choice;
    cout<<"Direnc Kac band(4-5): ";
    cin>>choice;
    switch(choice){
        case 4:
            resistorCalc(4);
        break;
        case 5:
            resistorCalc(5);
        break;
        default:
            cout<<"Gecersiz deger girdiniz."<<endl;
        break;
    }
}

int main(){
    char wantContinue;
    while(wantContinue != 'h'){
        userMenu();

        cout<<"Devam etmek ister misiniz?(*/h) "<<endl;
        cin>>wantContinue;
        system(CLEAR); //for better look
    }

    return 0;
}