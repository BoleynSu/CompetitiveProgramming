#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
using namespace std;

typedef long long int lli;

lli __powWithMod(lli x,lli y,lli z)
{
    lli result=1;
    x%=z;
    while (y)
    {
        if (y&1) result=result*x%z;
        y>>=1;
        x*=x;
        x%=z;
    }
    return result;
}
lli __phi(lli x)
{
    lli result=x;
    for (lli i=2;i*i<=x;i++)
        if (x%i==0)
        {
            result/=i;
            result*=i-1;
            while (x%i==0) x/=i;
        }
    if (x!=1) result/=x,result*=x-1;
    return result;
}
lli get(lli a,lli k,lli mod)
{
    lli p=__phi(mod);
    return k>1?__powWithMod(a,get(a,k-1,p)+p,mod):a%mod;
}

int main()
{
    lli a,k;
    while (scanf("%I64d%I64d",&a,&k)!=EOF)
    {
        if ((a==0)&&(k%2==0)) printf("1\n");
        else
 printf("%I64d\n",get(a,k,100000000));
    }
}

