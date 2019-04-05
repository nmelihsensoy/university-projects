/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "sum.cpp"
 * 
 * Calculates sum from N to 1 with using recursive function.
*/
#include <iostream>
using namespace std;

int sum_r(int n){
    if(n<=1) return n;
    else return n + sum_r(n-1);
}

int main(){

    int n;
    cout<<"Enter Number: ";
    cin>>n;
    
    cout<<sum_r(n)<<endl;

    return 0;
}