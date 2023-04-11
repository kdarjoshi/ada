#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
#define s 10
#define x 1
void main()
{
    int *a,px,count,poly;
    FILE *fp;
    srand(time(NULL));
    fp=fopen("poly.txt","a");
    for(int n=s;n<=100;n+=10)
    {
        a=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            a[i]=rand()%10;
        }
        count=0;
        px=1;
        poly=a[0];
        for(int i=1;i<=n;i++)
        {
            px=px*x;
            poly=poly+px*a[i];
            count+=2;
        }
        fprintf(fp,"%d\t%d\n",n,count);
    }
    fclose(fp);
}