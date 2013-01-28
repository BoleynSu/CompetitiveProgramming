#include <cstring>
#include <cstdio>
using namespace std;

enum{MAXN=200+2,oo=(~0u)>>5};
int n;
int T[MAXN],D[MAXN];
int F[MAXN][MAXN];
int G[MAXN][MAXN];

/*
void calc(int f,int t)
{
    if (G[f][t]) return;
    int wait,nf,nt;
    F[f][t]=+oo;
    if (f<t)
    {
        nf=t,nt=f;
        wait=T[nt]-(D[nf]-D[nt]);
        calc(nf,nt+1);
        if (F[nf][nt+1]<wait)
        {
            if (F[f][t]>F[nf][nt+1]+(D[nf]-D[nt]))
            {
                F[f][t]=F[nf][nt+1]+(D[nf]-D[nt]);
                G[f][t]=-nt;
            }
        }

        nf=f,nt=t;
        wait=T[nf]-(D[nf+1]-D[f]);
        calc(nf+1,nt);
        if (F[nf+1][nt]<wait)
        {
            if (F[f][t]>F[nf+1][nt]+(D[nf+1]-D[f]))
            {
                F[f][t]=F[nf+1][nt]+(D[nf+1]-D[f]);
                G[f][t]=nf;
            }
        }
    }
    else if (f>t)
    {
        nf=t,nt=f;
        wait=T[nt]-(D[nt]-D[nf]);
        calc(nf,nt-1);
        if (F[nf][nt-1]<wait)
        {
            if (F[f][t]>F[nf][nt-1]+(D[nt]-D[nf]))
            {
                F[f][t]=F[nf][nt-1]+(D[nt]-D[nf]);
                G[f][t]=-nt;
            }
        }

        nf=f,nt=t;
        wait=T[nf]-(D[f]-D[nf-1]);
        calc(nf-1,nt);
        if (F[nf-1][nt]<wait)
        {
            if (F[f][t]>F[nf-1][nt]+(D[f]-D[nf-1]))
            {
                F[f][t]=F[nf-1][nt]+(D[f]-D[nf-1]);
                G[f][t]=nf;
            }
        }
    }
    else
    {
        F[f][t]=0;
    }
}
*/
/*
void print(int f,int t)
{
    if (f<t)
    {
        if (f==G[f][t])
        {
            printf("%d ",f);
            print(f+1,t);
        }
        else
        {
            printf("%d ",f);
            print(t,f+1);
        }
    }
    else if (f>t)
    {
        if (f==G[f][t])
        {
            printf("%d ",f);
            print(f-1,t);
        }
        else
        {
            printf("%d ",f);
            print(t,f-1);
        }
    }
    else
    {
        printf("%d\n",f);
    }
}
*/

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",T+i);
        for (int i=1;i<=n;i++) scanf("%d",D+i);
        memset(G,0,sizeof G);
        for (int i=1;i<n;i++)
            for (int j=1;j+i<=n;j++)
            {
                int f,t;
                int wait,nf,nt;

                f=j,t=i+j;
                F[f][t]=+oo;

                nf=f,nt=t;
                wait=T[nf]-(D[nf+1]-D[f]);
                if (F[nf+1][nt]<wait)
                {
                    if (F[f][t]>F[nf+1][nt]+(D[nf+1]-D[f]))
                    {
                        F[f][t]=F[nf+1][nt]+(D[nf+1]-D[f]);
                        G[f][t]=nf;
                    }
                }
                nf=t,nt=f;
                wait=T[nt]-(D[nf]-D[nt]);
                if (F[nf][nt+1]<wait)
                {
                    if (F[f][t]>F[nf][nt+1]+(D[nf]-D[nt]))
                    {
                        F[f][t]=F[nf][nt+1]+(D[nf]-D[nt]);
                        G[f][t]=-nt;
                    }
                }

                f=i+j,t=j;
                F[f][t]=+oo;

                nf=f,nt=t;
                wait=T[nf]-(D[f]-D[nf-1]);
                if (F[nf-1][nt]<wait)
                {
                    if (F[f][t]>F[nf-1][nt]+(D[f]-D[nf-1]))
                    {
                        F[f][t]=F[nf-1][nt]+(D[f]-D[nf-1]);
                        G[f][t]=nf;
                    }
                }
                nf=t,nt=f;
                wait=T[nt]-(D[nt]-D[nf]);
                if (F[nf][nt-1]<wait)
                {
                    if (F[f][t]>F[nf][nt-1]+(D[nt]-D[nf]))
                    {
                        F[f][t]=F[nf][nt-1]+(D[nt]-D[nf]);
                        G[f][t]=-nt;
                    }
                }
            }
        int pf=0,pt=0;
        if (F[1][n]<T[1]&&F[n][1]<T[n])
        {
            if (F[1][n]<F[n][1]) pf=1,pt=n;
            else pf=n,pt=1;
        }
        else if (F[1][n]<T[1]) pf=1,pt=n;
        else if(F[n][1]<T[n]) pf=n,pt=1;
        else printf("Mission Impossible\n");
        while (pf&&pt)
        {
            int f=pf,t=pt;
            if (f<t)
            {
                if (f==G[f][t])
                {
                    printf("%d ",f);
                    pf=f+1,pt=t;
                }
                else
                {
                    printf("%d ",f);
                    pf=t,pt=f+1;
                }
            }
            else if (f>t)
            {
                if (f==G[f][t])
                {
                    printf("%d ",f);
                    pf=f-1,pt=t;
                }
                else
                {
                    printf("%d ",f);
                    pf=t,pt=f-1;
                }
            }
            else
            {
                printf("%d\n",f);
                pf=0,pt=0;
            }
        }
    }
}

