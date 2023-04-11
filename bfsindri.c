#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int G[10][10],n,conn=0,opcount=0,cnt=0;
int Q[10],f=0,r=-1;

void bfs(int i,int visited[])
{
    int j,x;
cnt++;

    visited[i]=cnt;
    Q[++r]=i;
    //x=Q[r];
    while(f-r!=1)
    {
        x=Q[f++];
        printf("%d",x);
        //visited[j]=x;
        for(j=0;j<n;j++)
        {
             opcount++;
            if(visited[j]==0 && G[x][j]==1)
            {

                cnt=cnt+1;

                visited[j]=cnt;
                Q[++r]=j;

            }


        }
    }
}


void BFS(int visited[])
{
int i,j;
cnt=0;
for(i=0;i<n;i++)
if(visited[i]==0)
      {
            //printf("%d",visited[i]);
         bfs(i,visited);
         printf("\n");
         conn++;
      }
}

void main()
{
    int i,j,*visited;
    srand(time(NULL));
    printf("Enter number of vertices:");
    scanf("%d",&n);

    /*printf("\nEnter the Array elements\n");
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);*/
    for(i=0;i<n;i++)
       for(j=i+1;j<n;j++)
            {
            //printf("%d row -> ",i);
            //scanf("%d",&G[i][j]);
            G[i][j]=rand()%2;
            G[j][i]=G[i][j];
            }

    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\t",G[i][j]);
            }
            printf("\n");
        }
    visited=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        visited[i]=0;
    BFS(visited);

    if(conn > 1)
   printf("\n not connected\n");
    else
   printf("\n connected\n");
   printf("count %d",opcount);
}