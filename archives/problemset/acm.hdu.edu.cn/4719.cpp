#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
const double eps=1e-5;
const int oo=(~0u)>>1;
inline double sqr(double x){return x*x;}
typedef long long int lli;
const lli ooll=(1ll<<60);

const int MAXN=100000+2;
int N,L;
pair<int,int> h[MAXN];
int H[MAXN];
lli f[MAXN];
#define idx(l,r) (((l)+(r))|((l)!=(r)))
#define rt st[idx(l,r)]
#define lc st[idx(l,m)]
#define rc st[idx(m+1,r)]
lli st[(MAXN<<1)-1];
void upd(int l,int r,int p,lli fi)
{
    if (p<l||p>r) ;
    else if (p<=l&&r<=p)
    {
        if (rt<fi) rt=fi;
    }
    else
    {
        int m=(l+r)>>1;
        upd(l,m,p,fi),upd(m+1,r,p,fi);
        rt=max(lc,rc);
    }
}
lli qry(int l,int r,int L,int R)
{
    if (R<l||r<L) return -ooll;
    else if (L<=l&&r<=R)
    {
        return rt;
    }
    else
    {
        int m=(l+r)>>1;
        return max(qry(l,m,L,R),qry(m+1,r,L,R));
    }
}

bool is[256];
void read(int& x)
{
    char c;
    while (!is[(int)(c=getchar())]);
    x=c-'0';
    while (is[(int)(c=getchar())]) x=x*10+c-'0';
}

int main()
{
    for (int i='0';i<='9';i++) is[i]=true;
    int T;
    read(T);
    for (int t=1;t<=T;t++)
    {
        read(N),read(L);
        for (int i=1;i<=N;i++)
        {
            read(h[i].x);
            h[i].y=-i;
            H[i]=h[i].x;
        }
        for (int i=0;i<=N*2+1;i++) st[i]=-ooll;
        sort(h+1,h+N+1);
        upd(0,N,0,0);
        for (int i=1;i<=N;i++)
        {
            f[-h[i].y]=qry(0,N,-h[i].y-L,-h[i].y)+lli(h[i].x)*lli(h[i].x-1);
            upd(0,N,-h[i].y,f[-h[i].y]);
        }
        lli ans=f[N]+H[N];
        if (ans<=-ooll/2) printf("Case #%d: No solution\n",t);
        else printf("Case #%d: %I64d\n",t,ans);
    }
}
