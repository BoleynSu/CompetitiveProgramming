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
using std::priority_queue;
#include <set>
using std::set;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
using std::min;
#include <cassert>
//using std::assert;

class Application
{
      static const int oo=1<<20;
      int N;
      vector<vector<int> > data;
      vector<vector<int> > cost;
      vector<vector<int> > c;
      int answer;
      void max_flow_with_min_cost(const int& S,const int& T)
      {
           static const int NOPRE=-1;
           answer=0;
           vector<vector<int> > f((N+1)*2,vector<int>((N+1)*2,0));
           for (;;)
           {
               vector<int> pre((N+1)*2,NOPRE);
               vector<int> dis((N+1)*2,oo);
               queue<int> q;
               vector<bool> inq((N+1)*2,false);
               pre[S]=S;
               dis[S]=0;
               q.push(S);
               inq[S]=true;
               while (!q.empty())
               {
                     int now=q.front();
                     for (int i=0;i<(N+1)*2;i++)
                         if ((f[now][i]<c[now][i])
                             &&(dis[i]>dis[now]+cost[now][i]))
                         {
                            pre[i]=now;
                            dis[i]=dis[now]+cost[now][i];
                            if (!inq[i])
                            {
                               q.push(i);
                               inq[i]=true;
                            }
                         }
                     q.pop();
                     inq[now]=false;
               }
               if (pre[T]==NOPRE) break;
               else
               {
                   int delta=oo;
                   int now;
                   now=T;
                   for (;;)
                   {
                       delta=min(delta,c[pre[now]][now]-f[pre[now]][now]);
                       now=pre[now];
                       if (pre[now]==now) break;
                   }
                   now=T;
                   for (;;)
                   {
                       f[pre[now]][now]+=delta;
                       f[now][pre[now]]-=delta;
                       now=pre[now];
                       if (pre[now]==now) break;
                   }
                   answer+=delta*dis[T];
               } 
           }
      }
      public:
      Application()
      {
                   cin>>N;
                   data.resize(N,vector<int>(N));
                   for (int i=0;i<N;i++)
                       for (int j=0;j<N;j++)
                           cin>>data[i][j];
      }
      int run()
      {
          const int S=N*2,T=N*2+1;
          cost.resize((N+1)*2,vector<int>((N+1)*2,oo));
          for (int i=0;i<N;i++)
          {
              int sum=0;
              for (int j=0;j<N;j++)
                  sum+=data[i][j];
              for (int j=0;j<N;j++)
              {
                  cost[i][N+j]=sum-data[i][j];
                  cost[N+j][i]=data[i][j]-sum;
              }
          }
          for (int i=0;i<N;i++)
          {
              cost[S][i]=0;
              cost[i][S]=0;
          }
          for (int i=0;i<N;i++)
          {
              cost[i+N][T]=0;
              cost[T][i+N]=0;
          }
          c.resize((N+1)*2,vector<int>((N+1)*2,0));
          for (int i=0;i<N;i++)
              for (int j=0;j<N;j++)
                  c[i][j+N]=oo;
          for (int i=0;i<N;i++)
              c[S][i]=1;
          for (int i=0;i<N;i++)
              c[i+N][T]=1;
          max_flow_with_min_cost(S,T);
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
