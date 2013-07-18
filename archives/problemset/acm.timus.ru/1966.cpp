#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;

#define rep(i,n) for (int i=0;;i<int(n);i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef long long int lli;

const double eps=1e-9;
int sgn(double x)
{
	if(fabs(x)<eps)return 0;
	return x>0?1:-1;
}
struct P
{
	double x,y;
	P (){}
	P(double _x,double _y):x(_x),y(_y){}
	P operator-(const P &a)const
	{
		return P(x-a.x,y-a.y);
	}
};
struct seg
{
	int s,e;
};
seg b[300];
P a[300];
int fa[300],n,m;
int gf(int x)
{
	if(fa[x]!=x)fa[x]=gf(fa[x]);
	return fa[x];
}
double det(const P &a,const P &b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(const P &a,const P &b)
{
	return a.x*b.x+a.y*b.y;
}
double det(const P &S,const P &A,const P &B)
{
	return det(A-S,B-S);
}
bool on(const P &T,const P &A,const P &B)
{
	return !sgn(det(T-A,T-B))&&sgn(dot(A-T,B-T))<0;
}
bool check(const P &A,const P &B,const P &C,const P &D)
{
	if(on(A,C,D)||on(B,C,D)||on(C,A,B)||on(D,A,B))return true;
	return sgn(det(A,B,C))*sgn(det(A,B,D))<0&&sgn(det(C,D,A))*sgn(det(C,D,B))<0;
}
void sol()
{
	int i;
	for(i=2;i<=n;i++)
		if(gf(i)!=gf(1))
		{
			puts("NO");
			return ;
		}
	puts("YES");
}
int main()
{
	int i,j;
	P A,B,C,D;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y),fa[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].s,&b[i].e);
		fa[gf(b[i].s)]=gf(b[i].e);
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			C=a[j];
			A=a[b[i].s];B=a[b[i].e];
			if(on(C,A,B))fa[gf(j)]=gf(b[i].s);
		}
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
		{
			A=a[b[i].s];B=a[b[i].e];
			C=a[b[j].s];D=a[b[j].e];
			if(check(A,B,C,D))
			{
				fa[gf(b[i].s)]=gf(b[j].s);
			}
		}
	sol();

}
//
//int main()
//{
//	lli n,m,N;
//	cin>>n>>m>>N;
//	lli M0=N*m/n;
//	lli M1=min(N,N*m/n+1);
//	if (M1==N) return cout<<N<<endl,0;
//	if (M0==0) return cout<<0<<endl,0;
//	double a=log(M0)*m+log(N-M0)*(n-m);
//	double b=log(M1)*m+log(N-M1)*(n-m);
//	if (fabs(a-b)<1e-6) cout<<M1<<endl;
//	else if (a<b) cout<<M1<<endl;
//	else cout<<M0<<endl;
//}