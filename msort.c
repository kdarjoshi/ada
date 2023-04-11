#include<stdio.h>
#include<stdlib.h>
int count=0;

void join(int arr1[], int left1[], int right1[],int l1, int m1, int r1){
   int i; 
   for (i = 0; i <= m1 - l1; i++)
      arr1[i] = left1[i];
   for (int j = 0; j < r1 - m1; j++)
      arr1[i + j] = right1[j];
}

void split(int arr1[], int left1[], int right1[],int l1, int m1, int r1){
   for (int i = 0; i <= m1 - l1; i++)
      left1[i] = arr1[i * 2];
   for (int i = 0; i < r1 - m1; i++)
      right1[i] = arr1[i * 2 + 1];
}

void generateworstcase(int arr1[], int l1, int r1){
   if (l1 < r1){
      int m1 = l1 + (r1 - l1) / 2;
      int left1[m1 - l1 + 1];
      int right1[r1 - m1];
      split(arr1, left1, right1, l1, m1, r1);
      generateworstcase(left1, l1, m1);
      generateworstcase(right1, m1 + 1, r1);
      join(arr1, left1, right1, l1, m1, r1);
   }
}

void merge(int *a,int l,int mid,int h)
{
	int i,j,k;
	i=l;j=mid+1;k=l;
	int b[101];
	while(i<=mid && j<=h)
	{
		count++;
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	for(;i<=mid;i++)//here we are using <= bcause mid and h are indicies
		b[k++]=a[i];
	for(;j<=h;j++)
		b[k++]=a[j];
	for(i=l;i<=h;i++)
		a[i]=b[i];
}

void msort(int *a,int l,int h)
{
	int i=l,j=h,mid;
	if(i<j)
	{
		mid=(l+h)/2;
		msort(a,l,mid);
		msort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}

void analysis(int ch)
{
	FILE *fp;
	int *w,*b;
	for(int i=10;i<=100;i+=10)
	{
		//w=(int*)malloc(i*sizeof(int));
		b=(int*)malloc(i*sizeof(int));
		w=(int*)malloc(i*sizeof(int));
		for(int j=0;j<i;j++)
		{
			b[j]=j;
			w[j]=j;
		}
		switch(ch)
		{
			case 1:msort(b,0,i-1);
				   fp=fopen("msort_b.txt","a");
				   fprintf(fp,"%d\t%d\n",i,count);
				   count=0;
				   fclose(fp);
				   break;
		   case 2:generateworstcase(w,0,i-1);
		    	   msort(w,0,i-1);
				   fp=fopen("msort_w.txt","a");
				   fprintf(fp,"%d\t%d\n",i,count);
				   count=0;
				   fclose(fp);
				   break;

		}
	}
}

int main()
{
	int ch;
	printf("1.Best case\n2.Worst case\nEnter your choise\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		case 2:
				analysis(ch);
				break;
		default:exit(0);
	}
	return 0;
}