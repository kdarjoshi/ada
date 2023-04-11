#include<stdio.h>
#include<stdlib.h>
int G[10][10],E[10][10];
int n;

void generate(int e)
{
        int i,j,p,q,k=1,w;
        while(k<=e)
        {
                printf("\nenter the connection ");
                scanf("%d %d",&p,&q);
                printf("\nenter its weight");
                scanf("%d",&w);
                G[p][q]=w;
                G[q][p]=w;
                k++;
        }
}

void Prim()
{
        int l1[n],l2[n],Vx[n-1],wt=0;
        int st,i,j,k,b=0;
        printf("enter the starting vertex");
        scanf("%d",&st);

        for(i=0;i<n;i++)
        {
                l1[i]=-1;
                l2[i]=99;
        }
        for(i=0;i<n;i++)
        {
                if(i!=st)
                   Vx[b++]=i;
        }
        int lst=st;
        for(k=0;k<n-1;k++)
        {
                for(j=0;j<b;j++)
                {
                        int p=Vx[j];
                        if(G[lst][p]!=9999)
                        {
                           l1[p]=lst;
                           l2[p]=G[lst][p];
                        }
                }
                int min=l2[lst],pos;
                        for(i=0;i<n;i++)
                        {
                           if(min>l2[i])
                           {
                              min=l2[i];
                              pos=i;
                           }
                        }

                        wt=wt+min;
                        l2[pos]=99;
                        E[lst][pos]=1;
                        E[pos][lst]=1;
                        lst=pos;
                        int pp;
                        for(i=0;i<b;i++)
                            if(Vx[i]==pos)
                                pp=i;
                        for(i=pp;i<b-1;i++)
                            Vx[i]=Vx[i+1];
                        b--;
        }
        printf("\n weight=%d",wt);
}


void main()
{
    int i,j,e;
    printf("enter no of vertices");
    scanf("%d",&n);
    printf("enter no of edges");
    scanf("%d",&e);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            G[i][j]=9999;
            E[i][j]=0;
        }        
    }
    generate(e);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
                printf("%d \t",G[i][j]);
        printf("\n");
    }

    Prim();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
                printf("%d \t",E[i][j]);
        printf("\n");
    }
}




