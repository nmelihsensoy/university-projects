/*
 * Author: Nuri Melih Şensoy
 * A program that finds prime numbers between 10-100 and check digits are single
 *
*/

#include <iostream>
using namespace std;

//Return true if number is a prime
bool isPrime(int n){
    if(n<=1)
        return false;

    for(int i=2; i<n; i++){
        if(n % i == 0)
            return false;
    }

    return true;
}

//Splits a number and return true if first two digits are single
bool isNumberDigitsSingle(int n){
    int firstDigit = n / 10;
    int secondDigit = n % 10;

    if((firstDigit % 2 != 0) && (secondDigit % 2 != 0)){
        return true;
    }

    return false;
}

int main(){
   int specificCounter;

   for(int i = 10; i <= 100; i = i + 1) {
      if(isPrime(i) == true){
          if(isNumberDigitsSingle(i) == true){
              //cout << i << " "<< i / 10 << " " << i % 10 << "\n";
              specificCounter++;
          }
      }
            
   }

    //Print numbers count that fits a specific rules
    cout << specificCounter;    
 
   return 0;
}
