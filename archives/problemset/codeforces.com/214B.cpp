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

int c[10];
int c3[3];
int mod3;

int main()
{
	int n;
	cin>>n;
	rep(i,n)
	{
		int a;
		cin>>a;
		c[a]++;
		c3[a%3]++;
		mod3=(mod3+a)%3;

	}
	if (!c[0]) cout<<-1<<endl;
	else if (mod3==0)
	{
		bool allZero=true;
		ft(i,1,9) if (c[i]) allZero=false;
		if (allZero) cout<<0<<endl;
		else
		{
			fdt(i,9,0)
				rep(j,c[i])
					cout<<i;
			cout<<endl;
		}
	}
	else if (mod3==1)
	{
		if (c3[1]>=1)
		{
			rep(i,10)
				if (i%3==1&&c[i])
				{
					c[i--]--;
					break;
				}
			bool allZero=true;
			ft(i,1,9) if (c[i]) allZero=false;
			if (allZero) cout<<0<<endl;
			else
			{
				fdt(i,9,0)
					rep(j,c[i])
						cout<<i;
				cout<<endl;
			}
		}
		else if (c3[2]>=2)
		{
			int t=0;
			rep(i,10)
				if (i%3==2&&c[i])
				{
					c[i--]--;
					t++;
					if (t==2) break;
				}
			bool allZero=true;
			ft(i,1,9) if (c[i]) allZero=false;
			if (allZero) cout<<0<<endl;
			else
			{
				fdt(i,9,0)
					rep(j,c[i])
						cout<<i;
				cout<<endl;
			}
		}
		else cout<<-1<<endl;
	}
	else if (mod3==2)
	{
		if (c3[2]>=1)
		{
			rep(i,10)
				if (i%3==2&&c[i])
				{
					c[i--]--;
					break;
				}
			bool allZero=true;
			ft(i,1,9) if (c[i]) allZero=false;
			if (allZero) cout<<0<<endl;
			else
			{
				fdt(i,9,0)
					rep(j,c[i])
						cout<<i;
				cout<<endl;
			}
		}
		else if (c3[1]>=2)
		{
			int t=0;
			rep(i,10)
				if (i%3==1&&c[i])
				{
					c[i--]--;
					t++;
					if (t==2) break;
				}
			bool allZero=true;
			ft(i,1,9) if (c[i]) allZero=false;
			if (allZero) cout<<0<<endl;
			else
			{
				fdt(i,9,0)
					rep(j,c[i])
						cout<<i;
				cout<<endl;
			}
		}
		else cout<<-1<<endl;
	}
}

