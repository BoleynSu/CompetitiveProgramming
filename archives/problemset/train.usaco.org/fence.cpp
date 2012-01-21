/*
ID: sujiao1
PROG: fence
LANG: C++
*/
/*
PROGRAM: fence
AUTHOR: Su Jiao
DATE: 2009-12-20
DESCRIPTION:
农民John每年有很多栅栏要修理。他总是骑着马穿过每一个栅栏并修复它破损的地方。 
John是一个与其他农民一样懒的人。他讨厌骑马，因此从来不两次经过一个栅栏。你必须编
一个程序，读入栅栏网络的描述，并计算出一条修栅栏的路径，使每个栅栏都恰好被经过一
次。John能从任何一个顶点(即两个栅栏的交点)开始骑马，在任意一个顶点结束。 
每一个栅栏连接两个顶点，顶点用1到500标号(虽然有的农场并没有500个顶点)。一个顶点
上可连接任意多(>=1)个栅栏。所有栅栏都是连通的(也就是你可以从任意一个栅栏到达另外
的所有栅栏)。 
你的程序必须输出骑马的路径(用路上依次经过的顶点号码表示)。我们如果把输出的路径看
成是一个500进制的数，那么当存在多组解的情况下，输出500进制表示法中最小的一个 (也
就是输出第一个数较小的，如果还有多组解，输出第二个数较小的，等等)。 
输入数据保证至少有一个解。
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
      static const int MAXF=1024;
      static const int MAXN=500;
      int F;
      int map[MAXN+2][MAXN+2];
      int degree[MAXN+2];
      bool have[MAXN+2];
      int startPosition;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),startPosition(MAXN)
      {
                              memset(map,0,sizeof(map));
                              memset(degree,0,sizeof(degree));
                              memset(have,false,sizeof(have));
                              cin>>F;
                              for (int k=1;k<=F;k++)
                              {
                                  int i,j;
                                  cin>>i>>j;
                                  degree[i]++;
                                  degree[j]++;
                                  have[i]=true;
                                  have[j]=true;
                                  map[i][j]++;
                                  map[j][i]++;
                              }
                              bool find=false;
                              for (int i=1;i<=MAXN;i++)
                              {
                                  if (degree[i]%2==1)
                                  {
                                     startPosition=i;
                                     find=true;
                                     break;
                                  }
                              }
                              if (!find)
                              {
                                        for (int i=1;i<=MAXN;i++)
                                            if (have[i])
                                            {
                                               startPosition=i;
                                               break;
                                            }
                              }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void go(int start)
      {
           int circuit[MAXF+2];
           int ctop;
           int stack[MAXF+2];
           int top;
           ctop=0;
           top=0;
           circuit[F]=start;
           stack[top]=start;
           
           while (ctop++<=F)
           {
                 int location=stack[top];
                 for (;;)
                 {
                     for (location=1;location<=MAXN;location++)
                         if (map[stack[top]][location]!=0) break;
                     if (location>MAXN) break;
                     map[stack[top]][location]--;
                     map[location][stack[top]]--;
                     stack[++top]=location;
                 }
                 circuit[ctop]=stack[top--];
           }
           
           for (int i=F+1;i>=1;i--)
               cout<<circuit[i]<<endl;
      }
      int run()
      {
          go(startPosition);
          return 0;
      }
};

int main()
{
    Application app("fence.in","fence.out");
    return app.run();
}
