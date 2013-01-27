#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int lli;
const lli MOD=1000000007;
#define I(x) ((x)&1)
lli f[2][5000+2];
lli g[2][5000+2];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		f[I(1)][i]=1;
		g[I(1)][i]=g[I(1)][i-1]+f[I(1)][i];
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[I(i)][j]=(f[I(i-1)][j]*j+(j>=i?(g[I(i-1)][j-1]-g[I(i-1)][i-1]+MOD):0))%MOD;
			g[I(i)][j]=(g[I(i)][j-1]+f[I(i)][j])%MOD;
			//cout<<i<<" "<<j<<" "<<f[I(i)][j]<<" "<<min(i,j)<<endl;
		}
	}
	printf("%d\n",int(f[I(n)][n]));
	return 0;
}
