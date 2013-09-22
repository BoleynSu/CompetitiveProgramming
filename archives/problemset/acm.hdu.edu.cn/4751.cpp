#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include <cmath>
#define mp make_pair
#define pb push_back
using namespace std;
bool g[20][20][2];
pair<int,int>p[200];
//const double pi=acos(-1);
typedef long long big;

const int N=120;
bool b[N][N],a[N][N];
int n;
int col[N],q[N];
bool check(int S)
{
    int i,s,h,tail;
    q[h=tail=1]=S;
    col[S]=0;
    while(h<=tail)
    {
        s=q[h++];
        for(i=1;i<=n;i++)
            if(a[s][i])
            {
                if(col[i]==-1)
                {
                    col[i]=1-col[s],q[++tail]=i;
                }
                else if(col[i]!=1-col[s])
                    return false;
            }
    }
    return true;
}
bool sol()
{
    int i;
    for(i=1;i<=n;i++)
        if(col[i]==-1)
            if(!check(i))return false;
    return true;
}
int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        memset(a,false,sizeof(a));
        memset(b,false,sizeof(b));
        for(i=1;i<=n;i++)
        {
            while(scanf("%d",&j),j)b[i][j]=true;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(i!=j)
            {
                a[i][j]=!b[i][j];
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j]|a[j][i];
        memset(col,-1,sizeof(col));
        if(sol())puts("YES");
        else puts("NO");
    }
}

