/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-16 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
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
      vector<int> a;
      vector<int> b;
      vector<char> c;
      public:
      Application() 
      {
                    cin>>N;
                    a.resize(N);
                    b.resize(N);
                    c.resize(N);
                    for (int i=0;i<N;i++)
                        cin>>a[i]>>b[i]>>c[i];
      }
      int run()
      {
          vector<pair<int,int> > q;     
          q.push_back(make_pair(0,1000000000));
          for (int i=0;i<N;i++)
          {
              switch (c[i])
              {
                     case 'w':
                          q.push_back(make_pair(a[i],b[i]));
                          break;
                     case 'b':
                          int end=q.size();
                          for (int j=0;j<end;j++)
                          {
                              if (q[j].first<b[i]&&q[j].second>a[i])
                              {
                                 if (q[j].first<a[i])
                                    q.push_back(make_pair(q[j].first,a[i]));
                                 if (b[i]<q[j].second)
                                    q.push_back(make_pair(b[i],q[j].second));
                              }
                              else q.push_back(make_pair(q[j].first,q[j].second));
                          }
                          q.erase(q.begin(),q.begin()+end);
                          break;
              }
          }
          
          sort(q.begin(),q.end());
          
          pair<int,int> answer=make_pair(0,0);
          for (int i=0,j;i<q.size();i=j)
          {
              int first=q[i].first,second=q[i].second;
              for (j=i+1;j<q.size();j++)
                  if (q[j].first<=second)
                  {
                     if (q[j].second>second)
                        second=q[j].second;
                  }
                  else break;
              if (second-first>answer.second-answer.first)
                 answer=make_pair(first,second);
          }
          cout<<answer.first<<" "<<answer.second<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
