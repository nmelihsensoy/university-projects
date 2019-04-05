/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "fibonacci.cpp"
 * 
 * Finds fibonacci series with using recursive function.
*/
#include <iostream>
using namespace std;

int fibo(int n){
    if(n<=1) return n;
    else return fibo(n-2) + fibo(n-1);
}

int main(){

    int n;
    cout<<"Enter Number: ";
    cin>>n;
    
    cout<<n<<". "<<fibo(n)<<endl;
    for(int i=1; i<=n; i++)
        cout<<fibo(i)<<" ";

    cout<<endl;
    return 0;
}