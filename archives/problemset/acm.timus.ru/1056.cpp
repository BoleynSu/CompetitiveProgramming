/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-28
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
      int N;
      vector<vector<int> > link;
      int max;
      int maxid;
      vector<bool> visited;
      vector<int> mark;
      void dfs(int node,int depth=0)
      {
           if (visited[node]) return;
           
           visited[node]=true;
           if (depth>max)
           {
              max=depth;
              maxid=node;
           }
           for (int i=0;i<link[node].size();i++)
               dfs(link[node][i],depth+1);
           visited[node]=false;
      }
      void dfs_mark(int node,int R)
      {
           if (visited[node]) return;
           if (R<0) return;
           
           visited[node]=true;
           mark[node]++;
           for (int i=0;i<link[node].size();i++)
               dfs_mark(link[node][i],R-1);
           visited[node]=false;
      }
      public:
      Application()
      {
                   cin>>N;
                   link.resize(N);
                   for (int i=1,p;i<N;i++)
                       cin>>p,link[p-1].push_back(i),link[i].push_back(p-1);
      }
      int run()
      {
          int head,tail,R;
          visited.resize(N,false);
          
          max=0;
          dfs(0);
          head=maxid;
          
          max=0;
          dfs(maxid);
          tail=maxid;
          
          R=(max+1)/2;
          
          mark.resize(N,0);
          dfs_mark(head,R);
          dfs_mark(tail,R);
          
          vector<int> answer;
          for (int i=0;i<N;i++)
              if (mark[i]==2) answer.push_back(i+1);
          for (int i=0;i<answer.size();i++)
              cout<<answer[i]<<char(i+1==answer.size()?'\n':' ');
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
