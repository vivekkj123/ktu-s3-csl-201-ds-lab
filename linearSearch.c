/*
Program for performing Linear Search
Author: Vivek K J
S3 CSA
*/
#include<stdio.h>
void main(){
	int a[100], key, flag=0, n, i;
	printf("Enter the Size of Array: ");
	scanf("%d", &n);
	printf("Input Array Elements:");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d", &key);
	for(i=0; i<n; i++){
		if(a[i] == key){
			printf("Element found at position %d", i+1);
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("Element not found");
	}
}
