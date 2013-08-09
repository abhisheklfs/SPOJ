/*
User: abhisheklfs
Algo: Segment Tree

*/
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int arr[1000000],segment[8000000];

void make(int node,int i,int j)
{
  if(i==j)
	{
		segment[node]=arr[i];
		return;
	}
	int p=node<<1;
	make(p,i,(i+j)>>1);
	make(p+1,((i+j)>>1)+1,j);
	segment[node]=max(segment[p],segment[p+1]);
}
int query(int node,int i,int j,int l,int r)
{
	if(r<i||l>j)
		return -1;
	else if(i<=l&&r<=j)
		return segment[node];
	else
		return max(query(node<<1,i,(i+j)>>1,l,r),query((node<<1)+1,((i+j)>>1)+1,j,l,r));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	make(0,0,n-1);
	int k;
	cin>>k;
	for(int i=0;i<n-k;i++)
	{
		int x=query(0,0,n-1,i,i+k);
		cout<<x<<endl;
		if(!i)printf("%d",x);
		else printf(" %d",x);
	}
}

