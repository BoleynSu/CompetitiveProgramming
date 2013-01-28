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

char s[1000000];
int sum[1000000];
int f[1000000];
int st[1000000];
int qh,qt;
int q[1000000];
int main()
{
	int value[256];
	clr(value);
	const char* v="aeiouAEIOU";
	while (*v) value[int(*v)]=1,v++;

	gets(s);
	int n=strlen(s);

	sum[0]=0;
	ft(i,1,n) sum[i]=sum[i-1]+value[int(s[i-1])];
	ft(i,0,n) f[i]=3*sum[i]-2*i;
	//ft(i,0,n) prt(f[i]);
	//max{x-y|3*(sum[x]-sum[y])<=2(x-y)}
	//max{x-y|3*sum[x]-2*x<=3*sum[y]-2*y}
	//x-min{y|3*sum[y]-2*y>=3*sum[x]-2*x}
	//x-min{y|f[y]>=f[x]}
	int ans=0,cnt=0;
	q[qh=qt=0]=0;
	ft(x,1,n)
	{
		int l=qh-1,r=qt;
		while (l+1!=r)
		{
			int mid=(l+r)>>1;
			if (f[q[mid]]>=f[x]) r=mid;
			else l=mid;
		}
		if (f[q[r]]>=f[x])
		{
			if (cmax(ans,x-q[r])) cnt=0;
			if (ans==x-q[r]) cnt++;
		}
		if (f[q[qt]]<f[x]) q[++qt]=x;
	}
	if (ans) cout<<ans<<" "<<cnt<<endl;
	else cout<<"No solution"<<endl;
}

