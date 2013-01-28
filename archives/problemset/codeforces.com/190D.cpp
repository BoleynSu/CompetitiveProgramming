#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

long long n,k;
pair<pair<long long,long long>,long long> a[400000];
long long L,R;
long long st[400000*4];
long long query(long long L,long long R,long long l,long long r,long long root=1)
{
	if (l<=L&&R<=r) return st[root];
	else if (R<l||r<L) return 0;
	else
	{
		long long LL=L,LR=(L+R)>>1,Lroot=root<<1;
		long long RL=LR+1,RR=R,Rroot=Lroot|1;
		return max(query(LL,LR,l,r,Lroot),query(RL,RR,l,r,Rroot));
	}
}
void insert(long long L,long long R,long long p,long long v,long long root=1)
{
	if (p<=L&&R<=p) st[root]=v;
	else if (R<p||p<L) return;
	else
	{
		long long LL=L,LR=(L+R)>>1,Lroot=root<<1;
		long long RL=LR+1,RR=R,Rroot=Lroot|1;
		insert(LL,LR,p,v,Lroot);
		insert(RL,RR,p,v,Rroot);
		st[root]=max(st[Lroot],st[Rroot]);
	}
}

bool mycmp(const pair<pair<long long,long long>,long long>& a,const pair<pair<long long,long long>,long long>& b)
{
	return a.first.second<b.first.second;
}

int main()
{
	cin>>n>>k;
	for (long long i=0;i<n;i++) cin>>a[i].first.first,a[i].first.second=i;
	sort(a,a+n);
	for (long long i=0;i<n;i++)
	{
		if (i+1!=n&&a[i].first.first!=a[i+1].first.first)
		{
			a[i].first.first=R;
			R++;
		}
		else a[i].first.first=R;
	}
	for (long long i=0,j;i<n;i=j)
	{
		j=i;
		while (j<n&&a[j].first.first==a[i].first.first) j++;
		for (long long t=i;t<i+k-1&&t<j;t++)
			a[t].second=0;
		for (long long t=i+k-1;t<j;t++)
			a[t].second=a[t-k+1].first.second+1;
	}
	sort(a,a+n,mycmp);
	long long answer=0;
	for (long long i=0;i<n;i++)
	{
		insert(L,R,a[i].first.first,a[i].second);
		answer+=query(L,R,L,R);
	}
	cout<<answer<<endl;
	//for (long long i=0;i<n;i++)
	//	cout<<a[i].first.first<<" "<<a[i].first.second<<" "<<a[i].second<<endl;
}

