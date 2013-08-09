/*
User: abhisheklfs
*/
#include<iostream>
#include<cstdio>
using namespace std;
int arr[110];
int main()
{
  int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		int c=(m-1)/2;
		int d=n-m;
		int ans=d&c;
		cout<<(!ans)<<endl;
	}
	return 0;
}
