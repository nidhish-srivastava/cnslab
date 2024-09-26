#include<stdio.h>
#include<time.h>
int main()
{
  	int i,n,temp,j,a[100000],key;
	double clk;
	clock_t starttime,endtime;
	printf("Enter the seat numbers \n");
	scanf("%d",&n);   
     		printf("The seat nuymbers are : \n");
	for(i=0;i<n;i++) 
   	{
     		a[i]=rand()%100;
      	printf("\t%d",a[i]);
   	}
   	starttime=clock();
     for(i=0;i<n-1;i++)
   	{
    		for(j=0;j<n-i-1;j++)
     		{
        		if(a[j]>a[j+1])   
        		{
            			temp=a[j];
           			 a[j]=a[j+1];
            			a[j+1]=temp;
        		}
      	}
   }
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("\n Seat numbers in ascending order: \n");
    for(i=0;i<n;i++)
    printf("\t%d",a[i]);
    printf("\n Time taken is %f",clk);
   }
