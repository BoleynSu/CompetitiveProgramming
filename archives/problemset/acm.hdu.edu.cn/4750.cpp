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
const double pi=acos(-1);
typedef long long big;

const int N=10020,M=500020;
struct E
{
    int a,b,c;
    bool operator<(const E &t)const
    {
        return c<t.c;
    }
}e[M];


int n,m;
int fa[N],s[N],slx[M];
big sum[M];
int gf(int x)
{
    if(fa[x]!=x)fa[x]=gf(fa[x]);
    return fa[x];
}
int fd(int x)
{
    static int st,ed,mid;
    st=1;ed=m;
    while(st<=ed)
    {
        mid=st+ed>>1;
        if(e[mid].c<x)st=mid+1;
        else ed=mid-1;
    }
    return ed;
}
int main()
{
    int i,x,y,p;
    big now,all,tmp;
    while(~scanf("%d%d",&n,&m))
    {
        now=0;
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),e[i].a++,e[i].b++;
        sort(e+1,e+1+m);
        for(i=1;i<=n;i++)
            fa[i]=i,s[i]=1;
        for(i=1;i<=m;i++)
        {
            x=gf(e[i].a);y=gf(e[i].b);
            if(x!=y)
            {
                now+=1ll*s[x]*s[y]*2;
                s[y]+=s[x];
                fa[x]=y;
            }
            sum[i]=now;
        }
        all=1ll*(n)*(n-1);
        sum[m+1]=sum[m];
        scanf("%d",&p);
        while(p--)
        {
            scanf("%d",&x);
            x=fd(x);
//            printf("%d!\n",x);
            tmp=sum[x];
            printf("%I64d\n",all-tmp);
        }
    }
}
