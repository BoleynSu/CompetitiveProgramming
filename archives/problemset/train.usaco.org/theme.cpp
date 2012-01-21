/*
ID: sujiao1
PROG: theme
LANG: C++
*/
/*
PROGRAM: theme
AUTHOR: Su Jiao
DATE: 2010-1-14
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
      static const int MAXN=5000;
      int N;
      int a[MAXN+2];
      int answer;
      int f[2][MAXN+2];
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output),answer(0)
      {
                        cin>>N;
                        for (int i=1;i<=N;i++) cin>>a[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int K(int k)
      {
             return k%2;
      }
      inline 
      int max(int a,int b)
      {
          return a>b?a:b;
      }
      inline
      int abs(int n)
      {
          return n>0?n:-n;
      }
      int run()
      {
          //f[i][j]=max{f[i-1][j-1]+1} (a[i]-a[i-1])==(a[j]-a[j-1])&&(i!=j)&&(abs(i-j)>f[i-1][j-1])
          answer=0;
          for (int i=1;i<=N;i++)
              for (int j=1;j<=N;j++)
              {
                  f[K(i)][j]=1;
                  if (((a[i]-a[i-1])==(a[j]-a[j-1]))&&(i!=j)&&(abs(i-j)>f[K(i-1)][j-1]))
                     f[K(i)][j]=max(f[K(i)][j],f[K(i-1)][j-1]+1);
                  if (answer<f[K(i)][j]) answer=f[K(i)][j];
                  //cout<<"f["<<i<<","<<j<<"]="<<f[K(i)][j]<<endl;
              }
          cout<<(answer>=5?answer:0)<<endl;
          return 0;
      }
};

int main()
{
    static
    Application app("theme.in","theme.out");
    return app.run();
}
