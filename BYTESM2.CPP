/*

User: abhisheklfs
Algo: Greedy DP

*/
#include<iostream>
#include<cstdio>
using namespace std;
int arr[100][100];

int max(int a,int b)
{
    return a>b?a:b;
}


int main()
{
  int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)scanf("%d",&arr[i][j]);
		}

/*
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)printf("%d ",arr[i][j]);
printf("\n");
}
*/		
		int res=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j==0)
				{
					arr[i][j]+=max(arr[i-1][j],arr[i-1][j+1]);
				}
				else if(j==m-1)
				{
					arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j]);
				}
				else
				{
					arr[i][j]+=max(arr[i-1][j-1],(max(arr[i-1][j],arr[i-1][j+1])));
				}
               // printf("%d ",arr[i][j]);
			}//printf("\n");

		}

		for(int i=0;i<m;i++)
		{
			res=max(res,arr[n-1][i]);
		}
		printf("%d\n",res);
	}
	
	return 0;
}
