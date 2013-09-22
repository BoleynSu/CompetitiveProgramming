#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define rep(i,n) for (int i=0;i<(n);i++)
#define sz(x) (int((x).size()))

typedef long long int lli;

const int N=16;
int f[1<<N];
vector<int>a;
char str[N+5];
int cnt[1<<N];
int n;
char s2[N+5];
int ct(int x)
{
    static int s=0;s=0;
    while(x)
    {
        x-=(x)&(-x);
        s++;
    }
    return s;
}
bool ok(int dep)
{
    int i;
    for(i=1;i+i<=dep;i++)
    {
        if(s2[i]!=s2[dep-i+1])return false;
    }
    return true;
}
int now[N+5];
void Dfs(int dep,int state)
{
    int i;
    if(dep>1)
    {
        if(ok(dep-1))
            a.pb(state);
    }
    for(i=now[dep-1]+1;i<n;i++)
    {
        now[dep]=i;s2[dep]=str[i];
        Dfs(dep+1,state|(1<<i));
    }
}
void get()
{
    a.clear();
    Dfs(1,0);
}
int dfs(int x)
{
    if(f[x]!=-1)return f[x];
    int i;
    if(!x)return f[x]=0;
    f[x]=n;
    for(i=0;i<a.size();i++)
    if((a[i]|x)==x)
    {
        f[x]=min(f[x],dfs(x^a[i])+1);
    }
    return f[x];
}
bool cmp(const int &x,const int &y)
{
    return cnt[x]>cnt[y];
}
int main()
{
    int cas,i;
    now[0]=-1;
    for(i=1;i<(1<<N);i++)
        cnt[i]=ct(i);
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",str);
        memset(f,-1,sizeof(f));
        n=strlen(str);
        get();
        sort(a.begin(),a.end(),cmp);
        printf("%d\n",dfs((1<<n)-1));
    }
}
