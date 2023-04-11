#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct queue
{
	int f,r;
	int q[10];
}que;

que qu;

int a[10][10];
int visited[10];
int connected[10];
int count=0;
int bop=0;
int con=0;
int cycle=0;

void bfs(int v,int V)
{
	count++;
	visited[v]=count;
	connected[con++]=v;
	qu.q[++qu.r]=v;
	while(qu.f<=qu.r)
	{
		int i=qu.q[qu.f++];
		for(int j=0;j<V;j++)
		{
			bop++;
			if(a[i][j]==1 && visited[i]<visited[j])cycle++;
			if(a[i][j]==1)
			{
				if(visited[j]==0)
				{
					count++;
					connected[con++]=j;
					visited[j]=count;
					qu.q[++qu.r]=j;
				}
			}
		}
	}
}

void BFS(int V)
{
	int flag;
	for(int v=0;v<V;v++)
	{
		flag=0;
		if(visited[v]==0)
		{
			flag=1;
			con=0;
			bfs(v,V);
		}
		if(con<V && flag==1)
		{
			printf("Graph is disconnected and the connected components are̦: ");
			for(int i=0;i<con;i++)
				printf("%d ",connected[i]);
			printf("\n");
		}
	}
}

int main()
{
	int V;
	qu.r=-1;
	qu.f=0;
	printf("Enter the no of verticies\n");
	scanf("%d",&V);
	printf("Enter the adjacency matrix\n");
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0;i<V;i++)
		visited[i]=0;
	BFS(V);
	if(cycle)
		printf("Cycle exists\n"); 
	printf("After bfs traversal\n");
	for(int i=0;i<V;i++)
		printf("%d is visited %d\n",i+1,visited[i]);
	printf("Basic operation count:%d\n",bop);
	return 0;
}