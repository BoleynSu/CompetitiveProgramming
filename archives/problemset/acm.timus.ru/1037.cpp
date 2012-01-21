/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-21
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
      static const int T=600;
      static const int N=30000;
      static const int oo=~(1<<31);
      vector<int> block,st;
      void change(int now,int l,int r,int id)
      {
           int mid=(l+r)/2;
           if (l==id&&r==id) st[now]=block[id];
           else
           {
               if (l<=id&&id<=mid)
                  change(now*2,l,mid,id);
               if (mid+1<=id&&id<=r)
                  change(now*2+1,mid+1,r,id);
               
               if (st[now*2]<st[now*2+1]) st[now]=st[now*2];
               else st[now]=st[now*2+1];
           }
      }
      int findmin(int now,int l,int r,int time)
      {
          int mid=(l+r)/2;
          if (l==r) return mid;
          if (st[now*2]<time) return findmin(now*2,l,mid,time);
          else return findmin(now*2+1,mid+1,r,time);
      }
      bool update(int id,int time)
      {
           if (block[id]<time) return false;
           else
           {
               block[id]=time+T-1;
               change(1,0,N-1,id);
               return true;
           }
      }
      int get(int time)
      {
          int find=findmin(1,0,N-1,time);
          block[find]=time+T-1;
          change(1,0,N-1,find);
          return find;
      }
      public:
      Application()
                   :block(N,-oo),st(N*4,-oo)
      {
      }
      int run()
      {
          int time;
          while (cin>>time)
          {
                char order;
                cin>>order;
                if (order=='.')
                {
                   int blockid;
                   cin>>blockid;
                   if (update(blockid-1,time)) cout<<"+"<<endl;
                    else cout<<"-"<<endl;
                }
                else cout<<get(time)+1<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
