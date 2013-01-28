#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100+2;
int n;
int T[MAXN],D[MAXN],S[MAXN],E[MAXN];
int start,end;

void read_time(int& t)
{
     int h,m;
     scanf("%d:%d",&h,&m);
     t=h*60+m;
}
bool possible()
{
     int now=start;
     for (int i=1;i<=n;i++)
         if (max(now,S[i])>=min(now+T[i],E[i])) now+=T[i];
         else now+=T[i]+D[i];
     return now<end;
}

int main()
{
    for (;;)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&T[i],&D[i]),
            read_time(S[i]),read_time(E[i]);
        read_time(start),read_time(end);
        if (possible()) printf("Lucky YY!\n");
        else printf("Poor YY!\n");
    }
}

