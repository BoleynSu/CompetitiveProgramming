/*
ID: sujiao1
PROG: shuttle
LANG: C++
*/
/*
PROGRAM: shuttle
AUTHOR: Su Jiao
DATE: 2010-1-10
DESCRIPTION:
大小为3的棋盘游戏里有3个白色棋子，3个黑色棋子，和一个有7个格子一线排开的木盒子。3个白棋子被放在一头，3个黑棋子被放在另一头，中间的格子空着。 
初始状态: WWW_BBB 
目标状态: BBB_WWW
在这个游戏里有两种移动方法是允许的： 
你可以把一个棋子移到与它相邻的空格； 
你可以把一个棋子跳过一个(仅一个)与它不同色的棋子到达空格。 
大小为N的棋盘游戏包括N个白棋子，N个黑棋子，还有有2N+1个格子的木盒子。 
这里是3-棋盘游戏的解，包括初始状态，中间状态和目标状态： 
 WWW BBB
 WW WBBB
 WWBW BB
 WWBWB B
 WWB BWB
 W BWBWB
  WBWBWB
 BW WBWB
 BWBW WB
 BWBWBW 
 BWBWB W
 BWB BWW
 B BWBWW
 BB WBWW
 BBBW WW
 BBB WWW
请编一个程序解大小为N的棋盘游戏(1 <= N <= 12)。要求用最少的移动步数实现。 
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
      static const int MAXN=12;
      //                        1 2 3 4 5 6 7 8 9 0 1 2
      static const int MAXSTATE=3*3*3*3*3*3*3*3*3*3*3*3;
      int N;
      typedef int string[MAXN*2+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>N;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      static int link[MAXSTATE+2];
      static int opt[MAXSTATE+2];
      static long long int q[MAXSTATE+2];
      //static int step[MAXSTATE+2];
      int open,close;
      void bfs(long long int s,long long int t)
      {
           //memset(step,0,sizeof(step));
           //cout<<s<<" "<<t<<endl;
           open=1;
           close=1;
           
           q[open]=s;
           //step[q[open]]=1;
           link[open]=close;
           opt[q[open]]=N+1;
           long long int next;
           while (close<=open)
           {
                 long long int now=q[close];
                 string ns;
                 toString(now,ns);
                 //printString(ns);
                 for (int i=1;i<=N*2+1;i++)
                 {
                     if (ns[i]==2)
                     {
                        if ((i>1)&&(ns[i-1]==0))
                        {
                           ns[i]=ns[i-1];
                           ns[i-1]=2;
                           next=toInteger(ns);
                           //printString(ns);                      
                           //if (!step[next])
                           {
                              //step[next]=step[now]+1;
                              q[++open]=next;
                              //step[open]=step[close]+1;
                              link[open]=close;
                              opt[open]=i-1;
                              if (q[open]==t) return;
                           }
                           ns[i-1]=ns[i];
                           ns[i]=2;
                        }
                        if ((i<N*2+1)&&(ns[i+1]==1))
                        {
                           ns[i]=ns[i+1];
                           ns[i+1]=2;
                           next=toInteger(ns);
                           //printString(ns);                      
                           //if (!step[next])
                           {
                              //step[next]=step[now]+1;
                              q[++open]=next;
                              //step[open]=step[close]+1;
                              link[open]=close;
                              opt[open]=i+1;
                              if (q[open]==t) return;
                           }
                           ns[i+1]=ns[i];
                           ns[i]=2;
                        }
                        if ((i>1+1)&&(ns[i-1]==1)&&(ns[i-2]==0))
                        {
                           ns[i]=ns[i-2];
                           ns[i-2]=2;
                           next=toInteger(ns);
                           //printString(ns);                      
                           //if (!step[next])
                           {
                              //step[next]=step[now]+1;
                              q[++open]=next;
                              //step[open]=step[close]+1;
                              link[open]=close;
                              opt[open]=i-2;
                              if (q[open]==t) return;
                           }
                           ns[i-2]=ns[i];
                           ns[i]=2;                                  
                        }
                        if ((i<N*2+1-1)&&(ns[i+1]==0)&&(ns[i+2]==1))
                        {
                           ns[i]=ns[i+2];
                           ns[i+2]=2;
                           next=toInteger(ns);
                           //printString(ns);                      
                           //if (!step[next])
                           {
                              //step[next]=step[now]+1;
                              q[++open]=next;
                              //step[open]=step[close]+1;
                              link[open]=close;
                              opt[open]=i+2;
                              if (q[open]==t) return;
                           }
                           ns[i+2]=ns[i];
                           ns[i]=2;
                        }
                     }
                 }
                 //cout<<open<<endl;
                 close++;
           }
      }
      void print()
      {
           int now=open;           
           static const int MAXOUTPUT=1000;
           int output[MAXOUTPUT];
           int output_top=0;
           while (link[now]!=now)
           {
                 output[++output_top]=opt[now];
                 now=link[now];
           }
           for (int i=output_top;i>=1;i--)
           {
               cout<<output[i]<<char(((i==1)||((output_top-i+1)%20)==0)?'\n':' ');
           }
      }
      void toString(long long int i,string s)
      {
           for (int j=1;j<=N*2+1;j++)
           {
               s[N*2+1+1-j]=i%3;
               i/=3;
           }
      }
      void printString(string s)
      {
           for (int i=1;i<=N*2+1;i++)
               cout<<s[i];
           cout<<endl;
      }
      long long 
      int toInteger(string s)
      {
          long long int i=0;
          for (int j=1;j<=N*2+1;j++)
              i=i*3+s[j];
          return i;
      }
      long long 
      int getStart()
      {
          //[0]n 2 [1]n
          long long int v=0;
          for (int i=1;i<=N;i++)
              v=v*3+0;
          v=v*3+2;
          for (int i=1;i<=N;i++)
              v=v*3+1;
          return v;
      }
      long long 
      int getEnd()
      {
          //[1]n 2 [0]n
          long long int v=0;
          for (int i=1;i<=N;i++)
              v=v*3+1;
          v=v*3+2;
          for (int i=1;i<=N;i++)
              v=v*3+0;
          return v;
      }
      int run()
      {
          //bfs
          bfs(getStart(),getEnd());
          print();
          return 0;
      }
};
int Application::link[MAXSTATE+2];
int Application::opt[MAXSTATE+2];
long long int Application::q[MAXSTATE+2];
//int Application::step[MAXSTATE+2];

int main()
{
    Application app("shuttle.in","shuttle.out");
    return app.run();
}
