/*
Program for implementing Depth First Search (DFS) algorithm
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
int n, mat[20][20], visited[20];
void readAdjacencyMatrix(){
	int i, j;
	printf("Enter no. of vertices");
	scanf("%d", &n);
	printf("Enter the Adjacency Matrix: \n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
}
void dfs(int v){
	int i;
	printf("%d \t", v);
	visited[v] = 1;
	for(i=0; i<n ; i++){
		if(mat[v][i] ==1 && !visited[i]){
			dfs(i);
		} 
	}
}
void main(){
	readAdjacencyMatrix();
	dfs(0);
}
