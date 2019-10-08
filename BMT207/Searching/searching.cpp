/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "searching.cpp"
 * 
 * Linear and Binary Search
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

int linear_search(int *arr, int arr_size, int key){ //O(n)
	for(int i=0; i<arr_size; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

int binary_search(int *arr, int arr_size, int key){ //O(logn)
	int low = arr[0];
	int high = arr[arr_size-1];

	while(low <= high){
		int mid = (low+high)/2;
		if(arr[mid] < key){
			low = mid+1;
		}else if(arr[mid] > key){
			high = mid-1;
		}else{
			return mid;
		}
	}

	return -1;
}

int main(){

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	print_arr(arr, 10);
	cout<<binary_search(arr, 10, 8)<<endl;
	cout<<linear_search(arr, 10, 8)<<endl;
	return 0;
}