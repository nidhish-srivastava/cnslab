#include<stdio.h>
#include<time.h>
void bfs(int a[10][10],int n,int source)
{
 	int s[10],q[10],f=0,r=-1,t,v;
	 for(v=0;v<n;v++)
	{
		s[v]=0;
	}
 	q[++r]= source;
 	s[source]=1;
	while(f<=r)
 	{
  		t=q[f++];
  		for(v=0; v<n; v++)
		if(a[t][v]==1 && s[v]==0)
		{
	 		q[++r]=v;
	 		printf("\n The BFS traversal is: %d %d", t, v);
	 		s[v]=1;
		}
 	}
  }


int main()
{
 	int a[10][10],n,i,j,s;
      double clk;
      clock_t starttime,endtime;
	printf("\n Enter the number of cities\n");
 	scanf("%d",&n);
	printf("\nEnter the matrix represention:");
 	for(i=0;i<n;i++)
 	for(j=0;j<n;j++)
  	scanf("%d",&a[i][j]);
 	printf("\nEnter the source city");
 	scanf("%d",&s);
      starttime=clock(); 
 	bfs(a,n,s);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
      printf("\nThe run time is %f\n",clk);
 
}

/*
Enter the number of cities: 5
Enter the matrix representation:
0 1 1 1 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Enter the source city:  0
The BFS traversal is:
01
02
03
14


*/
