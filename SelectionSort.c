/*
Program for performing selection sort algorithm
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
void selectionSort(){
	int i, small, j, temp;
	for(i=0; i<=size-1; i++){
		small = i;
		for(j=i+1; j<size; j++){
			if(arr[j]<arr[small])
				small = j;
		}
		temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;
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
	selectionSort();
	printf("Array After sorting is:");
	printArray();
	
}
