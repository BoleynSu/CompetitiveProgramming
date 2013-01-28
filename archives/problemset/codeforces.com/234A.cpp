#include <cstdio>
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char s[1024];

bool m[1024];
int x[1024],y[1024];
void dfs(int d)
{
	if (d==0)
	{
		for (int i=n/2;i>0;i--)
		{
			if (s[x[i]]=='R'&&s[y[i]]=='L') swap(x[i],y[i]);
			cout<<x[i]+1<<" "<<y[i]+1<<endl;
		}
		exit(0);
	}
	else
	{
		for (int i=0;i<n;i++)
			if (!m[i])
			{
				m[i]=true;
				x[d]=i;
				for (int j=i+2;j<n;j++)
					if (!m[j])
					{
						m[j]=true;
						y[d]=j;
						dfs(d-1);
						m[j]=false;
					}
				m[i]=false;
			}
	}
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>s;
	for (int i=0;i<n/2;i++)
	{
		int x=i,y=i+n/2;
		if (s[x]=='R'&&s[y]=='L') swap(x,y);
		cout<<x+1<<" "<<y+1<<endl;
	}
}

