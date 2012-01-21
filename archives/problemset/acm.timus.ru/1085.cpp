/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-11
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

struct Record
{
       int money,start;
       bool have_card;
};
class Application
{
      static const int oo=1<<20;
      int N,M;
      vector<vector<int> > bus;
      int K;
      vector<Record> data;
      vector<vector<int> > cost;
      public:
      Application()
      {
                   cin>>N>>M;
                   bus.resize(M);
                   for (int i=0;i<M;i++)
                   {
                       int total;
                       cin>>total;
                       bus[i].resize(total);
                       for (int j=0;j<total;j++)
                       {
                           int get;
                           cin>>get;
                           bus[i][j]=get-1;
                       }
                   }
                   cin>>K;
                   data.resize(K);
                   for (int i=0;i<K;i++)
                   {
                       int get;
                       cin>>data[i].money>>get>>data[i].have_card;
                       data[i].start=get-1;
                   }
      }
      int run()
      {
          cost.resize(N,vector<int>(N,oo));
          for (int i=0;i<M;i++)
              for (int j=0;j<bus[i].size();j++)
                  for (int k=0;k<bus[i].size();k++)
                      cost[bus[i][j]][bus[i][k]]=1;
          for (int i=0;i<N;i++)
              cost[i][i]=0;
          for (int k=0;k<N;k++)
              for (int i=0;i<N;i++)
                  for (int j=0;j<N;j++)
                      if (cost[i][j]>cost[i][k]+cost[k][j])
                         cost[i][j]=cost[i][k]+cost[k][j];
          int station,money=oo;
          for (int i=0;i<N;i++)
          {
              int use=0;
              for (int j=0;j<K;j++)
                  if (!data[j].have_card)
                  {
                     use+=cost[data[j].start][i]*4;
                     if (cost[data[j].start][i]*4>data[j].money)
                     {
                        use=oo;
                        break;
                     }
                  }
                  else if (cost[data[j].start][i]==oo)
                  {
                       use=oo;
                       break;
                  }
              if (use<money)
              {
                 money=use;
                 station=i+1;
              }
          }
          if (money==oo) cout<<0<<endl;
          else cout<<station<<" "<<money<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
