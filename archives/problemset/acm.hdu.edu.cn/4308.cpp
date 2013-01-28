#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define foreach(e,set) for (typeof((set).begin()) e=(set).begin();e!=(set).end();e++)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define clr(x) memset((x),0,sizeof(x))
#define prt(x) cout<<#x<<"="<<x<<endl
#define prtm(x,y) cout<<x<<y<<endl

typedef long long lli;
typedef vector<lli> vlli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int oo=(~0u)>>1;
const lli ool=(~0ull)>>1;
const double inf=1e100;
const double eps=1e-8;

#define x first
#define y second

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};


int main()
{
    int r,c,cost;
    while (~scanf("%d%d%d",&r,&c,&cost))
    {
        getchar();
        string m[5000+2];
        rep(i,r)
        {
            char s[5000+2];
            gets(s);
            m[i]=s;
        }
        vector<pii> h;
        pii s,t;
        rep(i,r)
            rep(j,c)
                if (m[i][j]=='C') s=mp(i,j);
                else if (m[i][j]=='Y') t=mp(i,j);
                else if (m[i][j]=='P') h.pb(mp(i,j));
        bool reach=false;
        int qh,qt;
        pii q[5000];
        map<pii,int> d;
        q[qh=qt=0]=s;
        d[s]=0;
        while (qh<=qt)
        {
            pii u=q[qh++];
            if (u==t)
            {
                printf("%d\n",d[t]);
                reach=true;
                break;
            }
            rep(i,4)
            {
                pii v=mp(u.x+dx[i],u.y+dy[i]);
                if (0<=v.x&&v.x<r&&0<=v.y&&v.y<c&&m[v.x][v.y]!='#')
                {
                    if (m[v.x][v.y]=='*') d[v]=d[u]+cost;
                    else if (m[v.x][v.y]=='P')
                    {
                        d[v]=d[u];
                        rep(j,sz(h))
                            if (h[j]!=v)
                            {
                                pii w=h[j];
                                d[w]=d[v];
                                m[w.x][w.y]='#';
                                q[++qt]=w;
                            }
                    }
                    else d[v]=d[u];
                    m[v.x][v.y]='#';
                    q[++qt]=v;
                }
            }
        }
        if (!reach) puts("Damn teoy!");
    }
}
