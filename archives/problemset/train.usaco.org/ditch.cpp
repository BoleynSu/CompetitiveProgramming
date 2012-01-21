/*
ID: sujiao1
PROG: ditch
LANG: C++
*/
/*
PROGRAM: ditch
AUTHOR: Su Jiao
DATE: 2010-1-4
DESCRIPTION:
在农夫约翰的农场上，每逢下雨，Bessie最喜欢的三叶草地就积聚了一潭水。这意味着草
地被水淹没了，并且小草要继续生长还要花相当长一段时间。因此，农夫约翰修建了一套
排水系统来使贝茜的草地免除被大水淹没的烦恼（不用担心，雨水会流向附近的一条小
溪）。作为一名一流的技师，农夫约翰已经在每条排水沟的一端安上了控制器，这样他可
以控制流入排水沟的水流量。 
农夫约翰知道每一条排水沟每分钟可以流过的水量，和排水系统的准确布局（起点为水潭
而终点为小溪的一张网）。需要注意的是，有些时候从一处到另一处不只有一条排水沟。 
根据这些信息，计算从水潭排水到小溪的最大流量。对于给出的每条排水沟，雨水只能沿
着一个方向流动，注意可能会出现雨水环形流动的情形。
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
      static const int MAXM=200;
      static const int oo=1024*1024*1024;
      int M;
      //C((v,u))=c[v][u]
      int c[MAXM+2][MAXM+2];
      //F((v,u))=f[v][u]
      int f[MAXM+2][MAXM+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              int N;
                              cin>>N>>M;
                              memset(c,0,sizeof(c));
                              for (int i=1;i<=N;i++)
                              {
                                  int v,u;
                                  cin>>v>>u;
                                  int C;
                                  cin>>C;
                                  c[v][u]+=C;
                              }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline 
      int h(int n)
      {
          return n%MAXM;
      }
      inline
      int min(int a,int b)
      {
          return a<b?a:b;
      }
      int maxFlow(int s,int t)
      {
          //label(v)=(p[v],value[v])
          int p[MAXM+2];
          int value[MAXM+2];
          //U
          int U[MAXM+2];
          int U_close,U_open;
          //init flow
          memset(f,0,sizeof(f));
          
          for (;;)//find max flow
          {
              //for each v
              //label(v)=(null,0)
              memset(p,0,sizeof(p));
              memset(value,0,sizeof(value));
              //label(s)=(s,oo)
              p[s]=s;
              value[s]=oo;
              
              //U={s}
              U_close=1;
              U_open=1;
              U[U_close]=s;
              
              while (p[t]==0)//t is not labeled
              {
                    if (U_close>U_open) return calcFlow(s,t);
                    
                    int v=U[h(U_close++)];
                    for (int w=1;w<=M;w++)
                        if ((c[v][w]!=0)&&(p[w]==0))
                        {
                           if (f[v][w]<c[v][w])
                           {
                              p[w]=v;
                              value[w]=min(value[v],c[v][w]-f[v][w]);
                              U[h(++U_open)]=w;
                           }
                        }
                    for (int w=1;w<=M;w++)
                        if ((c[w][v]!=0)&&(p[w]==0))
                        {
                           if (f[w][v]>0)
                           {
                              p[w]=v;
                              value[w]=min(value[v],f[w][v]);
                              U[h(++U_open)]=w;
                           }
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
          int flow=0;
          for (int i=1;i<=M;i++)
              flow+=f[s][i];
          return flow;
      }
      int run()
      {
          cout<<maxFlow(1,M)<<endl;
          return 0;
      }
};

int main()
{
    Application app("ditch.in","ditch.out");
    return app.run();
}
