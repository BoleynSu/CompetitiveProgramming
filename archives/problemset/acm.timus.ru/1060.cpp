/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-30
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::stringstream;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <set>
using std::set;
#include <map>
//using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;

struct State
{
       static const int SIZE=4;
       bool map[SIZE][SIZE];
       int id;
       void getId()
       {
            id=0;
            for (int i=0;i<SIZE;i++)
                for (int j=0;j<SIZE;j++)
                {
                    id<<=1;
                    if(map[i][j]) id++;
                }
       }
       void read()
       {
            for (int i=0;i<SIZE;i++)
                for (int j=0;j<SIZE;j++)
                {
                    char c;
                    cin>>c;
                    map[i][j]=(c=='w');
                }
            getId();
       }
       void set(bool what)
       {
            for (int i=0;i<SIZE;i++)
                for (int j=0;j<SIZE;j++)
                    map[i][j]=what;
            getId();
       }
       void turn(int x,int y)
       {
            map[x][y]=!map[x][y];
            if (x-1>=0) map[x-1][y]=!map[x-1][y];
            if (x+1<SIZE) map[x+1][y]=!map[x+1][y];
            if (y-1>=0) map[x][y-1]=!map[x][y-1];
            if (y+1<SIZE) map[x][y+1]=!map[x][y+1];
            getId();
       }
       void print()
       {
            for (int i=0;i<SIZE;i++)
            {
                for (int j=0;j<SIZE;j++)
                    cout<<map[i][j];
                cout<<endl;
            }
       }
};

class Application
{
      static const int NOTREACH=~(1<<31);
      State s,t1,t2;
      public:
      Application()
      {
                   s.read();
                   t1.set(true);
                   t2.set(false);
      }
      int run()
      {
          vector<int> step(1<<((State::SIZE)*(State::SIZE)),NOTREACH);
          queue<State> q;
          
          q.push(s);
          step[s.id]=0;
          
          while (!q.empty())
          {
                State& now=q.front();
                for (int i=0;i<State::SIZE;i++)
                    for (int j=0;j<State::SIZE;j++)
                    {
                        State get=now;
                        get.turn(i,j);
                        if (step[get.id]==NOTREACH)
                        {
                           q.push(get);
                           step[get.id]=step[now.id]+1;
                        }
                    }
                q.pop();
          }
          int answer=step[t1.id]<step[t2.id]?step[t1.id]:step[t2.id];
          if (answer==NOTREACH) cout<<"Impossible"<<endl;
          else cout<<answer<<endl;
          
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
