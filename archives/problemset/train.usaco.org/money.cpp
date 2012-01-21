/*
ID: sujiao1
PROG: money
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::endl;
using std::string;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("money.in");
std::ofstream cout("money.out");

struct Program
{
       static const int MAXV=25;//1 to 25
       static const int MAXN=10000;//1 to 10000
       int N,V;
       int v[MAXV+2];
       unsigned long long f[MAXN+2];
       Program()
       {
                cin>>V>>N;
                for (int i=1;i<=V;i++)
                    cin>>v[i];
       }
       struct DP
       {
              unsigned long long **f;
              bool dp[MAXV+2][MAXN+2];
              int* v;
              DP(int V,int N,int* vlist)
              {
               v=vlist;
               for (int i=0;i<=V;i++)
                   for (int j=0;j<=N;j++)
                       dp[i][j]=false;
               f=new unsigned long long *[MAXV+2];
               for (int i=0;i<=V;i++)
                   f[i]=new unsigned long long[MAXN+2];
               cout<<dpf(V,N)<<endl;
               }
               unsigned long long dpf(int k,int i)
               {
                        if (k==0)
                        {
                           if (i==0) return 1;
                           else return 0;
                        }
                        if (dp[k][i]) return f[k][i];
                        f[k][i]=0;
                        for (int j=0;v[k]*j<=i;j++)
                            f[k][i]+=dpf(k-1,i-v[k]*j);
                        dp[k][i]=true;
                        return f[k][i];
               }
       };
       inline
       int K(int k)
       {
           return k%2;
       }
       int run()
       {
           //N=sum{a[i]*v[i]}
           //f[0][0]=1
           //f[0][other]=0
           //f[k][i]=sum{f[k-1][i-v[k]*j]}
           /*
           for (int i=0;i<=N;i++)
               f[K(0)][i]=0;
           f[K(0)][0]=1;
           for (int k=1;k<=V;k++)
               for (int i=0;i<=N;i++)
               {
                   f[K(k)][i]=0;
                   for (int j=0;j*v[k]<=i;j++)
                       f[K(k)][i]+=f[K(k-1)][i-v[k]*j];
               }
           cout<<f[K(V)][N]<<endl;
           */
           
           for (int i=10;i<=N;i++) f[i]=0;
           f[0]=1;
           for (int k=1;k<=V;k++)
               for (int i=v[k];i<=N;i++)
                   f[i]+=f[i-v[k]];
           cout<<f[N]<<endl;
           
           //DP(V,N,v);
           //cout<<clock()<<endl;
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
