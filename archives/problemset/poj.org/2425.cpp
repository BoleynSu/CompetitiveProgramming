/*
AUTHOR: Su Jiao
DATE: 2010-6-18
DESCRIPTION:
http://acm.pku.edu.cn/JudgeOnline/problem?id=2960
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string.h>

class Application
{
      static const int MAXN=1000;
      static const int MAXM=10;
      int N,M;
      vector<int> adj[MAXN];
      int _sg[MAXN];
      int SG(int x)
      {
          if (_sg[x]!=-1) return _sg[x];
          else 
          {
               bool found[MAXN];
               memset(found,0,sizeof(found));
               for (int i=0;i<adj[x].size();i++)
                   found[SG(adj[x][i])]=true;
               for (int i=0;i<MAXN;i++)
                   if (!found[i]) return _sg[x]=i;
          }
      }
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
      }
      int run()
      {
          while (cin>>N)
          {
                for (int i=0;i<N;i++)
                {
                    adj[i].clear();
                    int x;
                    cin>>x;
                    adj[i].resize(x);
                    for (int j=0;j<x;j++)
                        cin>>adj[i][j];
                }
                memset(_sg,-1,sizeof(_sg));
                for (cin>>M;M;cin>>M)
                {
                    int sg=0;
                    for (int i=0;i<M;i++)
                    {
                        int j;
                        cin>>j;
                        sg=sg xor SG(j);
                    }
                    if (sg) cout<<"WIN"<<endl;
                    else cout<<"LOSE"<<endl;
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
