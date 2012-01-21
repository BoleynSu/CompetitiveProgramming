/*
ID: sujiao1
PROG: nocows
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
std::ifstream cin("nocows.in");
std::ofstream cout("nocows.out");

struct Program
{
       static const int MAXN=200;//3 to 200
       static const int MAXK=100;//1 to 100
       int N,K;
       long long int f[MAXN+2][MAXK+2];
       long long int g[MAXN+2][MAXK+2];
       Program()
       {
                cin>>N>>K;
       }
       int run()
       {
           /*
           //f[1][1]=1
           //f[1][other]=0
           //f[n][k]=sum{f[i][k-1]*f[n-1-i][k-1]}
           //        +sum{f[i][k-1]*f[n-1-i][k2]} k2=k-2 to 1
           //        +sum{f[i][k2]*f[n-1-i][k-1]} k2=k-2 to 1
           //         i=0 to n-1
           for (int n=0;n<=MAXN;n++)
               f[n][1]=0;
           f[1][1]=1;
           for (int k=2;k<=K;k++)
           {
               for (int n=0;n<=N;n++)
               {
                   f[n][k]=0;
                   for (int i=0;i<n;i++)
                   {
                       f[n][k]+=(f[i][k-1]*f[n-1-i][k-1]%9901);
                       for (int k2=k-2;k2>=1;k2--)
                           f[n][k]+=(f[i][k-1]*f[n-1-i][k2]%9901);
                       for (int k2=k-2;k2>=1;k2--)
                           f[n][k]+=(f[i][k2]*f[n-1-i][k-1]%9901);
                   }
                   //cout<<"f["<<n<<","<<k<<"]="<<f[n][k]<<endl;
               }
           }
           cout<<f[N][K]%9901<<endl;
           */
           for (int n=0;n<=MAXN;n++)
               g[n][1]=f[n][1]=0;
           g[1][1]=f[1][1]=1;
           
           for (int k=2;k<=K;k++)
           {
               for (int n=0;n<=N;n++)
               {
                   f[n][k]=0;
                   for (int i=0;i<n;i++)
                   {
                       f[n][k]+=(
                       (f[i][k-1]*g[n-1-i][k-1]%9901)
                       +(f[n-1-i][k-1]*g[i][k-1]%9901)
                       -(f[i][k-1]*f[n-1-i][k-1]%9901))%9901;
                   }
                   g[n][k]=(g[n][k-1]+f[n][k])%9901;
                   //cout<<"f["<<n<<","<<k<<"]="<<f[n][k]<<endl;
               }
           }
           cout<<f[N][K]%9901<<endl;
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
