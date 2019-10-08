/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "sorting.cpp"
 * 
 * Sorting Algorithms
 *
 */

#include <iostream>
using namespace std;

void print_arr(int *arr, int arr_size){
	for(int i=0; i<arr_size; i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr, int arr_size){ //O(n^2)
	for(int i=0; i<arr_size-1; i++){
		for(int j=0; j<arr_size-i-1; j++){
			if(arr[j] > arr[j+1]){ 
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void selection_sort(int *arr, int arr_size){ //O(n^2)
	int min;
	for(int i=0; i<arr_size-1; i++){
		min = i;
		for(int j=i+1; j<arr_size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
}

void insertion_sort(int *arr, int arr_size){
	for(int i=0; i<arr_size; i++){
		int j=i;
		int temp = arr[i];
		while(j > 0 && temp < arr[j-1]){
			arr[j] = arr[j-1];
			j = j-1;
		}
		arr[j] = temp;
	}
}

int main(){
	
	int arr[] = {2, 6, 7, 9, 1, 15, 8, 0};
	print_arr(arr, 8);
	//bubble_sort(arr, 8);
	insertion_sort(arr, 8);
	print_arr(arr, 8);

	return 0;
}