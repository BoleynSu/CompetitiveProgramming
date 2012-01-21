/*
ID: sujiao1
PROG: rockers
LANG: C++
*/
/*
PROGRAM: rockers
AUTHOR: Su Jiao
DATE: 2009-12-28
DESCRIPTION:
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=20;
      static const int MAXM=20;
      static const int MAXT=20;
      int N,T,M;
      int p[MAXN+2];
      int f[MAXN+2][MAXT+2][MAXM+2];
      bool g[MAXN+2][MAXT+2][MAXM+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>N>>T>>M;
                              for (int i=1;i<=N;i++) cin>>p[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int max(int a,int b)
      {
          return a>b?a:b;
      }
      /*
      f(n,t,m)=max(f(n-1,t-p[n],m)+1 if (t>=p[n])
                   f(n,T,m-1) else
                   ,f(n-1,t,m)
                  )
      */
      int dp(int n,int t,int m)
      {
          if (g[n][t][m]) return f[n][t][m];
          
          g[n][t][m]=true;
          f[n][t][m]=0;
          
          if ((n!=0)&&(m!=0))
          {
              if (t>=p[n])
                 f[n][t][m]=max(f[n][t][m],dp(n-1,t-p[n],m)+1);
              else
                  f[n][t][m]=max(f[n][t][m],dp(n,T,m-1));
                  
              f[n][t][m]=max(f[n][t][m],dp(n-1,t,m));
          }
          //cout<<"f["<<n<<","<<t<<","<<m<<"]="<<f[n][t][m]<<endl;
          return f[n][t][m];
      }
      int run()
      {
          //k //N
          //sk //[T,M]
          //xk //0 1
          //vk //0 1
          //sk_1=g(sk,xk)
          //fk(sk)=max{fk_1(sk_1)+vk}
          //BY FOR LOOP
          memset(g,false,sizeof(g));
          cout<<dp(N,T,M)<<endl;
          return 0;
      }
};

int main()
{
    Application app("rockers.in","rockers.out");
    return app.run();
}
