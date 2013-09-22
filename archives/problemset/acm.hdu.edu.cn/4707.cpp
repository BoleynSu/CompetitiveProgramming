#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge{
    int u,v,n;
};
edge e[200010];
int next[100010],d;

int top;

void add(int u,int v){
    e[++top].u=u;e[top].v=v;e[top].n=next[u];next[u]=top;
    e[++top].u=v;e[top].v=u;e[top].n=next[v];next[v]=top;
}



long long dfs(int u,int p,int dis){
    int v=0,num=1;

    if(dis>=d)
        return num;

    for(int i=next[u];i;i=e[i].n)
    if((v=e[i].v)!=p)
    {
        num+=dfs(v,u,dis+1);
    }
    return num;
}

int main()
{
    int cas,n,x,y;
    scanf("%d",&cas);
    while(cas--){

        top=0;
        memset(next,0,sizeof(next));
        scanf("%d%d",&n,&d);

        for(int i=1;i<n;i++)
            scanf("%d%d",&x,&y),add(x,y);

        long long ans=dfs(0,0,0);
        ans=n-ans;
        printf("%I64d\n",ans);
    }
    return 0;
}
