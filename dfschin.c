#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int visited[10];
int con;
int cyc;
int count=0;
int connected[10];
int cyclic[10];
int cycle=0;
int bop=0;

void dfs(v,V)
{
    count+=1;
    visited[v]=count;
    connected[con++]=v+1;
    for(int w=0;w<V;w++)
    {
        if(a[v][w]==1 && visited[w]==1 && (visited[v]-visited[w]!=1))
        {
            cycle++;
        }
        bop++;
        if(a[v][w]==1)
        {
            
            if(visited[w]==0)
            {
                
                dfs(w,V);
            }
        }
    }
}

void DFS(int n)
{
    int flag;
    for(int i=0;i<n;i++)
    {
        flag=1;
        if(visited[i]==0)
        {
            con=0;
            dfs(i,n);
            flag=0;
        }
        if(con<n && flag==0)
        {
            printf("Graph is disconnected and the connected components are:\n");
            for(int j=0;j<con;j++)
                printf("%d ",connected[j]);
            printf("\n");
        }
    }
}

int main()
{
    int n,i,j;
    printf("Enter the number of vertiecies\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    DFS(n);
    printf("The order in which the vertiecies are visited are\n");
    for(i=0;i<n;i++)
        printf("vertex %d is visited-%d\n",i+1,visited[i]);
    printf("count:%d\n",bop);
    if(cycle>0)
        printf("Cycle exists\n");
    return 0;
}