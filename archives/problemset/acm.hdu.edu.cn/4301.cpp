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
#define foreach(e,set) for (vector<pii>::iterator e=(set).begin();e!=(set).end();e++)
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

const int MODER=100000007;
int f[2][8][2000+2];
int p[8][8]=
{//  0 1 2 3 4 5 6 7
    {1,1,0,0,1,1,0,0},
    {0,0,1,1,0,0,1,1},
    {0,0,1,1,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {0,0,1,1,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
};
#define x -1
int dk[8][8]=
{//  0 1 2 3 4 5 6 7
    {0,0,x,x,0,1,x,x},
    {x,x,0,1,x,x,1,2},
    {x,x,0,1,x,x,1,2},
    {0,0,0,1,0,1,1,2},
    {x,x,0,1,x,x,1,2},
    {0,0,0,1,0,1,1,2},
    {0,0,0,1,0,1,1,2},
    {0,0,0,1,0,1,1,2},
};
map<pii,int> answer;
vector<pii> answerv;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        answer.insert(mp(mp(n,k),0));
        answerv.pb(mp(n,k));
    }
    f[0][7][0]=1;
    for (int n=0;n<=1000;n++)
    {
        int nn=n+1;
        clr(f[nn&1]);
        for (int s=0;s<8;s++)
        {
            for (int k=0;k<=n*2;k++)
            {
                for (int ns=0;ns<8;ns++)
                    if (p[s][ns])
                    {
                        int nk=k+dk[s][ns];
                        f[nn&1][ns][nk]+=f[n&1][s][k];
                        while (f[nn&1][ns][nk]>=MODER) f[nn&1][ns][nk]-=MODER;
                    }
                if ((s==5||s==7)&&answer.find(mp(n,k))!=answer.end())
                {
                    answer[mp(n,k)]+=f[n&1][s][k];
                    while (answer[mp(n,k)]>=MODER) answer[mp(n,k)]-=MODER;
                }
            }
        }
    }
    foreach(e,answerv) printf("%d\n",answer[*e]);
}

