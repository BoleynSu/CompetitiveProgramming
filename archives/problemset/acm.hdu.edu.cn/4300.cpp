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

char table[26+2];
char rtable[26+2];
char s[100000+2];
char t[100000+2];
int pi[100000+2];

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        gets(table);
        for (int i=0;i<26;i++)
            rtable[table[i]-'a']=i+'a';
        gets(s);
        int sl;
        for (sl=0;s[sl];sl++)
            t[sl]=table[s[sl]-'a'];
        t[sl]='\0';
        int j;
        j=pi[0]=-1;
        for (int i=1;i<sl/2;i++)
        {
            while (j>=0&&s[j+1]!=s[i]) j=pi[j];
            if (s[j+1]==s[i]) j++;
            pi[i]=j;
        }
        char backup=s[sl/2];
        s[sl/2]='\0';
        j=-1;
        for (int i=0;i<sl;i++)
        {
            while (j>=0&&s[j+1]!=t[i]) j=pi[j];
            if (s[j+1]==t[i]) j++;
        }
        j++;
        s[sl/2]=backup;
        for (int i=0;i<sl-j;i++)
            putchar(s[i]);
        for (int i=0;i<sl-j;i++)
            putchar(rtable[s[i]-'a']);
        putchar('\n');
    }
}
