/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-22 
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
      static const int NOMARK=-1;
      int N,M;
      vector<pair<pair<int,int>,int> > flight;
      void dfs(int node,int& mark)
      {
           for (int i=0;i<M;i++)
           {
               if (flight[i].second==NOMARK)
               {
                  if (flight[i].first.first==node)
                  {
                     flight[i].second=mark;
                     mark++;
                     dfs(flight[i].first.second,mark);
                  }
                  if (flight[i].first.second==node)
                  {
                     flight[i].second=mark;
                     mark++;
                     dfs(flight[i].first.first,mark);
                  }
               }
           }
      }
      public:
      Application() 
      {
                    cin>>N>>M;
                    flight.resize(M);
                    for (int i=0;i<M;i++)
                    {
                        cin>>flight[i].first.first
                           >>flight[i].first.second;
                        flight[i].second=NOMARK;
                    }
      }
      int run()
      {
          int mark=1;
          for (int i=1;i<=N;i++)
              dfs(i,mark);
          
          cout<<"YES"<<endl;
          for (int i=0;i<M;i++)
              cout<<flight[i].second<<char(i+1==M?'\n':' ');
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
