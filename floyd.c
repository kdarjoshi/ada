#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

int min(int a,int b)
{
	return a>b?b:a;
}

void floyd(int a[100][100],int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				count++;
			}
		}
	}
	printf("printing the distance matrix\n");
	for(int A=0;A<n;A++)
		{
			for(int b=0;b<n;b++)
			{
				printf("%d ",a[A][b]);
			}
			printf("\n");
		}
		printf("\n");
}

void analysis()
{
	FILE *f;
	int am[100][100];
	int ri;
	int ci;
	srand(time(NULL));
	for(int i=4;i<=10;i++)
	{
		f=fopen("floyd.txt","a");
		for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
			{
				int ri=rand()%i;
				int ci=rand()%i;
				if(ri==ci)
					am[ri][ci]=0;
				else
				am[ri][ci]=1;
			}
		for(int a=0;a<i;a++)
		{
			for(int b=0;b<i;b++)
			{
				if(am[a][b]==0 && a!=b)
					am[a][b]=1000;
				else if(a!=b)
					am[a][b]=rand()%100;
			}
		}
		printf("printing the weighted matrix\n");
		for(int a=0;a<i;a++)
		{
			for(int b=0;b<i;b++)
			{
				printf("%d ",am[a][b]);
			}
			printf("\n");
		}
		printf("\n");
		count=0;
		floyd(am,i);
		fprintf(f,"%d\t%d\n",i,count);
		fclose(f);
	}
}

int main()
{
	analysis();
	return 0;
}