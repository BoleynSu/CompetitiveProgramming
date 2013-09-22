#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long int lli;
#define mp make_pair
#define sz(x) (int((x).size()))

//const int MAXN=100000;
//int N,C;
//int val[MAXN],is[MAXN];
//vector<int> adj[MAXN];
//map<pair<pair<int,int>,int>,lli> f;
//
//lli dp(int u,int p,int c)
//{
//    if (!f.count(mp(mp(u,p),c)))
//    {
//        lli& ans=f[mp(mp(u,p),c)];
//        ans=val[u];
//        if (c>is[u])
//        {
//            for (int i=0;i<sz(adj[u]);i++)
//            {
//                int v=adj[u][i];
//                if (v!=p)
//                {
//                    if (ans<dp(v,u,c-is[u])+val[u])
//                        ans=dp(v,u,c-is[u])+val[u];
//                }
//            }
//        }
//    }
//    //cout<<u<<p<<c<<":"<<f[mp(mp(u,p),c)]<<endl;
//    return f[mp(mp(u,p),c)];
//}
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while (T--)
//    {
//        scanf("%d%d",&N,&C);
//        for (int i=0;i<N;i++) scanf("%d%d",&val[i],&is[i]);
//        for (int i=1;i<N;i++)
//        {
//            int a,b;
//            scanf("%d%d",&a,&b);
//            adj[a].push_back(b);
//            adj[b].push_back(a);
//        }
//        lli ans=0;
//        for (int i=0;i<N;i++)
//        {
//            //cout<<dp(i,-1,C)<<endl;
//            if (ans<dp(i,-1,C)) ans=dp(i,-1,C);
//        }
//        cout<<ans<<endl;
//        for (int i=0;i<N;i++) adj[i].clear();
//        f.clear();
//    }
//}


const int N=50200;
struct node
{
    int size,s,l,r;
    node *c[2];
}mem[N*2];
node *root,*cur;
int n,m;
int L,R;
inline void pushdown(node *x)
{
    if(x->size==x->s)
    {
        x->c[0]->s=x->c[0]->size;
        x->c[1]->s=x->c[1]->size;
    }
    else if(!x->s)
    {
        x->c[0]->s=0;
        x->c[1]->s=0;
    }
}
inline void update(node *x)
{
    x->s=x->c[0]->s+x->c[1]->s;
}
node *init(int l,int r)
{
    node *p=cur++;
    p->l=l;p->r=r;
    p->size=r-l+1;
    p->s=0;
    if(l==r)return p;
    int mid=l+r>>1;
    p->c[0]=init(l,mid);
    p->c[1]=init(mid+1,r);
    return p;
}
int get(node *x,int l,int r)
{
    if(l<=x->l&&x->r<=r)
        return x->s;
    pushdown(x);
    int mid=x->l+x->r>>1,s=0;
    if(l<=mid)s+=get(x->c[0],l,r);
    if(r>mid)s+=get(x->c[1],l,r);
    update(x);
    return s;
}
int query(int pos)
{
    int s,e,mid;
    s=pos,e=n;
    while(s<=e)
    {
        mid=s+e>>1;
        if(get(root,pos,mid)<mid-pos+1)e=mid-1;
        else s=mid+1;
    }
    if(s>n)return -1;
    return s;
}
void change(node *x,int l,int r,int c)
{
    if(l<=x->l&&x->r<=r)
    {
//        L=min(L,x->l);
//        R=max(R,x->r);
        x->s=c*x->size;
        return ;
    }
    pushdown(x);
    int mid=x->l+x->r>>1;
    if(l<=mid)change(x->c[0],l,r,c);
    if(r>mid)change(x->c[1],l,r,c);
    update(x);
}
int main()
{
    int t1,t2;
    int cas,a,b,c,s,e,mid,bf;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        cur=mem;
        root=init(1,n);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            b++;
            if(a==1)
            {
                t1=query(b);
                c=min(c,n-b+1-get(root,b,n));
                if(!c)puts("Can not put any one.");
                else
                {
                    s=b;e=n;
                    while(s<=e)
                    {
                        mid=s+e>>1;
                        if(get(root,b,mid)+c<=mid-b+1)e=mid-1;
                        else s=mid+1;
                    }
                    s=min(s,n);
                    L=n+1;R=-1;
                    change(root,b,s,1);t2=s;
                    printf("%d %d\n",t1-1,t2-1);
                }
            }
            else
            {
                c++;
                printf("%d\n",get(root,b,c));
                change(root,b,c,0);
            }
        }
        puts("");
    }
}
