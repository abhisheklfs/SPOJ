/*
User: abhisheklfs
algo: inverse_modulo

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 1000000007
using namespace std;
long long int fact[10010];
long long int invi[10010];
long long int arr[10010];
long long inver(long long int value);
long long combi(int n,int k);
int main()
{
	fact[0]=1;
	for(int i=1;i<10010;i++)
		fact[i]=(fact[i-1]*i)%M;
	for(int i=0;i<10010;i++)
		invi[i]=inver(fact[i])%M;
	int c=1;
	int tc;scanf("%d",&tc);
	//cin>>tc;
	while(tc--)
	{
		int n,k;cin>>n>>k;
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);//cin>>arr[i];
		sort(arr,arr+n);
		long long int ans=0;
		for(int i=k-1;i<n;i++)
		{
			ans=(ans+(arr[i]*combi(i,k-1))%M)%M;
		}
		cout<<"Case #"<<(c++)<<": "<<(ans+M)%M<<endl;
	}
}


long long combi(int n,int k)
{
	long long ans=1;
	ans=(ans*fact[n])%M;
	ans=(ans*invi[k])%M;
	ans=(ans*invi[n-k])%M;
	return ans;
}

long long int inver(long long int value)
{
	long long int pex=M-2;
	long long int ans=1;
	while(pex>0)
	{
		if(pex&1)
		ans=(ans*value)%M;
		value=(value*value)%M;
		pex/=2;
	}
	return ans;
}
