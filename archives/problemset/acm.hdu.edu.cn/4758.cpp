#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include <cmath>
#include <map>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;

const int oo=19930309;
typedef long long big;
typedef pair<int,int> pii;
const int N=102;
const int MOD=1000000007;
int l1,l2,n,m;
struct node
{
    node *c[2],*fail;
    int id,flag;
}mem[300],*nul,*root,*cur;
int f[2][N][206][4];
node *q[300];
char str[200];
int cz(char x){if(x=='R')return 0;return 1;}
int dx[]={1,0},dy[]={0,1};
node *newnode()
{
    node *p=cur++;
    p->c[0]=p->c[1]=nul;
    p->flag=0;p->id=p-mem;
    p->fail=root;
    return p;
}
void ins(int x)
{
    int i;
    node *now=root;
    for(i=0;str[i];i++)
    {
        if(now->c[cz(str[i])]==nul)now->c[cz(str[i])]=newnode();
        now=now->c[cz(str[i])];
    }
    now->flag|=1<<x;
}
void bfs()
{
    int i,h,tail;
    node *s,*v;
    root->fail=root;
    q[h=tail=1]=root;
    while(h<=tail)
    {
        s=q[h++];
        for(i=0;i<2;i++)
        {
            if(s->c[i]==nul)s->c[i]=s->fail->c[i];
            else
            {
                q[++tail]=s->c[i];
                if(s!=root)
                {
                    v=s->fail;
                    s->c[i]->fail=v->c[i];
                    s->c[i]->flag|=s->c[i]->fail->flag;
                }
            }
        }
    }
}
int main()
{
    int cas,i,j,k,idx,p;
    int ans;
    scanf("%d",&cas);
    node *s;
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        swap(n,m);
        nul=root=mem;cur=mem+1;
        root->id=0;
        root->fail=root;
        nul->c[0]=nul->c[1]=nul;
        nul->flag=0;
        root->c[0]=newnode();
        root->c[1]=newnode();
        scanf("%s",str);
        ins(0);
        scanf("%s",str);
        ins(1);
        bfs();
        idx=0;
        ans=0;
        memset(f,0,sizeof(f));
        f[0][0][root->id][0]=1;
        for(i=0;i<=n;i++)
        {
            memset(f[!idx],0,sizeof(f[!idx]));
            for(j=0;j<=m;j++)
                for(s=mem;s<cur;s++)
                    for(k=0;k<4;k++)
                    if(f[idx][j][s->id][k])
                    {
                        if(i==n&&j==m&&k==3)
                        {
                            ans+=f[idx][j][s->id][k];
                            if(ans>=MOD)ans-=MOD;
                        }
                        if(j<m)
                        {
                            f[idx][j+1][s->c[0]->id][k|s->c[0]->flag]+=f[idx][j][s->id][k];
                            if(f[idx][j+1][s->c[0]->id][k|s->c[0]->flag]>=MOD)
                                f[idx][j+1][s->c[0]->id][k|s->c[0]->flag]-=MOD;
                        }
                        if(i<n)
                        {
                            f[!idx][j][s->c[1]->id][k|s->c[1]->flag]+=f[idx][j][s->id][k];
                            if(f[!idx][j][s->c[1]->id][k|s->c[1]->flag]>=MOD)
                                f[!idx][j][s->c[1]->id][k|s->c[1]->flag]-=MOD;
                        }
                    }
            idx^=1;
        }
        printf("%d\n",ans);

    }
}
