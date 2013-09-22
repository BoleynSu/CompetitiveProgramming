#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
//
//#define x first
//#define y second
//typedef long long big;
//const int P=1000000007;
//typedef map<int,int> mii;
//
//const int MAXN=100000+2;
//int N,A[MAXN];
//int inc[MAXN],de[MAXN],f[MAXN];
//
//void upd(int st[MAXN],int p,int v)
//{
//    for (int i=p;i<MAXN;i+=i&(-i))
//        if (st[i]<v) st[i]=v;
//}
//int qry(int st[MAXN],int p)
//{
//    int ans=0;
//    for (int i=p;i;i-=i&(-i))
//        if (ans<st[i]) ans=st[i];
//    return ans;
//}
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while(T--)
//    {
//        mii h;
//        scanf("%d",&N);
//        for (int i=1;i<=N;i++)
//        {
//            scanf("%d",&A[N-i+1]);
//            h[A[N-i+1]]=i;
//        }
//        int cnt=0;
//        for (mii::iterator it=h.begin();it!=h.end();it++)
//        {
//            it->y=++cnt;
//        }
//        memset(inc,0,sizeof inc);
//        memset(de,0,sizeof de);
//        int ans=0;
//        for (int i=1;i<=N;i++)
//        {
//            upd(inc,h[i],qry(inc,h[i])+1);
//            upd(de,cnt-h[i]+1,qry(de,cnt-h[i]+1)+1);
//            int get=qry(inc,h[i])+qry(de,cnt-h[i]);
//            if (ans<get) ans=get;
//        }
//        printf("%d\n",ans);
//    }
//}

const int N=200200;
int n,m;
int head[N],next[N],v[N],t=1;
int q[N];
int dis[N];
void add(int a,int b)
{
    next[++t]=head[a];v[t]=b;head[a]=t;
    next[++t]=head[b];v[t]=a;head[b]=t;
}
int bfs(int S)
{
    memset(dis,-1,sizeof(dis));
    dis[S]=0;
    int h,tail,s,i;
    q[h=tail=1]=S;
    while(h<=tail)
    {
        s=q[h++];
        for(i=head[s];i;i=next[i])
            if(dis[v[i]]==-1)
            {
                dis[v[i]]=dis[s]+1;
                q[++tail]=v[i];
            }
    }
    int id=1;
    for(i=1;i<=n;i++)
        if(dis[id]<dis[i])id=i;
    return id;
}
int main()
{
    int l,i,cas,a,b;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));t=1;
        for(i=1;i<n;i++)
            scanf("%d%d",&a,&b),add(a,b);
        a=bfs(1);
        b=bfs(a);
        l=dis[b];
        while(m--)
        {
            scanf("%d",&a);
            printf("%d\n",2*(a-1)-min(l,a-1));
        }
    }
}
//struct mat
//{
//    big s[2][2];
//};
//void operator*=(mat &a,const mat &b)
//{
//    int i,j,k;
//    static mat c;
//    memset(c.s,0,sizeof(c.s));
//    for(k=0;k<2;k++)
//        for(i=0;i<2;i++)
//            for(j=0;j<2;j++)
//                c.s[i][j]+=a.s[i][k]*b.s[k][j],c.s[i][j]%=P;
//    for(i=0;i<2;i++)
//        for(j=0;j<2;j++)
//            a.s[i][j]=c.s[i][j];
//}
//mat operator^(const mat &a,const mat &b)
//{
//    int i,k;
//    static mat c;
//    memset(c.s,0,sizeof(c.s));
//    for(k=0;k<2;k++)
//        for(i=0;i<2;i++)
//                c.s[i][0]+=a.s[i][k]*b.s[k][0],c.s[i][0]%=P;
//    return c;
//}
//int n,k;
//mat ans,g;
//int main()
//{
//    int cas;
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        scanf("%d%d",&n,&k);
//        if(n<k)puts("0");
//        else
//        {
//            memset(g.s,0,sizeof(g.s));
//            memset(ans.s,0,sizeof(ans.s));
//            g.s[0][0]=2;
//            g.s[0][1]=1;
//            g.s[1][0]=1;
//            ans.s[0][0]=1;
//            ans.s[1][0]=0;
//            n-=k;
//            for(;n;n>>=1,g*=g)
//                if(n&1)ans=g^ans;
//            cout<<ans.s[0][0]<<endl;
//        }
//    }
//}
//
