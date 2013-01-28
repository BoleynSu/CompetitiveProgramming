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

const lli MODER=1000000007;
int n;
int a[10];
lli c[1000][1000];
lli f[10][1000];

int main()
{
	cin>>n;
	rep(i,10) cin>>a[i];
	ft(i,0,n) c[i][0]=1;
	ft(i,1,n)
		ft(j,1,i)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MODER;
	fdt(i,9,0)
	{
		if (i==9)
		{
			ft(j,0,a[i]-1) f[i][j]=0;
			ft(j,a[i],n) f[i][j]=1;
		}
		else if (i==0)
		{
			ft(j,0,a[i]-1) f[i][j]=0;
			ft(j,a[i],n)
			{
				f[i][j]=0;
				ft(k,a[i],j)
					if (k)
					{
						if (j>1) f[i][j]=(f[i][j]+f[i+1][j-k]*c[j-1][k])%MODER;
					}
					else f[i][j]=(f[i][j]+f[i+1][j-k]*c[j][k])%MODER;
			}
		}
		else
		{
			ft(j,0,a[i]-1) f[i][j]=0;
			ft(j,a[i],n)
			{
				f[i][j]=0;
				ft(k,a[i],j)
					f[i][j]=(f[i][j]+f[i+1][j-k]*c[j][k])%MODER;
			}
		}
	}
	int answer=0;
	ft(i,1,n) answer=(answer+f[0][i])%MODER;
	cout<<answer<<endl;
}

