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
//
//int a[111][111]={0};
//int b[111][111]={0};

struct P
{
	double x,y;
	P(){}
	P(double _x,double _y):x(_x),y(_y){}
	P operator-(const P &a)const
	{
		return P(x-a.x,y-a.y);
	}
	P operator+(const P &a)const
	{
		return P(x+a.x,y+a.y);
	}
	P operator/(const double d)const
	{
		return P(x/2.0,y/2.0);
	}
};
int sgn(double x)
{
	if(fabs(x)<eps)return 0;
	return x>0?1:-1;
}
P a[22],now[22];
const int n=4;
P rot(const P &a,const double ang)
{
	return P(a.x*cos(ang)-a.y*sin(ang),a.x*sin(ang)+a.y*cos(ang));
}
bool ck()
{
	int i;
	for(i=0;i<4;i++)
		printf("%f %f\n",now[i].x,now[i].y);
	puts("");
	for(i=0;i<2;i++)
	{
		if(sgn(now[i].x-now[3-i].x)||sgn(now[i].y+now[3-i].y))return false;

	}
	return true;
}
int main()
{
	P A,B,C,D,T1,T2,dir;
	int i,j;
	double ang;
	int ans=0;
	for(i=0;i<4;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	a[4]=a[0];
	a[5]=a[1];
	a[6]=a[2];
	a[7]=a[3];
	for(i=0;i<2;i++)
	{
		A=a[i];B=a[i+1];
		C=a[i+2];D=a[i+3];
		T1=(A+B)/2.0;
		T2=(C+D)/2.0;;
		dir=T2-T1;
		ang=atan2(dir.y,dir.x);
		for(j=0;j<4;j++)
		{
			now[j]=a[j]-T1;
			now[j]=rot(now[j],-ang);
		}
		for(j=0;j<4;j++)
			now[j+4]=now[j];
		if(!sgn(now[i].x-now[i+1].x)&&!sgn(now[i].y+now[i+1].y)
				&&!sgn(now[i+2].x-now[i+3].x)&&!sgn(now[i+2].y+now[i+3].y))ans+=2;

		T1=a[i];T2=a[i+2];
		dir=T2-T1;
		ang=atan2(dir.y,dir.x);
		for(j=0;j<4;j++)
		{
			now[j]=a[j]-T1;
			now[j]=rot(now[j],-ang);
		}
		for(j=0;j<4;j++)
			now[j+4]=now[j];
		if(!sgn(now[i+1].x-now[i+3].x)&&!sgn(now[i+1].y+now[i+3].y))ans+=2;
	}
	printf("%d\n",ans);
}

//void sol(int x1,int y1,int x2,int y2)
//{
//	if(x1==x2 || y1==y2)
//	{
//		return;
//	}
//
//	int i,j;
//	for(i=x1;i<=x2;i+=2)
//	{
//
//		if(a[i][y1]!=0 && a[i+1][y1]!=0)
//		{
//			a[i][y1]=0;
//			a[i+1][y1]=0;
//			a[i][y1+1]=0;
//			a[i+1][y1+1]=0;
//		}
//		if(a[i][y2]!=0&& a[i+1][y2]!=0)
//		{
//			a[i][y2]=0;
//			a[i+1][y2]=0;
//			a[i][y2-1]--;
//			a[i+1][y2-1]--;
//		}
//	}
//
//	for(i=y1;i<=y2;i+=2)
//	{
//		if(a[x1][i]!=0 && a[x1][i+1]!=0)
//		{
//			a[x1][i]--;
//			a[x1+1][i]--;
//			a[x1][i+1]--;
//			a[x1+1][i]--;
//		}
//
//		if(a[x2][i]!=0 && a[x2][i+1]!=0)
//		{
//			a[x2][i]--;
//			a[x2-1][i]--;
//			a[x2][i+1]--;
//			a[x2-1][i+1]--;
//		}
//	}
//	//
//void sol(int x1,int y1,int x2,int y2)
//{
//	if(x1==x2 || y1==y2)
//	{
//		return;
//	}
//
//	int i,j;
//	for(i=x1;i<=x2;i+=2)
//	{
//
//		if(a[i][y1]==1 && a[i+1][y1]==1)
//		{
//			a[i][y1]--;
//			a[i+1][y1]--;
//			a[i][y1+1]--;
//			a[i+1][y1+1]--;
//		}
//		if(a[i][y2]==1&& a[i+1][y2]==1)
//		{
//			a[i][y2]--;
//			a[i+1][y2]--;
//			a[i][y2-1]--;
//			a[i+1][y2-1]--;
//		}
//	}
//
//	for(i=y1;i<=y2;i+=2)
//	{
//		if(a[x1][i]==1 && a[x1][i+1]==1)
//		{
//			a[x1][i]--;
//			a[x1+1][i]--;
//			a[x1][i+1]--;
//			a[x1+1][i]--;
//		}
//
//		if(a[x2][i]==1 && a[x2][i+1]==1)
//		{
//			a[x2][i]--;
//			a[x2-1][i]--;
//			a[x2][i+1]--;
//			a[x2-1][i+1]--;
//		}
//	}
//
//	sol(x1+1,y1+1,x2-1,y2-1);
//}
//
//int main()
//{
//	cin>>n>>m;
//	for(i=1;i<=n;i++)
//	for(j=1;j<=m;j++)
//		cin>>a[i][j];
//
//	sol(1,1,n,m);
//
//}
//	sol(x1+1,y1+1,x2-1,y2-1);
//}
//
//int main()
//{
//	cin>>n>>m;
//	for(i=1;i<=n;i++)
//	for(j=1;j<=m;j++)
//		cin>>a[i][j];
//
//	sol(1,1,n,m);
//
//}
//

//int main()
//{
//	lli n,m,N;
//	cin>>n>>m>>N;
//	lli M0=N*m/n;
//	lli M1=min(N,N*m/n+1);
//	if (M1==N) return cout<<M1<<endl,0;
//	//cout<<(M0+1)*(N-M0+m-n)<<" "<<(M0-m+1)*(N-M0)<<endl;
//	if ((M0+1)*(N-M0+m-n)>=(M0-m+1)*(N-M0)) cout<<M1<<endl;
//	else cout<<M0<<endl;
//}