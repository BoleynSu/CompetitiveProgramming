#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

enum{MAXN=199339};
int N;
int a[MAXN];
int b[MAXN];
int bh,bt;

int main()
{
    int T;
    scanf("%d\n",&T);
    while (T--)
    {
        scanf("%d",&N);
        for (int i=1;i<=N;i++)
            scanf("%d",a+i);
        bh=0,bt=-1;
        int answer=N;
        a[0]=a[N+1]=0;
        for (int i=1;i<=N+1;i++)
            if (a[i-1]<a[i])
            {
                int k=a[i]-a[i-1];
                while (k--) b[++bt]=i;
            }
            else if (a[i-1]>a[i])
            {
                int k=a[i-1]-a[i];
                while (k--) answer=min(answer,i-b[bh++]);
            }
        printf("%d\n",answer);
    }
}

