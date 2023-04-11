#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int bsearch(int [],int,int);
void analysis(int);

int main()
{
    int ch;
    for(;;)
    {
        printf("Binary Search Analysis\n");
        printf("1. Best case\n2. Worst Case\n3. Average Case\n4. Exit\nEnter ur choice\n");
          scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            case 2:
            case 3: analysis(ch);
            case 4: exit(0);
        }
    }
    return 0;
}

int bsearch(int a[],int i,int key)
{

    int high=i-1,low =0,mid,count=0;
    mid=(low+high)/2;
    while(low<high)
    {
        count++;
        if(key==a[mid])
          break; //return count;
       else if(key>a[mid])
         low=mid-1;
       else 
         high=mid+1;
       mid=(low+high)/2;
    }
  return count;
      
}

void analysis(int ch)
{
    int* a;
    FILE * fp1;
    int key,mid,high,low,count;
    
    
    for(int i=10;i<=100;i+=10)
    {
        a=(int *)malloc(i*sizeof(int));
        for(int j=0;j<=i;j++)
          a[j]=j*2+i;
    switch(ch)
    {
        case 1:fp1=fopen("bsearch_b.txt","a");
            //    low=0;
            //    high=i-1;
            //    mid=(low+high)/2;
            //    key=a[mid];
               count=bsearch(a,i,a[i/2]);
               fprintf(fp1,"%d\t%d\n",i,count);
               fclose(fp1);
               break;
        case 2:fp1=fopen("bsearch_w.txt","a");
                count=bsearch(a,i,a[0]);
               fprintf(fp1,"%d\t%d\n",i,count);
               fclose(fp1);
               break;          
    }
 }
}
