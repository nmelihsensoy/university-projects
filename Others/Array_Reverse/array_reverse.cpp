/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "array_reverse.cpp"
 * 
 * Array Reverse
 *
 */

#include <iostream>
using namespace std;

void print_arr(int *arr, int _s){
    for(int i=0; i<_s; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int _size){
    for(int i=0; i<_size; i++){
        for(int j=0; j<_size-i-1; j++){
            swap(arr[j], arr[j+1]);
        }
    }
}

void reverse_rec(int *arr, int first, int last){
    if(first == last) return;
    swap(arr[first], arr[last]);
    reverse_rec(arr, first+1, last-1);
}

void reverse2(int *arr, int _size){
    int st = 0;
    while(st != _size-1){
        swap(arr[st], arr[_size-1]);
        st++;
        _size--;
    }
}

int main(){

    int arr[] = {5, 6, 7, 8, 9};
    int _size = 5;

    print_arr(arr, _size);
    reverse2(arr, _size);
    reverse_rec(arr, 0, _size-1);
    print_arr(arr, _size);

    return 0;
}