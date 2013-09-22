#ifndef DEBUG
//https://github.com/boleynsu/acmicpc-codes/blob/master/templates/Core.hpp
/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间;
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

//用于减少代码量的宏;
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define rrepf(i,a,b) fdt(i,(a)-1,b)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))

//调试相关的宏;
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<"第"<<__LINE__<<"行\t: "<<#x"\t="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型;
typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数;
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
inline lli bin_pow(lli x,lli y){lli z=1;whl(y){if(y&1)z=mod(z*x);x=mod(sqr(x)),y>>=1;}rtn z;}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));rrep(i,y){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
inline void make_set(vpii& st){rep(i,sz(st))st[i]=mp(i,1);}
inline int find_set(vpii& st,int x){int y=x,z;whl(y!=st[y].x)y=st[y].x;whl(x!=st[x].x)z=st[x].x,st[x].x=y,x=z;rtn y;}
inline bool union_set(vpii& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?(st[a].y>st[b].y?st[a].x=b,st[a].y+=st[b].y:st[b].x=a,st[b].y+=st[a].y),true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化;
struct Initializer{
#ifndef DEBUG
Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
~Initializer(){runtime();}
#endif
}initializer;

////非标准;
//#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//typedef __gnu_cxx::rope<char> rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount
#else
//上面部分的代码生成的Precompiled Headers
#include <Core>
#endif
//
//int mex(vi a,int l,int r)
//{
//    si s;
//    ft(i,l,r) s.ins(a[i]);
//    int ans=0;
//    whl(s.count(ans)) ans++;
//    rtn ans;
//}
//
//int main()
//{
//    int n;
//    whl(cin>>n,n)
//    {
//        vi a(n);
//        cin>>a;
//        rep(i,n) rep(j,n-i) prt(mex(a,j,j+i));
//        vvi p(n+1);
//        rep(i,n) if (a[i]<=n) p[a[i]].pb(i);
//        vec<vpii> rng(n+1);
//        ft(i,0,n)
//        {
//            if (0<=p[i][0]-1) rng[i].pb(mp(0,p[i][0]-1));
//            rep(j,sz(p[i])-1) if (p[i][j]+1<=p[i][j+1]-1) rng[i].pb(mp(p[i][j]+1,p[i][j+1]-1));
//            if (p[i][sz(p[i])-1]+1<=n-1) rng[i].pb(mp(p[i][sz(p[i])-1]+1,n-1));
//        }
//        lli ans=0;
//        ft(i,1,n)
//        {
//        }
//        cout<<ans<<endl;
//    }
//}

//int lcs(int n,vi& a,vi& b)
//{
//    int ans=0;
//    vi f(n);
//    rep(i,n)
//    {
//        cmax(ans,f[i]);
//    }
//    rtn ans;
//}
//
//int main()
//{
//    int n;
//    whl(cin>>n,n)
//    {
//        vi a(n),b(n);
//        cin>>a;
//        int ans=0;
//        rep(i,n)
//        {
//            rep(j,n) b[j]=(a[i+j>=n?i+j-n:i+j]);
//            reverse(b.begin()+1,b.end());
//            prt(a),prt(b);
//            cmax(ans,lcs(n,a,b));
//        }
//        cout<<ans<<endl;
//    }
//}
//
//const int MAXV=202;
//const int MAXE=21000;
//typedef int flow_type;
//typedef int cost_type;
//const int MAX_FLOW=oo;
//const int MAX_COST=0x7f7f7f7f;
//typedef struct struct_edge* edge;
//struct struct_edge{int v;flow_type c;cost_type d;edge n,b;}pool[MAXE];
//edge top;
//int V=MAXV,S,T;
//edge adj[MAXV];
//void build_graph(int v,int s,int t)
//{
//    top=pool,clr(adj);
//    V=v,S=s,T=t;//点的编号的范围为[0,v),源,汇
//    //add_edge(u,v,c,d);
//}
//void add_edge(int u,int v,flow_type c,cost_type d)
//{
//    top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
//    top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
//    adj[u]->b=adj[v],adj[v]->b=adj[u];
//    if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;//防止add_edge(u,u,c,d)时出现RE
//}
//cost_type h[MAXV],d[MAXV];
//int q[MAXV];
//bool inq[MAXV];
//int qh,qt;
//edge p[MAXV];
//void min_cost_max_flow(flow_type& flow,cost_type& cost,bool has_negative_edges=true)
//{
//    if (has_negative_edges)
//    {
//        fl(h,MAX_COST),fl(inq,false),qh=0,qt=-1;
//        rep(i,V) h[i]=0,q[++qt]=i,inq[i]=true;
//        whl(qh<=qt)
//        {
//            int u=q[(qh++)%MAXV];
//            inq[u]=false;
//            for (edge i=adj[u];i;i=i->n)
//                if (i->c&&cmin(h[i->v],h[u]+i->d))
//                {
//                    p[i->v]=i;
//                    if (cmax(inq[i->v],true)) q[(++qt)%MAXV]=i->v;
//                }
//        }
//    }
//    else clr(h);
//    lp
//    {
//        fl(d,MAX_COST),fl(inq,false);
//        prq<pr<cost_type,int> > Q;
//        d[S]=0,p[S]=0,Q.push(mp(-d[S],S));
//        whl(sz(Q))
//        {
//            int u=Q.top().y;
//            Q.pop();
//            if (cmax(inq[u],true))
//                for (edge i=adj[u];i;i=i->n)
//                    if (i->c&&!inq[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
//                        p[i->v]=i,Q.push(mp(-d[i->v],i->v));
//        }
//        if (d[T]==MAX_COST) break;
//        else
//        {
//            flow_type delta=MAX_FLOW;
//            for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
//            for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
//            flow+=delta;
//            rep(i,V) h[i]+=d[i];
//        }
//    }
//}
//
//int N;
//int x[101],y[101],z[101], w[101];
//int flow_need;
//
//int dis(int u, int v) {
//    int tmp = (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]) + (z[u]-z[v])*(z[u]-z[v]);
//    return (int)sqrt(tmp);
//}
//
//void init() {
//    build_graph(2*N+2,0,2*N+1);
//    flow_need = 0;
//    for (int i=1;i<=N;i++) {
//        scanf("%d%d%d%d",&x[i],&y[i],&z[i], &w[i]);
//    }
//    for (int i=1;i<=N;i++) {
//        add_edge(S, i, w[i], 0);
//        add_edge(i+N, T, w[i], 0);
//        flow_need += w[i];
//    }
//    for (int i=1;i<=N;i++) {
//        for (int j=1;j<=N;j++) if (i!=j) {
//            add_edge(i, j+N, 50, dis(i, j));
//        }
//    }
//}
//
//void solve() {
//    int flow=0,cost=0;
//    min_cost_max_flow(flow,cost,false);
//    if (flow_need != flow) printf("-1\n");
//    else printf("%d\n", cost);
//}
//
//typedef long long LL;
//int main()
//{
//    do {
//        scanf("%d", &N);
//        if (!N) break;
//        init();
//        solve();
//    }while(true);
//    return 0;
//}

#define X x.x
#define Y x.y
#define Z y
#define pt pr<pdd,db>

inline
pt operator-(pt a,pt b)
{
    rtn mp(a.x-b.x,a.y-b.y);
}
inline
pt operator+(pt a,pt b)
{
    rtn mp(a.x+b.x,a.y+b.y);
}
inline
pt operator/(pt a,db b)
{
    rtn mp(a.x/b,a.y/b);
}
inline
pt operator*(pt a,db b)
{
    rtn mp(a.x*b,a.y*b);
}
inline
db len(pt x)
{
    rtn sqrt(sqr(x.X)+sqr(x.Y)+sqr(x.Z));
}
inline
pt cross(pt a,pt b)
{
    pt c;
    c.Z=a.X*b.Y-a.Y*b.X;
    c.X=a.Y*b.Z-a.Z*b.Y;
    c.Y=a.Z*b.X-a.X*b.Z;
    rtn c;
}
inline
db dot(pt a,pt b)
{
    rtn a.X*b.X+a.Y*b.Y+a.Z*b.Z;
}
inline
db dis(pt a,pt b,pt c)
{
    rtn abs(len(cross(b-a,c-a))/len(b-c));
}
inline
void out(db x)
{
    if (abs(x)<1e-6) printf("%.6f",0.0);
    else printf("%.6f",x);
}

int main()
{
    int T;
    sf("%d",&T);
    whl(T--)
    {
        pt a,b,c,d;
        sf("%lf%lf%lf",&a.X,&a.Y,&a.Z);
        sf("%lf%lf%lf",&b.X,&b.Y,&b.Z);
        sf("%lf%lf%lf",&c.X,&c.Y,&c.Z);
        sf("%lf%lf%lf",&d.X,&d.Y,&d.Z);
        pt ab=(b-a)/len(b-a),cd=(d-c)/len(d-c);
        db t1 = dot(cross(c-a,cd),cross(ab,cd))/sqr(len(cross(ab,cd)));
        db t2 = dot(cross(c-a,ab),cross(ab,cd))/sqr(len(cross(ab,cd)));
        pt e=a+ab*t1,f=c+cd*t2;
        out(len(f-e)),putchar('\n');
        out(e.X),putchar(' '),out(e.Y),putchar(' '),out(e.Z),putchar(' '),out(f.X),putchar(' '),out(f.Y),putchar(' '),out(f.Z),putchar('\n');
    }
}
