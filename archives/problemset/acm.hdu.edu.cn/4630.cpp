#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define rep(i,n) for (int i=0;i<(n);i++)
#define sz(x) (int((x).size()))
const double eps=1e-9;
typedef long long int lli;

const int MAXN=50013;
int T;
int n;
int a[MAXN];
int Q;
int l[MAXN],r[MAXN];
vector<int> fac[MAXN];
vector<pair<int,int> > lst[MAXN];
int last[MAXN];
int ans[MAXN];
int st[MAXN];
void upd(int p,int v)
{
    for (int i=p;i<MAXN;i+=i&(-i))
        if (st[i]<v) st[i]=v;
}
int qry(int p)
{
    int ans=0;
    for (int i=p;i;i-=i&(-i))
        if (ans<st[i]) ans=st[i];
    return ans;
}

int main()
{
    for (int f=1;f<MAXN;f++)
        for (int j=f;j<MAXN;j+=f)
            fac[j].pb(f);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&Q);
        for (int i=0;i<Q;i++)
            scanf("%d%d",&l[i],&r[i]),--l[i],--r[i];
        for (int i=0;i<n;i++) lst[i].clear();
        for (int i=0;i<Q;i++) lst[r[i]].pb(mp(l[i],i));
        memset(st,0,sizeof st);
        memset(last,-1,sizeof last);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<sz(fac[a[i]]);j++)
            {
                upd(n-last[fac[a[i]][j]],fac[a[i]][j]);
                last[fac[a[i]][j]]=i;
            }
            for (int j=0;j<sz(lst[i]);j++) ans[lst[i][j].y]=qry(n-lst[i][j].x);
        }
        for (int i=0;i<Q;i++)
            printf("%d\n",ans[i]);
    }
}

