#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cmath>
#include<map>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;

const int MAXN=20000+2;
typedef double db;
db a,b,c,l,r;
int n;
db x[MAXN],y[MAXN];
int cnt;
db xs[MAXN*2];
const db eps=1e-6;
int sgn(db x)
{
	if (x<-eps) return -1;
	else if (x>eps) return 1;
	else return 0;
}
bool check(db x1,db y1,db x2,db y2,db x3,db y3)
{
	db x=x1;
	db fk=2*a*x+b;
	db fb=a*x*x+b*x+c-fk*x;
	db Y2=fk*x2+fb;
	db Y3=fk*x3+fb;
	return (Y2>=y2&&Y3<=y3)||(y2>=Y2&&y3<=Y3);
}
void add(db x1,db y1,db x2,db y2,db x3,db y3)
{
	if (sgn(x1-x2))
	{
		db fk=(y1-y2)/(x1-x2);
		db fb=y1-fk*x1;
		//y=fkx+fb=ax^2+bx+c
		db A=a,B=b-fk,C=c-fb;
		db delta=B*B-4*A*C;
		if (sgn(delta)>=0)
		{
			db x;
			x=(-B+sqrt(delta))/(2*A);
			if ((sgn(x-x1)>0&&sgn(x2-x)>0)||(sgn(x-x2)>0&&sgn(x1-x)>0))
			{
				xs[cnt++]=x;
			}
			else if (((sgn(x-x1)==0&&sgn(x2-x)>0)||(sgn(x-x2)>0&&sgn(x1-x)==0))&&check(x1,y1,x2,y2,x3,y3))
			{
				xs[cnt++]=x;
			}
			x=(-B-sqrt(delta))/(2*A);
			if ((sgn(x-x1)>0&&sgn(x2-x)>0)||(sgn(x-x2)>0&&sgn(x1-x)>0))
			{
				xs[cnt++]=x;
			}
			else if (((sgn(x-x1)==0&&sgn(x2-x)>0)||(sgn(x-x2)>0&&sgn(x1-x)==0))&&check(x1,y1,x2,y2,x3,y3))
			{
				xs[cnt++]=x;
			}
		}
	}
	else
	{
		db y=a*x1*x1+b*x1+c;
		if ((sgn(y-y1)>0&&sgn(y2-y)>0)||(sgn(y-y2)>0&&sgn(y1-y)>0))
		{
			xs[cnt++]=x1;
		}
		else if (((sgn(y-y1)==0&&sgn(y2-y)>0)||(sgn(y-y2)>0&&sgn(y1-y)==0))&&check(x1,y1,x2,y2,x3,y3))
		{
			xs[cnt++]=x1;
		}
	}
}
db f(db x)
{
	return sqrt((2*a*x+b)*(2*a*x+b)+1);
}
db simpson(db a,db b)
{
	return (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6;
}
db integrate(db a,db b)
{
	db c=(a+b)/2;
	db l=simpson(a,c);
	db r=simpson(c,b);
	db t=simpson(a,b);
	return sgn(l+r-t)?integrate(a,c)+integrate(c,b):t;
}

int main()
{
	while (~scanf("%d%lf%lf%lf%lf%lf",&n,&a,&b,&c,&l,&r))
	{
		for (int i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		x[n]=x[0],y[n]=y[0];
		x[n+1]=x[1],y[n+1]=y[1];
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			add(x[i],y[i],x[i-1],y[i-1],x[i+1],y[i+1]);
		}
		sort(xs,xs+cnt);
		db ans=0;
		for (int i=0;i<cnt;i+=2)
		{
			db L=max(l,xs[i]),R=min(r,xs[i+1]);
			if (L<R) ans+=integrate(L,R);
		}
		printf("%.2f\n",ans);
	}
}
