#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define repf(i,b,n) for (int i=b;i<n;i++)
#define sqr(x) ((x)*(x))
typedef long long lli;
#define x first
#define y second

int n,m;
int t[2000];
double a[2000],b[2000],c[2000],d[2000];
double bx,by,ex,ey;
double length;
double bs[2000],es[2000];

const double eps=1e-8;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}

void calc(double& x,double& y,int i)
{
	int lsts=0;
	double lst[40],gy,gx;
	if (sgn(ey-by))
	{
		gy=b[i];
		gx=(ex-bx)/(ey-by)*(gy-by)+bx;
		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
		if (!sgn(l1+l2-length)&&sgn(gx-a[i])>=0&&sgn(c[i]-gx)>=0) lst[lsts++]=l1;
		gy=d[i];
		gx=(ex-bx)/(ey-by)*(gy-by)+bx;
		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
		if (!sgn(l1+l2-length)&&sgn(gx-a[i])>=0&&sgn(c[i]-gx)>=0) lst[lsts++]=l1;
	}
	if (!sgn(ey-by)&&sgn(b[i]-by)<=0&&sgn(by-d[i])<=0&&sgn(max(a[i],min(bx,ex))-min(c[i],max(bx,ex)))<=0)
	{
		gy=by;
		gx=max(a[i],min(bx,ex));
		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		lst[lsts++]=l1;
		gy=by;
		gx=min(c[i],max(bx,ex));
		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		lst[lsts++]=l1;
	}
	if (sgn(ex-bx))
	{
		gx=a[i];
		gy=(ey-by)/(ex-bx)*(gx-bx)+by;
		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
		if (!sgn(l1+l2-length)&&sgn(gy-b[i])>=0&&sgn(d[i]-gy)>=0) lst[lsts++]=l1;
		gx=c[i];
		gy=(ey-by)/(ex-bx)*(gx-bx)+by;
		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
		if (!sgn(l1+l2-length)&&sgn(gy-b[i])>=0&&sgn(d[i]-gy)>=0) lst[lsts++]=l1;
	}
	if (!sgn(ex-bx)&&sgn(a[i]-bx)<=0&&sgn(bx-c[i])<=0&&sgn(max(b[i],min(by,ey))-min(d[i],max(by,ey)))<=0)
	{
		gx=bx;
		gy=max(b[i],min(by,ey));
		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		lst[lsts++]=l1;
		gx=bx;
		gy=min(d[i],max(by,ey));
		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
		lst[lsts++]=l1;
	}
	if (sgn(bx-a[i])>=0&&sgn(c[i]-bx)>=0&&sgn(by-b[i])>=0&&sgn(d[i]-by)>=0)
		lst[lsts++]=0;
	if (sgn(ex-a[i])>=0&&sgn(c[i]-ex)>=0&&sgn(ey-b[i])>=0&&sgn(d[i]-ey)>=0)
		lst[lsts++]=length;
	for (int i=0;i<lsts;i++)
		for (int j=i+1;j<lsts;j++)
			if (!sgn(lst[i]-lst[j]))
				swap(lst[--lsts],lst[j--]);
	if (lsts<=1) x=0,y=0;
	else x=lst[0],y=lst[1];
	if (x>y) swap(x,y);
}

double calc()
{
	length=sqrt(sqr(bx-ex)+sqr(by-ey));
	lli len6=length*1e6;
	lli bs6[2000],es6[2000];
	rep(i,n)
	{
		calc(bs[i],es[i],i);
		bs6[i]=bs[i]*1e6,es6[i]=es[i]*1e6;
	}
	map<lli,int> mark;
	mark[-10000]=0;
	mark[len6+10000]=0;
	rep(i,n)
	{
		map<lli,int>::iterator it=mark.upper_bound(es6[i]+1);
		int c=(--it)->y;
		mark[es6[i]+1]=c;
		mark[bs6[i]]=t[i];
		for (map<lli,int>::iterator jt=mark.upper_bound(bs6[i]);jt->x!=es6[i]+1;mark.erase(jt++)) ;
	}
	lli ans6=0;
	for (map<lli,int>::iterator it=mark.begin(),jt=it++;;)
	{
		if (jt->y) ans6+=it->x-jt->x;
		jt=it++;
		if (it==mark.end()) break;
	}
	return double(ans6)/1e6;
}

int main()
{
	while (cin>>n>>m)
	{
		rep(i,n) cin>>t[i]>>a[i]>>b[i]>>c[i]>>d[i];
		double ans=0;
		cin>>bx>>by;
		repf(i,1,m)
		{
			cin>>ex>>ey;
			ans+=calc();
			bx=ex,by=ey;
		}
		if (sgn(ans)) printf("%.2f\n",ans);
		else puts("0.00");
	}
}
