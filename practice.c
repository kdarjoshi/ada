#include<stdio.h>
#include<stdlib.h>
int count=0,w=5;


int main()
{
	int a[]={4,2,1,8,5};
	quickSort(a,0,4);
	printf("Printing array elements\n");
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\nCount=%d\n",count);
	return 0;
}