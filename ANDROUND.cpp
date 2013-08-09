/*

User: abhisheklfs
Algo: Segment Tree

*/


#include<iostream>
#include<cstdio>
#include<stdio.h>
#define get getchar_unlocked
using namespace std;
long long int arr[20010];long long segment[100010];
inline long long int inp()
{
    long long int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9')
    {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=get();
    }
    return n*s;
}

long long int query(long long int node,long long int l,long long int r,long long int i,long long int j)
{
  if(j<l||i>r)
		return -1;
	if(l>=i&&r<=j)
		return segment[node];
	long long int p=query((node<<1),l,((l+r)>>1),i,j);
	long long int q=query((node<<1)+1,((l+r)>>1)+1,r,i,j);
	//if(p==-1)
	if(p==-1)
		return q;
	else
		if(q==-1)
			return p;
		else
			return (p&q);
}

void make(long long int node,long long int l,long long int r)
{
	if(l==r)
	{
		segment[node]=arr[l];
		return;
	}
	//int n=node<<1;
	make(node<<1,l,(l+r)>>1);
	make((node<<1)+1,((l+r)>>1)+1,r);
	segment[node]=segment[node<<1]&segment[(node<<1)+1];
}

int main()
{
	long long int high1,high2,low1,low2,high,low;
	int tc;
	long long int ans=-1;
	long long int n,k;
	tc=inp();
	while(tc--)
	{
		ans=-1;
		n=inp();
		k=inp();
		for(int i=0;i<n;i++)
			arr[i]=inp();
		if((k<<1)<n)
		{
			make(1,0,n-1);
			for(int  i=0;i<n;i++)
			{
				high=(i+k)%n;
				low=(i+(n-k))%n;
				if(i>high)
				{
					low1=0;high1=high;low2=low;high2=n-1;
					ans=(query(1,0,n-1,low1,high1)&query(1,0,n-1,low2,high2));
				}
				else if(low>i)
				{
					low2=low;high2=n-1;low1=0;high1=high;
					ans=(query(1,0,n-1,low1,high1)&query(1,0,n-1,low2,high2));
				}	
				else
				{
					ans=query(1,0,n-1,low,high);
				}
				if(i!=0)
					//cout<<" "<<ans;
					printf(" %lld",ans);
				else
					//cout<<ans;
					printf("%lld",ans);
			}
			//cout<<endl;
			printf("\n");
		}
		else
		{
			ans=arr[0];
			for(int i=1;i<n;i++)
				ans&=arr[i];
			for(int i=0;i<n;i++)
				if(i!=0)
					//cout<<" "<<ans;
					printf(" %lld",ans);
				else
					//cout<<ans;
					printf("%lld",ans);
					//cout<<endl;
				printf("\n");
		}
	}
}
