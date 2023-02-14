/*
C Program for implementing Binary Search Algorithm
Author: Vivek K J
S3 CSA
*/
#include<stdio.h>
int main(){
	int n, a[100], i, term, FIRST=0, LAST, flag=0, MID;
	printf("Enter No. of Elements: ");
	scanf("%d", &n);
	LAST=n-1;
	printf("Enter array elements:");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Enter the element to be searched:");
	scanf("%d", &term);
	while(FIRST<=LAST){
		MID = (FIRST+LAST)/2;
		if(a[MID] == term){
			printf("Element found at %d", MID+1);
			flag=1;
			break;
		}
		else if(a[MID] < term){
			FIRST = MID+1;
		}
		else{
			LAST=MID-1;
		}
	}
	if(flag==0){
		printf("Searched Element Not Found \n");
	}
}
