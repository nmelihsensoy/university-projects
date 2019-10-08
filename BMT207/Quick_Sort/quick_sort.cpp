/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "quick_sort.cpp"
 * 
 * Quick Sort Algorithm
 *
 */

#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low-1);

	for(int j = low; j<=high-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quick_sort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi-1);
		quick_sort(arr, pi+1, high);
	}
}

void print_arr(int *arr, int arr_size){
	for(int i=0; i<arr_size; i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}

int main(){

	int arr[] = {26, 33, 35, 29, 19, 12, 22};
	print_arr(arr, 7);
	quick_sort(arr, 0, 6);
	print_arr(arr, 7);

	return 0;
}