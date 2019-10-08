/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "heap_tree.cpp"
 * 
 * Heap Tree Implementation
 * 
 */

#include <iostream>
using namespace std;

int arr[10];
int arr_i = 1;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x){
    arr[arr_i] = x;
    int i = arr_i;
    while(i != 1 && arr[i/2] < arr[i]){ //percolate up
        swap(arr[i], arr[i/2]);
        i = i/2;
    }
    arr_i++;
}

void remove_max(){
    int i = 1;
    swap(arr[i], arr[arr_i]);
    arr_i--;
    while(i*2 < arr_i){ //percolate down
        if(arr[i*2] > arr[i*2+1]){
            swap(arr[i], arr[i*2]);
            i = i*2;
        }else{
            swap(arr[i], arr[i*2+1]);
            i = i*2+1;
        }
    }
}

void print_h(){
    for(int i=1; i<arr_i; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}


int main(){

    insert(45);
    insert(35);
    insert(23);
    insert(27);
    insert(21);
    insert(22);
    insert(4);
    insert(19);
    insert(42);

    print_h();

    remove_max();
    print_h();
    
    return 0;
}