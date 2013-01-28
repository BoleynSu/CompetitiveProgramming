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
lli a[100000+2];
lli f[100000+2];
lli g[100000+2];
lli s[100000+2];

int main()
{
    cin>>n;
    --n;
    rep(i,n) cin>>a[i];
    rep(i,n) f[i]=a[i]/2?(i?f[i-1]:0)+a[i]/2*2:0;
    fdt(i,n-1,0) g[i]=a[i]/2?(i+1!=n?g[i+1]:0)+a[i]/2*2:0;
    rep(i,n) s[i]=(i?s[i-1]:0)+(a[i]-1)/2*2+1;
    lli answer=0,maxfms=0;
    rep(i,n)
    {
        //prt(i);prt(f[i]);prt(s[i]);prt(g[i+1]);
        cmax(maxfms,f[i]-s[i]);
        //prt(maxfms);
        cmax(answer,maxfms+s[i]+(i+1!=n?g[i+1]:0));
        //prt(answer);
    }
    cout<<answer<<endl;
}

