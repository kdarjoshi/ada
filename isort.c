#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int isort(int *a,int n)
{
	int i,j,v,count=0;
	for(i=1;i<n;i++)
	{
		j=i-1;
		v=a[i];
		count++;
		while(j>=0 && a[j]>v)
		{
			count++;
			a[j+1]=a[j];
			j--;
		}
		if(j<0)
			count--;
		a[j+1]=v;
	}
	return count;
}

void analysis(int ch)
{
	FILE *f;
	int *b,*a,*w;
	int key,i,j,count;
	srand(time(NULL));
	for(i=10;i<=100;i+=10)
	{
		b=(int*)malloc(i*sizeof(int));
		a=(int*)malloc(i*sizeof(int));
		w=(int*)malloc(i*sizeof(int));
		for(j=0;j<i;j++)
		{
			b[j]=j;
			a[j]=rand()%100;
			w[j]=i-j;
		}
		switch(ch)
		{
			case 1:
				   count=isort(b,i);
				   f=fopen("bs_b.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 2:
				   count=isort(a,i);
				   f=fopen("bs_a.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 3:
				   count=isort(w,i);
				   f=fopen("bs_w.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice\n1.Best case\n2.Average case\n3.Worst case\n");
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