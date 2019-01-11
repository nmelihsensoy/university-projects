/*
 * Author: Nuri Melih Sensoy
 * Print palindrome numbers between 10-9999
 *
*/
#include <iostream>
using namespace std;

bool isPalindrome(int number){
    int rev = 0;
    int oldNumber = number;
    do{
        int digit = number%10;

        rev = (rev*10) + digit;
        digit = number / 10;
    }while(number>0);

    if(rev == oldNumber){
        return true;
    }

    return false;
}

int main(){

    for(int i=10; i<=9999; i++){
        if(isPalindrome(i) == true){
            cout<<i<<endl;
        }
    }

    return 0;
}
