#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

//#define pb push_back
#define mp make_pair
typedef long long big;

//const int N=100020;
//int f[1<<20],cnt[1<<20];
//int idx;
//int ans;
//char cmd[290];
//int a[N];
//bool cmp(const int &x,const int &y)
//{
//    return cnt[x]<cnt[y];
//}
//int cn(char x)
//{
//    if(x>='0'&&x<='9')return x-'0';
//    return x-'A'+10;
//}
//int num()
//{
//    int i,s=0;
//    scanf("%s",cmd);
//    for(i=0;cmd[i];i++)
//        s*=16,s+=cn(cmd[i]);
//    return s;
//}
//int ct(int x)
//{
//    int s=0;
//    while(x)
//    {
//        x-=x&-x;
//        s++;
//    }
//    return s;
//}
//void pri(int x)
//{
//    int i;
//    for(i=0;i<20;i++)
//        printf("%d",x>>i&1);
//    puts("");
//}
//
//int main()
//{
//    int x,n,cas,i;
//    for(i=1;i<(1<<20);i++)
//        cnt[i]=ct(i);
//    scanf("%d",&cas);
//    idx=2;
//    while(cas--)
//    {
//        memset(f,0x3f,sizeof(f));
//        idx++;
//        ans=1<<30;
//        scanf("%d",&n);
//        for(i=1;i<=n;i++)
//        {
//            a[i]=num();
//        }
//        sort(a+1,a+1+n,cmp);
//        for(i=1;i<=n;i++)X=a[i],
//            dfs(a[i]);
//        printf("%d\n",ans);
//    }
//}
const int M=120,N=1020;
double a[M][M],b[M][M],pa[M][M],pb[M][M];
double f[N][M];
int pre[N][M];
int n,m,w;
int weather[N];
const double inf=2e9,inf2=1e9;
bool ck0(double x){return x<1e-9;}
bool able(double x){return x>-inf2;}
vector<int>ans,tmp;
void sol()
{
    int i,j,k;
    i=n;k=1;
    ans.clear();
    for(j=1;j<=m;j++)
        if(f[i][j]>f[i][k])k=j;
    int t=k;;
    for(k=1;k<=m;k++)
        if(fabs(f[n][t]-f[n][k])<1e-9)
        {
            i=n;j=k;
            tmp.clear();
            for(;i;i--)
            {
                tmp.push_back(j);
                j=pre[i][j];
            }
            reverse(tmp.begin(),tmp.end());
            if(!ans.size())ans=tmp;
            else if(ans>tmp)ans=tmp;
        }
}
int main()
{
    int cas,i,j,k,p;
    double x;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(i=1;i<=n;i++)
            scanf("%d",&weather[i]),weather[i]++;
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%lf",&a[i][j]);
                if(ck0(a[i][j]))pa[i][j]=-inf;
                else pa[i][j]=log(a[i][j]);
            }
        for(i=1;i<=m;i++)
            for(j=1;j<=w;j++)
            {
                scanf("%lf",&b[i][j]);
                if(ck0(b[i][j]))pb[i][j]=-inf;
                else pb[i][j]=log(b[i][j]);
            }
        for(i=0;i<=n;i++)
            for(j=1;j<=m;j++)
                f[i][j]=-inf;
        f[0][1]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            if(able(f[i-1][j]))
            {
                x=-inf;
                for(k=1;k<=m;k++)
                    if(f[i][k]<f[i-1][j]+pa[j][k]+pb[k][weather[i]])
                    {
                        f[i][k]=f[i-1][j]+pa[j][k]+pb[k][weather[i]];
                        pre[i][k]=j;
                    }
            }
        }
//        for(i=1;i<=n;i++,puts(""))
//            for(j=1;j<=m;j++)
//                printf("%f ",f[i][j]);
        sol();
        for(i=0;i<ans.size();i++)
        {
            if(i)printf(" ");
            printf("%d",ans[i]-1);
        }
        puts("");
    }
}
