/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-10
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
      int N,M;
      vector<vector<bool> > map;
      vector<vector<bool> > spaning_tree;
      vector<bool> visited;
      vector<int> path;
      void dfs(int node)
      {
           visited[node]=true;
           for (int i=0;i<N;i++)
               if (map[node][i]&&(!visited[i]))
               {
                  map[node][i]=false;
                  map[i][node]=false;
                  spaning_tree[node][i]=true;
                  spaning_tree[i][node]=true;
                  dfs(i);
               }
      }
      void print(int node,const int& end)
      {
           if (!visited[node])
           {
              visited[node]=true;
              path.push_back(node);
              if (node==end)
              {
                 cout<<path.size();
                 for (int i=0;i<path.size();i++) cout<<" "<<path[i]+1;
                 cout<<endl;
              }
              for (int i=0;i<N;i++)
                  if (spaning_tree[node][i])
                     print(i,end);
              path.pop_back();
              visited[node]=false;
           }
      }
      public:
      Application() 
      {
                    cin>>N>>M;
                    map.resize(N,vector<bool>(N,false));
                    for (int i=0;i<M;i++)
                    {
                        int u,v;
                        cin>>u>>v;
                        map[u-1][v-1]=map[v-1][u-1]=true;
                    }
      }
      int run()
      {
          spaning_tree.resize(N,vector<bool>(N,false));
          visited.resize(N,false);
          int part=0;
          for (int i=0;i<N;i++)
              if (!visited[i]) dfs(i),part++;
          cout<<M-N+part<<endl;
          
          visited=vector<bool>(N,false);
          for (int i=0;i<N;i++)
              for (int j=i+1;j<N;j++)
                  if (map[i][j])
                     print(i,j);
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
