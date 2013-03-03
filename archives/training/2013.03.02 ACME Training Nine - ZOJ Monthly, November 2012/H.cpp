#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long big;

#define add(a,b,mod) ((a)>=(mod)-(b)?(b)-((mod)-(a)):(a)+(b))
big mul(big a,big b,big mod)
{
	big c=0;
	while (b)
	{
		if (b&1) c=add(c,a,mod);
		a=add(a,a,mod);
		b>>=1;
	}
	return c;
}
big pow(big a,big b,big mod)
{
	big c=1;
	while (b)
	{
		if (b&1) c=mul(c,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return c;
}
big gcd(big a,big b)
{
	return a?gcd(b%a,a):b;
}
bool witness(big n)
{
	big nm1=n-1;
	big a=rand()%nm1+1;
	big d=nm1;
	while (d%2==0) d>>=1;
	big x=pow(a,d,n);
	if (x==1) return true;
	for (;;)
	{
		if (x==nm1) return true;
		d<<=1;
		if (d==nm1) break;
		x=mul(x,x,n);
	}
	return false;
}
bool isprime(big n,int k=20)
{
	if (n%2==0) return n==2;
	else
	{
		for (int i=0;i<k;i++)
			if (!witness(n))
				return false;
		return true;
	}
}
big rho(big n)
{
	if (n%2==0) return big(2);
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
		while(d==1);
		return d;
	}
}
big factor(big n,int k=20)
{
	if (isprime(n,k)) return n;
	else
	{
		big d;
		do d=rho(n);
		while (d==1||d==n);
		return factor(d);
	}
}

const int MAXP=10000;
const int MAXPS=10000;
bool isnp[MAXP+1];
int pp[MAXP+1];
int ft[MAXP+1];
int ps;
int p[MAXPS];
void make_prime_table()
{
	isnp[0]=isnp[1]=true;
	for (int i=2;i<=MAXP;i++)
	{
		if (!isnp[i]) pp[p[ps]=i]=ps,ps++,ft[i]=i;
		for (int j=0;p[j]*i<=MAXP;j++)
		{
			isnp[p[j]*i]=true,ft[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
}

int factor_table(big x)
{
	if (x<=big(MAXP)) return pp[ft[x]];
	else
	{
		for (int i=0;i<ps;i++) if (x%p[i]==0) return i;
		return ps;
	}
}

big x,y,t,delta,sqrt_delta,a,b;
int facs;
big fac[93];
int cnt[93];
int anss;
big ansa[93],ansb[93];
int dep;
big ys[93];
int itr[93];

int main()
{
	//a^3+b^3=(a+b)((a-b)^2+ab)
	//a+b=y
	//(2a-y)^2+a(y-a)=x/y
	//3 a^2 - 3y a + y^2-x/y = 0

	make_prime_table();

	while (~scanf("%llu",&x))
	{
		facs=0;
		y=x;
		while (y!=big(1))
		{
			t=factor_table(y);
			if (int(t)==ps) break;
			t=p[t];
			fac[facs]=t;
			cnt[facs]=0;
			while (y%t==0) y/=t,cnt[facs]++;
			facs++;
		}
		while (y!=big(1))
		{
			t=factor(y);
			fac[facs]=t;
			cnt[facs]=0;
			while (y%t==0) y/=t,cnt[facs]++;
			facs++;
		}
		for (int i=0;i<facs;i++)
		{
			for (int j=i+1;j<facs;j++)
				if (fac[i]<fac[j])
				{
					big swapbig;
					swapbig=fac[i],fac[i]=fac[j],fac[j]=swapbig;
					int swapint;
					swapint=cnt[i],cnt[i]=cnt[j],cnt[j]=swapint;
				}
		}

		anss=0;
		dep=0;
		ys[dep]=big(1);
		itr[dep]=0;
		big maxy=pow(x*4.0,1.0/3.0);
		for (;;)
		{
			y=ys[dep];

			if (y>maxy)
			{
				dep--;
				if (dep>=0)
				{
					ys[dep]*=fac[dep];
					itr[dep]++;
				}
				else break;
			}
			else if (dep<facs)
			{
				if (itr[dep]>cnt[dep])
				{
					dep--;
					if (dep>=0)
					{
						ys[dep]*=fac[dep];
						itr[dep]++;
					}
					else break;
				}
				else
				{
					dep++;
					ys[dep]=ys[dep-1];
					itr[dep]=0;
				}
			}
			else
			{
				delta=(x/y*4-y*y)*3;
				if (delta>=0)
				{
					sqrt_delta=sqrt(delta);
					if (sqrt_delta*sqrt_delta<delta)
						sqrt_delta++;
					if (sqrt_delta*sqrt_delta==delta)
					{
						a=(y*3-sqrt_delta)/6;
						b=y-a;
						if (a>0&&b>0&&a*a*a+b*b*b==x)
						{
							ansa[anss]=a;
							ansb[anss]=b;
							anss++;
						}
					}
				}
				dep--;
				if (dep>=0)
				{
					ys[dep]*=fac[dep];
					itr[dep]++;
				}
				else break;
			}
		}

		printf("%d",anss);
		for (int i=0;i<anss;i++)
		{
			for (int j=i+1;j<anss;j++)
				if (ansa[i]>ansa[j])
				{
					big swap;
					swap=ansa[i],ansa[i]=ansa[j],ansa[j]=swap;
					swap=ansb[i],ansb[i]=ansb[j],ansb[j]=swap;
				}
			printf(" (%llu,%llu)",ansa[i],ansb[i]);
		}
		printf("\n");
	}
}
