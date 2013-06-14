#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

int n,k;
int a[1000];
int cost[1000][1000];
int f[1000][1000];
int g[1000][1000];

int main()
{
	sf("%d%d",&n,&k);
	repf(i,1,n)
		ft(j,i+1,n)
			sf("%d",&cost[i-1][j]);
	ft(d,2,n) ft(i,0,n-d)
	{
		int j=i+d;
		cost[i][j]+=cost[i][j-1]+cost[i+1][j]-cost[i+1][j-1];
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	ft(i,1,k+1)
	{
		ft(j,0,n)
		{
			ft(j_,j?g[i][j-1]:0,j)
			{
				if (cmin(f[i][j],f[i-1][j_]+cost[j_][j]))
				{
					g[i][j]=j_;
				}
				else if (f[i][j]==f[i-1][j_]+cost[j_][j])
				{
					if (j_!=j) g[i][j]=j_;
				}
			}
		}
	}
	pf("%d\n",cost[0][n]-f[k+1][n]);
	int lst[1000];
	fdt(i,k+1,2) lst[i-1]=n=g[i][n];
	ft(i,1,k) pf("%d%c",lst[i],i==k?'\n':' ');
}