/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-20
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
      int N;
      vector<int> p;
      int total;
      public:
      Application()
      {
                   cin>>N;
                   p.resize(N);
                   for (int i=0;i<=N;i++)
                   {
                       int id,position;
                       cin>>id>>position;
                       p[id-1]=position-1;
                   }
      }
      bool can()
      {
           vector<bool> sum(N*2,false),delta(N*2,false);
           for (int i=0;i<N;i++)
           {
               if (sum[i+p[i]]) return false;
               else sum[i+p[i]]=true;
               if (delta[N+i-p[i]]) return false;
               else delta[N+i-p[i]]=true;
           }
           return true;
      }
      int run()
      {
          total=0;
          for (int c1=0;c1<N;c1++)
              for (int c2=c1+1;c2<N;c2++)
                  for (int c3=c2+1;c3<N;c3++)
              {
                  //backup
                  int b1=p[c1],b2=p[c2],b3=p[c3];
                  //CASE 1:
                  p[c1]=b3;
                  p[c2]=b1;
                  p[c3]=b2;
                  if (can()) total++;
                  //CASE 2:
                  p[c1]=b2;
                  p[c2]=b3;
                  p[c3]=b1;
                  if (can()) total++;
                  //recover
                  p[c1]=b1;
                  p[c2]=b2;
                  p[c3]=b3;
              }
          cout<<total<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
