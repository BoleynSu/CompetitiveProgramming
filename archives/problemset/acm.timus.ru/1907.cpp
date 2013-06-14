#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define sf scanf
#define pf printf
#define rep(i,n) for (int i=0;i<(n);i++)
#define repf(i,b,e) for (int i=(b);i<(e);i++)
#define ft(i,b,e) for (int i=(b);i<=(e);i++)
#define fdt(i,b,e) for (int i=(b);i>=(e);i--)
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long lli;

template<typename T>
bool cmin(T& a,const T& b)
{
	return a>b?a=b,true:false;
}

int cnt;
lli p[100];

lli calc(lli n,int dep,int flag=1,lli get=1)
{
	if (cnt==dep)
	{
		return flag*n/get;
	}
	else
	{
		return calc(n,dep+1,flag,get)+calc(n,dep+1,-flag,get*p[dep]);
	}
}


lli get(lli a,lli n)
{
	for (lli i=2;i*i<=a;i++) if (a%i==0)
	{
		while( a%i==0) a/=i;
		p[cnt++]=i;
	}
	if (a!=1)
	{
		lli i=a;
		p[cnt++]=i;
	}
	return n-calc(n,0);
}


int main()
{
	lli a,n;
	cin>>a>>n;
	if (a%2==0)
	{
		//gcd(a,x)>1 1<=x<=n
		cout<<get(a,n)<<endl;
	}
	else
	{
		//x=2k+1 1<=x<=n
		//gcd(a,x)>1 1<=x<=n/2
		cout<<get(a,n/2)+(n+1)/2<<endl;
	}
}