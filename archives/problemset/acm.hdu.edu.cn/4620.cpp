/*
 * main.cpp
 *
 *  Created on: 2013-7-5
 *      Author: whd
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long big;
const int N=202;
int vis[N];
int n,m,w;
struct Cut
{
    vector<int>fruit;
    int id,t;
    bool operator<(const Cut &b)const
    {
        return t<b.t;
    }
}a[N];
int A[N],ans,now[N];
inline bool ok(int x)
{
    static int i,s;
    for(i=0,s=0;i<a[x].fruit.size();i++)
    {
        s+=(!vis[a[x].fruit[i]]);
        if(s>=3)return true;
    }
    return false;
}
inline void change(int x,int y)
{
    static int i;
    for(i=0;i<a[x].fruit.size();i++)
        vis[a[x].fruit[i]]+=y;
}
void dfs(int dep,int t)
{
    int i;
    if(n-now[dep-1]+dep-1<=ans)return ;
    if(dep-1>ans)
    {
        ans=dep-1;
        for(i=1;i<dep;i++)
            A[i]=now[i];
    }
    for(i=now[dep-1]+1;i<=n&&(a[i].t-t<=w||t==-1);i++)
    if(ok(i))
    {
        change(i,1);
        now[dep]=i;
        dfs(dep+1,a[i].t);
        change(i,-1);
    }
}
int main()
{
    int cas,x,i,y,z;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&w);
        for(i=1;i<=n;i++)
        {
            a[i].fruit.clear();
            a[i].id=i;
            scanf("%d%d",&x,&a[i].t);
            while(x--)
                scanf("%d",&y),a[i].fruit.pb(y);
        }
        ans=0;
        sort(a+1,a+1+n);
        dfs(1,-1);
        printf("%d\n",ans);
        for(i=1;i<=ans;i++)
            A[i]=a[A[i]].id;
        sort(A+1,A+1+ans);
        for(i=1;i<=ans;i++)
        {
            if(i>1)printf(" ");
            printf("%d",A[i]);
        }
        puts("");
    }
}
