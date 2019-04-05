/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "factorial.cpp"
 * 
 * Calculates factorial with using recursive function.
*/
#include <iostream>
using namespace std;

int fac(int n){
    if(n<=1) return n;
    else return n * fac(n-1);
}

int main(){

    int n;
    cout<<"Enter Number: ";
    cin>>n;
    
    cout<<fac(n)<<endl;

    return 0;
}