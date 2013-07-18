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
//typedef int g[4][4];
//g a[9];
//void read(g a)
//{
//	for (int i=0;i<4;i++)
//		for (int j=0;j<4;j++)
//			scanf("%d",&a[i][j]);
//}
//void write(g a)
//{
//	for (int i=0;i<4;i++)
//		for (int j=0;j<4;j++)
//			printf("%d%c",a[i][j],char(j==3?'\n':' '));
//}
//void rotate(g a)
//{
//	g t;
//	write(a);
//	for (int i=0;i<4;i++)
//		for (int j=0;j<4;j++)
//			t[j][3-i]=g[i][j];
//	memcpy(a,sizeof g,t);
//	write(a);
//}
//
//int main()
//{
//	read(a);
//	rotate(a);
//	//for (int i=0;i<9;i++) read(a[i]);
//
//}

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
//
//			tmp=a[x1][i];
//			a[x1][i]-=tmp;
//			a[x1+1][i]-=tmp;
//			a[x1][i+1]-=tmp;
//			a[x1+1][i]-=tmp;
//		}
//
//		if(a[x2][i]!=0 && a[x2][i+1]!=0)
//		{
//			b[x2-1][i]+=a[x2][i];
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
//
//

int main()
{
	lli n,m,N;
	cin>>n>>m>>N;
	lli M0=N*m/n;
	lli M1=min(N,N*m/n+1);
	if (M0>N-1-n+m) return cout<<M0<<endl,0;
	//cout<<(M0+1)*(N-M0+m-n)<<" "<<(M0-m+1)*(N-M0)<<endl;
	if ((M0+1)*(N-M0+m-n)>=(M0-m+1)*(N-M0)) cout<<M1<<endl;
	else cout<<M0<<endl;
}