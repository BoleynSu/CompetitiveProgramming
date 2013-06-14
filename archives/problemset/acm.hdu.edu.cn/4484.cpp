#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define sf scanf
#define pf printf

map<int,int> f;
int dp(int x)
{
    if (!f.count(x))
    {
        int nx;
        if (x%2==0) nx=x/2;
        else nx=x*3+1;
        f[x]=max(x,dp(nx));
    }
    return f[x];
}

int main()
{
    f[1]=1;
    int p;
    sf("%d",&p);
    for (int i=1;i<=p;i++)
    {
        int n;
        sf("%d%d",&n,&n);
        pf("%d %d\n",i,dp(n));
    }
}
