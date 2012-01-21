/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-20
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

class Application
{
      int N;
      vector<vector<char> > map;
      void bfs()
      {
           int answer=0;
           queue<pair<int,int> > q;
           vector<vector<bool> > inq(N,vector<bool>(N,false));
           #define go(dx,dy)\
           {\
                   int nexti=gi+(dx),nextj=gj+(dy);\
                   if ((nexti<N)\
                      &&(nexti>=0)\
                      &&(nextj<N)\
                      &&(nextj>=0)\
                      &&(!inq[nexti][nextj])\
                      &&(map[nexti][nextj]=='.'))\
                   {\
                     q.push(make_pair(nexti,nextj));\
                     inq[nexti][nextj]=true;\
                   }\
                   if ((nexti>=N)\
                       ||(nexti<0)\
                       ||(nextj>=N)\
                       ||(nextj<0)\
                       ||(map[nexti][nextj]=='#'))\
                      answer++;\
           }
           #define bfs_f(fi,fj)\
           if (!inq[fi][fj])\
           {\
              q.push(make_pair(fi,fj));\
              inq[fi][fj]=true;\
              while (!q.empty())\
              {\
                    int gi=q.front().first,\
                        gj=q.front().second;\
                    go(1,0);\
                    go(-1,0);\
                    go(0,1);\
                    go(0,-1);\
                    q.pop();\
              }\
           }
           bfs_f(0,0);
           bfs_f(N-1,N-1);
           #undef bfs_f
           #undef go
           answer-=4;
           answer*=3*3;
           cout<<answer<<endl;
      }
      public:
      Application() 
      {
                    cin>>N;
                    map.resize(N,vector<char>(N));
                    for (int i=0;i<N;i++)
                        for (int j=0;j<N;j++)
                            cin>>map[i][j];
      }
      int run()
      {
          bfs();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
