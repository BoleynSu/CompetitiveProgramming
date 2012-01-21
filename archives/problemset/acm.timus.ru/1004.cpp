/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-10 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
//using std::map;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
using std::pair;
using std::make_pair;
#include <cassert>
//using std::assert;

class Question
{
      static const int oo=1<<29;
      vector<vector<int> > map;
      void print(stack<int>& s,vector<vector<int> >& mid,int u,int v)
      {
           if (mid[u][v]<0)
           {
              if (s.top()!=u) s.push(u);
              if (s.top()!=v) s.push(v);
           }
           else
           {
               print(s,mid,u,mid[u][v]);
               print(s,mid,mid[u][v],v);
           }
      }
      public:
      bool read()
      {
           int N,M;
           cin>>N;
           if (N==-1) return false;           
           cin>>M;
           
           map.resize(N,vector<int>(N,oo));
           
           for (int i=0;i<M;i++)
           {
               int u,v,l;
               cin>>u>>v>>l;
               u--;
               v--;
               //assert(u<N&&v<N);
               if (map[u][v]>l) map[u][v]=l;
               if (map[v][u]>l) map[v][u]=l;
           }
           return true;
      }
      void solve()
      {
           vector<vector<int> > dist,mid;
           
           dist=map;
           mid.resize(dist.size(),vector<int>(dist.size(),-1));
           
           int min=oo;
           int min_i,min_j,min_k;
           for (int k=0;k<dist.size();k++)
           {
               for (int i=0;i<k;i++)
                   for (int j=i+1;j<k;j++)
                   {
                       //assert(i!=j&&i!=k&&j!=k);
                       if (min>(dist[j][i]+map[i][k]+map[k][j]))
                       { 
                          min=dist[j][i]+map[i][k]+map[k][j];
                          min_i=i;
                          min_j=j;
                          min_k=k;
                       }
                   }
               
               for (int i=0;i<dist.size();i++)
                   for (int j=0;j<dist.size();j++)
                       if (dist[i][j]>dist[i][k]+dist[k][j])
                          dist[i][j]=dist[i][k]+dist[k][j];
           }
           
           if (min<oo)
           {
              dist=map;
              dist[min_i][min_k]=dist[min_k][min_i]=oo;
              dist[min_j][min_k]=dist[min_k][min_j]=oo;
              
              for (int k=0;k<dist.size();k++)
                  for (int i=0;i<dist.size();i++)
                      for (int j=0;j<dist.size();j++)
                          if (dist[i][j]>dist[i][k]+dist[k][j])
                          {
                             dist[i][j]=dist[i][k]+dist[k][j];
                             mid[i][j]=k;
                          }
              
              stack<int> s;
              
              s.push(min_k);
              print(s,mid,min_i,min_j);
              
              for (;;)
              {
                  cout<<s.top()+1;
                  s.pop();
                  if (s.empty()) 
                  {
                     cout<<endl;
                     break;
                  }
                  else cout<<" ";
              }
           }
           else cout<<"No solution."<<endl;
           
           map.clear();
      }
}; 

class Application
{
      public:
      Application() 
      {
      }
      int run()
      {
          Question q;
          while (q.read()) q.solve();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
