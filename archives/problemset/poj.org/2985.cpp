#include <stdlib.h>
#include <stdio.h>

#define MAXBIT 17
#define MAXN 262144//1<<(MAXBIT+1)
#define shifted 131072////1<<MAXBIT

int st[MAXN];
int size[MAXN];
int p[MAXN];

int find(int x)
{
    if (p[x]) return p[x]=find(p[x]);
    else return x;
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++)
        size[i]=1;
    for (int value=1;value<MAXN;value+=value&(-value)) st[value]+=N;
    for (int m=0;m<M;m++)
    {
        int C;
        scanf("%d",&C);
        if (C)
        {
           int k;
           scanf("%d",&k);
    
    int index=N-k+1;
    int value=0;
    for (int i=shifted;i;i>>=1)
    {
        value|=i;
        if (st[value]>=index) value^=i;
        else index-=st[value];
    }
    
           printf("%d\n",value+1);
        }
        else
        {
            int i,j;
            scanf("%d%d",&i,&j);
            i=find(i);
            j=find(j);
            if (i==j) continue;
            N--;
            p[i]=j;
            for (int value=size[i];value<MAXN;value+=value&(-value)) st[value]--;
            for (int value=size[j];value<MAXN;value+=value&(-value)) st[value]--;
            size[j]+=size[i];
            for (int value=size[j];value<MAXN;value+=value&(-value)) st[value]++;
        }
    }
}
