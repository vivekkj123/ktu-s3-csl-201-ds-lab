/*
Program for performing heap sort algorithm
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
int arr[20], n;
void heapify(int a,int i){
	int largest, left, right, temp;
	largest = i;
	left = 2*i+1;
	right = 2*i+2;
	if(left<a && arr[left] > arr[largest]){
		largest = left;
	}
	if(right<a && arr[right] > arr[largest]){
			largest = right;
	}
	if(largest != i){
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(a, largest);
	}
}

void HeapSort(){
	int i, temp;
	for(i=n/2-1; i>=0; i--){
		heapify(n,i);
	}
	for(i=n-1; i>=0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(i,0);
	}
}


void main(){
	printf("Enter Size of Array: ");
	scanf("%d", &n);
	printf("Enter Array Elements: \n");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	HeapSort();
	printf("Array after sorting is: \n");
	for(int i=0; i<n; i++){
		printf("%d \t", arr[i]);
	}
}
