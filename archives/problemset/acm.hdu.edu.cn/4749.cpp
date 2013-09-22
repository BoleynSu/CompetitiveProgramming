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
//
//
//const int N=102000;
//struct node
//{
//    int s;
//    node *c[2];
//}mem[N*20],*nul,*cur,*tr[N];
//int val[N];
//int q[N],head[N],nxt[N*2],v[N*2],t=1;
//int pre[N][19],dep[N];
//int n,m;
//inline void add(int x,int y)
//{
//    nxt[++t]=head[x];v[t]=y;head[x]=t;
//    nxt[++t]=head[y];v[t]=x;head[y]=t;
//}
//
//node *ins(int x,node *base)
//{
//    static int c,i;
//    static node *now,*root;
//    now=root=++cur;
//    for(i=15;i>=0;i--)
//    {
//        c=x>>i&1;
//        now->c[!c]=base->c[!c];
//        now->c[c]=++cur;now->c[c]->c[0]=now->c[c]->c[1]=nul;
//        now->s=base->s+1;
//        now=now->c[c];
//        base=base->c[c];
//    }
//    now->s=base->s+1;
//    return root;
//}
//void bfs()
//{
//    int s,i,h,tail;
//    q[h=tail=1]=1;
//    pre[1][0]=-1;
//    dep[1]=0;
//    tr[0]=nul;
//    ins(val[1],tr[0]);
//    while(h<=tail)
//    {
//
//        cerr<<tail<<endl;
//        s=q[h++];
//        for(i=head[s];i;i=nxt[i])
//            if(pre[s][0]!=v[i])
//            {
//                ins(val[v[i]],tr[s]);
//                pre[v[i]][0]=s;
//                dep[v[i]]=dep[s]+1;
//                q[++tail]=v[i];
//            }
//    }
//    pre[1][0]=0;
//    int j;
//    for(j=1;j<=18;j++)
//        for(i=1;i<=n;i++)
//            pre[i][j]=pre[pre[i][j-1]][j-1];
//}
//int lca(int x,int y)
//{
//    int i;
//    if(dep[x]<dep[y])swap(x,y);
//    for(i=18;i>=0;i--)
//        if(dep[x]-(1<<i)>=dep[y])
//            x=pre[x][i];
//    if(x==y)return x;
//    for(i=18;i>=0;i--)
//        if(pre[x][i]&&pre[y][i]&&pre[x][i]!=pre[y][i])
//            x=pre[x][i],y=pre[y][i];
//    return pre[x][0];
//}
//int query(int x,int y,int z)
//{
//    int p=lca(x,y);
//    static node *a,*b,*c,*d;
//    int idx,res=0,i;
//    a=tr[x];b=tr[y];c=tr[p];d=tr[pre[p][0]];
//    for(i=15;i>=0;i--)
//    {
//        idx=!(z>>i&1);
//        if(a->c[idx]->s+b->c[idx]->s-c->c[idx]->s-d->c[idx]->s>0)
//            res+=1<<i,a=a->c[idx],b=b->c[idx],c=c->c[idx],d=d->c[idx];
//        else a=a->c[!idx],b=b->c[!idx],c=c->c[!idx],d=d->c[!idx];
//    }
//    return res;
//}
//int main()
//{
//    int i,x,y,z;
//    while(~scanf("%d%d",&n,&m))
//    {
//        memset(head,0,sizeof(head));
//        t=1;
//        nul=mem;cur=mem+1;
//        nul->c[0]=nul->c[1]=nul;
//        nul->s=0;
//        for(i=1;i<=n;i++)
//            scanf("%d",&val[i]);
//        for(i=1;i<n;i++)
//            scanf("%d%d",&x,&y),add(x,y);
//        bfs();
//        while(m--)
//        {
//            scanf("%d%d%d",&x,&y,&z);
//            printf("%d\n",query(x,y,z));
//        }
//    }
//}
//int n,m;
//const int MOD=1000000007;
//const int N=220;
//int C[N][N];
//
//char s1[N],s2[N];
//int l1,l2;
//int ans=0;
//void check(int bef)
//{
//    int i;
//    for(i=)
//}
//int main()
//{
//    int cas,i,j;
//    C[0][0]=1;
//    for(i=1;i<=200;i++)
//        for(j=0;j<=200;j++)
//        {
//            C[i][j]=C[i-1][j];
//            if(j)C[i][j]+=C[i-1][j-1];
//            if(C[i][j]>=MOD)C[i][j]-=MOD;
//        }
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        ans=0;
//        scanf("%d%d",&n,&m);
//        scanf("%s",s1);
//        scanf("%s",s2);
//        l1=strlen(s1);
//        l2=strlen(s2);
//        for(i=l1-1;i<=)
//    }
//}
const int MAXN=100000+2;
const int MAXK=25+2;
int n,m,k;
int x[MAXN];
int a[MAXN];
pii sa[MAXN];
int b[MAXN];
int pi[MAXN];
struct st
{
    int cnt[MAXK];
    st()
    {
        memset(cnt,0,sizeof cnt);
    }
    void inc(int st[],int x,int v)
    {
        for (int i=x;i<MAXK;i+=i&(-i)) st[i]+=v;
    }
    int sum(int st[],int x)
    {
        int s=0;
        for (int i=x;i;i-=i&(-i)) s+=st[i];
        return s;
    }
    void insert(int x)
    {
//        cerr<<"+"<<x<<endl;
        inc(cnt,x,1);
    }
    void erase(int x)
    {
//        cerr<<"-"<<x<<endl;
        inc(cnt,x,-1);
    }
    pii order(int x)
    {
        return mp(sum(cnt,x),sum(cnt,x)-sum(cnt,x-1));
    }
};

int main()
{
    while (~scanf("%d%d%d",&n,&m,&k))
    {
        for (int i=0;i<n;i++) scanf("%d",&x[i]);
        st ast;
        for (int i=0;i<m;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++)
        {
            ast.insert(a[i]);
            sa[i]=ast.order(a[i]);
        }
        int j;
        st pist;
        pi[0]=j=-1;
        for (int i=1;i<m;i++)
        {
            pist.insert(a[i]);
            while (j!=-1&&pist.order(a[i])!=sa[j+1])
            {
                //[i-1-j..i-1] = [0..j]
                //[i-1-pi[j]..i-1] = [0,..pi[j]]
                for (int k=i-1-j;k<i-1-pi[j];k++) pist.erase(a[k]);
                j=pi[j];
            }
            if (pist.order(a[i])==sa[j+1]) j++;
            pi[i]=j;
        }
        int ans=0;
        st xst;
        j=-1;
        for (int i=0;i<n;i++)
        {
            xst.insert(x[i]);
//            cerr<<xst.order(x[i])<<" "<<a[j+1]<<endl;
            while (j!=-1&&xst.order(x[i])!=sa[j+1])
            {
                for (int k=i-1-j;k<i-1-pi[j];k++) xst.erase(x[k]);
                j=pi[j];
            }
            if (xst.order(x[i])==sa[j+1]) j++;
//            cerr<<i<<":"<<j<<endl;
            if (j==m-1)
            {
//                cerr<<i-m+1<<" "<<i<<endl;
                ans++;
                for (int k=i-j;k<=i;k++) xst.erase(x[k]);
                j=-1;
            }
        }
        printf("%d\n",ans),fflush(stdout);
    }
}

