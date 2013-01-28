#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=16;
const int MAXS=1<<MAXN;

int N,M;
int s[MAXS];
int v[MAXS];
int f[MAXS];
int answer;

int main()
{
    for (;;)
    {
        scanf("%d",&N);
        if (N==0) break;
        scanf("%d",&M);
        memset(v,0,sizeof(v));
        for (int i=0;i<M;i++)
            scanf("%d",&s[i]),
            scanf("%d",&v[s[i]]);
        answer=0;
        memset(f,0,sizeof(f));
        for (int i=0;i<M;i++) f[s[i]]=v[s[i]];
        for (int i=0;i<N;i++)
            for (int j=0;j<(1<<N);j++)
                if (j&(1<<i)) f[j]+=f[j-(1<<i)];
        for (int i=0;i<(1<<N);i++)
            if (answer<f[i]) answer=f[i];
        printf("%d\n",answer);
    }
}

