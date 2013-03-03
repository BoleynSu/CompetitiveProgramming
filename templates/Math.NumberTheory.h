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

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
const int MAXP=10000000;
const int MAXPS=664579;
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

//带mod的乘法
lli mulWithMod(lli x,lli y,lli z)
{
	lli ret=0;
	x%=z;
	y%=z;
	whl(y)
	{
		if (y&1)
		{
			ret+=x;
			if (ret>=z) ret-=z;
		}
		x<<=1;
		if (x>=z) x-=z;
		y>>=1;
	}
	rtn ret;
}

//带mod的指数函数
lli powWithMod(lli x,lli y,lli z)
{
	lli ret=1;
	x%=z;
	whl(y)
	{
		if (y&1) ret=mulWithMod(ret,x,z);
		y>>=1;
		x=mulWithMod(x,x,z);
	}
	rtn ret;
}

//Rabin-Miller素数测试
bool isProbablePrime(lli n,lli k=50)
{
	if (n<=1) rtn false;
	else if (n<=3) rtn true;
	else
	{
		lli d=n-1;
		whl(!(d&1)) d>>=1;
		rep(i,k)
		{
			lli a=rand()%(n-3)+2;//2 to n-2
			lli x=powWithMod(a,d,n);
			if (x==1) continue;
			whl(d!=n-1&&x!=n-1&&x!=1)
			{
				x=mulWithMod(x,x,n);
				d<<=1;
			}
			if (x!=n-1) rtn false;
		}
		rtn true;
	}
}

//Pollard's rho大数分解
lli factor(lli n,lli k=50)
{
	if (isProbablePrime(n,k)) rtn n;
	lp
	{
		lli d=1,x=rand()%(n-1)+1,//1 to n-1
				y=rand()%(n-1)+1,//1 to n-1
				c=rand()%n;
		if (c==0) c++;//c!=0
		if (c==n-2) c++;//c!=n-2
		lli loop=0;
		whl(d==1)
		{
			loop++;
			if (((-loop)&loop)==loop) y=x;
			x=(mulWithMod(x,x,n)+c)%n;
			if (x==y) break;
			d=gcd(y-x+n,n);
			if (d!=1&&d!=n) rtn factor(d,k);
		}
	}
}

//计算phi
lli phi(lli x,lli k=50)
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
