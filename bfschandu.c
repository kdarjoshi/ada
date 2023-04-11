#include<stdio.h>
#include<stdlib.h>
int count=0;
typedef struct queue
{
    int *arr,f,r,cnt;
}QUE;
void bfs(int* a[],int vis[],int v,int n)
{
    QUE q;
    q.f=0;
    q.r=-1;
    q.cnt=0;
    q.arr=(int*)malloc(sizeof(int)*n);
    
    q.r=(q.r+1)%n;
    count++;
    q.cnt++;
    vis[v]=count;
    printf("%d\t",v+1);
    q.arr[q.r]=v;
    int i;
    while(q.cnt!=0)
    {
        for(i=0;i<n;i++)
        {
            if(a[q.f][i]==1 && vis[i]==0)
            {
                 q.r=(q.r+1)%n;
                 count++;
                 q.cnt++;
                 vis[i]=count;
                 printf("%d\t",i+1);
                 q.arr[q.r]=i;
                 continue;
            }
            
            if(a[q.f][i]==1 && vis[i]!=0 && vis[q.f]-vis[i]>1)
            {
                printf("Graph has cycles\n");
            }
        }
        
        q.f=(q.f+1)%n;
        q.cnt--;
    }
}

int BFS(int *a[],int v,int vis[])
{
    int cflag=0;
    int i;
    count=0;
    for(i=0;i<v;i++)
    {
        if(vis[i]==0)
        {
            cflag++;
            printf("Connected component %d\n",cflag);
            bfs(a,vis,i,v);
        }
    }
    return cflag;
}

void main()
{
    int v;
    printf("Enter number of vertices\n");
    scanf("%d",&v);
    int *a[v];
    int i,j;
    for(i=0;i<v;i++)
        a[i]=(int *)malloc(sizeof(int)*v);
    printf("Enter adjacency matrix\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    int vis[v];
    for(i=0;i<v;i++)
    {vis[i]=0;}
    
    int flag=BFS(a,v,vis);
    printf("Graph has %d components\n",flag);
    
    for(i=0;i<v;i++)
    {printf("%d\t",vis[i]);}
}