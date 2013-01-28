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
lli phi(lli x,lli factorK=INT_MAX,lli isProbablePrimeK=50)
{
	lli result=x;
	while (x!=1)
	{
		lli d=factor(x,factorK,isProbablePrimeK);
		result/=d;
		result*=d-1;
		while (x%d==0) x/=d;
	}
	return result;
}

int main()
{
	lli n,t=0;
	while (cin>>n)
	{
		if (!n) break;
		n=n*9/gcd(8,n);
		if (gcd(10,n)!=1)
		{
			cout<<"Case "<<++t<<": ";
			cout<<0<<endl;
			continue;
		}
		lli p=phi(n,INT_MAX,500);
		lli answer;
		for (lli i=1;i*i<=p;i++)
			if (p%i==0)
				if (powWithMod(10,p/i,n)==1)
					answer=p/i;
		for (lli i=1;i*i<=p;i++)
			if (p%i==0)
				if (powWithMod(10,i,n)==1)
				{
					answer=i;
					break;
				}
		cout<<"Case "<<++t<<": ";
		cout<<answer<<endl;
	}
}