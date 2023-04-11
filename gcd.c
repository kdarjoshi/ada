#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 200
#define incre 10
//  To analyze all algorithms  in single execution 
// plot the graphs of different algorithms separately
void main()
{
 
  int i,j,k,m,n,r,itn=1,tm,tn,min,E_Maxcount, E_Mincount,E_count, ME_Maxcount, ME_Mincount,ME_count, temp, CI_Maxcount,CI_Mincount,CI_count;
  FILE *fp1,*fp2, *fp3, *fp4, *fp5,*fp6,*fp7;

// system("rm GCD_data.txt");
 
for(i=x;i<=y;i+=incre)
        {   
           E_Maxcount = 0;
	       E_Mincount= 999;
           ME_Maxcount = 0;
           ME_Mincount= 999;
           CI_Maxcount = 0;
           CI_Mincount= 999;
			
		for(j=2;j<=i;j++)
        {
			for(k=2;k<=i;k++)
            {
				m = j;
				n = k;
								
				tm = m;
				tn = n;
              //  Euclid Algorithm
              {
				E_count=0 ;
				while(n!=0)
                {
					++E_count;
					r = m%n;
					m = n;
					n = r;
				} 
                 
	            if(E_count> E_Maxcount)
	               E_Maxcount = E_count;
                if(E_count < E_Mincount)
	               E_Mincount = E_count;            
              }             
              // end of Euclid

// Modified Euclid
{
   m=tm; n = tn;
   ME_count= 0;
	while(n!=0)
    {
    	if(n>m)
    	{
    		temp=m;
	        m=n;
	        n=temp;
    	} 
    	++ME_count;
	    m= m- n;                   
    }  
	
    if(ME_count> ME_Maxcount)
	   ME_Maxcount =ME_count;
    if(ME_count< ME_Mincount)
	   ME_Mincount= ME_count;
  } 
  // end of modified euclid  
  // consecutive integer checking method
    {
    	m=tm;
    	n=tm;
    	min=m;
    	CI_count=0;
    	if(min>n)
    		min=n;
    	while(min!=0)
    	{
    		++CI_count;
    		if(m%min==0)
    		{	
    			++CI_count;
    		    if(n%min==0)
    		    	break;
    		    //else
    		    	//min--;
    		}
    		//else
    			min--;
    	} 
    } 

    if(CI_count> CI_Maxcount)
	   CI_Maxcount =CI_count;
    if(CI_count< CI_Mincount)
	   CI_Mincount= CI_count;
    //end of consecutive integer method

 //      fp1=fopen("GCD_data.txt","a");
 //     fprintf(fp1,"Ieration range:%d\n M  N  GCD\n",i);
 //      fprintf(fp1,"%d %d  %d\n",tm,tn,m);
	// fclose(fp1);
       }  // k loop  
		
    } // j loop
	fp2 = fopen("euclid_W.txt","a");
	fprintf(fp2,"%d %d\n",i,E_Maxcount);
	fclose(fp2);
        fp3 = fopen("euclid_B.txt","a");
	fprintf(fp3,"%d %d\n",i,E_Mincount);
	fclose(fp3);
        fp4 = fopen("Meuclid_W.txt","a");
	fprintf(fp4,"%d %d\n",i,ME_Maxcount);
	fclose(fp4);
        fp5 = fopen("Meuclid_B.txt","a");
	fprintf(fp5,"%d %d\n",i,ME_Mincount);
	fclose(fp5);

	      fp6 = fopen("con_W.txt","a");
	fprintf(fp6,"%d %d\n",i,CI_Maxcount);
	fclose(fp6);
        fp7 = fopen("con_B.txt","a");
	fprintf(fp7,"%d %d\n",i,CI_Mincount);
	fclose(fp7);
  }  // i loop
 
	
} 	