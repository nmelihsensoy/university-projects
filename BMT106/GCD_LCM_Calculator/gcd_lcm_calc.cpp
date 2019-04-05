/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "gcd_lcm_calc.cpp"
 * 
 * GCD(OBEB) and LCM(OKEK) calculator for only 2 numbers.
*/
#include <iostream>
using namespace std;

int gcd_lcm(int a, int b, short mode=0){
    int lcm = a;
    for(int i=2; i<a*b; i++){
        if((i%a==0) and (i%b==0)){
            lcm = i;
            break;
        }
    }
    if(mode==0) 
        return a*b/lcm;
    else
        return lcm;
}

int main(){

    int a, b;
    cout<<"Enter Numbers: ";
    cin>>a>>b;

    cout<<"GCD(OBEB): "<<gcd_lcm(a, b)<<endl;
    cout<<"LCM(OKEK): "<<gcd_lcm(a, b, 1)<<endl;

    return 0;
}