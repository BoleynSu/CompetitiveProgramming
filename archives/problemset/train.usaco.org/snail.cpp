/*
ID: sujiao1
PROG: snail
LANG: C++
*/
/*
PROGRAM: snail
AUTHOR: Su Jiao
DATE: 2010-1-14
DESCRIPTION:
萨丽·斯内尔（Sally Snail，蜗牛）喜欢在 N x N 的棋盘上闲逛（1 < n <= 120）。她
总是从棋盘的左上角出发。棋盘上有空的格子（用“.”来表示）和 B 个路障（用“#”来
表示）。下面是这种表示法的示例棋盘： 
         A B C D E F G H
       1 S . . . . . # .
       2 . . . . # . . .
       3 . . . . . . . .
       4 . . . . . . . .
       5 . . . . . # . .
       6 # . . . . . . .
       7 . . . . . . . .
       8 . . . . . . . .
萨丽总是垂直（向上或者向下）或水平（向左或者向右）地走。她可以从出发地（总是记作
 A1 ）向下或者向右走。一旦萨丽选定了一个方向，她就会一直走下去。如果她遇到棋盘边
 缘或者路障，她就停下来，并且转过 90 度。她不可能离开棋盘，或者走进路障当中。并
 且，萨丽从不跨过她已经经过的格子。当她再也不能走的时候，她就停止散步。 
这里是上面的棋盘上的一次散步路线图示： 
         A B C D E F G H
       1 S---------+ # .
       2 . . . . # | . .
       3 . . . . . | . .
       4 . . . . . +---+
       5 . . . . . # . |
       6 # . . . . . . |
       7 +-----------+ |
       8 +-------------+
萨丽向右走，再向下，向右，向下，然后向左，再向上，最后向右走。这时她遇到了一个她
已经走过的格子，她就停下来了。但是，如果她在 F5 格遇到路障后选择另外一条路——向
我们看来是左边的方向转弯，情况就不一样了。 
你的任务是计算并输出，如果萨丽聪明地选择她的路线的话，她所能够经过的最多格子数。
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
      static const int MAXN=120;
      int N;
      int M;
      bool map[MAXN+2][MAXN+2];
      bool got[MAXN+2][MAXN+2];
      int answer;
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        cin>>N>>M;
                        memset(map,false,sizeof(map));
                        memset(got,false,sizeof(got));
                        for (int i=1;i<=M;i++)
                        {
                            char x;
                            int y;
                            cin>>x>>y;
                            map[x-'A'+1][y]=true;
                        }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void dfs()
      {
           
      }
      bool canGet(int x,int y)
      {
           return !(x<1||y<1||x>N||y>N||map[x][y]);
      }
      void dfs(int x,int y,int dx,int dy,int get)
      {
           if (get>answer) answer=get;
           if (!canGet(x,y)||got[x][y])
              return;
           //cout<<x<<","<<y<<":"<<get<<endl;
           got[x][y]=true;
           if (!canGet(x+dx,y+dy))
           {
              dfs(x-dy,y-dx,-dy,-dx,get+1);
              dfs(x+dy,y+dx,dy,dx,get+1);
           }
           else
               dfs(x+dx,y+dy,dx,dy,get+1);
           got[x][y]=false;
      }
      int run()
      {
          answer=0;
          dfs(1,1,0,1,0);
          dfs(1,1,1,0,0);
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app("snail.in","snail.out");
    return app.run();
}
