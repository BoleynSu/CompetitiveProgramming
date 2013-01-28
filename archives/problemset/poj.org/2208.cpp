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
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

typedef pdd pnt;//二维点
struct seg{pnt a,b;};//线段ab
struct ln{db a,b,c;};//直线ax+by+c=0
struct pnt3:pnt{db z;pnt3(){}pnt3(db x,db y,db z):pnt(x,y),z(x){}};//三维点
struct pln{pnt3 a,b,c;};//平面abc

pnt add(pnt a,pnt b){rtn pnt(a.x+b.x,a.y+b.y);}//向量加
pnt sub(pnt a,pnt b){rtn pnt(a.x-b.x,a.y-b.y);}//向量减
db dot(pnt a,pnt b){rtn a.x*b.x+a.y*b.y;}//点积
inline db cross(pnt a,pnt b){rtn a.x*b.y-a.y*b.x;}//叉积
inline db mod(pnt a){rtn sqrt(dot(a,a));}//向量的模
struct pnt_sort
{
	pnt c;
	bool operator()(const pnt& a,const pnt& b)
	{
		rtn true;
	}
};

/*[四面体体积公式]
 * (12倍体积)^2=[(对棱积)^2*(侧棱平方和-对棱平方和)]的三组和-(四个表面三棱积的平方和)
 */
db volume(db ao,db bo,db co,db bc,db ac,db ab)
{
	rtn sqrt(sqr(ao*bc)*(sqr(bo)+sqr(co)+sqr(ac)+sqr(ab)-sqr(ao)-sqr(bc))
			+sqr(bo*ac)*(sqr(ao)+sqr(co)+sqr(bc)+sqr(ab)-sqr(bo)-sqr(ac))
			+sqr(co*ab)*(sqr(ao)+sqr(bo)+sqr(bc)+sqr(ac)-sqr(co)-sqr(ab))
			-sqr(ao*bo*ab)-sqr(bo*co*bc)-sqr(ao*co*ac)-sqr(ab*bc*ac))/12.0;
}

/*[Pick定理]
 * 设以整数点为顶点的多边形的面积为S,多边形内部的整数点数为N,多边形边界上的整数点数为L,则 N+L/2-1=S.
 */

/*[费马点]
 * 对于三角形:
 * 当三个角都小于120度,则费马点在三角形内部与任意两定点的连线构成的角都为120度;
 * 若存在一个角大于等于120度,则费马点为此角顶点.
 * 对于平面四边形:
 * 若为凸四边形,则费马点为两对角线交点;
 * 对于凹四边形,为其凹顶点(只要枚举四个顶点即可).
 */

int main()
{
	db  AB, AC, AD, BC, BD, CD;
	cin>>AB>>AC>>AD>>BC>>BD>>CD;
	pdb(4,volume(AD,BD,CD,BC,AC,AB));
}
