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
const double eps=1e-8;
const int oo=(~0u)>>1;
//
//struct P
//{
//    double x,y;
//    void in(){scanf("%lf%lf",&x,&y);}
//};
//double dis(P a,P b)
//{
//    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
//}
//int sgn(double x)
//{
//    return (x>eps)-(x<-eps);
//}
//P a,b,c,T,p[6];
//bool ck(P s,double r)
//{
//    int i;
//    for(i=0;i<3;i++)
//        if(sgn(dis(p[i],s)-r)>0)return false;
//    return true;
//}
//int main()
//{
//    int cas,i,j;
//    scanf("%d",&cas);
//    P cp,S;
//    double R;
//    bool flag;
//    pair<int,int>t;
//    for(int k=1;k<=cas;k++)
//    {
//        a.in();
//        b.in();
//        c.in();
//        T.in();
//        double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
//        double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
//        double d=a1*b2-a2*b1;
//        p[0]=a;p[1]=b;p[2]=c;
//        if(sgn(d))
//        {
//            cp.x=a.x+(c1*b2-c2*b1)/d;
//            cp.y=a.y+(a1*c2-a2*c1)/d;
//            S=cp;R=dis(S,a);
//        }
//        for(i=0;i<3;i++)
//            for(j=i+1;j<3;j++)
//            {
//                cp.x=(p[i].x+p[j].x)/2;
//                cp.y=(p[i].y+p[j].y)/2;
//                if(ck(cp,dis(cp,p[i])))
//                {
//                    if(dis(cp,p[i])<R)
//                        R=dis(cp,p[i]),S=cp;
//                }
//            }
//        printf("%f %f %f\n",S.x,S.y,R);
//        if(sgn(dis(S,T))<=R)flag=true;
//        else flag=false;
//        printf("Case #%d: ",k);
//        if(flag)puts("Danger");
//        else puts("Safe");
//
//    }
//}

const int MAXN=100000*2+2;
int lev[MAXN];
list<pair<int,int> > adj[MAXN];
int d[MAXN];

int dijkstra(int s,int t,int V)
{
    for (int i=1;i<=V;i++) d[i]=+oo;
    priority_queue<pair<int,int> > q;
    d[s]=0;
    q.push(mp(-d[s],s));
    while (q.size())
    {
        int u=q.top().y;
        int du=-q.top().x;
        q.pop();
        if (u==t) return du;
        if (du==d[u])
        {
            for (list<pair<int,int> >::iterator it=adj[u].begin();it!=adj[u].end();it++)
            {
                int v=it->x;
                int l=it->y;
                if (d[v]>d[u]+l)
                {
                    d[v]=d[u]+l;
                    q.push(mp(-d[v],v));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&lev[i]);
        }
        for (int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].pb(mp(v,w)),adj[v].pb(mp(u,w));
        }
        for (int i=1;i<=n;i++)
        {
            if (lev[i]!=1)
            {
                adj[i].pb(mp(n+lev[i]-1,0));
            }
            if (lev[i]!=n)
            {
                adj[i].pb(mp(n+lev[i]+1,0));
            }
            adj[n+lev[i]].pb(mp(i,c));
        }
        printf("Case #%d: %d\n",t,dijkstra(1,n,n*2));
        for (int i=1;i<=n*2;i++) adj[i].clear();
    }
}
