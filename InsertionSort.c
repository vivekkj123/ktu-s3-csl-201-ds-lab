/*
Program for performing Insertion sort algorithm
Author: Vivek K J
S3 CSA
*/
#include<stdio.h>
int size, arr[100];
void readArray(){
	int i;
	printf("Enter The Size of Array: ");
	scanf("%d", &size);
	printf("Enter the array elements:");
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
}
void insertionSort(){
	int i, key, j;
	for(i=1; i<=size-1; i++){
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
void printArray(){
	int i;
	for(i=0; i<size; i++){
		printf("%d \t", arr[i]);
	}
	printf("\n");
}
int main(){
	readArray();
	printf("Array Before sorting is:");
	printArray();
	insertionSort();
	printf("Array After sorting is:");
	printArray();
	
}
