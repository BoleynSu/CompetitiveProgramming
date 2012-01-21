/*
ID: sujiao1
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::endl;
using std::string;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("maze1.in");
std::ofstream cout("maze1.out");

struct Program
{
       static const int MAXW=38;//1 to 38
       static const int MAXH=100;//1 to 100
       static const int MAXD=4;
       static const int MAXDOOR=2;
       struct Point{int x,y;};
       int W,H;
       int counter;
       int answer[MAXDOOR+2][MAXH+2][MAXW+2];
       Point door[MAXDOOR+2];
       int map[MAXH+2][MAXW+2];
       Program()
       {
                cin>>W>>H;
                char tmap[MAXH*2+1+2][MAXW*2+1+2];
                for (int i=1;i<=H*2+1;i++)
                {
                    cin.get();
                    for (int j=1;j<=W*2+1;j++)
                        tmap[i][j]=cin.get();
                }
                /*
                for (int i=1;i<=H*2+1;i++)
                {
                    for (int j=1;j<=W*2+1;j++)
                        cout<<tmap[i][j];
                    cout<<endl;
                }
                */
                //up 1 right 2 down 4 left 8
                for (int i=1;i<=H;i++)
                {
                    for (int j=1;j<=W;j++)
                    {
                        map[i][j]=0;
                        if (tmap[i*2-1][j*2]==' ') map[i][j]+=1;
                        if (tmap[i*2][j*2+1]==' ') map[i][j]+=2;
                        if (tmap[i*2+1][j*2]==' ') map[i][j]+=4;
                        if (tmap[i*2][j*2-1]==' ') map[i][j]+=8;
                        //cout<<map[i][j]<<" ";
                    }
                    //cout<<endl;
                }
       }
       inline
       bool cu(int room)//can up
       {
            return room%2==1;
       }
       inline
       bool cr(int room)//can right
       {
            return (room/2)%2==1;
       }
       inline
       bool cd(int room)//can down
       {
            return (room/4)%2==1;
       }
       inline
       bool cl(int room)//can left
       {
            return (room/8)%2==1;
       }
       void findDoor()
       {
            counter=0;
            for (int i=1;i<=H;i++)
                for (int j=1;j<=W;j++)
                {
                    if (
                    ((j==1)&&cl(map[i][j]))||
                    ((i==1)&&cu(map[i][j]))||
                    ((j==W)&&cr(map[i][j]))||
                    ((i==H)&&cd(map[i][j]))
                    )
                    {
                       counter++;
                       door[counter].x=i;
                       door[counter].y=j;
                       //cout<<door[counter].x<<" "<<door[counter].y<<"d\n";
                    }
                }
       }
       void bfs(int flag)
       {
            bool mark[MAXH+2][MAXW+2];
            int open,close;
            Point q[MAXW*MAXH+2];
            
            for (int i=1;i<=H;i++)
                for (int j=1;j<=W;j++)
                    mark[i][j]=false;
            open=1;
            close=1;
            q[open]=door[flag];
            mark[q[open].x][q[open].y]=true;
            answer[flag][q[open].x][q[open].y]=1;
            
            while (open<=close)
            {
                  Point& now=q[open];
                  open++;
                  int can=map[now.x][now.y];
                  if (cu(can)&&now.x>1)
                  {
                     Point next;
                     next.x=now.x-1;
                     next.y=now.y;
                     if (!mark[next.x][next.y])
                     {
                        close++;
                        q[close].x=next.x;
                        q[close].y=next.y;
                        mark[next.x][next.y]=true;
                        answer[flag][next.x][next.y]=answer[flag][now.x][now.y]+1;
                     }
                  }
                  if (cr(can)&&now.y<W)
                  {
                     Point next;
                     next.x=now.x;
                     next.y=now.y+1;
                     if (!mark[next.x][next.y])
                     {
                        close++;
                        q[close].x=next.x;
                        q[close].y=next.y;
                        mark[next.x][next.y]=true;
                        answer[flag][next.x][next.y]=answer[flag][now.x][now.y]+1;
                     }
                  }
                  if (cd(can)&&now.x<H)
                  {
                     Point next;
                     next.x=now.x+1;
                     next.y=now.y;
                     if (!mark[next.x][next.y])
                     {
                        close++;
                        q[close].x=next.x;
                        q[close].y=next.y;
                        mark[next.x][next.y]=true;
                        answer[flag][next.x][next.y]=answer[flag][now.x][now.y]+1;
                     }
                  }
                  if (cl(can)&&now.y>1)
                  {
                     Point next;
                     next.x=now.x;
                     next.y=now.y-1;
                     if (!mark[next.x][next.y])
                     {
                        close++;
                        q[close].x=next.x;
                        q[close].y=next.y;
                        mark[next.x][next.y]=true;
                        answer[flag][next.x][next.y]=answer[flag][now.x][now.y]+1;
                     }
                  }
            }
            /*
            cout<<"bfs()\n";
            for (int i=1;i<=H;i++)
            {
                for (int j=1;j<=W;j++)
                    cout<<answer[flag][i][j]<<" ";
                cout<<endl;
            }
            */
       }
       void getAnswer()
       {
            for (int i=1;i<=counter;i++)
                bfs(i);
       }
       int run()
       {
           findDoor();
           getAnswer();
           for (int i=1;i<=H;i++)
               for (int j=1;j<=W;j++)
                   answer[0][i][j]=MAXW*MAXH+2;
           for (int k=1;k<=counter;k++)
               for (int i=1;i<=H;i++)
                   for (int j=1;j<=W;j++)
                       if (answer[0][i][j]>answer[k][i][j])
                          answer[0][i][j]=answer[k][i][j];
           
           int maxanswer=0;
           for (int i=1;i<=H;i++)
               for (int j=1;j<=W;j++)
                   if (answer[0][i][j]>maxanswer) maxanswer=answer[0][i][j];
           cout<<maxanswer<<endl;
           //cout<<clock()<<endl;
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
