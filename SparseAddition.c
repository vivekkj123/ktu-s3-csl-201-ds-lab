/*
Program for performing sparse matrix addition
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
int rows, cols, sparseA[10][10], sparseB[10][10], Result[10][10];
// Function for converting both matrices into sparse
void convertToSparse(int mat1[20][20], int mat2[20][20]){
	int i, j, count, k;
	sparseA[0][0] = rows;
	sparseA[0][1] = cols;
	sparseB[0][0] = rows;
	sparseB[0][1] = cols;
	// Convert first matrix to Sparse
	count=0, k=1;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			if(mat1[i][j] != 0){
				count = count+1;
				sparseA[k][0]=i;
				sparseA[k][1]=j;
				sparseA[k][2]=mat1[i][j];
				k++;
			}
		}
	}
	sparseA[0][2] = count;
	// Convert second matrix to Sparse
	count=0, k=1;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			if(mat2[i][j] != 0){
				count = count+1;
				sparseB[k][0]=i;
				sparseB[k][1]=j;
				sparseB[k][2]=mat2[i][j];
				k++;
			}
		}
	}
	sparseB[0][2] = count;
}
//Function for Adding sparse Matrices
void sparseAdd(){
	int apos =1, bpos = 1, rpos=1;
	while(apos <= sparseA[0][2] && bpos<= sparseB[0][2]){
		if(sparseA[apos][0] == sparseB[bpos][0] && sparseA[apos][1] == sparseB[bpos][1]){
			Result[rpos][0] = sparseA[apos][0];
			Result[rpos][1] = sparseA[apos][1];
			Result[rpos][2] = sparseA[apos][2] + sparseB[bpos][2];
			apos++; bpos++;rpos++;
		}
		else if(sparseA[apos][0] == sparseB[bpos][0]){
			Result[rpos][0] = sparseA[apos][0];
			if (sparseA[apos][1] < sparseB[bpos][1] && apos < sparseA[0][2])
            {
                Result[rpos][1] = sparseA[apos][1];
                Result[rpos][2] = sparseA[apos][2];
                apos++; rpos++;
            }
            else{
                Result[rpos][1] = sparseB[bpos][1];
                Result[rpos][2] = sparseB[bpos][2];
                bpos++; rpos++;
            }
		}
		else{
			if (sparseA[apos][0] < sparseB[bpos][0])
            {
                Result[rpos][0] = sparseA[apos][0];
                Result[rpos][1] = sparseA[apos][1];
                Result[rpos][2] = sparseA[apos][2];
                apos++;rpos++;
            }
            else
            {
            	Result[rpos][0] = sparseB[bpos][0];
 	            Result[rpos][1] = sparseB[bpos][1];
            	Result[rpos][2] = sparseB[bpos][2];
                bpos++;rpos++;
            }
		}
	}
	while(apos <= sparseA[0][2]){
		Result[rpos][0] = sparseA[apos][0];
		Result[rpos][1] = sparseA[apos][1];
		Result[rpos][2] = sparseA[apos][2];
		apos++;rpos++;
	}
	while(bpos <= sparseB[0][2]){
		Result[rpos][0] = sparseB[bpos][0];
		Result[rpos][1] = sparseB[bpos][1];
		Result[rpos][2] = sparseB[bpos][2];
		bpos++;rpos++;
	}
	Result[0][0] = rows;
	Result[0][1] = cols;	
	Result[0][2] = rpos-1;
	// Print the resultant matrix
	printf("Resultant Matrix is: \n");
	for(int i=0; i<rpos; i++){
		for(int j=0; j<3; j++){
			printf("%d \t", Result[i][j]);
		}
		printf("\n");
	}
}
// Main function
void main(){
	int a[20][20], b[20][20], i, j, k;
	// Input order of both matrices
	printf("Rows of Matrix:");
	scanf("%d", &rows);
	printf("Columns of Matrix:");
	scanf("%d", &cols);
	// Input First Matrix
	printf("Enter the first matrix: \n");
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){		
		 	printf("a[%d][%d]=", i, j);
		 	scanf("%d", &a[i][j]);
		}
	}
	// Input Second Matrix
	printf("Enter the second matrix: \n");
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){		
		 	printf("b[%d][%d]=", i, j);
		 	scanf("%d", &b[i][j]);
		}
	}
	// Convert Both matrices to Sparse
	convertToSparse(a, b);
	sparseAdd();
}
