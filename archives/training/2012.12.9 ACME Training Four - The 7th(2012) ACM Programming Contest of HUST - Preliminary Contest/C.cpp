//============================================================================
// Name        : G.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN=100000;
int n;
int a[MAXN+2];
int m;
pair<pair<int,int>,int> q[MAXN+2];
long long f[MAXN+2];
long long ans[MAXN+2];

int main()
{
	while (~scanf("%d",&n))
	{
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	for (int i=0;i<m;i++) scanf("%d%d",&q[i].first.second,&q[i].first.first),q[i].second=i;
	sort(q,q+m);
	for (int i=0,j;i<m;i=j)
	{
		j=i;
		int b=q[i].first.first;
		while (j<m&&b==q[j].first.first) j++;
		if (b*b<=n)
		{
			for (int k=n;k>=1;k--) f[k]=(k+b<=n?f[k+b]:0)+a[k];
			for (int k=i;k<j;k++) ans[q[k].second]=f[q[k].first.second];
		}
		else
		{
			for (int k=i;k<j;k++)
			{
				ans[q[k].second]=0;
				for (int p=q[k].first.second;p<=n;p+=b) ans[q[k].second]+=a[p];
			}
		}
	}
	for (int i=0;i<m;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}