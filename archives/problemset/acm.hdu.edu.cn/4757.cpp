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
typedef pair<int,int> pii;


const int N=102000;
struct node
{
    int s;
    node *c[2];
}mem[N*20],*nul,*cur,*tr[N];
int val[N];
int q[N],head[N],nxt[N*2],v[N*2],t=1;
int pre[N][19],dep[N];
int n,m;
inline void add(int x,int y)
{
    nxt[++t]=head[x];v[t]=y;head[x]=t;
    nxt[++t]=head[y];v[t]=x;head[y]=t;
}

node *ins(int x,node *base)
{
    static int c,i;
    static node *now,*root;
    now=root=++cur;
    for(i=15;i>=0;i--)
    {
        c=x>>i&1;
        now->c[!c]=base->c[!c];
        now->c[c]=++cur;now->c[c]->c[0]=now->c[c]->c[1]=nul;
        now->s=base->s+1;
        now=now->c[c];
        base=base->c[c];
    }
    now->s=base->s+1;
    return root;
}
void bfs()
{
    int s,i,h,tail;
    q[h=tail=1]=1;
    pre[1][0]=-1;
    dep[1]=0;
    tr[0]=nul;
    tr[1]=ins(val[1],tr[0]);
    while(h<=tail)
    {
        s=q[h++];
        for(i=head[s];i;i=nxt[i])
            if(pre[s][0]!=v[i])
            {
                tr[v[i]]=ins(val[v[i]],tr[s]);
                pre[v[i]][0]=s;
                dep[v[i]]=dep[s]+1;
                q[++tail]=v[i];
            }
    }
    pre[1][0]=0;
    int j;
    for(j=1;j<=18;j++)
        for(i=1;i<=n;i++)
            pre[i][j]=pre[pre[i][j-1]][j-1];
}
int lca(int x,int y)
{
    int i;
    if(dep[x]<dep[y])swap(x,y);
    for(i=18;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=pre[x][i];
    if(x==y)return x;
    for(i=18;i>=0;i--)
        if(pre[x][i]&&pre[y][i]&&pre[x][i]!=pre[y][i])
            x=pre[x][i],y=pre[y][i];
    return pre[x][0];
}
int query(int x,int y,int z)
{
    int p=lca(x,y);
    static node *a,*b,*c,*d;
    int idx,res=0,i;
    a=tr[x];b=tr[y];c=tr[p];d=tr[pre[p][0]];
    for(i=15;i>=0;i--)
    {
        idx=!(z>>i&1);
        if(a->c[idx]->s+b->c[idx]->s-c->c[idx]->s-d->c[idx]->s>0)
            res+=1<<i,a=a->c[idx],b=b->c[idx],c=c->c[idx],d=d->c[idx];
        else a=a->c[!idx],b=b->c[!idx],c=c->c[!idx],d=d->c[!idx];
    }
    return res;
}
int main()
{
    int i,x,y,z;
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,0,sizeof(head));
        t=1;
        nul=mem;cur=mem+1;
        nul->c[0]=nul->c[1]=nul;
        nul->s=0;
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=1;i<n;i++)
            scanf("%d%d",&x,&y),add(x,y);
        bfs();

        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query(x,y,z));
        }
    }
}
