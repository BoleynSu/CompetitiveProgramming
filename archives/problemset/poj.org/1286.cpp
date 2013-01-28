#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int lli;

int main()
{
	lli n;
	while (cin>>n,n!=EOF)
	{
		lli answer;
		if (n==0) answer=0;
		else
		{
			answer=0;
			for (int i=0;i<n;i++)
			{
				int circle;
				bool visited[n];
				int p[n];
				lli get;
				circle=0;
				memset(visited,0,sizeof visited);
				for (int j=0;j<n;j++)
					p[(i+j)%n]=j;
				for (int j=0;j<n;j++)
					if (!visited[j])
					{
						circle++;
						while (!visited[j]) visited[j]=true,j=p[j];
					}
				get=1;
				for (int i=0;i<circle;i++) get*=3;
				answer+=get;
				circle=0;
				memset(visited,0,sizeof visited);
				for (int j=1;j+j<n;j++)
				{
					int swap=p[j];
					p[j]=p[n-j];
					p[n-j]=swap;
				}
				for (int j=0;j<n;j++)
					if (!visited[j])
					{
						circle++;
						while (!visited[j]) visited[j]=true,j=p[j];
					}
				get=1;
				for (int i=0;i<circle;i++) get*=3;
				answer+=get;
			}
			answer/=n*2;
		}
		cout<<answer<<endl;
	}
}
