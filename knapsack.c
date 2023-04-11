#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct knapsack
{
	int no;
	int wt;
	int val;
}knap;

knap k[10];
int a[10][10];
int count=0;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int ksack(int item,int w)
{
	int i,j;
	for(i=0;i<=item;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0 || j==0)
				a[i][j]=0;
			else
			{
				count++;
				if(j-k[i-1].wt<0)
					a[i][j]=a[i-1][j];
				else
					a[i][j]=max(a[i-1][j],k[i-1].val+a[i-1][j-k[i-1].wt]);
			}
		}
	}
	return a[item][w];
}

int mfksack(int item,int w)
{
	if(a[item][w]<0)
	{
		count++;
		if(w<k[item-1].wt)
			a[item][w]=mfksack(item-1,w);
		else
		{
			a[item][w]=max(mfksack(item-1,w),k[item-1].val+mfksack(item-1,w-(k[item-1].wt)));
		}
	}
	return a[item][w];
}


void analysis(int ch)
{
	int i,j,n,w;
	FILE * f;
	srand(time(NULL));
	for(n=4;n<=8;n++)
	{
		for(i=0;i<n;i++)
		{
			k[i].no=i+1;
			k[i].wt=(rand()+1)%3;
			k[i].val=(rand()+1)%20+10;
		}
		w=5;
		switch(ch)
		{
			case 1:f=fopen("knapsack.txt","a");
				   for(i=0;i<=n;i++)
						for(j=0;j<=w;j++)
							if(i==0 || j==0)
								a[i][j]=0;
				   ksack(n,w);
				   fprintf(f,"%d\t%d\n",n,count);
				   count=0;
				   fclose(f);
				   break;
			case 2:f=fopen("mfknapsack.txt","a");
				   for(i=0;i<=n;i++)
						for(j=0;j<=w;j++)
							if(i==0 || j==0)
								a[i][j]=0;
							else
								a[i][j]=-1;
					mfksack(n,w);
					fprintf(f,"%d\t%d\n",n,count);
					count=0;
					fclose(f);
					break;
		}
	}
}

int main()
{
	int i,w,j,ch,item;
	while(1)
	{
		printf("1.knapsack using iteration\n2.Knapsack using recursion\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			case 2:
				   analysis(ch);
				   break;
			default:exit(1);
		}
		for(i=0;i<=4;i++)
		{
			for(j=0;j<=5;j++)
				printf("%d\t",a[i][j]);
			printf("\n");
		}
		//printf("%d",count);
	}
	return 0;
} 