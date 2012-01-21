/*
ID: sujiao1
PROG: schlnet
LANG: C++
*/
/*
PROGRAM: schlnet
AUTHOR: Su Jiao
DATE: 2010-1-17
DESCRIPTION:
一些学校连入一个电脑网络。那些学校已订立了协议：每个学校都会给其它的一些学校分发
软件（称作“接受学校”）。注意如果 B 在 A 学校的分发列表中，那么 A 不一定也在 B 
学校的列表中。 
你要写一个程序计算，根据协议，为了让网络中所有的学校都用上新软件，必须接受新软件
副本的最少学校数目（子任务 A）。更进一步，我们想要确定通过给任意一个学校发送新软
件，这个软件就会分发到网络中的所有学校。为了完成这个任务，我们可能必须扩展接收学
校列表，使其加入新成员。计算最少需要增加几个扩展，使得不论我们给哪个学校发送新软
件，它都会到达其余所有的学校（子任务 B）。一个扩展就是在一个学校的接收学校列表中
引入一个新成员。 
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
      int N;
      bool m[MAXN+2][MAXN+2];
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        memset(m,false,sizeof(m));
                        cin>>N;
                        for (int i=1;i<=N;i++)
                        {
                            int t;
                            for (;;)
                            {
                                cin>>t;
                                if (t) m[i][t]=true;
                                else break;
                            }
                        }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
          for (int k=1;k<=N;k++)
              for (int i=1;i<=N;i++)
                  for (int j=1;j<=N;j++)
                      m[i][j]=m[i][j]||(m[i][k]&&m[k][j]);
          
          int part=0;
          int representative[MAXN+2];
          bool visited[MAXN+2];
          memset(visited,false,sizeof(visited));
          for (int i=1;i<=N;i++)
              if (!visited[i])
              {
                 representative[++part]=i;
                 visited[i]=true;
                 for (int j=1;j<=N;j++)
                     if (m[i][j]&&m[j][i])
                        visited[j]=true;
              }
          
          int indegree[MAXN+2];
          int outdegree[MAXN+2];
          memset(indegree,0,sizeof(indegree));
          memset(outdegree,0,sizeof(outdegree));
          for (int i=1;i<=part;i++)
              for (int j=1;j<=part;j++)
                  if (i!=j&&m[representative[i]][representative[j]])
                  {
                     indegree[j]++;
                     outdegree[i]++;
                  }
          int inTotal=0,outTotal=0;
          for (int i=1;i<=part;i++)
          {
              if (!indegree[i]) inTotal++;
              if (!outdegree[i]) outTotal++;
          }
          if (part>1) cout<<inTotal<<endl<<(inTotal>outTotal?inTotal:outTotal)<<endl;
          else cout<<1<<endl<<0<<endl;
          return 0;
      }
};

int main()
{
    Application app("schlnet.in","schlnet.out");
    return app.run();
}
