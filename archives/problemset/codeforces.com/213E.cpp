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
#define foreach(e,set,type) for (type::iterator e=(set).begin();e!=(set).end();++e)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define sqr(x) (x)*(x)
#define lb(x) (x)&(-(x))
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
#define asrtWA(s) do if(!(s))exit(0);whl(false)
#define asrtTLE(s) do if(!(s))whl(true);whl(false)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(false)

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<string> vs;
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
const db inf=1e100;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){return a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){return a>b?a=b,true:false;}
template<typename type>inline int sgn(const type& x){return (x>0)-(x<0);}
template<>inline int sgn(const db& x){return (x>+eps)-(x<-eps);}

enum{h=19930309};
class st
{
	int s;
	vi t,m,pw;
public:
	st(int s,int i=0):s(s),t((s+2)*4,i),m((s+2)*4,i),pw(s){pw[0]=1;ft(i,1,s-1)pw[i]=pw[i-1]*h;}
	void ins(int p,int v){ins(p,v,0,s-1);}
	void ins(int p,int v,int l,int r,int rt=1)
	{
		if (p<l||r<p) ;
		else if (p<=l&&r<=p)
		{
			t[rt]+=v;
			m[rt]=sgn(t[rt]);
		}
		else
		{
			int ll=l,lr=(l+r)>>1,lrt=rt<<1;
			int rl=lr+1,rr=r,rrt=lrt|1;
			ins(p,v,ll,lr,lrt);
			ins(p,v,rl,rr,rrt);
			t[rt]=t[lrt]*pw[m[rrt]]+t[rrt];
			m[rt]=m[lrt]+m[rrt];
		}
	}
	int qry(){rtn t[1];}
};
int main()
{
	int n,m;
	cin>>n>>m;

	vi a(n),b(m),A(n),B(m);
	rep(i,n) cin>>a[i],A[--a[i]]=i;
	rep(i,m) cin>>b[i],B[--b[i]]=i;
	int trg=0,one=0;
	rep(i,n) trg=trg*h+a[i],one=one*h+1;
	int ans=0;
	st t(m);
	rep(i,n-1) t.ins(B[i],i+1);
	ft(i,n-1,m-1)
	{
		t.ins(B[i],i+1);
		if (t.qry()-one==trg+one*(i-(n-1))) ans++;
		t.ins(B[i-(n-1)],-(i-(n-1)+1));
	}
	cout<<ans<<endl;
}

