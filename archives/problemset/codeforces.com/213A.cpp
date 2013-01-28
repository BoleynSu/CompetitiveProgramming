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
#define cpy(x,y) memcpy((x),(y),sizeof(x))
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
int a[1000][1000];

bool m[1000];

int g(int s)
{
    clr(m);
    int r=0;
    int cc=0;
    while (cc!=n)
    {
        bool update;
        do
        {
            update=false;
            rep(i,n)
            {
                if (!m[i]&&c[i]==s)
                {
                    bool f=true;
                    rep(j,k[i]) if (!m[a[i][j]]) f=false;
                    if (f)
                    {
                        m[i]=true;
                        update=true;
                        cc++;
                        r++;
                    }
                }
            }
        }
        while (update);
        s=(++s)%3;
        r++;
    }
    r--;
    return r;
}

int main()
{
    cin>>n;
    rep(i,n)cin>>c[i],c[i]--;
    rep(i,n)
    {
        cin>>k[i];
        rep(j,k[i])cin>>a[i][j],a[i][j]--;
    }
    int answer=oo;
    rep(i,3) cmin(answer,g(i));
    cout<<answer<<endl;
}

