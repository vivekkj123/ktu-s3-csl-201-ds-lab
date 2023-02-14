/*
C Program for implementing Evaluating postfix Expression
Author: Vivek K J
S3 CSA
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100
// Global variables
int stack[MAX_SIZE], top=-1;
// Function to push
void push(int item){
	if(top==MAX_SIZE-1){
		printf("Stack Overflow");
	}else{
		top=top+1;
		stack[top] = item;
	}

}
// Function to pop
int pop(){
	if(top==-1){
		printf("Stack Underflow");
	}else{
		int item = stack[top];
		top = top-1;
		return item;
	}
}
void display(){
	if(top==-1){
		printf("Stack Underflow");
	}else{
		for(int i=0; i<=top; i++){
			printf("%d \t", stack[i]);
		}
	}
}

// Main function
void main(){
	char postfix[100];
	printf("Enter Postfix Expression: ");
	scanf("%s", postfix);
	for(int i=0; postfix[i]!=')'; i++)
	{
		if(isalnum(postfix[i]))
		{
			push(postfix[i] - '0');
		}
		else
		{
			int res;
			int a = pop();
			int b = pop();			
			switch(postfix[i])
			{
				case '+':
					res=b+a;
					break;
				case '-':
					res=b-a;
					break;
				case '*':
					res=b*a;
					break;
				case '/':
					res=b/a;
					break;
				case '^':
					res=b^a;
					break;
			}
			push(res);
		}
	}
	display();
}
