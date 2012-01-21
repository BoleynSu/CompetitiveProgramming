/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-6
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
      static const int oo=~(1<<31);
      static const int SIDE=6;
      vector<vector<int> > c;
      vector<int> degree;
      //GET PART
      vector<int> getid;
      void dfs(int id,stack<int>& s)
      {
           static vector<bool> visited(SIDE,false);
           if (!visited[id])
           {
              visited[id]=true;
              s.push(id);
              for (int i=0;i<SIDE;i++)
                  if (c[id][i])
                     dfs(i,s);
           }
      }
      void get_part()
      {
           vector<vector<int> > part;
           getid.resize(SIDE);
           stack<int> s;
           for (int i=0;i<SIDE;i++)
           {
               if (degree[i])
               {
                  dfs(i,s);
                  if (!s.empty())
                  {
                     part.push_back(vector<int>());
                     while (!s.empty())
                           part.back().push_back(s.top()),
                           getid[s.top()]=part.size(),
                           s.pop();
                  }
               }
           }
      }
      //END GET PART
      //GET ANSWER
      int answer;
      vector<pair<int,int> > list;
      bool check()
      {
           vector<vector<bool> > link(SIDE,vector<bool>(SIDE,false));
           
           for (int i=0;i<SIDE;i++)
               for (int j=0;j<SIDE;j++)
                   link[i][j]=c[i][j]||i==j;
           
           for (int k=0;k<SIDE;k++)
               for (int i=0;i<SIDE;i++)
                   for (int j=0;j<SIDE;j++)
                       if (link[i][k]&&link[k][j])
                          link[i][j]=true;
           
           for (int i=0;i<SIDE;i++)
               for (int j=0;j<SIDE;j++)
                   if (degree[i]&&degree[j]&&(!link[i][j])) return false;
           
           return true;
      }
      void update(vector<pair<int,int> >& record)
      {
           int nanswer=0;
           for (int i=0;i<record.size();i++)
               nanswer+=record[i].first+1+record[i].second+1;
           vector<pair<int,int> > nlist(record);
           
           int counter=0;
           for (int i=0;i<SIDE;i++)
               if (degree[i]%2) counter++;
           vector<int> add;
           for (int i=0;i<SIDE;i++)
           {
               if (counter==2||counter==0) break;
               if (degree[i]%2)
               {
                  nanswer+=i+1;
                  counter--;
                  add.push_back(i);
               }
           }
           for (int i=0;i<add.size();i+=2)
               nlist.push_back(make_pair(add[i],add[i+1]));
           
           if (nanswer<answer)
           {
              answer=nanswer;
              list=nlist;
           }
      }
      void search(const vector<int>& getid)
      {
           static vector<pair<int,int> > record;
           set<int> part;
           for (int i=0;i<SIDE;i++)
               if (getid[i])
                  part.insert(getid[i]);
           
           if (part.size()>1)
           {
              for (int i=0;i<SIDE;i++)
                  for (int j=i+1;j<SIDE;j++)
                      if (degree[i]&&degree[j]&&getid[i]!=getid[j])
                      {
                         vector<int> ngetid=getid;
                         for (int k=0;k<SIDE;k++)
                             if (getid[k]==getid[i])
                                ngetid[k]=ngetid[j];
                         c[i][j]++;
                         c[j][i]++;
                         degree[i]++;
                         degree[j]++;
                         record.push_back(make_pair(i,j));
                         search(ngetid);
                         record.pop_back();
                         degree[j]--;
                         degree[i]--;
                         c[j][i]--;
                         c[i][j]--;
                      }
           }
           else
           {
               if (check())
                  update(record);
           }
      }
      //END GET ANSWER
      public:
      Application()
                   :c(SIDE,vector<int>(SIDE,0)),degree(SIDE,0)
      {
                   int N;
                   cin>>N;
                   for (int i=0;i<N;i++)
                   {
                       int u,v;
                       cin>>u>>v;
                       c[u-1][v-1]++;
                       c[v-1][u-1]++;
                       degree[u-1]++;
                       degree[v-1]++;
                   }
      }
      int run()
      {
          get_part();
          answer=oo;
          search(getid);
          cout<<answer<<endl;
          cout<<list.size()<<endl;
          for (int i=0;i<list.size();i++)
              cout<<list[i].first+1<<" "<<list[i].second+1<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
