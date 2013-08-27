/*
 * Package: StandardCodeLibrary.NumberTheory
 * Description:
 * O(n)的筛法求素数表;
 * 带mod的乘法;
 * 带mod的指数函数;
 * Rabin-Miller素数测试;
 * Pollard's rho大数分解;
 * 计算phi;
 * 扩展gcd;
 * 中国剩余定理;
 * 指数循环节;
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace Math
{
namespace NumberTheory
{

typedef unsigned long long big;

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
const int MAXP=2;
const int MAXPS=1;
bool isp[MAXP+1];//isp[x]=x是否为素数
int pp[MAXP+1];//pp[x]=x在素数表中的位置(从0开始)
int fac[MAXP+1];//fac[x]=x最小的质因子(x<=1时无意义)
int ps;//素数表的大小
int p[MAXPS];//素数表
void make_prime_table()
{
	fl(isp,true);
	isp[0]=isp[1]=false;
	ft(i,2,MAXP)
	{
		if (isp[i]) pp[p[ps]=i]=ps,ps++,fac[i]=i;
		for (int j=0;p[j]*i<=MAXP;j++)
		{
			isp[p[j]*i]=false,fac[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
}

//带mod的加法 0<=a,b<mod
#define add(a,b,mod) ((a)>=(mod)-(b)?(b)-((mod)-(a)):(a)+(b))
//带mod的乘法 0<=a,b<mod
big mul(big a,big b,big mod)
{
	big c=0;
	whl(b)
	{
		if (b&1) c=add(c,a,mod);
		a=add(a,a,mod);
		b>>=1;
	}
	rtn c;
}
//带mod的指数函数 0<=a,b<mod
big pow(big a,big b,big mod)
{
	big c=1;
	whl(b)
	{
		if (b&1) c=mul(c,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	rtn c;
}
//Rabin-Miller素数测试 n>1且n为奇数
bool witness(big n)
{
	big nm1=n-1;
	big a=rand()%nm1+1;
	big d=nm1;
	whl((d&1)==0) d>>=1;
	big x=pow(a,d,n);
	if (x==1) rtn true;
	lp
	{
		if (x==nm1) rtn true;
		d<<=1;
		if (d==nm1) rtn false;
		x=mul(x,x,n);
	}
}
//Rabin-Miller素数测试 n>=2
bool isprime(big n,int k=20)
{
	if (n%2==0) rtn n==2;
	else
	{
		rep(i,k) if (!witness(n)) rtn false;
		rtn true;
	}
}
//Pollard's rho大数分解 n>1且n为合数
big rho(big n)
{
	if (n%2==0) rtn big(2);
	else
	{
		big d;
		big c=rand()%n;
		big x=rand()%n;
		big y=x;
		do
		{
			x=add(mul(x,x,n),c,n);
			y=add(mul(y,y,n),c,n);
			y=add(mul(y,y,n),c,n);
			if (x>y) d=gcd(x-y,n);
			else d=gcd(y-x,n);
		}
		whl(d==1);
		rtn d;
	}
}
//Pollard's rho大数分解 n>1
big factor(big n,int k=20)
{
	if (isprime(n,k)) rtn n;
	else
	{
		big d;
		do d=rho(n);
		whl(d==1||d==n);
		rtn factor(d);
	}
}
#undef add

//计算phi
lli phi(lli x,int k=20)
{
	lli ret=x;
	whl(x!=1)
	{
		lli d=factor(x,k);//如果是小范围的 此处可用fac[x]代替
		ret/=d;
		ret*=d-1;
		whl(x%d==0) x/=d;
	}
	rtn ret;
}

//扩展gcd
lli gcd(lli a,lli b,lli& x,lli& y)
{
	if (b)
	{
		lli g=gcd(b,a%b,y,x);
		rtn y-=a/b*x,g;
	}
	else rtn x=1,y=0,a;
}

//中国剩余定理
//一般地,中国剩余定理是指若有一些两两互质的整数m[i],则对任意的整数a[i],以下联立同余方程组对模m[i]有公解
//x mod m[i]=a[i]
lli chinese_remainder(lli n,lli m[],lli a[])
{
	lli lcm=1;
	rep(i,n) lcm*=m[i];
	lli ans=0;
	rep(i,n)
	{
		lli Mi=lcm/m[i],x,y;
		gcd(Mi,m[i],x,y);
		ans+=Mi*x*a[i];
		ans%=lcm;
	}
	if (ans<0) ans+=lcm;
	rtn ans;
}

//指数循环节
//如果(a,p)=1		a^x%p=a^(x%phi(p))%p
//否则若x>=phi(p)	a^x%p=a^(x%phi(p)+phi(p))%p
lli mod(lli x,lli phip)
{
	rtn x>=phip?x%phip+phip:x;
}

}
}
}
