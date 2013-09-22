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

#define pb push_back
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
//const int N=10020;
//int n;
//float a[N];
//int p[N],top=0;
//bool flag[N];
//int r[N];
//float ans;
//int A[N],sz;
//void init_p()
//{
//    int i,j;
//    for(i=2;i<N;i++)
//    {
//        if(!flag[i])p[++top]=i;
//        for(j=1;j<=top&&i*p[j]<N;j++)
//        {
//            flag[i*p[j]]=true;
//            if(i%p[j]==0)break;
//        }
//    }
//    for(i=1;i<=top;i++)
//        a[i]=log(p[i]);
//}
//void dfs(int dep,int sum,float now)
//{
//    int i,k;
//    if(now>ans)
//    {
//        ans=now;
//        for(i=1;i<dep;i++)
//            A[i]=r[i];
//        sz=dep-1;
//    }
//    for(i=1,k=p[dep];k+sum<=n;k*=p[dep],i++);
//    i--;i=min(i,r[dep-1]);k/=p[dep];
//    for(;i;i--)
//    {
//        r[dep]=i;
//        dfs(dep+1,sum+k,now+a[dep]*i);
//        k/=p[dep];
//    }
//}
//vector<int>path,pt;
//int main()
//{
//    int s,i,cas,j,k;
//    init_p();
//    r[0]=14;
//
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        ans=-1;
//        scanf("%d",&n);
//        dfs(1,0,0);
//        path.clear();
//        s=n;
//
//
//
//        int mark=0;
//        for(i=1;i<=sz;i++)
//        {
//            k=1;
//            for(j=1;j<=A[i];j++)
//            {
//                k*=p[i];
//                if(A[i]>0)
//                    mark=i;
//            }
//            s-=k;
//            //path.pb(k);
//        }
//
//        int j=0;
//        while(p[mark+j+1]-p[mark]>=s)
//            j++;
//
//        cout<<s<<"!!!"<<endl;
//
////        s-=p[mark+j]-p[mark];
////        A[mark]=0;
////        A[mark+j]=1;
//
////        for(i=1;i<=sz;i++)
////        {
////            k=1;
////            for(j=1;j<=A[i];j++)
////                k*=p[i];
//            //s-=k;
////            path.pb(k);
////        }
//
//        for(i=1;i<=s;i++)
//            path.pb(1);
//        sort(path.begin(),path.end());
//
//
//
//        //for(int i=0;i<path.size();i++)
//        //    printf("%d ",path[i]);
//        //printf("\n");
//
//        int st=1;
//        for(int i=0;i<path.size();i++){
//            //st+=path[i];
//            for(int j=st+1;j<st+path[i];j++)
//                printf("%d ",j);
//            if(i!=path.size()-1)
//                printf("%d ",st);
//            else
//                printf("%d\n",st);
//            st+=path[i];
//
//        }
//
//    }
//}
const int N=10000;
float f[1232][N+5];
int pre[1232][N+5];
int n;
int p[1400],top=0;
bool flag[N];
float a[1400];
vector<int>ans;
void get(int size)
{
    ans.clear();
    int i=top,j=size;
    for(i=top;i;i--)
    {
        if(pre[i][j])ans.pb(pre[i][j]);
        j-=pre[i][j];
    }
    while(j--)ans.pb(1);
    sort(ans.begin(),ans.end());
}
void init()
{
    int i,j,k,t;
    for(i=2;i<=N;i++)
    {
        if(!flag[i])p[++top]=i,a[top]=log(1.0*p[top]);
        for(j=1;j<=top&&i*p[j]<=N;j++)
        {
            flag[i*p[j]]=true;
            if(i%p[j]==0)break;
        }
    }
    for(i=1;i<=top;i++)
    {
        for(j=0;j<=N;j++)
            f[i][j]=f[i-1][j],pre[i][j]=0;
        for(j=p[i],t=1;j<=N;j=j*p[i],t++)
        {
            for(k=j;k<=N;k++)
                if(f[i][k]<f[i-1][k-j]+a[i]*t)
                {
                    f[i][k]=f[i-1][k-j]+a[i]*t;
                    pre[i][k]=j;
                }
        }
    }
}
int main()
{
    int cas,i;
    init();
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        get(n);
//        for(i=0;i<ans.size();i++)
//            printf("%d ",ans[i]);
//        puts("");
        int cur=1;
        for (int i=0;i<ans.size();i++)
        {
            for (int j=1;j<ans[i];j++) printf("%d ",cur+j);
            printf("%d",cur);
            cur+=ans[i];
            if (cur!=n+1)
                printf(" ");
        }
        puts("");
    }
}
