#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cmath>
#include<complex>
#define pb push_back
#define mp make_pair
double PI=acos(-1.0);
using namespace std;
const int N=1<<18;
int L;
struct CP
{
    double x,y;
    CP(){}
    CP(double _x,double _y):x(_x),y(_y){}
    CP operator+(const CP &b)const{return CP(x+b.x,y+b.y);}
    CP operator-(const CP &b)const{return CP(x-b.x,y-b.y);}
    CP operator*(const CP &b)const{return CP(x*b.x-y*b.y,x*b.y+y*b.x);}
};
CP A[N],B[N],C[N],w[N],tt[N];
int ans[N];
char str[N];
void dft(CP *a,int s,int t)
{
    if((L>>t)==1)return ;
    dft(a,s,t+1);
    dft(a,s+(1<<t),t+1);
    int i,p;
    static CP W;
    for(i=0;i<L>>(t+1);i++)
    {
        p=(i<<(t+1))+s;
        W=w[i<<t]*a[p+(1<<t)];
        tt[i]=a[p]+W;
        tt[i+(L>>(t+1))]=a[p]-W;
    }
    for(i=0;i<L>>t;i++)a[(i<<t)+s]=tt[i];
}

const int MAXN=100000;
int n;
int a[MAXN];
long long int ff[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int maxa=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (maxa<a[i]) maxa=a[i];
        }
        L=1;
        while (L<=maxa) L<<=1;
        L<<=1;
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        for (int i=0;i<n;i++) A[a[i]].x++,B[a[i]].x++;
        for(int i=0;i<L;i++) w[i]=CP(cos(PI*2*i/L),sin(PI*2*i/L));
        dft(A,0,0);
        dft(B,0,0);
        int i;
        for(i=0;i<L;i++) A[i]=A[i]*B[i];
        for(i=0;i<L;i++) w[i].y=-w[i].y;
        dft(A,0,0);
        for (int i=0;i<L;i++) ff[i]=(A[i].x/L)+0.5;
        sort(a,a+n);
        long long ans=0;
        for(int i=0;i<=a[n-1]+a[n-1];i++)
        if(ff[i]!=0)
        {
            long long ke=lower_bound(a,a+n,i)-a;
            ans=ans+ke*ff[i];
            ke=n-ke;
            ans=ans-(ke*ff[i])*2;
        }

        for(int i=0;i<n;i++)
        {
            long long ke=lower_bound(a,a+n,a[i]+a[i])-a;
            ans=ans-ke*3+2;
        }
        double tmp=n;
        tmp=tmp*(tmp-1)*(tmp-2);
        printf("%.7f\n",ans/tmp);
    }
}
