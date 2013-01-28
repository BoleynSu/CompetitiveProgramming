#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int lli;

lli mulWithMod(lli x,lli y,lli z)
{
    lli result=0;
    x%=z;
    y%=z;
    while (y)
    {
        if (y&1)
        {
            result+=x;
            if (result>=z) result-=z;
        }
        x<<=1;
        if (x>=z) x-=z;
        y>>=1;
    }
    return result;
}
lli powWithMod(lli x,lli y,lli z)
{
    lli result=1;
    x%=z;
    while (y)
    {
        if (y&1) result=mulWithMod(result,x,z);
        y>>=1;
        x=mulWithMod(x,x,z);
    }
    return result;
}
bool isProbablePrime(lli n,lli k=50)
{
    if (n<=1) return false;
    if (n==2||n==3) return true;
    lli d=n-1;
    while (!(d&1)) d>>=1;
    for (lli i=0;i<k;i++)
    {
        lli a=rand()%(n-3)+2;
        lli x=powWithMod(a,d,n);
        if (x==1) continue;
        while (d!=n-1&&x!=n-1&&x!=1)
        {
            x=mulWithMod(x,x,n);
            d<<=1;
        }
        if (x!=n-1) return false;
    }
    return true;
}
lli gcd(lli a,lli b)
{
    lli c;
    while (a!=0)
    {
        c=a;
        a=b%a;
        b=c;
    }
    return b;
}
lli gcd(lli a,lli b,lli& x,lli& y)
{
    if (a==0)
    {
        x=0,y=1;
        return b;
    }
    else
    {
        lli g=gcd(b%a,a,y,x);
        x-=b/a*y;
        return g;
    }
}
lli factor(lli n,lli k=INT_MAX,lli isProbablePrimeK=50)
{
    if (isProbablePrime(n,isProbablePrimeK)) return n;
    for (lli i=0;i<k;i++)
    {
        lli d=1,x=rand()%(n-1)+1,y=rand()%(n-1)+1,c=rand()%n;
        if (c==n-2) c++;
        int loop=0;
        while (d==1)
        {
            loop++;
            if (((-loop)&loop)==loop) y=x;
            x=(mulWithMod(x,x,n)+c)%n;
            if (x==y) break;
            d=gcd(y-x+n,n);
            if (d!=1&&d!=n) return factor(d,k,isProbablePrimeK);
        }
    }
    return n;
}
lli phi(lli x,lli factorK=INT_MAX,lli isProbablePrimeK=50)
{
    lli result=x;
    for (int i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            result/=i,result*=i-1;
            while (x%i==0) x/=i;
        }
    }
    if (x!=1) result/=x,result*=x-1;
    return result;
}
//a^x%p=a^(x%phi(p)+phi(p))%p

int main()
{
    int t;
    cin>>t;
    int CT=0;
    while (t--)
    {
        lli c,n,p;
        cin>>c>>n;
        p=1000000007;
        lli div2,div2n,y;
        gcd(2,p,div2,y);
        gcd(2*n,p,div2n,y);
        while (div2<0) div2+=p;
        while (div2n<0) div2n+=p;
        lli answer=(n%2==0)?((powWithMod(c,n/2,p)+powWithMod(c,n/2+1,p))*n%p)*div2:powWithMod(c,n/2+1,p)*n;
        for (int i=1;i*i<=n;i++)
        {
            if (n%i==0)
            {
                lli ph=phi(i);
                answer+=mulWithMod(ph,powWithMod(c,n/i,p),p);
                answer%=p;
                if (i*i!=n)
                {
                    lli ph=phi(n/i);
                    answer+=mulWithMod(ph,powWithMod(c,i,p),p);
                    answer%=p;
                }
            }
        }
        answer*=div2n;
        answer%=p;
        cout<<"Case #"<<++CT<<": ";
        cout<<answer<<endl;
    }
}

