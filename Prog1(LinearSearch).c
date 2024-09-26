#include<stdio.h>
#include<time.h>
int main()
{
  	int i,a[100000],key;
	long int n;
 	double clk;
	clock_t starttime,endtime;
    	printf("Enter the number of medicines\n");
  	scanf("%d",&n);   
    	for(i=0;i<n;i++) 
   	{
      	a[i]=rand()%100;
      	printf("The medicine codes are: %d\n",a[i]);
   	}
      printf("Enter the medicine code to search\n");
   	scanf("%d",&key);
   	starttime=clock();
   	 for (i=0;i<n;i++)
   	{
      	if (a[i]==key)     /* if required element found */
      	{
         		printf("%d is present at location %d\n", key, i+1);
          		endtime=clock();
          		clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
         		printf("Time taken to search is %f\n",clk);
         		return 0;
            	}
   }
    printf("not found\n");
}

