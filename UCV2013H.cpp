/*

User: abhisheklfs
Algo: BFS

*/
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

bool flag[12510]={0};
int arr[260][260];
int n,m;
vector < pair<int ,int > > slick;
//vector <int> c;
int xa[4]={0,1,0,-1};
int ya[4]={1,0,-1,0};



bool valid(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y])return 1;
  return 0;
}



void call()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0)
			continue;
			
			int c=1;
			arr[i][j]=0;
			queue <pair<int,int> > pos;
			pos.push(make_pair(i,j));
			while(!pos.empty())
			{
				int x=(pos.front()).first,y=(pos.front()).second;
				//cout<<"x="<<x<<"  y="<<y<<"  c="<<c<<endl;
				pos.pop();
				for(int k=0;k<4;k++)
				
				if(valid(x+xa[k],y+ya[k]))
				{
					pos.push(make_pair(x+xa[k],y+ya[k]));
					c++;
					arr[x+xa[k]][y+ya[k]]=0;
				}
			}
			if(!flag[c])
			{
				flag[c]=1;
				slick.push_back(make_pair(c,1));
			}
			else
			{
				for(int i=0;i<slick.size();i++)
				{
					if(slick[i].first==c)slick[i].second++;
				}
			}
		}
	}
	return;
}




int main()
{
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		slick.cllear();
		//res=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
		}
		
		call();
		int res=0;
		for(int i=0;i<slick.size();i++)res+=slick[i].second;
		
		printf("%d\n",res);
		sort(slick.begin(),slick.begin()+slick.size());
		for(int i=0;i<slick.size();i++)
		{
			printf("%d %d\n",slick[i].first,slick[i].second);
			flag[slick[i].first]=0;
		}
	
		
	}
	
	return 0;
}
