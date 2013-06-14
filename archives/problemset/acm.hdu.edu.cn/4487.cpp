#include <stdio.h>
#define sf scanf
#define pf printf
double f[2][100+2];
int main()
{
    int p;
    sf("%d",&p);
    for (int t=1;t<=p;t++)
    {
    int n;
    double l,r;
    sf("%*d%d%lf%lf",&n,&l,&r);
    f[0][0]=1;
    for (int i=1;i<=n;i++) f[0][i]=0;
    int ii=0;
    for (int i=1;i<=n;i++,ii=!ii)
        for (int p=0;p<=n;p++)
        f[!ii][p]=(p?f[ii][p-1]*r:f[ii][p]*l)+f[ii][p+1]*l+f[ii][p]*(1-l-r);
    double ans=0;
    for (int i=0;i<=n;i++) ans+=f[ii][i]*i;
    pf("%d %.4f\n",t,ans);
    }
}
