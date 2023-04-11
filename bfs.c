#include<stdio.h>
#include<stdlib.h>
#define size 5

int visited[5]={0,0,0,0,0};
	int a[5][5]={
				 {0,1,1,1,1},
	             {1,0,1,1,1},
	             {1,1,0,1,1},
	             {1,1,1,0,1},
	             {1,1,1,1,0}
	            };
typedef struct queue
{
	int item[size];
	int f,r;
} que;
que q;
void enqueue(que *q, int a)
{
	q->item[q->r++]=a;
} 

int dequeue(que *q)
{
	return q->item[q->f++];
}
	
void bfs(int v)
{
	int j,node;
	printf("%d ",v);
	    visited[v]=1;
	    enqueue(&q,v);

	while(q.f<=q.r)
	{
		for(j=0;j<5;j++)
	    {
	    	node=dequeue(&q);
			if(a[node][j]==1 && visited[j]==0)
			{
				enqueue(&q,j);
				printf("%d ",j);
				visited[j]=1;
			}
		}
	}
}
int main()
{
	int v;
	q.f=0;
	q.r=0;
	printf("BFS traversal\nEnter the node to start from:\n");
	  scanf("%d",&v);
	bfs(v);
	// printf("printing the visited array to check whether all vertices are visited\n");
	// for(int i=0;i<5;i++)
 //    	printf("%d ",visited[i]);
	return 0;
}