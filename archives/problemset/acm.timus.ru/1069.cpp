/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-8
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
using std::priority_queue;
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
      vector<int> out;
      vector<int> rest;
      vector<vector<int> > link;
      public:
      Application()
      {
                   int get;
                   while (cin>>get) out.push_back(get-1);
      }
      int run()
      {
          rest.resize(out.size()+1,0);
          link.resize(out.size()+1);
          
          priority_queue<int> q;
          for (int i=0;i<out.size();i++)
              rest[out[i]]++;
          for (int i=0;i<rest.size();i++)
              if (rest[i]==0) q.push(-i);
          for (int i=0;i<out.size();i++)
          {
              link[out[i]].push_back(-q.top());
              link[-q.top()].push_back(out[i]);
              rest[out[i]]--;
              q.pop();
              if (rest[out[i]]==0) q.push(-out[i]);
          }
          for (int i=0;i<link.size();i++)
          {
              sort(link[i].begin(),link[i].end());
              cout<<i+1<<":";
              for (int j=0;j<link[i].size();j++)
                  cout<<" "<<link[i][j]+1;
              cout<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
