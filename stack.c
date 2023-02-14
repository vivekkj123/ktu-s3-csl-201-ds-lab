/*
C Program for implementing Stack using Array
Author: Vivek K J
S3 CSA
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
// Global variables
int stack[MAX_SIZE], top=-1;
// Function to push
void push(int s[], int t, int maxSize){
	int item;
	if(t==maxSize-1){
		printf("Stack Overflow");
	}else{
		printf("Enter the item to be pushed:");			
		scanf("%d", &item);
		top=t+1;
		s[top] = item;
	}

}
// Function to pop
void pop(int s[], int t){
	if(t==-1){
		printf("Stack Underflow");
	}else{
		int item = stack[t];
		printf("Element deleted is %d", item);
		top = t-1;
	}
}
// Function to display
void display(int s[], int t){
	if(t==-1){
		printf("Stack Underflow");
	}else{
		for(int i=t; i>=0; i--){
			printf("%d \t", s[i]);
		}
	}
}
// Main function
void main(){
	while(1){
	int n;
	printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
	printf("Enter your choice:");
	scanf("%d", &n);
	switch(n){
		case 1: 
			push(stack, top, MAX_SIZE);
			break;
		case 2:
			pop(stack, top);
			break;
		case 3:
			display(stack, top);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Enter a valid choice");
	

	}
	 }
}
