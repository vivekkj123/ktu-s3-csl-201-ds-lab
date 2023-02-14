/*
Program for performing bubble sort on array of n elements
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
void main(){
	int a[100], size, temp;
	printf("Enter the size of Array: ");
	scanf("%d", &size);
	printf("Enter Array Elements:");
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}
	printf("Array before sorting: ");
	for(int i=0; i<size; i++){
			printf("%d \t", a[i]);
	}
	for(int i=0; i<size-1; i++){
			for(int j=0; j<size-i-1; j++){
				if(a[j] > a[j+1]){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
	}
	printf("\nArray after sorting:");
		for(int i=0; i<size; i++){
			printf("%d \t", a[i]);
	}
}
