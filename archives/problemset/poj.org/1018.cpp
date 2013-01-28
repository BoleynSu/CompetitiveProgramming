#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
using namespace std;

#define data pair<int,int>
#define b first
#define p second

const int MAXN=100+2;
const int MAXM=1000+2;
int n;
int m[MAXN];
data d[MAXN][MAXM];

const int oo=0x7f7f7f7f;
int st[MAXN][MAXM];
int min(int a,int b)
{
    return a<b?a:b;
}
void insert(int st[MAXM],int L,int R,int position,int value,int root=1)
{
     if (position<L||R<position) return;
     st[root]=min(st[root],value);
     if (L==R) return;
     insert(st,L,(L+R)/2,position,value,root<<1);
     insert(st,(L+R)/2+1,R,position,value,(root<<1)|1);
}
int query(int st[MAXM],int L,int R,int l,int r,int root=1)
{
     if (r<L||R<l||L>R||l>r) return oo;
     if (l<=L&&R<=r) return st[root];
     return min(query(st,L,(L+R)/2,l,r,root<<1),query(st,(L+R)/2+1,R,l,r,(root<<1)|1));
}

bool data_less(const data& a,const data& b)
{
     return a.b<b.b;
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        cin>>n;
        memset(st,oo,sizeof(st));
        for (int i=1;i<=n;i++)
        {
            cin>>m[i];
            for (int j=1;j<=m[i];j++)
                cin>>d[i][j].b>>d[i][j].p;
            sort(d[i]+1,d[i]+m[i]+1,data_less);
            for (int j=1;j<=m[i];j++)
                insert(st[i],1,m[i],j,d[i][j].p);
        }
        double answer=0.0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m[i];j++)
            {
                int B=d[i][j].b;
                int P=d[i][j].p;
                bool possible=true;
                for (int k=1;k<=n;k++)
                    if (k!=i)
                    {
                       int get=query(st[k],1,m[k],lower_bound(d[k]+1,d[k]+m[k]+1,d[i][j],data_less)-d[k],m[k]);
                       if (get!=oo) P+=get;
                       else
                       {
                           possible=false;
                           break;
                       }
                    }
                if (possible&&double(B)/double(P)>answer) answer=double(B)/double(P);
            }
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<answer<<endl;
    }
    return 0;
}
