/*
C Program for implementing Double Ended Queue using Array
Author: Vivek K J
S3 CSA
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
// Global variables
int queue[MAX_SIZE], LEFT=-1, RIGHT=-1;
// Function to Enqueue
void enqueueRight(){
	int item;
	if((LEFT==0 && RIGHT==MAX_SIZE-1) || LEFT==RIGHT+1){
		printf("Queue is Full");
	}else{
		printf("Enter the item to be pushed:");			
		scanf("%d", &item);
		if(LEFT==-1 && RIGHT==-1){
			LEFT=0;
			RIGHT=0;
		}
		else{
			if(RIGHT==MAX_SIZE-1){
			 	RIGHT=0;
			}
			else{
				RIGHT=RIGHT+1;
			}
		}
		queue[RIGHT]=item;
	}

}

void enqueueLeft(){
	int item;
	if((LEFT==0 && RIGHT==MAX_SIZE-1) || LEFT==RIGHT+1){
		printf("Queue is Full");
	}else{
		printf("Enter the item to be pushed:");			
		scanf("%d", &item);
		if(LEFT==-1 && RIGHT==-1){
			LEFT=0;
			RIGHT=0;
		}
		else{
			if(LEFT==0){
				LEFT=MAX_SIZE-1;
			}
			else{
				LEFT=LEFT+1;
			}
		}
		queue[LEFT]=item;
	}

}
// Function to Dequeue
void dequeueRight(){
	int item;
	if(LEFT==-1 && RIGHT==-1){
		printf("Queue is empty");
	}
	else{
		item = queue[RIGHT];
		printf("Item Deleted is %d", item);
		if(LEFT==RIGHT){
			LEFT=-1;
			RIGHT=-1;
		}
		else if(RIGHT==0){
			RIGHT=MAX_SIZE-1;
		}
		else{
			RIGHT=RIGHT-1;
		}
	}
}

void dequeueLeft(){
	int item;
	if(LEFT==-1 && RIGHT==-1){
		printf("Queue is empty");
	}
	else{
		item = queue[LEFT];
		printf("Item Deleted is %d", item);
		if(LEFT==RIGHT){
			LEFT=-1;
			RIGHT=-1;
		}
		else if(LEFT==MAX_SIZE-1){
			LEFT=0;
		}
		else{
			LEFT=LEFT+1;
		}
	}
}
// Function to display
void display(){
	if(LEFT==-1 && RIGHT==-1)
     		printf("Queue is empty");
   	else if (LEFT<=RIGHT){
   	// Normal Condition i.e. FRONT<=REAR
 		for(int i=LEFT;i<=RIGHT;i++)
		{
    			printf("%d\t",queue[i]);
		}
	}
	else
	{
	// Several elements are dequed and several elements are enqueued i.e. LEFT>RIGHT
        // First Print from MAX_SIZE to RIGHT
                for (int i = 0; i <= RIGHT; i++)
    			printf("%d\t", queue[i]);
	// Then print from LEFT to MAX_SIZE
		for (int i = LEFT; i < MAX_SIZE; i++)
            		printf("%d\t", queue[i]);
    	}
}
// Main function
void main(){
	while(1){
	int n;
	printf("\n 1. Insertion Through Left\n 2. Insertion Through Right\n 3. Deletion Through Left\n 4. Deletion Through Right\n 5. Display\n 6. Exit");
	printf("\nEnter your choice:");
	scanf("%d", &n);
	switch(n){
		case 1: 
			enqueueLeft();
			break;
		case 2:
			enqueueRight();
			break;
		case 3:
			dequeueLeft();	
			break;	
		case 4:
			dequeueRight();
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Enter a valid choice");
	
		}
	 }
}
