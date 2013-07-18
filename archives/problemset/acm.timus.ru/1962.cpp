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

int n,m;
int k[102];
int g[102][102];
int in[102];
int ncnt;
int nlen[102];
int lcnt;
int llen[102];
int ccnt;
int clen[102];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&k[i]);
		if (g[i][k[i]]) continue;
		in[i]++;
		in[k[i]]++;
		g[i][k[i]]=g[k[i]][i]=true;
	}
	for (int i=1;i<=n;i++) if (in[i]>2) return cout<<0<<endl,0;
	for (int i=1;i<=n;i++) if (in[i]==0)
	{
		//cout<<"node"<<1<<endl;
		nlen[ncnt++]=1;
	}
	for (int i=1;i<=n;i++) if (in[i]==1)
	{
		int l=1;
		for (int u=i,v;in[u]!=0;u=v)
		{
			for (v=1;v<=n;v++) if (g[u][v])
			{
				l++;
				g[u][v]=g[v][u]=false;
				in[u]--,in[v]--;
				break;
			}
		}
		//cout<<"list"<<l<<endl;
		llen[lcnt++]=l;
	}
	for (int i=1;i<=n;i++) if (in[i]==2)
	{
		int l=0;
		for (int u=i,v;in[u]!=0;u=v)
		{
			for (v=1;v<=n;v++) if (g[u][v])
			{
				l++;
				g[u][v]=g[v][u]=false;
				in[u]--,in[v]--;
				break;
			}
		}
		//cout<<"circle"<<l<<endl;
		clen[ccnt++]=l;
	}
	if (n==2) cout<<1<<endl;
	else
	{
		if (ccnt>1) cout<<0<<endl;
		else if (ccnt==1)
		{
			if (clen[0]==n) cout<<2<<endl;
			else cout<<0<<endl;
		}
		else
		{
			lli MOD=1000000007;
			lli ans=1;
			for (lli i=1;i<=lcnt;i++) ans=ans*2%MOD;
			for (lli i=1;i<lcnt+ncnt;i++) ans=ans*i%MOD;
			cout<<ans<<endl;
		}
	}
}

//
//
//int a[111][111]={0};
//int b[55][55][55]={0};
//int n,m;
//
//void sol(int x1,int y1,int x2,int y2,int dep)
//{
//	if(x1>x2 || y1>y2)
//	{
//		return;
//	}
//
//	int i,tmp,j;
//	for(i=x1;i<=x2;i+=2)
//	{
//
//		if(a[i][y1]!=0 && a[i+1][y1]!=0)
//		{
//			for(j=a[i][y1];j>0;j--)
//				b[i][y1][dep-j-j+2]=1;
//			//b[i+1][y1+1]+=a[i][y1];
//
//			tmp=a[i][y1];
//			a[i][y1]-=tmp;
//			a[i+1][y1]-=tmp;
//			a[i][y1+1]-=tmp;
//			a[i+1][y1+1]-=tmp;
//		}
//		if(a[i][y2]!=0&& a[i+1][y2]!=0)
//		{
//
//			for(j=a[i][y2];j>0;j--)
//				b[i][y2-1][dep-j-j+2]=1;
//			//b[i+1][y2]+=a[i][y2];
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
////			b[x1][i]=dep+a[x1][i];
//
//			for(j=a[x1][i];j>0;j--)
//				b[x1][i][dep-j-j+2]=1;
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
////			b[x2-1][i]=dep+a[x2][i];
//			//b[x2][i+1]+=a[x2][i];
//
//			for(j=a[x2][i];j>0;j--)
//				b[x2-1][i][dep-j-j+2]=1;
//
//			tmp=a[x2][i];
//			a[x2][i]-=tmp;
//			a[x2-1][i]-=tmp;
//			a[x2][i+1]-=tmp;
//			a[x2-1][i+1]-=tmp;
//		}
//	}
//
////	for(i=1;i<=n;i++)
////	{
////		for(j=1;j<=m;j++)
////
////			{
////			printf("%d ",a[i][j]);
////			}
////		printf("\n");
////	}
////	printf("\n");
////	for(i=1;i<=n;i++)
////		{
////			for(j=1;j<=m;j++)
////
////				{
////				printf("%d ",b[i][j][dep]);
////				}
////			printf("\n");
////		}
////
////	printf("!!\n");
//
//	sol(x1+1,y1+1,x2-1,y2-1,dep+1);
//}
//
//void print(int x1,int y1,int x2,int y2,int dep)
//{
//	int i,j;
//	for(i=x1;i<=x2;i+=2)
//	{
//		for(j=y1;j<=y2;j+=2)
//		if(b[i][j][dep]>=1)
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
//	sol(1,1,n,m,1);
//	//printf("ok\n");
//	print(1,1,n,m,1);
//	return 0;
//}