#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ssort(int *a,int n)
{
	int i,j,count=0,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			count++;
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];a[i]=a[min];a[min]=temp;
	}
	return count;
}

void analysis(int ch)
{
	FILE *f;
	int *b,*w,*a;
	int key,count,i,j;
	srand(time(NULL));
	for(i=10;i<=100;i+=10)
	{
		
		a=(int*)malloc(i*sizeof(int));
		for(j=0;j<i;j++)
		{
			a[j]=rand()%100;
		}
		switch(ch)
		{
			case 1:
				   count=ssort(b,i);
				   f=fopen("s_b.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 2:
				   count=ssort(a,i);
				   f=fopen("s_a.txt","a");
				   fprintf(f,"%d\t%d\n",i,count);
				   fclose(f);
				   break;
			case 3:
				   count=ssort(w,i);
				   f=fopen("s_w.txt","a");
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