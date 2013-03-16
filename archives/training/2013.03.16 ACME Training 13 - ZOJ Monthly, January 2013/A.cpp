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

//int n,m;
//int t[200];
//double a[200],b[200],c[200],d[200];
//double bx,by,ex,ey;
//double length;
//double bs[2000],es[2000];
//
//const double eps=1e-8;
//int sgn(double x)
//{
//	return (x>eps)-(x<-eps);
//}
//
//void calc(double& x,double& y,int i)
//{
//	int lsts=0;
//	double lst[4],gy,gx;
//	if ((sgn(b[i]-by)||sgn(b[i]-ey))&&sgn(ey-by))
//	{
//		gy=b[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=(ex-bx)/(ey-by)*(gy-by)+bx;
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//	if (!(sgn(b[i]-by)||sgn(b[i]-ey))&&!sgn(ey-by))
//	{
//		gy=b[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=max(a[i],min(bx,ex));
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//		gy=b[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=min(c[i],max(bx,ex));
//		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//
//	if ((sgn(d[i]-by)||sgn(d[i]-ey))&&sgn(ey-by))
//	{
//		gy=d[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=(ex-bx)/(ey-by)*(gy-by)+bx;
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//	if (!(sgn(d[i]-by)||sgn(d[i]-ey))&&!sgn(ey-by))
//	{
//		gy=d[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=max(a[i],min(bx,ex));
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//		gy=d[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gx=min(c[i],max(bx,ex));
//		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//
//	if ((sgn(a[i]-bx)||sgn(a[i]-ex))&&sgn(ex-bx))
//	{
//		gx=a[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=(ey-by)/(ex-bx)*(gx-bx)+by;
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//	if (!(sgn(a[i]-bx)||sgn(a[i]-ex))&&!sgn(ex-bx))
//	{
//		gx=a[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=max(b[i],min(by,ey));
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//		gx=a[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=min(d[i],max(by,ey));
//		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//
//	if ((sgn(c[i]-bx)||sgn(c[i]-ex))&&sgn(ex-bx))
//	{
//		gx=c[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=(ey-by)/(ex-bx)*(gx-bx)+by;
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//	if (!(sgn(c[i]-bx)||sgn(c[i]-ex))&&!sgn(ex-bx))
//	{
//		gx=c[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=max(b[i],min(by,ey));
//		double l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		double l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//		gx=c[i];
//		//(gy-by)/(gx-bx)=(ey-by)/(ex-bx);
//		gy=min(d[i],max(by,ey));
//		l1=sqrt(sqr(bx-gx)+sqr(by-gy));
//		l2=sqrt(sqr(ex-gx)+sqr(ey-gy));
//		//cout<<l1<<" "<<l2<<" "<<length<<endl;
//		if (!sgn(l1+l2-length)) lst[lsts++]=l1;
//	}
//	for (int i=0;i<lsts;i++) cout<<lst[i]<<endl;
//	for (int i=0;i<lsts;i++)
//		for (int j=i+1;j<lsts;j++)
//		{
//			if (!sgn(lst[i]-lst[j]))
//			{
//				swap(lst[lsts-1],lst[j]);
//				lsts--;
//			}
//		}
//	x=lst[0],y=lst[1];
//	cout<<x<<" "<<y<<":"<<lsts<<endl;
//	if (x>y) swap(x,y);
//}
//
//double calc()
//{
//	length=sqrt(sqr(bx-ex)+sqr(by-ey));
//	lli len6=length*1000000;
//	lli bs6[2000],es6[2000];
//	rep(i,m)
//	{
//		calc(bs[i],es[i],i);
//		bs6[i]=bs[i]*1000000,es6[i]=es[i]*1000000;
//		//cout<<bs[i]<<" "<<es[i]<<endl;
//	}
//	map<lli,int> mark;
//	mark[0]=0;
//	mark[len6+1]=0;
//	rep(i,m)
//	{
//		for (map<lli,int>::iterator it=mark.lower_bound(bs6[i]),tmp;;)
//		{
//			if (it->x>es6[i])
//			{
//				tmp=--it;
//				mark[es6[i]+1]=tmp->y;
//				//cout<<es[i]<<":"<<tmp->y<<endl;
//				break;
//			}
//			if (it->x<=es6[i]) tmp=it,it++;
//			if (it->x>es6[i])
//			{
//				mark[es6[i]+1]=tmp->y;
//				//cout<<es[i]<<":"<<tmp->y<<endl;
//				break;
//			}
//			mark.erase(tmp);
//		}
//		mark[bs6[i]]=t[i];
//	}
//	lli ans6=0;
//	for (map<lli,int>::iterator it=mark.begin(),jt=it++;;)
//	{
//		if (jt->y) ans6+=it->x-jt->x;
//		//cout<<ans6<<":"<<it->x<<","<<jt->x<<endl;
//		jt=it++;
//		if (it==mark.end()) break;
//	}
//	return double(ans6)/1e6;
//}
//
//int main()
//{
//	while (cin>>n>>m)
//	{
//		rep(i,m) cin>>t[i]>>a[i]>>c[i]>>b[i]>>d[i];
//		double ans=0;
//		cin>>bx>>by;
//		repf(i,1,n)
//		{
//			cin>>ex>>ey;
//			ans+=calc();
//			bx=ex,by=ey;
//		}
//		printf("%.2f\n",ans);
//	}
//}

pair<int,int> lst[200000];
int sumq[200000],sump[200000];
int q[200000],p[200000];

int main()
{
	int n,t;
	while (scanf("%d%d",&n,&t)!=EOF)
	{
		rep(i,n) {scanf("%d%d",&q[i],&p[i]);
		lst[i].x=q[i]-p[i];
		lst[i].y=i;}
		sort(lst,lst+n);
		sump[0]=p[lst[0].y];
		repf(i,1,n) sump[i]=sump[i-1]+p[lst[i].y];
		sumq[n-1]=q[lst[n-1].y];
		for (int i=n-2;i>=0;i--) sumq[i]=sumq[i+1]+q[lst[i].y];
		rep(i,t)
		{
			int m;
			scanf("%d",&m);
			int idx=upper_bound(lst,lst+n,pair<int,int>(-m,-19930309))-lst;
			lli ans=(idx?sump[idx-1]:0)-lli(m)*(idx)+(idx==n?0:sumq[idx]);
			printf("%d\n",int(ans));
		}
	}
}
