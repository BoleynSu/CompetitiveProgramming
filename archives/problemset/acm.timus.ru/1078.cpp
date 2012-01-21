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
#include <cassert>
//using std::assert;

struct Compare
{
       inline
       bool operator ()(const pair<pair<int,int>,int>& a,
                        const pair<pair<int,int>,int>& b)
       {
            if (a.first.first>b.first.first) return true;
            else if (a.first.first<b.first.first) return false;
            else return a.first.second<b.first.second;
       }
};
class Application
{
      int N;
      vector<pair<pair<int,int>,int> > segment;
      public:
      Application()
      {
            cin>>N;
            segment.resize(N);
            for (int i=0;i<N;i++)
            {
                cin>>segment[i].first.first
                   >>segment[i].first.second;
                segment[i].second=i+1;
            }
      }
      int run()
      {
          sort(segment.begin(),segment.end(),Compare());
          static const int NOPRE=-1;
          vector<int> f(N);
          vector<int> pre(N);
          int answer=0;
          for (int i=0;i<N;i++)
          {
              f[i]=1;
              pre[i]=NOPRE;
              for (int j=0;j<i;j++)
                  if (segment[i].first.first<segment[j].first.first
                      &&segment[j].first.second<segment[i].first.second)
                     if (f[j]+1>f[i])
                     {
                        f[i]=f[j]+1;
                        pre[i]=j;
                     }
              if (f[i]>f[answer]) answer=i;
          }
          cout<<f[answer]<<endl;
          stack<int> output;
          int now=answer;
          while (now!=NOPRE)
          {
                output.push(segment[now].second);
                now=pre[now];
          }
          while (!output.empty())
          {
                cout<<output.top();
                output.pop();
                if (output.empty()) cout<<endl;
                else cout<<" ";
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
