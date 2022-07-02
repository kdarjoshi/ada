#include<stdio.h>
#include<stdlib.h>
void heapsort(int heap[], int n)
{
  int t;
  if(n==1)
    return;
  t=heap[1];
  heap[1]=heap[n];
  heap[n]=t;
  n--;
  for(int i=n/2;i>=1;i--)
	{
		int k=i;
		int v=heap[k];
		int h=0;
		while(!h && 2*k<=n)
		{
			int j=2*k;
			if(j<n)
				if(heap[j+1]>heap[j])
					j++;
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
	heapsort(heap,n);
}
int main()
{
	int heap[6]={-999,2,5,3,9,7};
	for(int i=5/2;i>=1;i--)
	{
		int k=i;
		int v=heap[k];
		int h=0;
		while(!h && 2*k<=5)
		{
			int j=2*k;
			if(j<5)
				if(heap[j+1]>heap[j])
					j++;
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
	printf("printing the array elements\n");
	for(int i=1;i<=5;i++)
		printf("%d ",heap[i]);
	printf("\n");
	printf("Sorting the elements\n");
	heapsort(heap,5);
	printf("Printing the sorted elements\n");
	  for(int i=1;i<=5;i++)
		   printf("%d ",heap[i]);
	printf("\n");
	return 0;
}
