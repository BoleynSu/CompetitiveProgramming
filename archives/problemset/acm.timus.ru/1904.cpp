#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


#define sf scanf
#define pf printf
#define rep(i,n) for (int i=0;i<(n);i++)
#define repf(i,b,e) for (int i=(b);i<(e);i++)
#define ft(i,b,e) for (int i=(b);i<=(e);i++)
#define fdt(i,b,e) for (int i=(b);i>=(e);i--)

template<typename T>
bool cmin(T& a,const T& b)
{
	return a>b?a=b,true:false;
}

bool _is[1000000];
bool* is=_is+500000;

int cnt;
int b[100000];
int e[100000];

int main()
{
	int k;
	int a[10];
	sf("%d",&k);
	rep(i,k) sf("%d",a+i);
	ft(x,-20000,20000)
	{
		int y=x;
		rep(i,k) y=max(y-a[i],a[i]-y);
		if (y<=1) is[x]=true;
	}
	ft(x,-20000,20000)
	{
		if (is[x])
		{
			b[cnt]=x;
			while (is[x+1]) x++;
			e[cnt]=x;
			cnt++;
		}
	}
	pf("%d\n",cnt);
	rep(i,cnt) pf("%d %d\n",b[i],e[i]);
}