#include<stdio.h>
#include<stdlib.h>
int count=0;
typedef struct queue
{
    int f,r,*arr,cnt;
} QUE;
void indegree(int *a[],int v,int inq[],QUE *temp,int flag[])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(a[j][i]==1)
                inq[i]=inq[i]+1;
        }
        if(inq[i]==0)
        {
            temp->r=(temp->r+1)%v;
            temp->arr[temp->r]=i;
            temp->cnt=temp->cnt+1;
            flag[i]=1;
            //after inserting it into the array of vertices with zero(sources) we are making the flag as '1' indicating its already in the list of vertices with indegree zero.
        }
    }
}

void sourceremove(int *a[],int v,QUE *temp,int inq[],int flag[])
{
    int cnt=0;
    while(temp->cnt!=0)
    {
        int source=temp->arr[temp->f];
        temp->f=(temp->f+1)%v;
        temp->cnt=temp->cnt-1;
        printf("%d\t",source+1);
        cnt++;
        for(int i=0;i<v;i++)
        {
            if(a[source][i]==1)
                inq[i]=inq[i]-1;
            if(inq[i]==0 && flag[i]==0)
            {
                temp->r=(temp->r+1)%v;
                temp->arr[temp->r]=i;
                temp->cnt=temp->cnt+1;
                flag[i]=1;
            }
        }
    }
    
   /* if(cnt!=v)
    {
        printf("Cycles exist no topological sorting possible\n");
    }*/
}
void main()
{
    int v;
    printf("Enter number of vertices\n");
    scanf("%d",&v);
    int *arr[v];
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
    
   QUE q;
   q.f=0;q.r=-1,q.cnt=0;
   q.arr=(int*)malloc(sizeof(int)*v);
    
    int *inq=(int *)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++)
        inq[i]=0;
    //indegree(arr,v,inq,&q);
    printf("The topological sorting is\n");
    int *flag=(int *)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++)
        flag[i]=0;
    indegree(arr,v,inq,&q,flag);
   /*  for(int i=0;i<v;i++)
        printf("%d\t",inq[i]);
     for(int i=0;i<q.cnt;i++)
        printf("%d\t",q.arr[i]);*/
   sourceremove(arr,v,&q,inq,flag);
    printf("\n");
}