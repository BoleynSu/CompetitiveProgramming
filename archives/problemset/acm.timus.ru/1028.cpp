/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-19
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
using std::find;
#include <cassert>
//using std::assert;

class Application
{
      static const int oo=32000;
      int N;
      vector<pair<int,int> > point;
      void insert(vector<int>& st,int where,int l,int r,int in)
      {
           if (l<=in&&in<=r) st[where-1]++;
           if (l>=r) return;
           int mid=(l+r)/2;
           if (l<=in&&in<=mid) insert(st,where*2,l,mid,in);
           if (mid+1<=in&&in<=r) insert(st,where*2+1,mid+1,r,in);
      }
      int ask(vector<int>& st,int where,int l,int r,int as)
      {
          if (r<=as) return st[where-1];
          else
          {
              if (l>=r) return 0;
              int mid=(l+r)/2;
              int get=0;
              if (l<=as) get+=ask(st,where*2,l,mid,as);
              if (mid+1<=as) get+=ask(st,where*2+1,mid+1,r,as);
              return get;
          }
      }
      public:
      Application() 
      {
                    cin>>N;
                    point.resize(N);
                    for (int i=0;i<N;i++)
                        cin>>point[i].first>>point[i].second;
      }
      int run()
      {
          vector<int> counter(N,0);
          vector<int> st(oo*4);
          for (int i=0;i<N;i++)
          {
              counter[ask(st,1,0,oo,point[i].first)]++;
              insert(st,1,0,oo,point[i].first);
          }
          for (int i=0;i<N;i++)
              cout<<counter[i]<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
