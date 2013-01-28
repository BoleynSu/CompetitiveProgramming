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
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define pb push_back
#define mp make_pair
#define itr iterator
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
const db inf=1e8;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type lb(type x){rtn x&(-x);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x+=lb(x);}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;while (x>0)s+=st[x],x-=lb(x);rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

bool isp[10000000+1];
int pp[10000000+1];
int fac[10000000+1];
int ps;
int p[664579];
int n,m;
int a[100000],b[100000];
int apc[664579];
int bpc[664579];
int main()
{
	fl(isp,true);
	isp[0]=isp[1]=false;
	ft(i,2,10000000)
	{
		if (isp[i])
		{
			pp[p[ps]=i]=ps;
			ps++;
			fac[i]=i;
		}
		for (int j=0;p[j]*i<=10000000;j++)
		{
			isp[p[j]*i]=false;
			fac[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
	cin>>n>>m;
	rep(i,n)
	{
		cin>>a[i];
		int x=a[i];
		whl(x!=1)
		{
			int y=fac[x];
			int z=pp[y];
			apc[z]++;
			x/=y;
		}
	}
	rep(i,m)
	{
		cin>>b[i];
		int x=b[i];
		whl(x!=1)
		{
			int y=fac[x];
			int z=pp[y];
			bpc[z]++;
			x/=y;
		}
	}
	rep(i,ps) apc[i]=bpc[i]=min(apc[i],bpc[i]);
	rep(i,n)
	{
		int x=a[i];
		whl(x!=1)
		{
			int y=fac[x];
			int z=pp[y];
			if (apc[z]) a[i]/=y,apc[z]--;
			x/=y;
		}
	}
	rep(i,m)
	{
		int x=b[i];
		whl(x!=1)
		{
			int y=fac[x];
			int z=pp[y];
			if (bpc[z]) b[i]/=y,bpc[z]--;
			x/=y;
		}
	}
	cout<<n<<" "<<m<<endl;
	rep(i,n) cout<<a[i]<<" "<<char(i+1==n?'\n':' ');
	rep(i,m) cout<<b[i]<<" "<<char(i+1==m?'\n':' ');
}

