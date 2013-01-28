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
#define rtn return
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue

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
typedef queue<int> qi;
typedef priority_queue<int> pqi;

const int oo=(~0u)>>1;
const lli ool=(~0ull)>>1;
const db inf=1e100;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline void cmax(type& a,const type& b){if(a<b)a=b;}
template<typename type>inline void cmin(type& a,const type& b){if(a>b)a=b;}

int n;
int m[1000+2][1000+2];
int l[1000+2][1000+2];
int r[1000+2][1000+2];
int u[1000+2][1000+2];
int d[1000+2][1000+2];
int lu[1000+2][1000+2];
int rd[1000+2][1000+2];

int st[(1000+2)];
void inc(int x,int value)
{
     for (;x<=n;x+=(x)&(-x)) st[x]+=value;
}
int sum(int x)
{
    int value=0;
    for (;x>0;x-=(x)&(-x)) value+=st[x];
    rtn value;
}

prq<pii,vec<pii>,greater<pii> > pq;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    ft(t,1,T)
    {
        scanf("%d",&n);
        getchar();
        ft(i,1,n) ft(j,1,n) m[i][j]=getchar()-'0',getchar();
        ft(i,1,n)
        {
            l[i][0]=0;
            ft(j,1,n) l[i][j]=(l[i][j-1]+1)*m[i][j];
            r[i][n+1]=0;
            fdt(j,n,1) r[i][j]=(r[i][j+1]+1)*m[i][j];
            u[0][i]=0;
            ft(j,1,n) u[j][i]=(u[j-1][i]+1)*m[j][i];
            d[n+1][i]=0;
            fdt(j,n,1) d[j][i]=(d[j+1][i]+1)*m[j][i];
        }
        ft(i,1,n) ft(j,1,n) lu[i][j]=min(l[i][j],u[i][j]),rd[i][j]=min(r[i][j],d[i][j]);
        int answer=0;
        ft(id,1-n,n-1)
        {
            int b=max(1,1+id),e=min(n,n+id);
            ft(i,b,e)
            {
                int j=i-id;
                inc(i,+1);
                pq.push(mp(i+rd[i][j],i));
                while (!pq.empty()&&pq.top().x<=i)
                {
                    inc(pq.top().y,-1);
                    pq.pop();
                }
                answer+=sum(n)-sum(i-lu[i][j]);
            }
            while (!pq.empty())
            {
                inc(pq.top().y,-1);
                pq.pop();
            }
        }
        printf("Case %d: %d\n",t,answer);
    }
}
