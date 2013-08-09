#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
  int c=1,a,b;
	string s;
	while(cin>>s)
	{
		if(s[0]=='-')
		break;
		a=b=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='{')
			a+=1;
			else
			a-=1;
			if(a<0)
			a+=2,b++;
		}
		cout<<c++<<". "<<((a/2)+b)<<endl;
	}
}
