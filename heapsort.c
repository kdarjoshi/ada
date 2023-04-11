#include<stdio.h>
#include<stdlib.h>
void heapcon(int heap[],int n,FILE *f)
{
	int count=0;
	for(int i=n/2;i>=1;i--)
	{
		int k=i;
		int v=heap[k];
		int h=0;
		while(!h && 2*k<=n)
		{
			int j=2*k;
			if(j<n)
			{
				count++;
				if(heap[j+1]>heap[j])
					j++;
			}
			count++;
			if(v>=heap[j])
				h=1;
			else
			{
				heap[k]=heap[j];
				k=j;
			}
		}
		heap[k]=v;
	}
	fprintf(f,"%d %d",n,count);
}

int heapsort(int heap[], int n,FILE *f)
{
	int size=n,count=0,t;
	for(int j=0;j<size-1;j++)
	{
	 t=heap[1];
   heap[1]=heap[n];
   heap[n]=t;
   n--;
  //for(int i=1;i<=n/2;i++)
		int k=1;
		int v=heap[k];
		int h=0;
		while(!h && 2*k<=n)
		{
			int j=2*k;
			if(j<n)
			{
				count++;
				if(heap[j+1]>heap[j])
					j++;
			}
			count++;
			if(v>=heap[j])
				h=1;
			else
			{
				heap[k]=heap[j];
				k=j;
			}
		}
  //int t;
  //if(n==1)
    //return;
		heap[k]=v;
	}
	//heapsort(heap,n);
	fprintf(f," %d\n",count);
	return count;
}
void analysis(int ch)
{
	FILE *f1,*f2;
	f1=fopen("hp_b.txt","a");
	f2=fopen("hp_w.txt","a");
	fprintf(f1,"i/p hcon hdel\n");
	fprintf(f2,"i/p hcon hdel\n");
	fclose(f1);
	fclose(f2);

   for(int i=10;i<=100;i+=10)
   {
   		int *a=(int *)malloc(i*sizeof(int));
   		switch(ch)
   		{
   			 case 1:
   			   f1=fopen("hp_b.txt","a");
   			   for(int j=1;j<i;j++)
   			   	 a[j]=i-j;
   			   heapcon(a,i-1,f1);
   			   heapsort(a,i-1,f1);
   			   fclose(f1);
   			   break;

   			 case 2:
   			   f2=fopen("hp_w.txt","a");
   			   //fprintf(f,"i/p hcon hdel\n");
   			   for(int j=1;j<i;j++)
   			   	 a[j]=10+j;
   			   heapcon(a,i-1,f2);
   			   heapsort(a,i-1,f2);
   			   fclose(f2);
   			   break;
   		}
   }
}


int main()
{
	int ch;
	//int heap[6]={-999,5,4,3,2,1};
	printf("Heap sort analysis\n");
	printf("1. BestCase\n2. WorstCase\n");
	printf("Enter ur choice\n");
	  scanf("%d",&ch);
	switch(ch)
	{
			case 1:
			case 2:analysis(ch); break;
			default: exit(0);
	}
	// printf("printing the array elements after heap construction\n");
	// for(int i=1;i<=5;i++)
	// 	printf("%d ",heap[i]);
 //  printf("\n");
	// printf("Heap construction count:%d\n",count);
	// //printf("\n");
	// printf("Sorting the elements\n");
	// count=heapsort(heap,5);
	// printf("Printing the sorted elements\n");
	//   for(int i=1;i<=5;i++)
	// 	printf("%d ",heap[i]);
	// printf("\n");
	// printf("After deletion count:%d\n",count);

	return 0;
}