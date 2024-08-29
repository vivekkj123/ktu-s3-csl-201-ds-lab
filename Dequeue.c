/*
C Program for implementing Double Ended Queue using Array
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

// Global variables
int queue[MAX_SIZE], LEFT = -1, RIGHT = -1;

// Function to Enqueue from Right
void enqueueRight() {
    int item;
    if ((LEFT == 0 && RIGHT == MAX_SIZE - 1) || (LEFT == RIGHT + 1)) {
        printf("Queue is Full\n");
    } else {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        if (LEFT == -1 && RIGHT == -1) { // Empty condition
            LEFT = 0;
            RIGHT = 0;
        } else if (RIGHT == MAX_SIZE - 1) {
            RIGHT = 0; // Wrap around
        } else {
            RIGHT++;
        }
        queue[RIGHT] = item;
    }
}

// Function to Enqueue from Left
void enqueueLeft() {
    int item;
    if ((LEFT == 0 && RIGHT == MAX_SIZE - 1) || (LEFT == RIGHT + 1)) {
        printf("Queue is Full\n");
    } else {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        if (LEFT == -1 && RIGHT == -1) { // Empty condition
            LEFT = 0;
            RIGHT = 0;
        } else if (LEFT == 0) {
            LEFT = MAX_SIZE - 1; // Wrap around
        } else {
            LEFT--;
        }
        queue[LEFT] = item;
    }
}

// Function to Dequeue from Right
void dequeueRight() {
    int item;
    if (LEFT == -1 && RIGHT == -1) {
        printf("Queue is empty\n");
    } else {
        item = queue[RIGHT];
        printf("Item Deleted is %d\n", item);
        if (LEFT == RIGHT) { // Single element condition
            LEFT = -1;
            RIGHT = -1;
        } else if (RIGHT == 0) {
            RIGHT = MAX_SIZE - 1; // Wrap around
        } else {
            RIGHT--;
        }
    }
}

// Function to Dequeue from Left
void dequeueLeft() {
    int item;
    if (LEFT == -1 && RIGHT == -1) {
        printf("Queue is empty\n");
    } else {
        item = queue[LEFT];
        printf("Item Deleted is %d\n", item);
        if (LEFT == RIGHT) { // Single element condition
            LEFT = -1;
            RIGHT = -1;
        } else if (LEFT == MAX_SIZE - 1) {
            LEFT = 0; // Wrap around
        } else {
            LEFT++;
        }
    }
}

// Function to display the queue
void display() {
    if (LEFT == -1 && RIGHT == -1) {
        printf("Queue is empty\n");
    } else if (LEFT <= RIGHT) { // Normal condition
        for (int i = LEFT; i <= RIGHT; i++) {
            printf("%d\t", queue[i]);
        }
    } else { // Circular condition
        for (int i = LEFT; i < MAX_SIZE; i++) {
            printf("%d\t", queue[i]);
        }
        for (int i = 0; i <= RIGHT; i++) {
            printf("%d\t", queue[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    while (1) {
        int n;
        printf("\n 1. Insertion Through Left\n 2. Insertion Through Right\n 3. Deletion Through Left\n 4. Deletion Through Right\n 5. Display\n 6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {
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
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}
