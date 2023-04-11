#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

int max(int a,int b)
{
	return a>b?a:b;
}

void warshal(int a[100][100],int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=max(a[i][j],a[i][k]&&a[k][j]);
				count++;
			}
		}
	}
}

void analysis()
{
	FILE *f;
	int am[100][100];
	srand(time(NULL));
	for(int i=4;i<=10;i++)
	{
		f=fopen("warshal.txt","a");
		for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
			{
				int ri=rand()%i;
				int ci=rand()%i;
				if(ri==ci)
					continue;
				am[ri][ci]=1;
			}
		count=0;
		warshal(am,i);
		fprintf(f,"%d\t%d\n",i,count);
		fclose(f);
	}
}

int main()
{
	analysis();
	return 0;
}