/*
ID: sujiao1
PROG: telecow
LANG: C++
*/
/*
PROGRAM: telecow
AUTHOR: Su Jiao
DATE: 2010-1-21
DESCRIPTION:
农夫约翰的奶牛们喜欢通过电邮保持联系，于是她们建立了一个奶牛电脑网络，以便互相交
流。这些机器用如下的方式发送电邮：如果存在一个由c台电脑组成的序列a1,a2,...,a(c)，
且a1与a2相连，a2与a3相连，等等，那么电脑a1和a(c)就可以互发电邮。 
很不幸，有时候奶牛会不小心踩到电脑上，农夫约翰的车也可能碾过电脑，这台倒霉的电脑
就会坏掉。这意味着这台电脑不能再发送电邮了，于是与这台电脑相关的连接也就不可用
了。 
有两头奶牛就想：如果我们两个不能互发电邮，至少需要坏掉多少台电脑呢？请编写一个程
序为她们计算这个最小值和与之对应的坏掉的电脑集合。 
以如下网络为例： 
              1*
             /  
            3 - 2*
这张图画的是有2条连接的3台电脑。我们想要在电脑1和2之间传送信息。电脑1与3、2与3直
接连通。如果电脑3坏了，电脑1与2便不能互发信息了。 
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
      static const int MAXN=100;
      static const int oo=~(1<<31);
      int N,M,s,t;
      int c[MAXN*2+2][MAXN*2+2];
      int f[MAXN*2+2][MAXN*2+2];
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        memset(c,0,sizeof(c));
                        cin>>N>>M>>s>>t;
                        for (int i=1;i<=N;i++)
                            c[i][next(i)]=c[next(i)][i]=1;
                        for (int i=1;i<=M;i++)
                        {
                            int v,u;
                            cin>>v>>u;
                            /* v-v'    v-v'
                               /\        /
                                 \     \/
                               u-u'    u-u' */
                            c[v][next(u)]=oo;
                            c[u][next(v)]=oo;
                        }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int next(int n)
      {
          return n+N;
      }
      inline
      int min(int a,int b)
      {
          return a<b?a:b;
      }
      
      int maxFlow(int s,int t,int l,int r)
      {
          //label(v)=(p[v],value[v])
          int p[MAXN*2+2];
          int value[MAXN*2+2];
          //U
          int U[MAXN*2+2];
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
                    if (U_close>U_open) return calcFlow(s,t,l,r);
                    
                    int v=U[U_close++];
                    for (int w=l;w<=r;w++)
                        if ((c[v][w]!=0)&&(p[w]==0))
                        {
                           if (f[v][w]<c[v][w])
                           {
                              p[w]=v;
                              value[w]=min(value[v],c[v][w]-f[v][w]);
                              U[++U_open]=w;
                           }
                        }
                    for (int w=l;w<=r;w++)
                        if ((c[w][v]!=0)&&(p[w]==0))
                        {
                           if (f[w][v]>0)
                           {
                              p[w]=v;
                              value[w]=min(value[v],f[w][v]);
                              U[++U_open]=w;
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
      int calcFlow(int s,int t,int l,int r)
      {
          int flow=0;
          for (int i=l;i<=r;i++)
              flow+=f[s][i];
          return flow;
      }
      int run()
      {
          int all=maxFlow(s,next(t),1,next(N));
          int rest=all;
          cout<<all<<endl;
          
          bool first=true;
          for (int i=1;(i<=N)&&rest;i++)
              if (i!=s&&i!=t)
              {
                 c[i][next(i)]=c[next(i)][i]=0;
                 int now=maxFlow(s,next(t),1,next(N));
                 if (now<rest)
                 {
                    rest=now;
                    if (first)
                    {
                       cout<<i;
                       first=false;
                    }
                    else cout<<" "<<i;
                 }
                 else c[i][next(i)]=c[next(i)][i]=oo;
              }
          cout<<endl;
          return 0;
      }
};

int main()
{
    Application app("telecow.in","telecow.out");
    return app.run();
}
