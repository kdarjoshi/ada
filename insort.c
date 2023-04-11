#include<stdio.h>
int count=0; 
int main()
{
     int a[]={8,7,6,5,4,3,2,1};
     int n=sizeof(a)/sizeof(a[0]);
     for(int i=1;i<n;i++)
     {
          
          int v=a[i];
          int j=i-1;
          int temp;
          count++;
          while(j>=0 && a[j]>v)
          {
               count++;
               a[j+1]=a[j];
               j--;
          }
          a[j+1]=v;
     }
     for(int i=0;i<n;i++)
       printf("%d ",a[i]);
     printf("\n%d",count);
     return 0;
}