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
const int N=100200;
double a,b;
double c[N],d[N];
int n,m;
inline double sqr(double x){return x*x;}
int main()
{
    double t1,t2,ans;
    int x,y,i,cas,cass;
    scanf("%d",&cas);
    for(cass=1;cass<=cas;cass++)
    {
        scanf("%lf%lf",&a,&b);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%lf",&c[i]);
        for(i=1;i<=m;i++)
            scanf("%lf",&d[i]);
        x=1;y=1;
        ans=0;
        ans+=sqrt(sqr(c[1]-d[1])+sqr(b-a));
        while(x<=n&&y<=m)
        {
            if(y<m)t1=sqrt(sqr(c[x]-d[y+1])+sqr(b-a));
            else t1=2e9;
            if(x<n)t2=sqrt(sqr(c[x+1]-d[y])+sqr(b-a));
            else t2=2e9;
            if(x==n&&y==m)break;
            if(t1<t2)ans+=t1,y++;
            else ans+=t2,x++;
        }
        printf("Case #%d: %.2f\n",cass,ans);
    }
}
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

//
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <vector>
//#include <list>
//#include <algorithm>
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//#define pb push_back
//#define mp make_pair
//#define x first
//#define y second
//const double eps=1e-8;
//const int oo=(~0u)>>1;
//
//int sa[30],sb[30];
//int n;
//char str[1002000];
//
//struct P
//{
//    int x,y;
//    P(){}
//    P(int _x,int _y):x(_x),y(_y){}
//    bool operator<(const P &b)const
//    {
//        return (x+y)%10>(b.x+b.y)%10;
//    }
//}a[120];
//char ans[1001000];
//vector<int> best;
//bool better(vector<int>& a,vector<int> &b )
//{
//    for (int i=10;i>=0;i--)
//        if (a[i]>b[i]) return true;
//        else if (a[i]<b[i]) return false;
//    return false;
//}
//int main()
//{
//    int cas,k,i,j,t,n,v,x,y,g;
//    scanf("%d",&cas);
//    for(k=1;k<=cas;k++)
//    {
//        memset(sa,0,sizeof(sa));
//        memset(sb,0,sizeof(sb));
//        scanf("%s",str);
//        for(i=0;str[i];i++)
//            sa[str[i]-'0']++;
//        scanf("%s",str);
//        for(i=0;str[i];i++)
//            sb[str[i]-'0']++;
//        n=strlen(str);
//
//        best=vector<int>(11);
//        for(i=1;i<10;i++)
//            for(j=1;j<10;j++) if (sa[i]&&sb[j])
//            {
//                int bsa[30],bsb[30];
//                memcpy(bsa,sa,sizeof bsa);
//                memcpy(bsb,sb,sizeof bsb);
//                sa[i]--,sb[j]--;
//                vector<int> get(11);
//                get[10]=(i+j)%10;
//                while(1)
//                {
//                    t=0;
//                    for(i=0;i<10;i++)
//                        for(j=0;j<10;j++)
//                            if(sa[i]&&sb[j])
//                                a[++t]=P(i,j);
//                    if(!t)break;
//                    sort(a+1,a+1+t);
//                    x=a[1].x;y=a[1].y;
//                    v=min(sa[x],sb[y]);
//                    sa[x]-=v;sb[y]-=v;
//                    get[(x+y)%10]+=v;
//                }
//                memcpy(sa,bsa,sizeof bsa);
//                memcpy(sb,bsb,sizeof bsb);
//                if (better(get,best)) best=get;
//            }
//        printf("Case #%d: ",k);
//        ans[n=1]=best[10]+'0';
//        for (int i=9;i>=0;i--)
//        {
//            for (int j=0;j<best[i];j++)
//                ans[++n]=i+'0';
//        }
//        for(i=1;ans[i]=='0'&&i<=n;i++);
//        if(i==n+1)putchar('0');
//        for(;i<=n;i++)
//            putchar(ans[i]);
//        puts("");
//    }
//}
