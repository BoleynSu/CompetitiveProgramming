/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-12
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
      int N,K;
      vector<vector<int> > data;
      int answer;
      static int count(const vector<int>& bst,int root,int l,int r,int c)
      {
             if (l>=c) return bst[root];
             if (l<r)
             {
                int g=0;
                int mid=(l+r)/2;
                if (l<=c)
                   g+=count(bst,(root*2),l,mid,c);
                if (c<=r)
                   g+=count(bst,(root*2)+1,mid+1,r,c);
                return g;
             }
             return 0;
      }
      static void insert(vector<int>& bst,int root,int l,int r,int i)
      {
             bst[root]++;
             if (l<r)
             {
                int mid=(l+r)/2;
                if (l<=i&&i<=mid)
                   insert(bst,(root*2),l,mid,i);
                if (mid+1<=i&&i<=r)
                   insert(bst,(root*2)+1,mid+1,r,i);
             }
      }
      public:
      Application()
      {
                   cin>>N>>K;
                   data.resize(K,vector<int>(N));
                   for (int i=0;i<K;i++)
                       for (int j=0;j<N;j++)
                       {
                           int get;
                           cin>>get;
                           data[i][j]=get-1;
                       }
      }
      int run()
      {
          int max=-1;
          for (int i=0;i<K;i++)
          {
              vector<int> bst(N*2*2,0);
              int total=0;
              for (int j=0;j<N;j++)
              {
                  int get=count(bst,1,0,N-1,data[i][j]);
                  total+=get;
                  insert(bst,1,0,N-1,data[i][j]);
              }
              if (total>max)
              {
                 max=total;
                 answer=i+1;
              }
          }
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
