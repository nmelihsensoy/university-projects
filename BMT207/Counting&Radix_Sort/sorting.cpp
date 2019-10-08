/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "sorting.cpp"
 * 
 * Counting and Radix Sort Algorithm
 * 
 */

#include <iostream>
using namespace std;
	
void counting_sort(int arr[], int _size){
	int i, output[_size], freq[10] = {0};
	for(i=0; i<_size; i++){
		freq[arr[i]]++;
	}

	for(int i=1; i<10; i++){
		freq[i] += freq[i-1];
	}

	for(i=_size-1; i>=0; i--){
		output[freq[arr[i]]-1] = arr[i];
		freq[arr[i]]--;
	}

	for(i=0; i<_size; i++){
		arr[i] = output[i];
	}

}

void counting_sort2(int arr[], int _size){
	int i, freq[10] = {0};
	for(i=0; i<_size; i++){
		freq[arr[i]]++;
	}

	int j=0;
	for(i=0; i<10; i++){
		int temp = freq[i];
		while(temp--){
			arr[j] = i;
			j++;
		}
	}
}

void counting_sort_digit(int arr[], int _size, int d_val){
	int i, freq[10] = {0}, output[_size];

	for(i=0; i<_size; i++){
		freq[(arr[i]/d_val)%10]++;
	}

	for(i=1; i<10; i++){
		freq[i] += freq[i-1];
	}

	for(i = _size-1; i>=0; i--){
		output[freq[(arr[i]/d_val)%10]-1] = arr[i];
		freq[(arr[i]/d_val)%10]--;
	}

	for(i=0; i<_size; i++){
		arr[i] = output[i];
	}

}

int get_max(int arr[], int _size){
	int max = arr[0];
	for(int i=0; i<_size; i++){
		if(max < arr[i]) max = arr[i];
	}
	return max;
}

void radix_sort(int arr[], int _size){
	int max = get_max(arr, _size);
	int digit_val = 1;
	while(max){
		counting_sort_digit(arr, _size, digit_val);
		digit_val *= 10;
		max /= 10;
	}
}

void print_arr(int arr[], int _size){
	for(int i=0; i<_size; i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}

int main(){

	int arr[] = {1, 4, 1, 2, 7, 5, 2};
	int _size = 7;

	int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int _size2 = sizeof(arr2)/sizeof(arr2[0]);

	print_arr(arr2, _size2);
	radix_sort(arr2, _size2);
	print_arr(arr2, _size2);


	return 0;
}