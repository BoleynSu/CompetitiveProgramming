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
      static const int oo=1000000000;
      int L1,L2,L3;
      int C1,C2,C3;
      int N;
      int start,end;
      vector<int> d;
      int price(int f,int t)
      {
          if (d[t]-d[f]<=L1) return C1;
          if (d[t]-d[f]<=L2) return C2;
          if (d[t]-d[f]<=L3) return C3;
          return oo;
      }
      public:
      Application() 
      {
                    cin>>L1>>L2>>L3
                       >>C1>>C2>>C3
                       >>N
                       >>start>>end;
                    if (start>end)
                    {
                       int swap=start;
                       start=end;
                       end=swap;
                    }
                    start--;
                    end--;
                    d.resize(N);
                    d[0]=0;
                    for (int i=1;i<N;i++)
                        cin>>d[i];
      }
      int run()
      {
          vector<int> f(N);
          std::deque<int> q1,q2,q3;
          f[start]=0;
          q1.push_back(start);
          q2.push_back(start);
          q3.push_back(start);
          for (int i=start+1;i<=end;i++)
          {
              f[i]=oo;
              while ((!q1.empty())&&(d[i]-d[q1.front()]>L1)) q1.pop_front();
              while ((!q2.empty())&&(d[i]-d[q2.front()]>L2)) q2.pop_front();
              while ((!q3.empty())&&(d[i]-d[q3.front()]>L3)) q3.pop_front();
              if ((!q1.empty())&&(f[i]>f[q1.front()]+price(q1.front(),i)))
                 f[i]=f[q1.front()]+price(q1.front(),i);
              if ((!q2.empty())&&(f[i]>f[q2.front()]+price(q2.front(),i)))
                 f[i]=f[q2.front()]+price(q2.front(),i);
              if ((!q3.empty())&&(f[i]>f[q3.front()]+price(q3.front(),i)))
                 f[i]=f[q3.front()]+price(q3.front(),i);
              q1.push_back(i);
              q2.push_back(i);
              q3.push_back(i);
          }
          cout<<f[end]<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
