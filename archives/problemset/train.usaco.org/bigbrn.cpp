/*
ID: sujiao1
PROG: bigbrn
LANG: C++
*/
/*
PROGRAM: bigbrn
AUTHOR: Su Jiao
DATE: 2010-1-17
DESCRIPTION:
农夫约翰想要在他的正方形农场上建造一座正方形大牛棚。他讨厌在他的农场中砍树，想找
一个能够让他在空旷无树的地方修建牛棚的地方。我们假定，他的农场划分成 N x N 的方
格。输入数据中包括有树的方格的列表。你的任务是计算并输出，在他的农场中，不需要砍
树却能够修建的最大正方形牛棚。牛棚的边必须和水平轴或者垂直轴平行。
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
      static const int MAXN=1000;
      int N,T;
      bool m[MAXN+2][MAXN+2];
      int f[MAXN+2][MAXN+2];
      int answer;
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        memset(m,false,sizeof(m));
                        cin>>N>>T;
                        for (int i=1;i<=T;i++)
                        {
                            int x,y;
                            cin>>x>>y;
                            m[x][y]=true;
                        }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int min(int a,int b,int c)
      {
          if (b<a) a=b;
          if (c<a) a=c;
          return a;      
      }
      inline
      int min(int a,int b)
      {
          return a<b?a:b;
      }
      int run()
      {
          //f[i][j]=min(f[i-1][j],f[i-1][j-1],f[i][j-1])+1 (m[i][j]==true)
          //        0                                       else
          memset(f,0,sizeof(f));
          answer=0;
          for (int i=1;i<=N;i++)
          {
              f[1][i]=!m[1][i];
              if (f[1][i]>answer) answer=f[1][i];
              f[i][1]=!m[i][1];
              if (f[i][1]>answer) answer=f[i][1];
          }
          for (int i=2;i<=N;i++)
              for (int j=2;j<=N;j++)
              {
                  if (!m[i][j])
                  {
                     if ((f[i][j]=(min(f[i-1][j],f[i-1][j-1],f[i][j-1])+1))>answer)
                        answer=f[i][j];
                  }
                  else f[i][j]=0;
              }
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    static
    Application app("bigbrn.in","bigbrn.out");
    return app.run();
}
