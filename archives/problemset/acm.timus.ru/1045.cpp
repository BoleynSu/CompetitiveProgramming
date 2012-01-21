/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-25
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
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;

class Application
{
      int N,K;
      vector<vector<int> > link;
      vector<bool> win;
      void go(int node,bool isMe,int father=-1)
      {
           for (int i=0;i<link[node].size();i++)
               if (link[node][i]!=father)
                  go(link[node][i],!isMe,node);
           if (isMe)
           {
              win[node]=false;
              for (int i=0;i<link[node].size();i++)
                  if (link[node][i]!=father)
                     win[node]=win[node] or win[link[node][i]];
           }
           else
           {
               win[node]=true;
               for (int i=0;i<link[node].size();i++)
                   if (link[node][i]!=father)
                      win[node]=win[node] and win[link[node][i]];
           }
      }
      public:
      Application() 
      {
                    cin>>N>>K;
                    link.resize(N);
                    for (int i=1,v,u;i<N;i++)
                        cin>>v>>u,link[v-1].push_back(u-1),link[u-1].push_back(v-1); 
      }
      int run()
      {
          win.resize(N,false);
          go(K-1,true);
          if (win[K-1])
          {
             int gohere=N;
             for (int i=0;i<link[K-1].size();i++)
                 if (win[link[K-1][i]])
                    if (gohere>link[K-1][i])
                       gohere=link[K-1][i]+1;
             cout<<"First player wins flying to airport "<<gohere<<endl;
          } 
          else cout<<"First player loses"<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
