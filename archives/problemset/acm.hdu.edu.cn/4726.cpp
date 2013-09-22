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

//
//const int N=102000;
//struct node
//{
//    node *c[2],*fa;
//    int v,lv,rv,lf,rf,lg,rg,f,g;
//    bool dir(){return fa->c[1]==this;}
//    inline bool isroot(){return fa->c[0]!=this&&fa->c[1]!=this;}
//    inline void set(node *x,bool d);
//}*nul,mem[N],*cur;
//void node::set(node *x,bool d){if(this!=nul)c[d]=x;if(x!=nul)x->fa=this;}
//inline void update(node *x)
//{
//    if(x==nul)return ;
//    x->lv=x->rv=x->v;
//    if(x->c[0]!=nul)x->lv=x->c[0]->lv;
//    if(x->c[1]!=nul)x->rv=x->c[0]->rv;
//
//    x->f=x->g=1;
//    if(x->c[0]->rv<x->v)x->f+=x->c[0]->rf;
//    if(x->v<x->c[1]->lv)x->f+=x->c[1]->lf;
//
//    if(x->c[0]->rv>x->v)x->g+=x->c[0]->rg;
//    if(x->v>x->c[1]->lv)x->g+=x->c[1]->lg;
//
//    x->lf=x->c[0]->lf;
//    x->rf=x->c[1]->rf;
//
//}
//void rot(node *x)
//{
//    static node *y;y=x->fa;
//    static bool d;d=x->dir();
//    if(y->fa->c[0]==y)y->fa->c[0]=x;
//    if(y->fa->c[1]==y)y->fa->c[1]=x;
//    x->fa=y->fa;
//    y->set(x->c[!d],d);
//    x->set(y,!d);
//    update(y);
//}
//void splay(node *x)
//{
//    static node *t;
//    while(!(x->isroot()))
//    {
//        if(x->fa->isroot())rot(x);
//        else
//        {
//            if(x->dir()==x->fa->dir())rot(x->fa);
//            else rot(x);
//            rot(x);
//        }
//    }
//}
//node *access(node *u)
//{
//    static node *v;
//    for(v=nul;u!=nul;v=u,u=u->fa)
//    {
//        splay(u);
//        u->c[1]=v;
//        update(u);
//    }
//    return v;
//}
//node *query(node *x,node *y)
//{
//    node *v,*u=y;
//    access(x);
//    for(v=nul;u!=nul;u=u->fa)
//    {
//        splay(u);
//        if(u->fa==nul)
//        {
//
//        }
//        u->c[1]=v;
//        update(v=u);
//    }
//}
//
//int main()
//{
//
//}

char a[1<<20],b[1<<20];
char c[1<<20];
int ac[10],bc[10];
char ans[1<<20];

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%s%s",a,b);
        int n=strlen(a);
        for (int i=0;i<10;i++) ac[i]=bc[i]=0;
        for (int i=0;i<n;i++) ac[a[i]-'0']++,bc[b[i]-'0']++;
        vector<int> best(11);
        for (int i=1;i<10;i++)
            for (int j=1;j<10;j++)
            {
                int _ac[10],_bc[10];
                memcpy(_ac,ac,sizeof ac);
                memcpy(_bc,bc,sizeof bc);
                if (ac[i]&&bc[j])
                {
                    ac[i]--,bc[j]--;
                    vector<int> get(11);
                    get[0]=(i+j)%10;
                    for (int s=9;s>=0;s--)
                    {
                        for (int i=0;i<10;i++)
                            for (int j=0;j<10;j++)
                                if ((i+j)%10==s)
                                {
                                    int d=min(ac[i],bc[j]);
                                    get[10-s]+=d,ac[i]-=d,bc[j]-=d;
                                }
                    }
                    if (get>best) best=get;
                }
                memcpy(ac,_ac,sizeof ac);
                memcpy(bc,_bc,sizeof bc);
            }
        int cur=0;
        ans[cur++]='0'+best[0];
        for (int i=1;i<=10;i++) for (int j=0;j<best[i];j++) ans[cur++]='0'+10-i;
        ans[cur]=0;
        cur=-1;
        while(cur+1<n-1&&ans[cur+1]=='0') cur++;
        cur++;
        printf("Case #%d: %s\n",t,ans+cur);
    }
}
