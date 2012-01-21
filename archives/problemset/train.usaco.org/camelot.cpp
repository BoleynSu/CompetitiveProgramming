/*
ID: sujiao1
PROG: camelot
LANG: C++
*/
/*
PROGRAM: camelot
AUTHOR: Su Jiao
DATE: 2009-12-22
DESCRIPTION:
ÑÇÉªÍõµÄ¹¬µî 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <ctime>
using std::clock;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXR=30;
      static const int MAXC=26;
      static const int MAXD=8;
      static const int oo=1024*1024*1024;
      struct Point{int x,y;};
      int R,C;
      Point king;
      int knight_len;
      Point knight[MAXR*MAXC+2];
      Point d[MAXD+2];
      static int dis[MAXR+2][MAXC+2][MAXR+2][MAXC+2];
      int answer;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),answer(oo)
      {
                              cin>>R>>C;
                              char x;
                              int y;
                              cin>>x>>y;
                              king.y=x-'A'+1;
                              king.x=y;
                              knight_len=0;
                              while (cin>>x>>y)
                              {
                                    knight_len++;
                                    knight[knight_len].y=x-'A'+1;
                                    knight[knight_len].x=y;
                              }
                              d[1].x=1;
                              d[1].y=2;
                              d[2].x=1;
                              d[2].y=-2;
                              d[3].x=-1;
                              d[3].y=2;
                              d[4].x=-1;
                              d[4].y=-2;
                              d[5].x=2;
                              d[5].y=1;
                              d[6].x=2;
                              d[6].y=-1;
                              d[7].x=-2;
                              d[7].y=1;
                              d[8].x=-2;
                              d[8].y=-1;
                              /*
                              cout<<"king: "<<king.x<<" "<<king.y<<endl;
                              cout<<"knight: "<<endl;
                              for (int i=1;i<=knight_len;i++)
                                  cout<<knight[i].x<<" "<<knight[i].y<<endl;
                              */
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int abs(int n)
      {
          return n>0?n:-n;
      }
      inline
      int max(int a,int b)
      {
          return a>b?a:b;
      }
      inline
      int dist(Point& f,Point& t)
      {
          //cout<<f.x<<" "<<f.y<<"to"<<t.x<<" "<<t.y<<"="<<dis[f.x][f.y][t.x][t.y]<<endl;
          return dis[f.x][f.y][t.x][t.y];
      }
      int run()
      {
          Point meet;
          Point together;
          bool visited[MAXR+2][MAXC+2];
          Point q[MAXR*MAXC+2];
          memset(dis,0x00f,sizeof(dis));
          for (meet.x=1;meet.x<=R;meet.x++)
              for (meet.y=1;meet.y<=C;meet.y++)
              {
                  //bfs
                  memset(visited,false,sizeof(visited));
                  int open=1;
                  int close=1;
                  q[close]=meet;
                  dis[meet.x][meet.y][meet.x][meet.y]=0;
                  visited[meet.x][meet.y]=true;
                  while (close<=open)
                  {
                        Point& now=q[close];
                        for (int i=1;i<=MAXD;i++)
                        {
                            Point next;
                            next.x=now.x+d[i].x;
                            next.y=now.y+d[i].y;
                            if ((!((next.x<1)||(next.y<1)||(next.x>R)||(next.y>C)))&&(!visited[next.x][next.y]))
                            {
                               visited[next.x][next.y]=true;
                               dis[meet.x][meet.y][next.x][next.y]=dis[meet.x][meet.y][now.x][now.y]+1;
                               open++;
                               q[open]=next;
                            }
                        }
                        close++;
                  }
              }
          
          Point f,t;
          f.x=(king.x-3)>=1?(king.x-3):1;
          f.y=(king.y-3)>=1?(king.y-3):1;
          t.x=(king.x+3)<=R?(king.x+3):R;
          t.y=(king.y+3)<=C?(king.y+3):C;
          for (meet.x=1;meet.x<=R;meet.x++)
              for (meet.y=1;meet.y<=C;meet.y++)
              {
                  
                  int all=0;
                  for (int who=1;who<=knight_len;who++)
                      all+=dist(meet,knight[who]);
                  for (together.x=f.x;together.x<=t.x;together.x++)
                      for (together.y=f.y;together.y<=t.y;together.y++)
                          for (int who=1;who<=knight_len;who++)
                          {
                              int got=max(abs(together.x-king.x),abs(together.y-king.y))
                                      +dist(together,meet)
                                      +dist(together,knight[who]);
                              got+=(all-dist(knight[who],meet));
                              if (got<answer) answer=got;                    
                          }
              }
          if (knight_len==0) cout<<0<<endl;
          else cout<<answer<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};
int Application::dis[MAXR+2][MAXC+2][MAXR+2][MAXC+2];

int main()
{
    Application app("camelot.in","camelot.out");
    return app.run();
}
