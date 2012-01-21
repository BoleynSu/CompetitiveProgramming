/*
ID: sujiao1
PROG: kimbits
LANG: C++
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <ctime>
using std::clock;
class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=31;
      static unsigned int f[MAXN+2][MAXN+2];
      static unsigned int g[MAXN+2][MAXN+2];
      unsigned int N,L,I;
      int answer[MAXN+2];
      public:
      Application() :cin("kimbits.in"),cout("kimbits.out")
      {
                    cin>>N>>L>>I;
                    f[0][0]=1;
                    for (int i=1;i<=MAXN;i++)
                        for (int j=0;j<=i;j++)
                        {
                            f[i][j]=f[i-1][j]+f[i-1][j-1];
                            //cout<<i<<" "<<j<<"="<<f[i][j]<<endl;
                        }
                    for (int i=1;i<=MAXN;i++)
                        for (int j=0;j<=i;j++)
                        {
                            for (int k=0;k<=j;k++)
                                g[i][j]+=f[i][k];
                            //cout<<i<<" "<<j<<"="<<g[i][j]<<endl;
                        }
                            
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
          //cout<<clock()<<endl;
          for (int i=N;i>=1;i--)
              answer[i]=0;
          /*
          (5,_)    (4,3)    (3,2)    (2,2)    (1,1)
                   15<(19)  
                   [19]-15
                   =(4)     7>(4)    4=(4)
          1        0        0        1        1
          */
          for (int i=N;i>=1;i--)
          {
              //cout<<I<<" "<<L<<" "<<g[i][L]<<endl;
              if (g[i][L]==I)
              {
                 for (int j=i-L+1;j<=i;j++)
                 {
                     answer[j]=1;
                 }
                 break;
              }
              else if (i<L)
              {
                   L--;
                   i++;
              }
              else if (g[i][L]<I)
              {
                   answer[i+1]=1;
                   I-=g[i][L];
                   L--;
              }
          }
          for (int i=N;i>=1;i--)
              cout<<answer[i];
          cout<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};
unsigned int Application::f[MAXN+2][MAXN+2];
unsigned int Application::g[MAXN+2][MAXN+2];

int main()
{
    Application app;
    return app.run();
}
