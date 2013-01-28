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

int f[500+2][500+2];
int cost[500+2][500+2];
int pre[500+2][500+2];
int qt;
int q[500+2];

int main()
{
     string s;
     int k;
     cin>>s>>k;
     for (int i=0;i<len(s);i++)
         for (int j=i;j<len(s);j++)
         {
             for (int t=0;i+t<=j-t;t++)
                 if (s[i+t]!=s[j-t])
                     cost[i][j]++;
         }
    for (int i=0;i<len(s);i++)
    {
        pre[0][i]=-1;
        f[0][i]=oo;
    }
     for (int i=1;i<=k;i++)
     {
         for (int j=0;j<len(s);j++)
         {
             f[i][j]=cost[0][j];
             pre[i][j]=-1;
             for (int k=0;k<=j;k++)
                 if (f[i-1][k]!=oo&&f[i-1][k]+cost[k+1][j]<f[i][j])
                     f[i][j]=f[i-1][k]+cost[k+1][j],
                     pre[i][j]=k;
         }
     }
     cout<<f[k][s.length()-1]<<endl;
     int i=k,j=s.length()-1;
     q[qt++]=s.length()-1;
     while (i>=0&&pre[i][j]!=-1)
     {
         if (pre[i][j]!=q[qt-1]) q[qt++]=pre[i][j];
         j=pre[i][j];
         i--;
     }
     q[qt]=-1;
     for (int i=qt;i>0;i--)
     {
         for (int j=q[i]+1;j<=q[i-1];j++)
         {
             if (j-(q[i]+1)<=q[i-1]-j)
                 s[q[i]+q[i-1]+1-j]=s[j];
             cout<<s[j];
         }
         cout<<char(i==1?'\n':'+');
     }
     return 0;
}

