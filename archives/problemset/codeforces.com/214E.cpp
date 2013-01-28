//Boleyn Su's Template for  Codeforces
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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define foreach(e,set,type) for (type::iterator e=(set).begin();e!=(set).end();++e)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define fl(x,y) memset((x),(y),sizeof(x))
#define clr(x) memset((x),0,sizeof(x))
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define sqr(x) (x)*(x)
#define lb(x) (x)&(-(x))
#define x first
#define y second

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vector<int> vint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef map<string,int> msi;
typedef set<int> si;

const int oo=(~0u)>>1;
const lli ool=(~0ull)>>1;
const db inf=1e100;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline void cmax(type& a,const type& b){if(a<b)a=b;}
template<typename type>inline void cmin(type& a,const type& b){if(a>b)a=b;}

int n;
int c[1000];
int k[1000];
int a[300][300];
int f[600][300][300];

int main()
{
	/*
	cin>>n;
	ft(i,1,n) cin>>c[i];
	ft(i,1,n)
	{
		cin>>k[i];
		rep(j,k[i]) cin>>a[i][j];
	}
	*/
	cin>>n;
	rep(i,n)rep(j,n)cin>>a[i][j];
	rep(i,n*2-1)
		rep(x1,min(i+1,n))
			rep(x2,min(i+1,n))
			{
				int y1=i-x1;
				int y2=i-x2;
				f[i][x1][x2]=a[x1][y1]+(x1==x2?0:a[x2][y2]);
				if (i)
				{
					int d=-oo;
					if (x1<i&&x2<i)cmax(d,f[i-1][x1][x2]);
					if (x1&&x2) cmax(d,f[i-1][x1-1][x2-1]);
					if (x1&&x2<i) cmax(d,f[i-1][x1-1][x2]);
					if (x2&&x1<i) cmax(d,f[i-1][x1][x2-1]);
					f[i][x1][x2]+=d;
				}
			}
	cout<<f[(n-1)*2][n-1][n-1]<<endl;
}

