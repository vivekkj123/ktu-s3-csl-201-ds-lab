/*
C Program for convertix Infix expression to Postfix Expression
Author: Vivek K J
S3 CSA
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100
// Global variables
char stack[MAX_SIZE];
char postfix[20];
int top=-1;
// Function to push
void push(char item){
	if(top==MAX_SIZE-1){
		printf("Stack Overflow");
	}else{
		top=top+1;
		stack[top] = item;
	}

}
// Function to pop
char pop(){
	char item = stack[top];
	top = top -1;
	return item;
}
// Function to find Precedence
int precedence(char n){
	switch(n){
		case '^':
			return 3;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '-':
		case '+':
			return 1;
			break;
		default:
			return 0;	
	}
}

// Main function
void main(){
	int i, j=0;
	char infix[100];
	printf("Enter Infix Expression: ");
	scanf("%s", infix);
	for(i=0; i<strlen(infix); i++){
		switch(infix[i]){
			case '(':
				push(infix[i]);
				break;
			case ')':
				while(stack[top] != '('){
					postfix[j] = pop();
					j++;
				}
	            pop(); 
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				if(precedence(infix[i]) > precedence(stack[top])){
					push(infix[i]);
				}
				else if(precedence(infix[i]) <= precedence(stack[top])){
					if(infix[i] == '^')
					{
						push(infix[i]);
					}
					else{
						while(precedence(infix[i]) <= precedence(stack[top])){
							postfix[j] = pop();
							j++;
						}
						push(infix[i]);
					}
				}
				// else{
					// postfix[j]=pop();
					// j++;
					// push(infix[i]);
				// }
				break;
			default: 
				postfix[j]=infix[i];
				j++;
		}		
	}
	printf("%s", postfix);
}
