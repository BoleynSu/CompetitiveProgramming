/*
ID: sujiao1
PROG: stall4
LANG: C++
*/
/*
PROGRAM: stall4
AUTHOR: Su Jiao
DATE: 2010-1-5
DESCRIPTION:
农夫约翰上个星期刚刚建好了他的新牛棚，他使用了最新的挤奶技术。不幸的是，由于工程
问题，每个牛栏都不一样。第一个星期，农夫约翰随便地让奶牛们进入牛栏，但是问题很快
地显露出来：每头奶牛都只愿意在她们喜欢的那些牛栏中产奶。上个星期，农夫约翰刚刚收
集到了奶牛们的爱好的信息（每头奶牛喜欢在哪些牛栏产奶）。一个牛栏只能容纳一头奶
牛，当然，一头奶牛只能在一个牛栏中产奶。 
给出奶牛们的爱好的信息，计算最大分配方案。 
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
      static const int MAXM=402;
      static const int oo=1;
      int M;
      int c[MAXM+2][MAXM+2];
      int f[MAXM+2][MAXM+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              memset(c,0,sizeof(c));
                              int N,_M;
                              cin>>N>>_M;
                              for (int n=1;n<=N;n++)
                              {
                                  int end;
                                  cin>>end;
                                  for (int j=1;j<=end;j++)
                                  {
                                      int m;
                                      cin>>m;
                                      c[n][N+m]=1;
                                  }
                              }
                              for (int i=1;i<=N;i++) c[N+_M+1][i]=oo;
                              for (int j=N+1;j<=N+_M;j++) c[j][N+_M+2]=oo;
                              M=N+_M+2;
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
      int maxFlow(int s,int t)
      {
          memset(f,0,sizeof(f));
          int p[MAXM+2];
          int value[MAXM+2];
          int U[MAXM+2];
          int U_open,U_close;
          for (;;)
          {
              memset(p,0,sizeof(p));
              memset(value,0,sizeof(value));
              p[s]=s;
              value[s]=oo;
              U_open=1;
              U_close=1;
              U[U_close]=s;
              while (!p[t])
              {
                    if (U_close>U_open) return calcFlow(s,t);
                    int v=U[U_close++];
                    for (int i=1;i<=M;i++)
                        if (c[v][i]&&(!p[i])&&(c[v][i]>f[v][i]))
                        {
                           U[++U_open]=i;
                           p[i]=v;
                           value[i]=min(value[v],c[v][i]-f[v][i]);
                        }
                    for (int i=1;i<=M;i++)
                        if (c[i][v]&&(!p[i])&&(f[i][v]>0))
                        {
                           U[++U_open]=i;
                           p[i]=v;
                           value[i]=min(value[v],f[i][v]);
                        }
              }
              int v=t;
              int dvalue=value[t];
              while (v!=s)
              {
                    int u=p[v];
                    if (c[u][v]>0)
                       f[u][v]+=dvalue;
                    else
                        f[u][v]-=dvalue;
                    v=u;
              }
          }
      }
      int calcFlow(int s,int t)
      {
          int v=0;
          for (int i=1;i<=M;i++)
              v+=f[s][i];
          return v;
      }
      int run()
      {
          cout<<maxFlow(M-1,M)<<endl;
          return 0;
      }
};

int main()
{
    Application app("stall4.in","stall4.out");
    return app.run();
}
