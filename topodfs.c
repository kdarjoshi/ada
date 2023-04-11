#include<stdio.h>
#include<stdlib.h>
int count=0,j=0;
typedef struct stack 
{
    int *item;
    int top;
} stk ;
stk s;

void enq(int e)
{
   s.item[s.top++]=e+1;
}

int deq()
{
    return s.item[--s.top];
}

void dfs(int *a[],int v,int n,int vis[],int topo[])
{
   // count++;
    vis[v]=-9;
    for(int k=0;k<n;k++)
    {
        if(a[v][k]==1 && vis[k]==0)
        {
            enq(k);
            dfs(a,k,n,vis,topo);
            if(vis[k]==1 && k!=v)
            {
                printf("Cycles exist topological sorting not possible\n");
                return;
            }
        }
    }
    topo[j++]=deq();
    // count++;
    // vis[v]=count;
    // topo[count-1]=v+1;
}

void DFS(int *a[],int n,int vis[],int topo[])
{
    //this functions consideres all the vertices as starting vertex ans then performs DFS
    count=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            enq(i);
            dfs(a,i,n,vis,topo);
        }
    }
    
}


void main()
{
    int v;
    s.top=0;
    printf("Enter number of vertices\n");
    scanf("%d",&v);
    int *arr[v];
    s.item=(int *)malloc(v*sizeof(int));
    for(int i=0;i<v;i++)
        arr[i]=(int *)malloc(sizeof(int)*v);
    printf("Enter the adjacency matrix\n");
    for(int i=0;i<v;i++)
    {
        printf("Enter 1 for the vertices adjacent to vertex %d\n",i+1);
        for(int j=0;j<v;j++)
        {
            printf("\nVertex %d : ",j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("Adjacency matrix\n");
     for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    
    printf("Performing dfs on graph\n");
    int *vis=(int *)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++)
        vis[i]=0;
  
    int *topo=(int *)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++)
        topo[i]=0;
    DFS(arr,v,vis,topo);
    
    printf("The topological sorting is\n");
    for(int i=v-1;i>=0;i--)
        printf("%d\t",topo[i]);
    printf("\n");
}