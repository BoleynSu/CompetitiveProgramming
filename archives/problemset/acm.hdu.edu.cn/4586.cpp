
#include <cstdio>
#include <iostream>
using namespace std;

typedef double db;
#define rep(i,n) for (int i=0;i<(n);i++)

int n,m;
int a[10000];
int b[10000];

int main()
{
    while (cin>>n)
    {
        rep(i,n) cin>>a[i];
        cin>>m;
        rep(i,m) cin>>b[i];
        int sum=0;
        rep(i,n) sum+=a[i];
        db get=db(sum)/n;
        db p=db(m)/db(n);
        db ans;
        if (sum) ans=get/(1-p);
        else ans=0;
        if (m==n&&sum) puts("inf");
        else printf("%.2f\n",ans);
    }
}

