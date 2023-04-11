#include<stdio.h>
#include<stdlib.h>

int prim(int n,int a[][n],int con)
{
   int select[n],temp,min;
   int cost=0;
   int count=0;
   for(int i=0;i<n;i++)
      select[i]=0;
   select[0]=1;
   while(count<n-1)
      {
         min=9999;
         int row=0,col=0;
         for(int i=0;i<n;i++)
            {
               if(select[i])
                  for(int j=0;j<n;j++){
                     if(a[i][j] && select[j]==0)
                        {
                           con++;
                           if(a[i][j] < min)
                           {
                              min=a[i][j];
                              row=i;
                              col=j;
                           }
                        }
                     }
            }
         printf("%d----%d----%d\n",row+1,a[row][col],col+1);
         cost+=a[row][col];
         select[col]=1;
         count++;
      }
   printf("Minimum spannig tree weight is %d\n",cost);
   return con;
}
void main()
{
   int ch,i,j,count,n;
   FILE *fp;
   for(n=4;n<=4;n++)
      {
         int a[n][n];
         fp=fopen("prim.txt","a");
         printf("Enter the values for %d*%d matrix\n",n,n);
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
               {
                  printf("Enter the weight b/w %d and %d vertex \n",i+1,j+1);
                  scanf("%d",&a[i][j]);
               }
         int con=0;
         con=prim(n,a,con);
         fprintf(fp,"%d\t%d\n",n,con);
         fclose(fp);
      }
}         