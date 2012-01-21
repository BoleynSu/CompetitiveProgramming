/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-15
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define MAXNODE 2000

int K;
int map[MAXNODE][MAXNODE];
int T;
int S1,S2;

int main()
{
    scanf("%d\n",&K);
    for (int i=1;i<=K;i++)
    {
        int u,v;
        scanf("%d %d\n",&u,&v);
        map[u-1][v-1]=i;
    }
    scanf("%d %d %d\n",&T,&S1,&S2);
    
    bool inq[MAXNODE];
    int q[MAXNODE];
    int open=0,close=0;
    int dis[MAXNODE];
    int pre[MAXNODE];
    memset(inq,false,sizeof(inq));    
    inq[q[open++]=S1-1]=true;
    pre[S1-1]=S1-1;
    dis[S1-1]=0;
    inq[q[open++]=S2-1]=true;
    pre[S2-1]=S2-1;
    dis[S2-1]=0;
    while (close<open)
    {
          int now=q[close++];
          for (int i=0;i<MAXNODE;i++)
              if (map[now][i]&&!inq[i])
              {
                 inq[q[open++]=i]=true;
                 pre[i]=now;
                 dis[i]=dis[now]+1;
              }
    }
    if (inq[T-1])
    {
       printf("%d\n",dis[T-1]);       
       int s[MAXNODE];
       int top=0;
       int u=T-1;
       while (pre[u]!=u)
             u=pre[s[top++]=u];
       s[top++]=u;
       for (int i=top-1;i>0;i--)
           printf("%d\n",map[s[i]][s[i-1]]);
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}
