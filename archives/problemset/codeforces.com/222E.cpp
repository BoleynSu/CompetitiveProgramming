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
#define feach(e,s,t) for (t::iterator e=(s).begin();e!=(s).end();++e)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
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

vvi mul(const vvi& a,const vvi& b)
{
	vvi c(a.size(),vi(b[0].size(),0));
	rep(i,a.size())
		rep(j,b[0].size())
			rep(k,b.size())
			{
				c[i][j]+=lli(a[i][k])*lli(b[k][j])%1000000007;
				c[i][j]%=1000000007;
			}
	return c;
}
vvi pow(const vvi& a,lli b)
{
	vvi t=a;
	vvi c(a.size(),vi(a.size(),0));
	rep(i,a.size()) c[i][i]=1;
	while (b)
	{
		if (b&1) c=mul(c,t);
		t=mul(t,t);
		b>>=1;
	}
	return c;
}

int main()
{
	lli n;
	int m,k;
	cin>>n>>m>>k;
	vvi matrix(m,vi(m,1));
	rep(i,k)
	{
		char c;
		cin>>c;
		int a=('a'<=c&&c<='z')?c-'a':26+c-'A';
		cin>>c;
		int b=('a'<=c&&c<='z')?c-'a':26+c-'A';
		if (a<m&&b<m) matrix[a][b]=0;
	}
	vvi a(m,vi(1,1)),b(1,vi(m,1));
	vvi x;
	cout<<mul(b,mul(x=pow(matrix,n-1),a))[0][0]<<endl;
}

