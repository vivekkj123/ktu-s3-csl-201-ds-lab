/*
Program for adding two polynomials using array
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
// Structure for polynomial
struct polynomial{
	int coeff;
	int exp;
};
void main(){
	int N1, N2, i, j, k;
	// Read First Polynomial	
	printf("Enter no. of terms of first polynomial:");
	scanf("%d", &N1);
	struct polynomial first[N1];
	for(i=0; i<N1; i++){
		printf("Enter coefficient of term %d:", i+1);
		scanf("%d", &first[i].coeff);
		printf("Enter exponent of term %d:", i+1);
		scanf("%d", &first[i].exp);
	}
	// Read Second Polynomial
	printf("Enter no. of terms of second polynomial:");
	scanf("%d", &N2);
	struct polynomial second[N2];
	for(i=0; i<N2; i++){
		printf("Enter coefficient of term %d:", i+1);
		scanf("%d", &second[i].coeff);
		printf("Enter exponent of term %d:", i+1);
		scanf("%d", &second[i].exp);
	}
	// Print both Polynomials
	printf("Polynomials are: \n");
	printf("First Polynomial:");
	for(i=0; i<N1; i++){
		printf("%+dx^%d", first[i].coeff, first[i].exp);
	}
	printf("\n");
	printf("Second Polynomial:");
	for(i=0; i<N2; i++){
		printf("%+dx^%d", second[i].coeff, second[i].exp);
	}
	printf("\n");
	// Create a structure variable for result with max size of N1+N2
	struct polynomial result[N1+N2];
	// Actual Polynomial Addition
	i=0, j=0, k=0;
	while(i<N1 && j<N2){
		if(first[i].exp == second[j].exp){
			result[k].coeff = first[i].coeff + second[j].coeff;
			result[k].exp = first[i].exp;
			i++, j++, k++;
		}
		else if(first[i].exp > second[j].exp){
			result[k].coeff = first[i].coeff;
			result[k].exp = first[i].exp;
			i++, k++;
		}
		else{
			result[k].coeff = second[j].coeff;
			result[k].exp = second[j].exp;
			j++, k++;
		}
	}
	while(i<N1){
		result[k].coeff = first[i].coeff;
		result[k].exp = first[i].exp;
		i++, k++;
	}
	while(j<N2){
		result[k].coeff = second[j].coeff;
		result[k].exp = second[j].exp;
		j++, k++;
	}
	// Print resultant polynomial
	printf("Resultant Polynomial Is: ");
	for(i=0; i<k; i++){
		printf("%+dx^%d", result[i].coeff, result[i].exp);
	}
}

