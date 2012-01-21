/*
ID: sujiao1
PROG: race3
LANG: C++
*/
/*
PROGRAM: race3
AUTHOR: Su Jiao
DATE: 2010-1-9
DESCRIPTION:
图一表示一次街道赛跑的跑道。可以看出有一些路口（用 0 到 N 的整数标号），和连接这些路口的箭头。路口 0 是跑道的起点，路口 N 是跑道的终点。箭头表示单行道。运动员们可以顺着街道从一个路口移动到另一个路口（只能按照箭头所指的方向）。当运动员处于路口位置时，他可以选择任意一条由这个路口引出的街道。 
图一：有 10 个路口的街道 一个良好的跑道具有如下几个特点： 
每一个路口都可以由起点到达。 
从任意一个路口都可以到达终点。 
终点不通往任何路口。 
运动员不必经过所有的路口来完成比赛。有些路口却是选择任意一条路线都必须到达的（称为“不可避免”的）。在上面的例子中，这些路口是 0，3，6，9。对于给出的良好的跑道，你的程序要确定“不可避免”的路口的集合，不包括起点和终点。 
假设比赛要分两天进行。为了达到这个目的，原来的跑道必须分为两个跑道，每天使用一个跑道。第一天，起点为路口 0，终点为一个“中间路口”；第二天，起点是那个中间路口，而终点为路口 N。对于给出的良好的跑道，你的程序要确定“中间路口”的集合。如果良好的跑道 C 可以被路口 S 分成两部分，这两部分都是良好的，并且 S 不同于起点也不同于终点，同时被分割的两个部分满足下列条件：（1）它们之间没有共同的街道（2）S 为它们唯一的公共点，并且 S 作为其中一个的终点和另外一个的起点。那么我们称 S 为“中间路口 ”。在例子中只有路口 3 是中间路口。 
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
      static const int MAXN=50;
      bool map[MAXN+2][MAXN+2];
      int N;
      bool got1[MAXN+2];
      bool got2[MAXN+2];
      int answer1[MAXN+2];
      int answer1_len;
      int answer2[MAXN+2];
      int answer2_len;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              memset(map,false,sizeof(map));
                              int id=0;
                              int get;
                              for (;;)
                              {
                                  cin>>get;
                                  if (get==-1)
                                  {
                                     id--;
                                     break;
                                  }
                                  else if (get==-2) id++;
                                  else
                                  {
                                      map[id][get]=true;
                                  }
                              }
                              N=id;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void dfs1(int from,int cannot)
      {
           if (from==cannot) return;
           got1[from]=true;
           for (int i=0;i<=N;i++)
               if (map[from][i]&&!got1[i])
                  dfs1(i,cannot);
      }
      void dfs2(int from)
      {
           got2[from]=true;
           for (int i=0;i<=N;i++)
               if (map[from][i]&&!got2[i])
                  dfs2(i);
      }
      int run()
      {
          answer1_len=0;
          answer2_len=0;
          for (int i=1;i<N;i++)
          {
              memset(got1,false,sizeof(got1));
              dfs1(0,i);
              if (!got1[N])
              {
                 answer1[++answer1_len]=i;
                 memset(got2,false,sizeof(got2));
                 dfs2(i);
                 bool isAnswer=true;
                 for (int j=0;j<=N;j++)
                     if (got1[j]&&got2[j])
                        isAnswer=false;
                 if (isAnswer)
                    answer2[++answer2_len]=i;
              }
          }
          cout<<answer1_len;
          for (int i=1;i<=answer1_len;i++)
              cout<<" "<<answer1[i];
          cout<<endl;
          cout<<answer2_len;
          for (int i=1;i<=answer2_len;i++)
              cout<<" "<<answer2[i];
          cout<<endl;
          return 0;
      }
};

int main()
{
    Application app("race3.in","race3.out");
    return app.run();
}
