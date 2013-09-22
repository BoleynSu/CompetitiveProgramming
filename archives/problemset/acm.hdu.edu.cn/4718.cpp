#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
const double eps=1e-5;
const int oo=(~0u)>>1;
inline double sqr(double x){return x*x;}


const int N=102000;
struct node
{
    node *c[2],*fa;
    int v,lv,rv,lf,rf,lg,rg,f,g,size;
    bool dir(){return fa->c[1]==this;}
    inline bool isroot(){return fa->c[0]!=this&&fa->c[1]!=this;}
    inline void set(node *x,bool d);
}*nul,mem[N],*cur;
void node::set(node *x,bool d){if(this!=nul)c[d]=x;if(x!=nul)x->fa=this;}
inline void update(node *x)
{
    if(x==nul)return ;
    x->lv=x->rv=x->v;
    if(x->c[0]!=nul)x->lv=x->c[0]->lv;
    if(x->c[1]!=nul)x->rv=x->c[1]->rv;

    x->lf=x->lg=x->rf=x->rg=x->f=x->g=1;
    if(x->c[0]->rv<x->v)x->f+=x->c[0]->rf;
    if(x->v<x->c[1]->lv)x->f+=x->c[1]->lf;

    if(x->c[0]->rv>x->v)x->g+=x->c[0]->rg;
    if(x->v>x->c[1]->lv)x->g+=x->c[1]->lg;

    x->size=x->c[0]->size+x->c[1]->size+1;

    if(x->c[0]->lf==x->c[0]->size&&x->c[0]->rv<x->v||x->c[0]==nul)
    {
        x->lf=x->c[0]->size+1;
        if(x->v<x->c[1]->lv)x->lf+=x->c[1]->lf;
    }

    if(x->c[0]->lg==x->c[0]->size&&x->c[0]->rv>x->v||x->c[0]==nul)
    {
        x->lg=x->c[0]->size+1;
        if(x->v>x->c[1]->lv)x->lg+=x->c[1]->lg;
    }

    if(x->c[1]->rf==x->c[1]->size&&x->c[1]->lv>x->v||x->c[1]==nul)
    {
        x->rf=x->c[1]->size+1;
        if(x->v>x->c[0]->rv)x->rf+=x->c[0]->rf;
    }

    if(x->c[1]->rg==x->c[1]->size&&x->c[1]->lv<x->v||x->c[1]==nul)
    {
        x->rg=x->c[1]->size+1;
        if(x->v<x->c[0]->rv)x->rg+=x->c[0]->rg;
    }


    x->lf=max(x->lf,x->c[0]->lf);
    x->lg=max(x->lg,x->c[0]->lg);
    x->rf=max(x->rf,x->c[1]->rf);
    x->rg=max(x->rg,x->c[1]->rg);


    x->f=max(x->f,x->c[0]->f);
    x->f=max(x->f,x->c[1]->f);
    x->g=max(x->g,x->c[0]->g);
    x->g=max(x->g,x->c[1]->g);

    x->f=max(x->f,x->lf);
    x->f=max(x->f,x->rf);
    x->g=max(x->g,x->lg);
    x->g=max(x->g,x->rg);
}
void rot(node *x)
{
    static node *y;y=x->fa;
    static bool d;d=x->dir();
    if(y->fa->c[0]==y)y->fa->c[0]=x;
    if(y->fa->c[1]==y)y->fa->c[1]=x;
    x->fa=y->fa;
    y->set(x->c[!d],d);
    x->set(y,!d);
    update(y);
}
void splay(node *x)
{
    static node *t;
    while(!(x->isroot()))
    {
        if(x->fa->isroot())rot(x);
        else
        {
            if(x->dir()==x->fa->dir())rot(x->fa);
            else rot(x);
            rot(x);
        }
    }
    update(x);
}
node *access(node *u)
{
    static node *v;
    for(v=nul;u!=nul;v=u,u=u->fa)
    {
        splay(u);
        u->c[1]=v;
        update(u);
    }
    return v;
}
void getans(node *x,node *y,node *z)
{
    int ans=1;
    ans=max(ans,y->g);
    ans=max(ans,z->f);
    ans=max(ans,1+(y->lv<x->v)*y->lg+(z->lv>x->v)*z->lf);
    printf("%d\n",ans);
}
void query(node *x,node *y)
{
    node *v,*u=y;
    access(x);
    for(v=nul;u!=nul;u=u->fa)
    {
        splay(u);
        if(u->fa==nul)
        {
            getans(u,u->c[1],v);
        }
        u->c[1]=v;
        update(v=u);
    }
}
int main()
{
    int cas,cass,n,i,x,m,y;
    scanf("%d",&cas);
    for(cass=1;cass<=cas;cass++)
    {
        if(cass>1)puts("");
        printf("Case #%d:\n",cass);
        scanf("%d",&n);
        nul=mem;
        node *s;
        nul->c[0]=nul->c[1]=nul->fa=nul;
        for(i=1;i<=n;i++)
        {
            s=mem+i;
            scanf("%d",&x);
            (mem+i)->v=(mem+i)->lv=(mem+i)->rv=x;
            s->f=s->g=s->lf=s->lg=s->rf=s->rg=s->size=1;
            s->c[0]=s->c[1]=s->fa=nul;
        }
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            (mem+i)->fa=(mem+x);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            if(x==y)puts("1");
            else query((mem+x),(mem+y));
        }
    }
}
