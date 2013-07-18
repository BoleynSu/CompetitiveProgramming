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
int a[100][100];
int p[100][100][100];


int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for (int dep=0;;dep++)
	{
		int bx=dep,ex=n-dep;
		int by=dep,ey=m-dep;
		int nbx=bx+1,nex=ex-1,nby=by+1,ney=ey-1;
		if (bx<ex&&by<ey)
		{
			for (int i=bx;i<ex;i+=2)
				for (int j=by;j<ey;j+=2)
				{
					int cnt=0;
					for (int x=i;x<i+2;x++)
						for (int y=j;y<j+2;y++)
							if (!(nbx<=x&&x<nex&&nby<=y&&y<ney))
								cnt=max(cnt,a[x][y]);
					for (int x=i;x<i+2;x++)
						for (int y=j;y<j+2;y++)
						{
							a[x][y]-=cnt;
							for (int d=dep%2,c=cnt;c;d+=2)
								if (!p[d][x][y])
									p[d][x][y]=1,c--;
						}
				}
		}
		else break;
	}
	for (int dep=0;;dep++)
	{
		int bx=dep,ex=n-dep;
		int by=dep,ey=m-dep;
		if (bx<ex&&by<ey)
		{
//			for (int x=bx;x<ex;x++)
//				for (int y=by;y<ey;y++)
//					cout<<p[dep][x][y]<<char(y+1==ey?'\n':' ');
			for (int i=bx;i<ex;i+=2)
			{
				for (int j=by;j<ey;j+=2)
					if (p[dep][i][j]) cout<<char('R');
					else cout<<char('W');
				cout<<endl;
			}
			cout<<endl;
		}
		else break;
	}
}