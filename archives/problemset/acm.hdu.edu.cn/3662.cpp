//Boleyn Su's Template for Codeforces
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

#define lp for(;;)
#define rep(i,n) for (int i=0;i<(n);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s,t) for (t::itr e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define cpy(x,y) memcpy((x),(y),sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) (x).resize(unique(all(x))-x.begin())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) printf("%."#prcs"f",(abs(x)<1e-##prcs)?0.0:x)
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() printf("Used: %.3fms\n",db(clock())/CLOCKS_PER_SEC);

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int, int> pii;
typedef pr<db,db> pdd;
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+8;
const db eps=1e-8;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}

//三维凸包模板,可以求三维凸包表面积,体积,表面多边形数和表面三角形数
#define MAXV 310//三维点
struct pt{
    double x, y, z;
    pt(){}
    pt(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
    pt operator - (const pt p1){return pt(x - p1.x, y - p1.y, z - p1.z);}
    pt operator * (pt p){return pt(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);} //叉乘
    double operator ^ (pt p){return x*p.x+y*p.y+z*p.z;} //点乘
    pt operator *(db s){rtn pt(x*s,y*s,z*s);}
    pt operator /(db s){rtn pt(x/s,y/s,z/s);}
    pt operator +(pt t){rtn pt(x+t.x,y+t.y,z+t.z);}
};
struct _3DCH{
    struct fac{
    int a, b, c; //表示凸包一个面上三个点的编号
    bool ok; //表示该面是否属于最终凸包中的面
    };
    int n; //初始点数
    pt P[MAXV]; //初始点
    int cnt; //凸包表面的三角形数
    fac F[MAXV*8]; //凸包表面的三角形
    int to[MAXV][MAXV];
    double vlen(pt a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);} //向量长度
    double area(pt a, pt b, pt c){return vlen((b-a)*(c-a));} //三角形面积*2
    double volume(pt a, pt b, pt c, pt d){return (b-a)*(c-a)^(d-a);}//四面体有向体积*6
    //正：点在面同向
    double ptof(pt &p, fac &f){
        pt m = P[f.b]-P[f.a], n = P[f.c]-P[f.a], t = p-P[f.a];
        return (m * n) ^ t;
    }
    void deal(int p, int a, int b){
        int f = to[a][b];
        fac add;
        if (F[f].ok)
        {
            if (ptof(P[p], F[f]) > eps) dfs(p, f);
            else{ add.a = b, add.b = a, add.c = p, add.ok = 1; to[p][b] = to[a][p] = to[b][a] = cnt;
            F[cnt++] = add;
            }
        }
    }
    void dfs(int p, int cur){
        F[cur].ok = 0;
        deal(p, F[cur].b, F[cur].a);
        deal(p, F[cur].c, F[cur].b);
        deal(p, F[cur].a, F[cur].c);
    }
    bool same(int s, int t){
        pt &a = P[F[s].a], &b = P[F[s].b], &c = P[F[s].c];
        return fabs(volume(a, b, c, P[F[t].a])) < eps && fabs(volume(a, b, c, P[F[t].b])) < eps && fabs(volume(a, b, c, P[F[t].c])) < eps;
    }
    //构建三维凸包
    void construct(){
        cnt = 0;
        if (n < 4) return; /*********此段是为了保证前四个点不公面，若已保证，可去掉********/
        bool sb = 1; //使前两点不公点
        for (int i = 1; i < n; i++){
            if (vlen(P[0] - P[i]) > eps){
                swap(P[1], P[i]);
                sb = 0;
                break;
            }
        }
        if (sb)return;
        sb = 1; //使前三点不公线
        for (int i = 2; i < n; i++){
            if (vlen((P[0] - P[1]) * (P[1] - P[i])) > eps){
                swap(P[2], P[i]);
                sb = 0;
                break;
            }
        }
        if (sb)return;
        sb = 1; //使前四点不共面
        for (int i = 3; i < n; i++){
            if (fabs((P[0] - P[1]) * (P[1] - P[2]) ^ (P[0] - P[i])) > eps){
                swap(P[3], P[i]);
                sb = 0;
                break;
            }
        }
        if (sb)return; /*********此段是为了保证前四个点不公面********/
        fac add;
        for (int i = 0; i < 4; i++){
            add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
            if (ptof(P[i], add) > 0) swap(add.b, add.c);
            to[add.a][add.b] = to[add.b][add.c] = to[add.c][add.a] = cnt;
            F[cnt++] = add;
        }
        for (int i = 4; i < n; i++){
            for (int j = 0; j < cnt; j++){
                if (F[j].ok && ptof(P[i], F[j]) > eps){
                    dfs(i, j);
                    break;
                }
            }
        }
        int tmp = cnt;
        cnt = 0;
        for (int i = 0; i < tmp; i++){
            if (F[i].ok){
                F[cnt++] = F[i];
            }
        }
    }
    //表面积
    double area(){
        double ret = 0.0;
        for (int i = 0; i < cnt; i++){
            ret += area(P[F[i].a], P[F[i].b], P[F[i].c]);
        }
        return ret / 2.0;
    }
    //体积
    double volume(){
            pt O(0, 0, 0);
            double ret = 0.0;
            for (int i = 0; i < cnt; i++){
                ret += volume(O, P[F[i].a], P[F[i].b], P[F[i].c]);
            }
            return fabs(ret / 6.0);
        }
    pt gc(){
            pt O(0, 0, 0);
            pt ret =O;
            for (int i = 0; i < cnt; i++){
                ret =ret+ (O+P[F[i].a]+ P[F[i].b]+ P[F[i].c])*volume(O, P[F[i].a], P[F[i].b], P[F[i].c])/24.0;
            }
            return ret/volume();
        } //表面三角形数
    int facetCnt_tri(){
        return cnt;
    }
    //表面多边形数
    int facetCnt(){
        int ans = 0;
        for (int i = 0; i < cnt; i++){
            bool nb = 1;
            for (int j = 0; j < i; j++){
                if (same(i, j)){
                    nb = 0; break;
                }
            }
            ans += nb;
        } return ans;
    }
};
_3DCH hull; //内有大数组，不易放在函数内
int main()
{
    pt p;

    whl(scanf("%d", &hull.n)!=EOF){
    for (int i = 0; i < hull.n; i++) scanf("%lf%lf%lf", &hull.P[i].x, &hull.P[i].y, &hull.P[i].z);
    hull.construct();
printf("%d\n",hull.facetCnt());
}
    return 0;
}

