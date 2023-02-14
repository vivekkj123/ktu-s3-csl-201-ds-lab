/*
C Program for implementing Binary Singly Linked List
Author: Vivek K J
S3 CSA
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
// Main function
struct node{
	int data;
	struct node * next;
};
struct node *head = NULL;
void InsertionBeginning(){
	int item;
	struct node *new;
	printf("Enter the data to be added: ");
	scanf("%d", &item);
	new = (struct node *)malloc(sizeof (struct node));
	new->data = item;
	new->next = NULL;
	if(head == NULL){
		head = new;
	}
	else{
		new->next = head;
		head = new;
	}
	
}
void InsertionEnd(){
	int item;
	struct node *new;
	struct node *temp;
	printf("Enter the data to be added: ");
	scanf("%d", &item);
	new = (struct node *)malloc(sizeof (struct node));
	new->data = item;
	new->next = NULL;
	if(head == NULL){
		head = new;
	}
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new;
	}
	
}
void InsertionAfter(){
	int item, x;
	struct node *new;
	struct node *temp;
	printf("Enter the data to be added: ");
	scanf("%d", &item);
	printf("After Which Element? :");
	scanf("%d", &x);
	new = (struct node *)malloc(sizeof (struct node));
	new->data = item;
	new->next = NULL;
	if(head == NULL){
		head = new;
	}
	else{
		temp = head;
		while(temp->data != x){
			temp = temp->next;
		}
		new->next = temp->next;
		temp->next = new;
	}
	
}
void deleteBeginning(){
	if(head==NULL){
		printf("Linked List is Empty");
	}
	else{
		head = head->next;
	}
}
void deleteEnd(){
	struct node * temp;
	struct node * prev;
	if(head==NULL){
			printf("Linked List is Empty");
	}
	else{
			temp = head;
			while(temp->next != NULL){
				prev = temp;
				temp = temp->next;
			}
			prev->next = NULL;	
	}
}
void deleteX(){
	struct node * temp;
	struct node * prev;
	int item;
	printf("Enter the element to be deleted: ");
	scanf("%d", &item);
	if(head==NULL){
			printf("Linked List is Empty");
	}
	else{
			temp = head;
			while(temp->data != item){
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;	
	}
}
void display(){
	struct node * temp;
	if(head==NULL){
		printf("Linked List is Empty");
	}
	else{
		temp = head;
		while(temp->next != NULL){
			printf("%d \t", temp->data);
			temp = temp->next;
		}
		printf("%d", temp->data);

	}
}

void main(){
	while(1){
	int n;
	printf("\n 1. Insertion In Beginning \
		\n 2. Insertion at End \
		\n 3. Insertion After a value \
		\n 4. Delete from Beginning \
		\n 5. Deletion from End \
		\n 6. Delete a given value \
		\n 7. Display \
		\n 8. Exit");
	printf("\nEnter your choice:");
	scanf("%d", &n);
	switch(n){
		case 1: 
			InsertionBeginning();
			break;
		case 2:
			InsertionEnd();
			break;
		case 3:
			InsertionAfter();	
			break;	
		case 4:
			deleteBeginning();
			break;
		case 5:
			deleteEnd();
			break;
		case 6:
			deleteX();
			break;
		case 7:
			display();
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("Enter a valid choice");
	
		}
	 }
}
