/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "count_word.cpp"
 * 
 * Counts words in a sentence.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string sentence;
    int wordCount = 0;
    cout<<"Enter Sentence: ";
    getline(std::cin, sentence);
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i] == ' ')
            wordCount++;
    }
    cout<<"Words Count: "<< wordCount+1<<endl;

    return 0;
}