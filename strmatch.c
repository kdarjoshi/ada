#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10

int match(int t[],int a[],int m)
{
    int count=0,j;
    for(int i=0;i<=x-m;i++)
            {
                for( j=0;j<m;j++)
                {
                    count++;
                    if(t[i+j]!=a[j])          
                      break;
                }
                if(j==m)
                    return count;
            }
            return count;
}

void analysis(int ch)
{
    int t[x],count;
    int *a,*b,*w;
    FILE *fp;
    srand(time(NULL));
    for(int i=0;i<x;i++)
       t[i]=0;
    switch(ch)
    {
        case 1:
        //count=0;
        fp=fopen("strmatch_b.txt","a");
           for(int i=2;i<=x;i++)
            {
                b=(int *)malloc(i*sizeof(int));
                for(int j=0;j<i;j++)
                   b[j]=0;
                count=match(t,b,i);
                fprintf(fp,"%d\t%d\n",i,count);
            }
        fclose(fp);
        free(b);
        break;
        case 2:
        count=0;
        
           for(int i=2;i<=x;i++)
            {
                fp=fopen("strmatch_w.txt","a");
                w=(int *)malloc(i*sizeof(int));
                for(int j=0;j<i;j++)
                {
                   if(j==i-1)
                      w[j]=1;
                   else
                     w[j]=0;
                }
                count=match(t,w,i);
                fprintf(fp,"%d\t%d\n",i,count);
                fclose(fp);
            }
        
        free(w);
        break;
        case 3:
        count=0;
        fp=fopen("strmatch_a.txt","a");
           for(int i=2;i<=x;i++)
            {
                a=(int *)malloc(i*sizeof(int));
                for(int j=0;j<i;j++)
                   a[j]=rand()%2;
                count=match(t,a,i);
                fprintf(fp,"%d\t%d\n",i,count);
            }
        fclose(fp);
        free(a);
        break;    
    }

}
 
void main()
{
    int ch;
    for(;;)
    {
       printf("String Matching Algo Analysis\n1. Best Case\n2. Worst Case\n3. Average Case\nEnter ur choice\n");
         scanf("%d\n",&ch);
       switch(ch)
       {
        case 1:
        case 2:
        case 3: analysis(ch); break;
        case 4: exit(0);
       }
    }  
}