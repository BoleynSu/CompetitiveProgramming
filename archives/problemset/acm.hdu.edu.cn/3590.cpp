#include <cstdio>
#include <cstring>
using namespace std;

enum{SIZE=150};
int N;
int m;
int adjs[SIZE];
int adj[SIZE][SIZE];
int sgs[SIZE*SIZE];

int sg(int u,int f=0)
{
    int result=0;
    for (int i=0;i<adjs[u];i++)
    {
        int v=adj[u][i];
        if (v!=f)
            result=(sg(v,u)+1)^result;
    }
    return result;
}

int main()
{
    while (scanf("%d",&N)!=EOF)
    {
        int SG=0;
        int sgss=0;
        for (int i=0;i<N;i++)
        {
            scanf("%d",&m);
            memset(adjs,0,sizeof adjs);
            for (int j=1;j<m;j++)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                adj[u][adjs[u]++]=v;
                adj[v][adjs[v]++]=u;
            }
            for (int j=0;j<adjs[1];j++)
                SG=SG^(sgs[sgss++]=sg(adj[1][j],1)+1);
        }
        bool win;
        if (!SG)
        {
            win=true;
            for (int i=0;i<sgss;i++)
                if (sgs[i]>1) win=false;
        }
        else
        {
            win=false;
            for (int i=0;i<sgss;i++)
                if (sgs[i]>1) win=true;
        }
        if (!win) puts("QQ");
        else puts("PP");
    }
}

