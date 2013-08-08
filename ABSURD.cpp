/*

User: abhisheklfs


*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		while(n%10==0)
			n/=10;
		float upper=(1.05*n);
		float lower=(0.95*n);
		if(n%5!=0)
		{
			int up=upper-upper%5;
			int down=lower+5-lower%5;
			if((up<=upper&&up>=lower)||(down<=upper&&down>=lower))
				printf("absurd\n");
			else
				printf("not absurd\n");
		}
		else
		{
			int up=n+5;
			int down=n-5;
			if((up<=upper&&up>=lower)||(down<=upper&&down>=lower))
				printf("absurd\n");
			else
				printf("not absurd\n");
		}
	}
	return 0;
}

