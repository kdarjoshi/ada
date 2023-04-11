#include <stdio.h>
#include<stdlib.h>
int count;

void printArray(int a[],int c)
{
    for(int i=0;i<c;i++)
       printf("%d ",a[i]);
    printf("\n");
}
int partition(int a[],int low,int high)
{
  int pivot,i,j,temp;
  pivot=a[low];
  i=low+1;
  j=high;
  do
  {
    count++;
    while(a[i]<pivot)
    {
        count++;
        i++;
    }
    count++;
    while(a[j]>pivot)
    {
        count++;
        j--;
    }
      
    if(i<=j)
    {
      //count++;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;
      j--;
    }
  } while(i<j);
  temp=a[low];
  a[low]=a[j];
  a[j]=temp;
  return j;
}
void quickSort(int a[],int low,int high)
{
    int pivotIndex;
    if(low<high)
    {
        pivotIndex=partition(a,low,high);
        quickSort(a,low,pivotIndex-1);
        quickSort(a,pivotIndex+1,high);
    }
}
void analysis(int ch)
{
    int *a;
    FILE *fp;
    switch(ch)
    {
        case 1:
        fp=fopen("qsort_w.txt","a");
        for(int i=10;i<=100;i+=10)
        {
            count=0;
            a=(int *)malloc(i*sizeof(int));
            for(int j=0;j<i;j++)
              a[j]=25+j;
            quickSort(a,0,i-1);
            printArray(a,i);
            fprintf(fp,"%d\t%d\n",i,count);
        }
        fclose(fp);
        break;
        case 2:
        fp=fopen("qsort_b.txt","a");
        for(int i=10;i<=100;i+=10)
        {
            count=0;
            a=(int *)malloc(i*sizeof(int));
            for(int j=0;j<i;j++)
              a[j]=i;
            quickSort(a,0,i-1);
            printArray(a,i);
            fprintf(fp,"%d\t%d\n",i,count);
        }
        fclose(fp);
        break;
    }
}
int main()
{
    int ch;
    printf("Analysis of Quick Sort/n1.Worst Case\n2. Best Case\n");
      scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        case 2: analysis(ch);break;
    }
    // printArray(a,6);
    // quickSort(a,0,5);
    // printArray(a,6);
    return 0;
}