#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair


//const double pi=acos(double(-1));
//#define x first
//#define y second
//typedef long long big;
//const int P=1000000007;
//typedef map<int,int> mii;
//
//#define rep(i,n) for (int i=0;i<(n);i++)
//#define sz(x) (int((x).size()))
//typedef complex<double> cpx;
//typedef vector<cpx> vc;
//typedef vector<double> vdb;
//typedef vector<int> vi;
//
//
//struct CP
//{
//    double x,y;
//    CP(){}
//    CP(double _x,double _y):x(_x),y(_y){}
//    CP operator+(const CP &b)const{return CP(x+b.x,y+b.y);}
//    CP operator-(const CP &b)const{return CP(x-b.x,y-b.y);}
//    CP operator*(const CP &b)const{return CP(x*b.x-y*b.y,x*b.y+y*b.x);}
//    CP operator/(const CP &b)const
//    {
//        CP a;a.x=x;a.y=y;
//        a=a*CP(b.x,-b.y);
//        double tmp=b.x*b.x+b.y*b.y;
//        printf("%lf\n",tmp);
//        if(fabs(tmp)<1e-8)return CP(0,0);
//        a.x/=tmp;a.y/=tmp;
//        return a;
//    }
//};
//
//
//
//CP A[N],B[N],C[N],w[N],tt[N];
//int ans[N];
//char str[N];
//void dft(CP *a,int s,int t)
//{
//    if((L>>t)==1)return ;
//    dft(a,s,t+1);
//    dft(a,s+(1<<t),t+1);
//    int i,p;
//    static CP W;
//    for(i=0;i<L>>(t+1);i++)
//    {
//        p=(i<<(t+1))+s;
//        W=w[i<<t]*a[p+(1<<t)];
//        tt[i]=a[p]+W;
//        tt[i+(L>>(t+1))]=a[p]-W;
//    }
//    for(i=0;i<L>>t;i++)a[(i<<t)+s]=tt[i];
//}
//void get(CP *a)
//{
//    double tmp;
//    int l,t=0,i,j,nowL,len=strlen(str);
//    reverse(str,str+len);
//    while(len%2)str[len++]='0';
//    nowL=len/2;
//    for(i=0;i<N;i++)a[i]=CP(0,0);
//    for(i=0;i<nowL;i++)
//    {
//        for(tmp=0,j=(i+1)*2-1;j>=i*2;j--)
//        tmp*=10,tmp+=str[j]-'0';
//        a[i].x=tmp;
//    }
//    for(l=1;l<nowL*2;l<<=1);
//    L=max(l,L);
//}
//void FFT(vc& p,int flag=+1,bool aFFT=false)
//{
//    if (sz(p)!=1)
//    {
//        cpx w=1,wn=cpx(cos(flag*2*pi/sz(p)),sin(flag*2*pi/sz(p)));
//        vc p1(sz(p)/2),p2(sz(p)/2);
//        rep(i,sz(p1)) p1[i]=p[i*2],p2[i]=p[i*2+1];
//        FFT(p1,flag,false),FFT(p2,flag,false);
//        rep(k,sz(p1)) p[k]=p1[k]+w*p2[k],p[k+sz(p1)]=p1[k]-w*p2[k],w*=wn;
//        if (aFFT) rep(k,sz(p)) p[k]/=cpx(sz(p));
//    }
//}
//vdb multipy(vector<big>& p1,vector<big>& p2)
//{
//    int ps=sz(p1)+sz(p2),rps=1;
//    while(rps<ps)rps*=2;
//    vdb p(rps);
//    p1.resize(sz(p)),p2.resize(sz(p));
//    vc pc1(sz(p)),pc2(sz(p)),pc(sz(p));
//    rep(i,sz(p)) pc1[i]=cpx(p1[i]),pc2[i]=cpx(p2[i]);
//    FFT(pc1),FFT(pc2);
//    rep(i,sz(p)) pc[i]=pc1[i]*pc2[i];
//    FFT(pc,-1,true);
//    rep(i,sz(p)) p[i]=pc[i].real();
//    return p;
//}
//
//const int MAXN=100000;
//int n;
//int a[MAXN];
//big s[MAXN];
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while (T--)
//    {
//        scanf("%d",&n);
//        rep(i,n) scanf("%d",&a[i]);
//        vector<long long> f1(MAXN+1),f2(MAXN),ff(MAXN+1);
//        rep(i,n) f1[a[i]]++,f2[a[i]]++;
//        vdb ffdb=multipy(f1,f2);
//        rep(i,sz(ff)) ff[i]=ffdb[i]+0.5;
//        sort(a,a+n);
//        s[0]=ff[0];
//        long long ans=0;
//        for(int i=0;i<=a[n-1]+a[n-1];i++)
//        if(ff[i]!=0)
//        {
//            long long ke=lower_bound(a,a+n,i)-a;
//            ans=ans+ke*ff[i];
//            ke=n-ke;
//            ans=ans-(ke*ff[i])*2;
//        }
//
//        for(int i=0;i<n;i++)
//        {
//            long long ke=lower_bound(a,a+n,a[i]+a[i])-a;
//            ans=ans-ke*3+2;
//        }
//        double tmp=n;
//        tmp=tmp*(tmp-1)*(tmp-2);
//        printf("%.7f\n",ans/tmp);
//    }
//}
const int N=100200;
struct node
{
    node *c[2];
    int s;
}mem[N*40],*cur=mem,*nul;
vector<int>slx;
node *ins(int x,int y,node *base)
{
    static int l,r,mid,c;
    static node *now,*root;
    now=root=++cur;
    l=1;r=slx.size();
    while(l!=r)
    {
        mid=(l+r)>>1;
        c=x>mid;
        now->c[!c]=base->c[!c];
        now->c[c]=++cur;now->c[c]->c[0]=now->c[c]->c[1]=nul;
        now->s=base->s+y;
        now=now->c[c];
        base=base->c[c];
        if(c)l=mid+1;
        else r=mid;
    }
    now->s=base->s+y;
    return root;
}
int get(node *x,int y)
{
    static int c,l,r,mid,sum;
    l=1;r=slx.size();sum=0;
    while(l!=r)
    {
        mid=(l+r)>>1;
        c=y>mid;
        if(c)sum+=x->c[0]->s;
        x=x->c[c];
        if(c)l=mid+1;
        else r=mid;
    }
    if(y==l)sum+=x->s;
    return sum;
}
int n,m;
int w[N],ch[N][2];
int q[N];
node *tr[N],*T[N];
void init()
{
    int h=1,tail=1,s,i;
    q[h]=1;
    tr[1]=nul;
    T[1]=nul;
    while(h<=tail)
    {
        s=q[h++];
        if(ch[s][0])
        {
            for(i=0;i<2;i++)
                if(ch[s][i])
                {
                    tr[ch[s][i]]=ins(w[s],1,tr[s]);
                    q[++tail]=ch[s][i];
                }
            T[ch[s][0]]=T[s];
            T[ch[s][1]]=ins(w[s],1,T[s]);
        }
    }
}
int fd(int x)
{
    return lower_bound(slx.begin(),slx.end(),x)-slx.begin()+1;
}
int gd(int x)
{
    return upper_bound(slx.begin(),slx.end(),x)-slx.begin()+1;
}
int main()
{
    int cas;
    int i,a,b,c;
    int v,X;
    int ansa,ansb;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(ch,0,sizeof(ch));
        nul=mem;cur=mem+1;
        nul->c[0]=nul->c[1]=nul;
        nul->s=0;
        slx.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]),slx.pb(w[i]);
        sort(slx.begin(),slx.end());
        slx.erase(unique(slx.begin(),slx.end()),slx.end());
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        {
            w[i]=lower_bound(slx.begin(),slx.end(),w[i])-slx.begin()+1;
        }
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            ch[a][0]=b;
            ch[a][1]=c;
        }
        init();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&v,&X);
            a=tr[v]->s-get(tr[v],fd(X)-1);
            b=tr[v]->s-get(tr[v],gd(X)-1);
//            printf("%d %d#\n",a,b);
            if(a-b)puts("0");
            else
            {
                c=get(T[v],fd(X)-1);
//                printf("%d!!\n",c);
                ansb=a+(tr[v]->s-a)*3;
                ansa=c;
                printf("%d %d\n",ansa,ansb);
            }
        }
    }
}
