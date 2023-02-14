/*
Program for implementing Breadth First Search (BFS) algorithm
Author: Vivek K J
S3 CSA
*/

#include<stdio.h>
#include<stdlib.h>

int AdjMatrix[100][100],vertex[100],visited[100],stack[100],top=-1,max,queue[100],front=-1,rear=-1 ;

struct node
{
    int num;
    int status;
    struct node *next;
}*START=NULL,*ptr,*newnode,*preptr,*GRAPH[100];


struct node* nn(int z)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->num=z;
    newnode->status=1;
    newnode->next=NULL;
    return newnode;
}


void ins_e(int l, int m)
{
    START=GRAPH[l];
    nn(m);
    if(START==NULL)
    {
        START=newnode;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        
    }
}


void SET(int element,int st)
{
    int l;
    for(l=0;l<max;l++)
	{
	if(GRAPH[l]->num==element)
	{
	GRAPH[l]->status=st;
    }
    }
}    

void push(int x)
{
    int l;
    for(l=0;l<max;l++)
    {
        if (GRAPH[l]->num==x && GRAPH[l]->status==1)
        {
             stack[++top]=x;
             SET(x,2);
        }
        
    }
   
    
}

void DFS()
{
    int l,element;
    element=stack[top];
    printf("%d\t",stack[top--]);
    SET(element,3);
    
   for(l=0;l<max;l++)
	{
	if(GRAPH[l]->num==element)
	{
	START=GRAPH[l]->next;
	if(START==NULL)
    	{
       continue;
   	    }
    	else
    	{
        ptr=START;
        while(ptr->next!=NULL)
        {
            
            
            push(ptr->num);
            ptr=ptr->next;
        }
        push(ptr->num);
    	}
    }
    } 
    
    while(top>-1)
    {
        DFS();
    }
    for(l=0;l<max;l++)
	{
	if(GRAPH[l]->status==1)
	{
	push(GRAPH[l]->num);
    }
    }
     while(top>-1)
    {
        DFS();
    }
    
}

void enqueue(int x) 
{ 
    int l;
    for(l=0;l<max;l++)
    {
        if (GRAPH[l]->num==x && GRAPH[l]->status==1)
        {
             if (front==-1) 
                { 
                front=0; 
                rear=0; 
                queue[rear]=x; 
                SET(x,2);
                } 
                else 
                { 
                rear++; 
                queue[rear]=x; 
                SET(x,2);
                } 
        }
                        
    }
 
}

int dequeue() 
{ 
int x;
 if (rear==front) 
 { 
 int x=queue[front];
 printf("%d\t",x);
 front=-1; 
 rear=-1;
 SET(x,3); 
 } 
 
 else 
 { 
 int x=queue[front];
 printf("%d\t",x);
 front++; 
 SET(x,3); 
 } 
 return x;

} 




void BFS()
{
    int l,element;
    element=dequeue();
    
   for(l=0;l<max;l++)
	{
	if(GRAPH[l]->num==element)
	{
	START=GRAPH[l]->next;
	if(START==NULL)
    	{
        continue;
      
   	  }
    	else
    	{
        ptr=START;
        while(ptr->next!=NULL)
        {
            
            
            enqueue(ptr->num);
            ptr=ptr->next;
        }
        enqueue(ptr->num);
    	}
    }
    } 
    
    while(front!=-1)
    {
        BFS();
    }
    for(l=0;l<max;l++)
	{
	if(GRAPH[l]->status==1)
	{
	enqueue(GRAPH[l]->num);
    }
    }
     while(front!=-1)
    {
        BFS();
    }
    
}


int main()
{

int i=0,n,x,l,m,k,a,s;
char choice='n',sel='y';

printf("Enter number of vertices\n");
scanf("%d",&n);
max=n;

for(i=0;i<n;i++)
{
printf("Enter value: \n");
scanf("%d",&vertex[i]);

GRAPH[i]=nn(vertex[i]);

}

for(l=0;l<n;l++)
	{
	for(m=0;m<n;m++)
		{
		printf("Is %d linked with %d(Y/N): ",vertex[l],vertex[m]);
		scanf("%c",&choice);
		scanf("%c",&choice);
		if (choice=='y'||choice=='Y')
			{
			ins_e(l,vertex[m]);
			AdjMatrix[l][m]=1;
			}
		else
			{
			AdjMatrix[l][m]=0;
			}	
	
		}
	}


printf("Adjacency List\n");
for(l=0;l<n;l++)
	{
	printf("%d->\t",GRAPH[l]->num);
	
	START=GRAPH[l]->next;
	if(START==NULL)
    	{
       printf("NULL\n");
   	 }
    	else
    	{
        ptr=START;
        while(ptr->next!=NULL)
        {
            printf("%d\t",ptr->num);
            ptr=ptr->next;
        }
        printf("%d\t",ptr->num);
        printf("\n");
        
    	}
	
	
	
	}

printf("Adjacency Matrix\n");
printf("\n");
printf("\t");
for(l=0;l<n;l++)
{
printf("%d\t",vertex[l]);
}
printf("\n");

for(l=0;l<n;l++)
	{
	printf("%d*\t",vertex[l]);
	for(m=0;m<n;m++)
		{
		printf("%d",AdjMatrix[l][m]);
		printf("\t");
		}
		printf("\n");
	}

do{  

printf("1)DFS\n2)BFS\n");
scanf("%d",&s);
switch (s)
{
case 1:
    {
    printf("Enter element to Start DFS\n");
    for(l=0;l<max;l++)
    {
        SET(GRAPH[l]->num,1);
    }
    scanf("%d",&a);
    stack[++top]=a;
    SET(a,2);
    printf("********DFS**********\n");
    DFS();
    printf("\n");
    
    break; 
    }  
case 2:
    {
    printf("Enter element to Start BFS\n");
    for(l=0;l<max;l++)
    {
        SET(GRAPH[l]->num,1);
    }
    scanf("%d",&a);
    enqueue(a);
    printf("********BFS**********\n");
    BFS();
    printf("\n");
    
    break; 
    }   

default:
    break;
}


printf("Do you want to continue Y/N\n");
scanf("%c",&sel);
scanf("%c",&sel);
}while(sel=='y'||sel=='Y');

}


