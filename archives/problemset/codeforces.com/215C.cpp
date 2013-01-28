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

int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	lli ans=0;
	for (int a=1;a<=n;a+=2)
		for (int b=1;b<=m;b+=2)
		{
			for (int c=1;c<=n;c+=2)
			{
				//s=a*b+c*d-min(a,c)*min(b,d);
				//ans+=(n-max(a,c)+1)*(m-max(b,d)+1);
				if (a<=c)
				{
					//if a<=c and b<=d
					//s=c*d;
					//ans+=(n-c+1)*(m-d+1);
					if (s%c==0)
					{
						//d=s/c;
						int d=s/c;
						if (b<=d&&d<=m&&d%2==1) ans+=(n-c+1)*(m-d+1);
					}
					//if a<=c and b>d
					//s=a*b+c*d-a*d;
					//ans+=(n-c+1)*(m-b+1);
					if ((c-a==0)&&(s-a*b)==0)
					{
						//d=1 to b-2
						ans+=(n-c+1)*(m-b+1)*((b-2-1)/2+1);
					}
					if((c-a!=0)&&(s-a*b)%(c-a)==0)
					{
						//d=(s-a*b)/(c-a);
						int d=(s-a*b)/(c-a);
						if (b>d&&d>=1&&d%2==1) ans+=(n-c+1)*(m-b+1);
					}
				}
				else
				{
					//if a>c and b>d
					//s=a*b;
					//ans+=(n-a+1)*(m-b+1);
					if (s==a*b)
					{
						//d=1 to b-2
						ans+=(n-a+1)*(m-b+1)*((b-2-1)/2+1);
					}
					//if a>c and b<=d
					//s=a*b+c*d-c*b;
					//ans+=(n-a+1)*(m-d+1);
					if ((s-a*b+c*b)%c==0)
					{
						//d=(s-a*b+c*b)/c
						int d=(s-a*b+c*b)/c;
						if (b<=d&&d<=m&&d%2==1) ans+=(n-a+1)*(m-d+1);
					}
				}
			}
		}
	cout<<ans<<endl;
}

