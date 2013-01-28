#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSTEP=20;
const int MAXN=100000;
int sorted[MAXN];
int sortlist[MAXSTEP][MAXN];
int gotoleft[MAXSTEP][MAXN];
void build_RKthQ(int L,int R,int step=0)
{
     if (L!=R)
     {
        int mid=(L+R)>>1;
        int l=L,r=mid+1;
        int nextstep=step+1;
        for (int i=L;i<=R;i++)
        {
            gotoleft[step][i]=i==L?0:gotoleft[step][i-1];
            if (sortlist[step][i]<sorted[mid]) sortlist[nextstep][l++]=sortlist[step][i],gotoleft[step][i]++;
            else if (sortlist[step][i]>sorted[mid]) sortlist[nextstep][r++]=sortlist[step][i];
            else if (l<=mid) sortlist[nextstep][l++]=sortlist[step][i],gotoleft[step][i]++;
            else sortlist[nextstep][r++]=sortlist[step][i];
        }
        build_RKthQ(L,mid,nextstep);
        build_RKthQ(mid+1,R,nextstep);
     }
}
int RKthQ(int L,int R,int l,int r,int k,int step=0)
{
    while (l!=r)
    {
          int mid=(L+R)>>1;
          int lp=(l==L)?0:gotoleft[step][l-1],c=gotoleft[step][r]-lp;
          if (k<=c) R=mid,l=L+lp,r=L+lp+c-1,step++;
          else
          {
              k=k-c,lp=l-L-lp,c=r-l+1-c;
              L=mid+1,l=mid+1+lp,r=mid+1+lp+c-1,step++;
          }
    }
    return sortlist[step][l];
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>sorted[i];
    for (int i=0;i<n;i++) sortlist[0][i]=sorted[i];
    sort(sorted,sorted+n);
    build_RKthQ(0,n-1,0);
    for (int i=0;i<m;i++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        cout<<RKthQ(0,n-1,--a,--b,k)<<endl;
    }
}
