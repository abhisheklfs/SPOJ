#include<iostream>
#include<cstdio>
using namespace std;
int fibo(int n)
{
if(n<3)
return n+1;
else
return fibo(n-1)+fibo(n-2);
}

int main()
{
int tc;
cin>>tc;
while(tc--)
{
int n;
int ans;
cin>>n;
ans=fibo(n);
cout<<ans<<endl;
}
}
