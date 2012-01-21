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
      typedef unsigned int bit;
      vector<vector<bit> > computer;
      int f,t;
      public:
      Application()
      {
                   int n,k;
                   cin>>n;
                   computer.resize(n);
                   for (int i=0;i<n;i++)
                   {
                       cin>>k;
                       computer[i].resize(k);
                       for (int j=0;j<k;j++)
                       {
                           bit a,b,c,d;
                           bit A,B;
                           char dot;
                           cin>>a>>dot>>b>>dot>>c>>dot>>d;
                           A=(a<<24)|(b<<16)|(c<<8)|(d);
                           cin>>a>>dot>>b>>dot>>c>>dot>>d;
                           B=(a<<24)|(b<<16)|(c<<8)|(d);
                           computer[i][j]=A&B;
                       }
                   }
                   cin>>f>>t;
      }
      int run()
      {
          static const int NOPRE=-1;
          vector<int> pre(computer.size(),NOPRE);
          queue<int> q;
          pre[f-1]=f-1;
          q.push(f-1);
          while (!q.empty())
          {
                int now=q.front();
                for (int i=0;i<computer.size();i++)
                    if (pre[i]==NOPRE)
                    {
                       for (int j=0;j<computer[i].size();j++)
                           for (int k=0;k<computer[now].size();k++)
                               if (computer[i][j]==computer[now][k])
                               {
                                  pre[i]=now;
                                  q.push(i);
                                  break;
                               }
                    }
                q.pop();
          }
          if (pre[t-1]==NOPRE) cout<<"No"<<endl;
          else
          {
              cout<<"Yes"<<endl;
              stack<int> path;
              int u=t-1;
              for (;;)
              {
                    path.push(u);
                    if (pre[u]==u) break;
                    u=pre[u];
              }
              while (!path.empty())
              {
                    cout<<path.top()+1;
                    path.pop();
                    if (path.empty()) cout<<endl;
                    else cout<<" ";
              }
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
