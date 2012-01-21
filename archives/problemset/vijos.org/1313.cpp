#include <iostream>
using namespace std;

inline int max(int a,int b)
{
       return a>b?a:b;
}
int n,m;
struct data
{
      int v,p;
};

data in[60+1];
int re[60+1];

int dl;
data d[60][4];
int l[60];

const int MAX=3200;
int F[MAX+1];

void get()
{
     cin>>n>>m;
     n/=10;
     for (int i=1;i<=m;i++)
     {
         cin>>in[i].v>>in[i].p>>re[i];
         in[i].p*=in[i].v;
         in[i].v/=10;
     }
     for (int i=1;i<=m;i++)
     {
         if (re[i]==0)
         {
            d[dl][0].v=in[i].v;
            d[dl][0].p=in[i].p;
            
            for (int j=1;j<=m;j++)
            {
                if (re[j]==i)
                { 
                   l[dl]++;
                   d[dl][l[dl]].v=in[j].v+d[dl][0].v;
                   d[dl][l[dl]].p=in[j].p+d[dl][0].p;
                }
            }
            
            if (l[dl]==2)
            {
               d[dl][3].v=d[dl][1].v+d[dl][2].v-d[dl][0].v;
               d[dl][3].p=d[dl][1].p+d[dl][2].p-d[dl][0].p;
            }     
            
            if (l[dl]==0) l[dl]=1;
            else if (l[dl]==1) l[dl]=2;
            else if(l[dl]==2) l[dl]=4;
            
            dl++;
         }
     }
     for (int i=0;i<l[0];i++)
         F[d[0][i].v]=d[0][i].p;
     for (int i=1;i<dl;i++)
     {
         for (int j=n;j>=0;j--)
         {
                for (int k=0;k<l[i];k++)
                {
                    if ((j+d[i][k].v)<=n) F[j+d[i][k].v]=max(F[j+d[i][k].v],F[j]+d[i][k].p);
                }
         }
     }
     int output=0;
     for (int i=n;i>=0;i--)
     {
         if (F[i]>output) output=F[i];
     }
     cout<<output<<endl;
}

int main()
{
    get();
    return 0;
}
