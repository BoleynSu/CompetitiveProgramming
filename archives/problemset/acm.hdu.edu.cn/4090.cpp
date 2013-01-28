#include<stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>

#define N 9

struct node
{int x,y;};


int ans,b[100],arr[9],n,m,kkk,a[N][N];

int step[2][8]={
{-1,-1,-1, 0,0, 1,1,1},
{-1, 0, 1,-1,1,-1,0,1}};

void swap(int &aa,int &bb)
{
    int t;
    t=aa;aa=bb;bb=t;
}

void dfs(int now,int ar[N][N])
{
    /*if(now>=mid)
    {
        delta=now-mid;
        return 1;
    }*/

    int i,j,used[N][N],c[N][N],i1,j1,flag=now,xxx,tt,temp[10];

    for(i=1;i<=kkk;i++)
    if(arr[i]>=3)
        flag+=b[arr[i]];
    if(flag<ans)
        return;

    int head=0,tail=1,o,nx,ny;
    node q[90];

    memset(used,0,sizeof(used));

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(used[i][j]==0 && ar[i][j]!=0)
    {
        used[i][j]=1;
        q[1].x=i;q[1].y=j;
        head=0;tail=1;
        while(head!=tail)
        {
            head++;
            for(o=0;o<8;o++)
            {
                nx=q[head].x+step[0][o];
                ny=q[head].y+step[1][o];
                if(nx<=n && nx>=1 && ny<=m && ny>=1 && used[nx][ny]==0 && ar[nx][ny]==ar[i][j])
                {
                    tail++;
                    used[nx][ny]=1;
                    q[tail].x=nx;
                    q[tail].y=ny;
                }
            }
        }
        
        if(tail>=3)
        {
            xxx=flag;
            flag=flag-b[arr[ar[i][j]]] + b[tail]+ b[arr[ar[i][j]]-tail];
            if(flag<ans)
            {
                flag=xxx;
                continue;
            }
            if(now+b[tail]>ans)
                ans=now+b[tail];
            arr[ar[i][j]]-=tail;
            for(i1=1;i1<=n;i1++)
            for(j1=1;j1<=m;j1++)
                c[i1][j1]=ar[i1][j1];
            
            for(i1=1;i1<=tail;i1++)
                c[q[i1].x][q[i1].y]=0;

            for(j1=1;j1<=m;j1++)
            {
                tt=n;
                for(i1=n;i1>0;i1--)
                if(c[i1][j1])
                {
                    swap(c[i1][j1],c[tt][j1]);
                    tt--;
                }
            }

            for(j1=1;j1<=m;j1++)
            {
                temp[j1]=0;
                for(i1=1;i1<=n;i1++)
                    temp[j1]=temp[j1] | c[i1][j1];
            }

            tt=1;
            for(j1=1;j1<=m;j1++)
            {
                
                if(temp[j1])
                {
                    for(i1=1;i1<=n;i1++)
                        swap(c[i1][tt],c[i1][j1]);                        
                    tt++;
                }
            }


/*
            printf("\n");

            for(i1=1;i1<=n;i1++)
            {
                for(j1=1;j1<=m;j1++)
                    printf("%d ",c[i1][j1]);
                printf("\n");
            }*/


            dfs(now+b[tail],c);
            arr[ar[i][j]]+=tail;
            flag=xxx;
        }
    }
}

int main()
{
    int i,j,k,L,R,mid;
    for(i=0;i<=90;i++)
        b[i]=i*i;
    while(scanf("%d%d%D",&n,&m,&kkk)!=EOF)
    {
        ans=0;
        for(i=1;i<=6;i++)
            arr[i]=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            arr[a[i][j]]++;
        }/*
        L=0;R=1<<12+1;
        while(L!=R-1)
        {
            mid=(L+R)/2;
            if (dfs(0,mid,a))
                L=mid+delta;
            else
                R=mid;
        }*/
        dfs(0,a);

        printf("%d\n",ans);
    }
    return 0;
}

