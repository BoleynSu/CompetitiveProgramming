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
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define foreach(e,set) for (typeof((set).begin()) e=(set).begin();e!=(set).end();e++)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
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

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n,L;
        scanf("%d%d",&L,&n);
        map<int,int> cake;
        int hp=0,hd=true,dist=0;
        for (int i=0;i<n;i++)
        {
            int c;
            scanf("%d",&c);
            if (c)
            {
                if (!cake.empty())
                {
                    int np;
                    map<int,int>::iterator a=cake.lower_bound(hp);
                    if (a==cake.end()) np=cake.rbegin()->first;
                    else
                    {
                        map<int,int>::iterator b=a--;
                        if (a==cake.end())
                        {
                            np=b->first;
                        }
                        else
                        {
                            int ap=a->first,bp=b->first;
                            if (bp-hp!=hp-ap)
                            {
                                if (bp-hp<hp-ap) np=bp;
                                else np=ap;
                            }
                            else
                            {
                                if (hd) np=bp;
                                else np=ap;
                            }
                        }
                    }
                    dist+=abs(np-hp);
                    if (!--cake[np]) cake.erase(np);
                    if (np!=hp) hd=np>hp;
                    hp=np;
                }
                //prt(hp);prt(hd);
            }
            else
            {
                int p;
                scanf("%d",&p);
                if (0<=p&&p<=L) cake[p]++;
            }
        }
        printf("Case %d: %d\n",t,dist);
    }
}

