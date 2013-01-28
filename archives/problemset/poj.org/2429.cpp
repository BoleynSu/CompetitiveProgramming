#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
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
    while (y)
    {
        if (y&1) result=mulWithMod(result,x,z);
        y>>=1;
        x=mulWithMod(x,x,z);
        x%=z;
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
            d=gcd(y-x>=0?y-x:y-x+n,n);
            if (d!=1&&d!=n) return factor(d,k,isProbablePrimeK);
        }
    }
    return n;
}

vector<lli> dfs(vector<lli> f,lli i,lli x0,lli x1)
{
    if (i==f.size())
    {
        if (x0<x1)
        {
            vector<lli> v(2);
            v[0]=x0;
            v[1]=x1;
            return v;
        }
        else
        {
            vector<lli> v(2);
            v[0]=x1;
            v[1]=x0;
            return v;
        }
    }
    else
    {
        vector<lli> xx1=dfs(f,i+1,x0*f[i],x1);
        vector<lli> xx2=dfs(f,i+1,x0,x1*f[i]);
        if (xx1[0]+xx1[1]<xx2[0]+xx2[1]) return xx1;
        else return xx2;
    }
}

int main()
{
    lli gcd,lcm;
    while (cin>>gcd>>lcm)
    {
        lli c=lcm/gcd;
        vector<lli> f;
        while (c!=1)
        {
            lli d=factor(c);
            f.push_back(1);
            while (c%d==0)
            {
                f.back()*=d;
                c/=d;
            }
        }
        if (f.empty()) cout<<gcd<<" "<<gcd<<endl;
        else
        {
            vector<lli> x=dfs(f,0,1,1);
            cout<<gcd*x[0]<<" "<<gcd*x[1]<<endl;
        }
    }
}
