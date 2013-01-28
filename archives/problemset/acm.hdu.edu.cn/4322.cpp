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

int n,m,k;
int b[100];
int l[100][100];

bool usd[100];
int lst[100];
bool dfs(int r,int c)
{
    if (r<0) return false;
    else if (c==m) return true;
    else if (b[c]<=0) return dfs(r,c+1);
    else if (r<(b[c]+k-1)/k+lst[c+1]) return false;
    else
    {
        rep(i,n)
            if (!usd[i])
            {
                usd[i]=true;
                if (l[c][i]) b[c]-=k;
                else b[c]-=1;
                if (dfs(r-1,c)) return true;
                if (l[c][i]) b[c]+=k;
                else b[c]+=1;
                usd[i]=false;
            }
        return dfs(r-b[c],c+1);
    }
}

int main()
{
    int T;
    cin>>T;
    ft(t,1,T)
    {
        cin>>n>>m>>k;
        rep(i,m) cin>>b[i];
        rep(i,m) rep(j,n) cin>>l[i][j];
        lst[m]=0;
        fdt(i,m-1,0) lst[i]=lst[i+1]+(b[i]+(k-1))/k;
        clr(usd);
        cout<<"Case #"<<t<<": "<<(dfs(n,0)?"YES":"NO")<<endl;
    }
}

