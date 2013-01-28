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
#include <climits>
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
#define rtn return

typedef long long int lli;
typedef unsigned long long int ulli;
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

int n;

int main()
{
	cin>>n;
	db x=2000.0,y=4999.0;
	cout<<4*n+1<<endl;
	printf("%.50f %.50f\n",x,y);
	rep(i,n)
	{
		db a=10.0*cos(0.3*pi),b=10*sin(0.3*pi);
		printf("%.50f %.50f\n",x+b,y-a);
		db d=5.0/cos(0.3*pi)+5.0*tan(0.3*pi),e=5.0;
		printf("%.50f %.50f\n",x+e,y-d);
		printf("%.50f %.50f\n",x-e,y-d);
		printf("%.50f %.50f\n",x-b,y-a);
		x-=e;
		y-=d;
	}
	rep(i,n)
	{
		if (i) printf("%d",4*i);
		else printf("%d",1);
		rep(j,4) printf(" %d",i*4+2+j);
		printf("\n");
	}
	printf("%d",1);
	rep(i,n) printf(" %d %d %d %d",i*4+3,i*4+5,i*4+2,i*4+4);
	fdt(i,n-1,1) printf(" %d",i*4);
	printf(" %d\n",1);
}

