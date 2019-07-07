/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "array_rotation.cpp"
 * 
 * Array Rotation
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

void rotate_right(int *arr, int _size, int shift){
    int temp;
    for(int j=0; j<shift; j++){ 
        temp = arr[_size-1];
        for(int i = _size; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
}

void rotate_left(int *arr, int _size, int shift){
    int temp;
    for(int j=0; j<shift; j++){
        temp = arr[0];
        for(int i=0; i<_size; i++){
            arr[i] = arr[i+1];
        }
        arr[_size-1] = temp;
    }
}

int main(){

    int arr[] = {5, 6, 7, 8, 9};
    int _size = 5;
    int shift = 2;

    print_arr(arr, _size);
    rotate_left(arr, _size, 2);
    rotate_right(arr, _size, 2);
    print_arr(arr, _size);

    return 0;
}