#include <iostream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int oo=(~0u)>>1;

#define whl while
#define rep(i,n) for(int i=0;i<(n);i++)
#define ft(i,b,e) for(int i=(b);i<=(e);i++)
#define fdt(i,b,e) for(int i=(b);i>=(e);i--)
#define rtn return
#define pr pair
#define x first
#define y second
#define prt(x) cout<<#x<<"="<<x<<endl;
#define vec vector
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define sz(x) ((int)(x.size()))

typedef double db;
typedef pr<int,int> pii;
typedef vec<int> vi;

template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}

void calc(vec<pii>& op,vi& f)
{
    srt(op);
    f.assign(sz(f),+oo);
    f[0]=0;
    rep(k,sz(op))
        fdt(i,op[k].x+op[k].y,0)
            if (f[i]!=+oo)
                cmin(f[i-op[k].y],f[i]+1);
}
int main()
{
    int T;
    cin>>T;
    whl(T--)
    {
        int N,M;
        cin>>N>>M;
        vec<pii> op[2];
        rep(i,M)
        {
            int t,a,x;
            cin>>t>>a>>x;
            if (t==1)
            {
                op[0].pb(mp(a,-x));
            }
            else
            {
                op[1].pb(mp(N-a+1,-x));
            }
        }
        vi f[2];
        rep(i,2) f[i].resize(N+2),calc(op[i],f[i]);
        //rep(j,2) ft(i,1,N) prt(f[j][i]);
        int ansf=0,ansc=0;
        ft(i,0,N)
            ft(j,0,N-i)
                if (f[0][i]!=+oo&&f[1][j]!=+oo)
                {
                    //prt("here");
                    if (cmax(ansf,i+j)) ansc=f[0][i]+f[1][j];
                    else if (ansf==i+j) cmin(ansc,f[0][i]+f[1][j]);
                }
        static int t;
        cout<<"Case "<<(++t)<<": "<<ansf<<" "<<ansc<<endl;
    }
}

/*
int N,M;
pii w[200],s[2000];
int pc[200][200];
int nc[200][200];

int main()
{
    while (~scanf("%d%d",&N,&M))
    {
        rep(i,N) scanf("%d%d",&w[i].x,&w[i].y);
        rep(i,M) scanf("%d%d",&s[i].x,&s[i].y);
        rep(i,N) rep(j,N) rep(k,M)
        {
            int S=(w[i].x-s[k].x)*(w[j].y-s[k].y)-(w[i].y-s[k].y)*(w[j].x-s[k].x);
            if (S>0) pc[i][j]++;
            else nc[i][j]++;
        }
        int ans=0;
        rep(i,N) ft(j,i+1,N-1) ft(k,j+1,N-1)
        {
            ans+=(pc[i][j]*pc[j][k]*pc[k][i]+nc[i][j]*nc[j][k]*nc[k][i]);
            prt(ans);
        }
        prt(ans);
    }
}
*/

