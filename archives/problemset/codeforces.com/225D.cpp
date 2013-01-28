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
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)

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
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

int main()
{
	int n,m;
	cin>>n>>m;
	vs map(n);
	rep(i,n) map[i].resize(m);
	pii T;
	int sl=0;
	rep(i,n) rep(j,m)
	{
		cin>>map[i][j];
		if (map[i][j]=='@') T=mp(i,j);
		if ('1'<=map[i][j]&&map[i][j]<='9')
			cmax(sl,map[i][j]-'0');
	}
	pr<lli,lli> S;
	rep(i,n) rep(j,m)
		if ('1'<=map[i][j]&&map[i][j]<='9')
			S.x|=((lli(i)<<((map[i][j]-'1')<<2))),
			S.y|=((lli(j)<<((map[i][j]-'1')<<2)));
	lli Smask=(1ll<<(sl<<2))-1,Pmask=(1ll<<(1<<2))-1;
	set<pr<lli,lli> > INQ;
	que<pr<pr<lli,lli>,int> > Q;
	Q.push(mp(S,0)),INQ.insert(S);
	while (!Q.empty())
	{
		pr<lli,lli> QH=Q.front().x;
		int d=Q.front().y;
		rep(i,sl)
		{
			int cx=(QH.x>>(i<<2))&Pmask,cy=(QH.y>>(i<<2))&Pmask;
			//cout<<cx<<","<<cy<<endl;
		}
		//prt(d);
		int curx=QH.x&Pmask,cury=QH.y&Pmask;
		//prt(curx),prt(cury);
		Q.pop();
		if (mp(curx,cury)==T) return cout<<d<<endl,0;

		pr<lli,lli> QT=mp((QH.x<<(1<<2))&Smask,(QH.y<<(1<<2))&Smask);
		static const int dx[]={1,-1,0,0};
		static const int dy[]={0,0,1,-1};
		rep(dir,4)
		{
			bool possible=true;
			int nextx=curx+dx[dir],nexty=cury+dy[dir];
			rep(i,sl-1)
			{
				int cx=(QH.x>>(i<<2))&Pmask,cy=(QH.y>>(i<<2))&Pmask;
				if (cx==nextx&&cy==nexty)
				{
					possible=false;
					break;
				}
			}
			if (nextx<0||nextx>=n||nexty<0||nexty>=m||map[nextx][nexty]=='#') possible=false;
			pr<lli,lli> GQT=mp(QT.x|nextx,QT.y|nexty);
			//prt(nextx),prt(nexty);
			//prt(GQT.x%16),prt(GQT.y%16);
			rep(i,sl)
			{
				int cx=(GQT.x>>(i<<2))&Pmask,cy=(GQT.y>>(i<<2))&Pmask;
				//cout<<"GQT"<<cx<<","<<cy<<endl;
			}
			if (possible&&!INQ.count(GQT)) Q.push(mp(GQT,d+1)),INQ.insert(GQT);
		}
	}
	cout<<-1<<endl;
}


