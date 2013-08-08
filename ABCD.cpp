/*

User: abhisheklfs
Algo: Depth First Search

*/


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s[2];
int count[4];
char ch[4]={'A','B','C','D'};
bool dfs(int current , int total)
{
  if(current==total)
  {
    cout<<s[1]<<endl;
    return true;
  }
  for(int i=0;i<4;i++)
  {
    if(!count[i]||(s[0][current]==ch[i])||(current&&s[1][current-1]==ch[i]))
    continue;
    count[i]--;
    s[1][current]=ch[i];
    if(dfs(current+1,total))
      break;
    count[i]++;
  }
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  count[i]=n;
  cin>>s[0];
  dfs(0,2*n);
}
