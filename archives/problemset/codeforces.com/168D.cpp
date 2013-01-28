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
template<typename type>
void inc(vec<type>& st,int x,type inc){whl(x<sz(st)) st[x]+=inc,x+=lb(x);}
template<typename type>
type sum(vec<type>& st,int x){type s=0;while (x>0) s+=st[x],x-=lb(x);rtn s;}

db f[200+2][200+2][200+2];
int main()
{
	int n,l,k;
	cin>>n>>l>>k;
	vec<db> p(n);
	rep(i,n) cin>>p[i],p[i]/=100.0;
	vi a(n);
	rep(i,n) cin>>a[i];
	int I=0;
	f[I][min(k,n)][0]=1.0;
	I++;
	rep(i,n)
	{
		if (a[i]!=-1)
		{
			ft(j,0,n)
				ft(k,0,n)
					f[I][j][k]+=f[I-1][j][k]*(1.0-p[i]);
			ft(j,0,n)
				ft(k,0,n-1)
					f[I][min(j+a[i],n)][k+1]+=f[I-1][j][k]*p[i];
			I++;
		}
	}
	rep(i,n)
	{
		if (a[i]==-1)
		{
			ft(j,0,n)
				ft(k,0,n)
					f[I][j][k]+=f[I-1][j][k]*(1.0-p[i]);
			ft(j,0,n)
				ft(k,0,n-1)
					if (j) f[I][j-1][k+1]+=f[I-1][j][k]*p[i];
			I++;
		}
	}
	db ans=0.0;
	ft(j,0,n)
		ft(k,l,n)//cout<<j<<" "<<k<<":"<<f[n][j][k]<<endl,
			ans+=f[n][j][k];
	printf("%.50f\n",ans);
}

