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

struct T
{
	int a[4][4];
	void input()
	{
		int i,j;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a[i][j]);
	}
	void output()
	{

		int i,j;
		for(i=0;i<4;i++,puts(""))
			for(j=0;j<4;j++)
				printf("%d ",a[i][j]);
	}
};
T a[9];
int g[10][10];
bool flag=false;
bool vis[10];
T tmp;
void rot(T &a)
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			tmp.a[i][j]=a.a[3-j][i];
	a=tmp;
}
void pri()
{
	int i,j;
	for(i=0;i<10;i++,puts(""))
		for(j=0;j<10;j++)
			printf("%d ",g[i][j]);
	puts("#");
}
void dfs(int dep)
{
	if(flag)return ;
	if(dep==9)
	{
		int i,j;
		for(i=0;i<10;i++,puts(""))
			for(j=0;j<10;j++)
				printf("%d ",g[i][j]);
		flag=true;
		return ;
	}
	int x=dep/3,y=dep%3;
	int i,k,j,t1,t2;
	bool ff;
	for(i=0;i<9;i++)
		if(!vis[i])
		{
			vis[i]=true;
			for(k=0;k<4;k++)
			{
				rot(a[i]);
				ff=true;
				if(x)
				{
					for(j=0;j<4;j++)
						if(g[x*3][y*3+j]!=a[i].a[0][j])
							ff=false;
				}
				if(y&&ff)
				{
					for(j=0;j<4;j++)
						if(g[x*3+j][y*3]!=a[i].a[j][0])
							ff=false;
				}
				if(ff)
				{
					for(t1=!x?0:1;t1<4;t1++)
					for(t2=!y?0:1;t2<4;t2++)
						g[t1+x*3][t2+y*3]=a[i].a[t1][t2];
					dfs(dep+1);
				}
			}
			vis[i]=false;
		}
}
int main()
{
	int i;
	for(i=0;i<9;i++)
		a[i].input();
	dfs(0);
}
//
//
//int a[111][111]={0};
//int b[111][111]={0};
//int n,m;
//
//void sol(int x1,int y1,int x2,int y2)
//{
//	if(x1>x2 || y1>y2)
//	{
//		return;
//	}
//
//	int i,tmp;
//	for(i=x1;i<=x2;i+=2)
//	{
//
//		if(a[i][y1]!=0 && a[i+1][y1]!=0)
//		{
//			b[i][y1]+=a[i][y1];
//			b[i+1][y1+1]+=a[i][y1];
//
//			tmp=a[i][y1];
//			a[i][y1]-=tmp;
//			a[i+1][y1]-=tmp;
//			a[i][y1+1]-=tmp;
//			a[i+1][y1+1]-=tmp;
//		}
//		if(a[i][y2]!=0&& a[i+1][y2]!=0)
//		{
//			b[i][y2-1]+=a[i][y2];
//			b[i+1][y2]+=a[i][y2];
//
//			tmp=a[i][y2];
//			a[i][y2]-=tmp;
//			a[i+1][y2]-=tmp;
//			a[i][y2-1]-=tmp;
//			a[i+1][y2-1]-=tmp;
//		}
//	}
//
//	for(i=y1;i<=y2;i+=2)
//	{
//		if(a[x1][i]!=0 && a[x1][i+1]!=0)
//		{
//			b[x1][i]+=a[x1][i];
//			b[x1+1][i+1]+=a[x1][i];
//
//			tmp=a[x1][i];
//
//			a[x1][i]-=tmp;
//			a[x1+1][i]-=tmp;
//
//			a[x1][i+1]-=tmp;
//			a[x1+1][i+1]-=tmp;
//		}
//
//		if(a[x2][i]!=0 && a[x2][i+1]!=0)
//		{
//			b[x2-1][i]+=a[x2][i];
//			b[x2][i+1]+=a[x2][i];
//
//			tmp=a[x2][i];
//			a[x2][i]-=tmp;
//			a[x2-1][i]-=tmp;
//			a[x2][i+1]-=tmp;
//			a[x2-1][i+1]-=tmp;
//		}
//	}
//	int j;
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=m;j++)
//
//			{
//			printf("%d ",a[i][j]);
//			}
//		printf("\n");
//	}
//	printf("\n");
//	for(i=1;i<=n;i++)
//		{
//			for(j=1;j<=m;j++)
//
//				{
//				printf("%d ",b[i][j]);
//				}
//			printf("\n");
//		}
//
//	printf("!!\n");
//
//	sol(x1+1,y1+1,x2-1,y2-1);
//}
//
//void print(int x1,int y1,int x2,int y2,int dep)
//{
//	int i,j;
//	for(i=x1;i<=x2;i+=2)
//	{
//		for(j=y1;j<=y2;j+=2)
//		if(b[i][j]>=dep)
//			printf("R");
//		else
//			printf("W");
//		printf("\n");
//	}
//	if(x2!=x1+1 && y2!=y1+1)
//	{
//		printf("\n");
//		print(x1+1,y1+1,x2-1,y2-1,dep+1);
//	}
//}
//
//
//int main()
//{
//	int i,j;
//	cin>>n>>m;
//	for(i=1;i<=n;i++)
//	for(j=1;j<=m;j++)
//		cin>>a[i][j];
//
//	sol(1,1,n,m);
//	//printf("ok\n");
//	print(1,1,n,m,1);
//	return 0;
//}