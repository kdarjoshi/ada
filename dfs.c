#include<stdio.h>
#include<stdlib.h>
	int visited[5]={0,0,0,0,0};
	int a[5][5]={
				 {0,1,1,1,1},
	             {1,0,1,1,1},
	             {1,1,0,1,1},
	             {1,1,1,0,1},
	             {1,1,1,1,0}
	         };
void dfs(int v)
{
	int j;
	printf("Visited %d\n",v);
	    visited[v]=1;
	for(j=0;j<5;j++)
	{
		if(a[v][j]==1 && visited[j]!=1)
			dfs(j);
		if(visited[j]==1 && j!=v)
		{
			printf("Cycle detected.Back edge from %d to %d\n", j+1,v+1);
		}

	}
}
int main()
{
	int v;
	printf("DFS traversal\nEnter the node to start from:\n");
	  scanf("%d",&v);
	dfs(v);
	printf("printing the visited array to check whether all vertices are visited\n");
	for(int i=0;i<5;i++)
    	printf("%d ",visited[i]);
	return 0;
}