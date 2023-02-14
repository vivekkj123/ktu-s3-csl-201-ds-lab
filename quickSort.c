#include <stdio.h>  
int partition (int a[], int start, int end)  
{  
	int t;
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
    for (int j = start; j <= end - 1; j++)  
   	{  
        if (a[j] < pivot)  
        {  
           i++; 
           int t = a[i];  
           a[i] = a[j];  
           a[j] = t;  
        }  
 	 }  
    t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
/* function to implement quick sort */  
void quick(int a[], int start, int end) 
 {  
   if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
/* function to print an array */  
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
int main()  
{  
	int  a[20],i,n;
	printf("Enter the no. of elements:");
	scanf("%d",&n); 
	printf("Enter the elements:");
	for(i=0;i<n;i++)
        	    scanf("%d",&a[i]);
 	printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    quick(a, 0, n - 1);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}
