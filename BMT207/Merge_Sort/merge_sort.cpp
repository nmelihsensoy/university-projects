/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "merge_sort.cpp"
 * 
 * Merge Sort Algorithm
 * 
 * Sorry about the comment lines.
 *
 */

#include <iostream>
using namespace std;

void merge(int *arr, int low, int middle, int high){
	int i, j, k;
	int l_arr_size = middle-low+1; // sol tarafın boyutu 
	int r_arr_size = high-middle; // sağ tarafın boyutu
	
	int L[l_arr_size], R[r_arr_size];  //sol ve sağ taraf için geçici dizi

	for(i=0; i<l_arr_size; i++){ //sol diziye elemanlarını kopyala
		L[i] = arr[low+i];
		//cout<<"#"<<arr[low+i];
	}

	for(j=0; j<r_arr_size; j++){ //sağ diziye elemanlarını kopyala
		R[j] = arr[middle+j+1];
		//cout<<"$"<<arr[middle+j+1];
	}

	i=0; //i yi tekrar kullanmak için sıfırla
	j=0; //j yi tekrar kullanmak için sıfırla
	k=low; // k yı her bir parçanın ilk elemanına ayarla
	while(i < l_arr_size && j < r_arr_size){ //sağ ve sol dizideki en küçük elemanı bulup çıktıya ekle
		if(L[i] <= R[j]){ 
			arr[k] = L[i]; 
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < l_arr_size){ //sol dizideki sıralı kalanları çıktıya ekle
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < r_arr_size){ //sağ dizideki sıralı kalanları çıktıya ekle
		arr[k] = R[j];
		j++;
		k++;
	}

}

void merge_sort(int *arr, int low, int high){
	if(low < high){
		int middle = (low+high)/2;
		merge_sort(arr, low, middle);
		merge_sort(arr, middle+1, high);
		merge(arr, low, middle, high);
	}
}

void print_arr(int *arr, int arr_size){
	for(int i=0; i<arr_size; i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}

int main(){

	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	print_arr(arr, 7);

	merge_sort(arr, 0, 6);

	print_arr(arr, 7);
	return 0;
}