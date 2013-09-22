#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while (T--)
//    {
//        int A,B,N;
//        scanf("%d%d%d",&A,&B,&N);
//        int x=0;
//        for (int i=0;;i++)
//        {
//
//        }
//    }
//}

const int N=1020,M=N*3;
int next[M],v[M],head[N],t=1;
bool vis[N];
int n,m;
int re[N];
int id[120][120];
void add(int a,int b)
{
    next[++t]=head[a];v[t]=b;head[a]=t;
}
bool aug(int x)
{
    int i;
    for(i=head[x];i;i=next[i])
        if(!vis[v[i]])
        {
            vis[v[i]]=true;
            if(!re[v[i]]||aug(re[v[i]]))
            {
                re[v[i]]=x;
                return true;
            }
        }
    return false;
}
int main()
{
    int i,x,y;
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(id,0,sizeof(id));
        memset(head,0,sizeof(head));
        t=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            id[x][y]=id[x+1][y]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            if(id[x][y])add(id[x][y],i);
            if(id[x][y+1])add(id[x][y+1],i);
        }
        memset(re,0,sizeof(re));
        int res=n+m;
        for(i=1;i<=n;i++)
        {
            memset(vis,false,sizeof(vis));
            if(aug(i))res--;
        }
        printf("%d\n",res);
    }
}
