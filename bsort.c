#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bsort(int *a,int n)
{
	int count=0,i,j,flag,temp;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			return count;
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
				   count=bsort(b,i);
				   f=fopen("bs_b.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 2:
				   count=bsort(a,i);
				   f=fopen("bs_a.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 3:
				   count=bsort(w,i);
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