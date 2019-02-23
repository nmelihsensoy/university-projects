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

char resistor[6];
double toleranceValue[10] = {1, 2, 3, 4, 0.5, 0.25, 0.10, 0.05, 5, 10};
char menuText[256] = " 0 - Siyah \n 1 - Kahverengi\n 2 - Kırmızı\n 3 - Turuncu\n 4 - Sari\n 5 - Yesil\n 6 - Mavi\n 7 - Mor\n 8 - Gri\n 9 - Beyaz\n A - Altin\n G - Gumus\n ";

//Resistor input handling
//just getting the input and set resistor array value to received colors id
void resInput(int band){
    for(int i=0; i<band; i++){
        char bandChoice;
        cout<<"######################"<<endl;
        cout<<menuText;
        cout<<"######################"<<endl;
        cout<<i+1<<". bandin rengi: ";
        cin>>bandChoice;

        resistor[i] = bandChoice;
    }
}

//Multiplier and Tolerance Char Handling
//mode 0: tolerance, 1 = multiplier
double charHandling(char c, int mode){
    double toInt = c - '0'; // char to integer conversion with " -'0' " 

    if(mode == 0){
        //'A' for gold and 'G' for silver handling
        if(toInt==17) //A
            toInt -= 9; //17-9 = 8, means 8. element of toleransValue array
        else if(toInt == 23) //G
            toInt -= 14;//23-14 = 9, means 9. element of toleransValue array

    }else if(mode == 1){
        //'A' for gold and 'G' for silver handling
        if(toInt==17) //A
            toInt = pow(10, -1);
        else if(toInt==23) //G
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
        multiplier = charHandling(resistor[2], 1);
        number = (resistor[0]-'0')*10 + resistor[1]-'0'; 
        tolerance = charHandling(resistor[3], 0);

    }else if(band == 5){
        multiplier = charHandling(resistor[3], 1);
        number = (resistor[0]-'0')*100 + (resistor[1]-'0')*10 + resistor[2]-'0'; 
        tolerance = charHandling(resistor[4], 0);
    }

    value = number*multiplier;

    cout<<endl;
    /*for debugging
     cout<<"Multiplier: "<<carpan<<endl;
     cout<<"Number: "<<number<<endl;
     cout<<"Tolerance: "<<tolerans<<endl;
    */
    cout<<"Deger: "<<value<<" Ω"<<endl;
    cout<<value-value*toleranceValue[tolerance]/100<<"R - "<<value+value*toleranceValue[tolerance]/100<<"R arasında"<<endl;
    cout<<endl;
}   

void userMenu(){
    int choice;
    cout<<"Direnc Kac band: ";
    cin>>choice;

    switch(choice){
        case 4:
            resistorCalc(4);
        break;
        case 5:
            resistorCalc(5);
        break;
    }
}

int main(){
    char wantContinue;

    while(wantContinue != 'h'){
        userMenu();

        cout<<"Devam etmek ister misiniz?(e/h) "<<endl;
        cin>>wantContinue;
    }

    return 0;
}