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

lli f(lli x)
{
	int length=0;
	while ((1ll<<length)<=x) length++;
	vec<lli> F(length,0);
	for (int i=1;i<length;i++)
		if (length%i==0)
		{
			lli y=0;
			lli m=x>>(length-i);
			lli mask=(1ll<<i)-1;
			fdt(j,length/i-1,0)
			{
				if (((x>>(i*j))&mask)<m)
				{
					m--;
					break;
				}
				else if (((x>>(i*j))&mask)>m) break;
			}
			if (m>=(1ll<<(i-1))) y+=m-(1ll<<(i-1))+1;
			//prt(i);prt(y);
			for (int j=1;j<i;j++)
				if (i%j==0)
					y-=F[j];
			F[i]=y;
		}
	lli y=0;
	rep(i,length) y+=F[i];//,prt(F[i]);
	//prt(y);
	rtn y+(length?f((1ll<<(length-1))-1):0);
}

int main()
{
	//rep(i,100) cout<<bitset<6>(i)<<":"<<f(i)<<endl;
	//f(15);
	//f(7);
	//f(3);
	//rtn 0;
	lli l,r;
	cin>>l>>r;
	cout<<f(r)-f(l-1)<<endl;
}

