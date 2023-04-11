#include<stdio.h>
#include<stdlib.h>

float euclid(int m,int n)
{
	int r;
	float count=0;
	while👎
	{
		count++;
		r=m%n;
		m=n;
		n=r;
	}
	return count;
}

float con(int m,int n)
{
	float count=0;
	int min=m;
	if(n<min)
		min=n;
	while(1)
	{
		count++;
		if(m%min==0)
		{
			count++;
			if(n%min==0)
				break;
			else
				min-=1;
		}
		else
			min-=1;
	}
	return count;
}

float modified(int m,int n)
{
	float count=0;
	int temp;
	while👎
	{
		if(m<n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		count+=0.5;
		m=m-n;
	}
	return count;
}

void analysis(int ch)
{
	FILE *f1,*f2;
	int n,i,j;
	float count;int max,min;
	for(n=10;n<=100;n+=10)
	{
		max=0;
		min=999;
		for(i=2;i<=n;i++)
		{
			for(j=2;j<=n;j++)
			{
				switch(ch)
				{
					case 1:count=euclid(i,j);
						   break;
					case 2:count=con(i,j);
						   break;
					case 3:count=modified(i,j);
						   break;
				}
				if(count>max)
					max=count;
				else if(count<min)
					min=count;
			}
		}
			switch(ch)
			{
				case 1:f1=fopen("e_b.txt","a");
					   f2=fopen("e_w.txt","a");
					   fprintf(f1,"%d\t%d\n",n,min);
					   fprintf(f2,"%d\t%d\n",n,max);
					   fclose(f1);
					   fclose(f2);
					   break;
				case 2:f1=fopen("c_b.txt","a");
					   f2=fopen("c_w.txt","a");
					   fprintf(f1,"%d\t%d\n",n,min);
					   fprintf(f2,"%d\t%d\n",n,max);
					   fclose(f1);
					   fclose(f2);
					   break;
				case 3:f1=fopen("m_b.txt","a");
					   f2=fopen("m_w.txt","a");
					   fprintf(f1,"%d\t%d\n",n,min);
					   fprintf(f2,"%d\t%d\n",n,max);
					   fclose(f1);
					   fclose(f2);
					   break;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
	printf("Enter your choice\n1.Euclid\n2.Consecutive division method\n3.Modified Euclid\n");
	scanf("%d",&ch);
		
	switch(ch)
	{
		case 1:
		case 2:
		case 3:analysis(ch);
			   break;
		default:exit(1);
	}
	}
	return 0;
}