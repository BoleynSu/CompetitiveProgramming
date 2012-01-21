/*
ID: sujiao1
PROG: game1
LANG: C++
*/
/*
PROGRAM: game1
AUTHOR: Su Jiao
DATE: 2009-12-23
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
      static const int MAXN=100;//2 to 100
      static const int MAXA=200;//1 to 200
      static const int ISME=2;
      int N;
      int a[MAXN+2];
      int Sa;
      static int f[MAXN+2][MAXN+2][ISME];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),Sa(0)
      {
                              cin>>N;
                              for (int i=1;i<=N;i++)
                              {
                                  cin>>a[i];
                                  Sa+=a[i];
                              }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int min(int a,int b)
      {
          return a<b?a:b;
      }
      inline
      int max(int a,int b)
      {
          return a>b?a:b;
      }
      int dp(int l,int r,bool isMe)
      {
          if (l==r)
          {
             if (isMe) return a[l];
             else return 0;
          }
          else
          {
              if (f[l][r][isMe]) return f[l][r][isMe];
              
              if (isMe)
              {
                 f[l][r][isMe]=max(dp(l,r-1,!isMe)+a[r],dp(l+1,r,!isMe)+a[l]);
              }
              else
              {
                  f[l][r][isMe]=min(dp(l,r-1,!isMe),dp(l+1,r,!isMe));
              }
              return f[l][r][isMe];
          }
      }
      int run()
      {
          int me=dp(1,N,true);
          cout<<me<<" "<<Sa-me<<endl;
          return 0;
      }
};
int Application::f[MAXN+2][MAXN+2][ISME];

int main()
{
    Application app("game1.in","game1.out");
    return app.run();
}
