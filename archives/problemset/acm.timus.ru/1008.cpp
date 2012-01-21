/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-12 
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
using std::getline;

class ApplicationNumberToString
{
      static const int oo=~(1<<31);
      int n;
      pair<int,int> LB;
      vector<pair<pair<int,int>,bool> > dot;
      public:
      ApplicationNumberToString(int readn)
                                    :n(readn)
      {
                                    LB=make_pair(oo,oo);
                                    for (int i=0;i<n;i++)
                                    {
                                        pair<int,int> get;
                                        cin>>get.first>>get.second;
                                        dot.push_back(make_pair(get,false));
                                        if (get<LB) LB=get;
                                    }
      }
      int run()
      {
          queue<pair<int,int> > q;
          
          q.push(LB);
          for (int i=0;i<dot.size();i++)
              if (dot[i].first==q.front())
                 dot[i].second=true;
          cout<<LB.first<<" "<<LB.second<<endl;
          
          while (!q.empty())
          {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                #define if_find_print(point,flag)\
                        for (int i=0;i<dot.size();i++)\
                            if ((dot[i].first==point)&&(!dot[i].second))\
                            {\
                               dot[i].second=true;\
                               q.push(point);\
                               cout<<flag;\
                            }
                if_find_print(make_pair(x+1,y),'R');
                if_find_print(make_pair(x,y+1),'T');
                if_find_print(make_pair(x-1,y),'L');
                if_find_print(make_pair(x,y-1),'B');
                cout<<char(q.empty()?'.':',')<<endl;
                #undef if_find_print
          }
          return 0;
      }
};
class ApplicationStringToNumber
{
      pair<int,int> LB;
      vector<pair<int,int> > dot;
      public:
      ApplicationStringToNumber(pair<int,int> readLB)
                                              :LB(readLB)
      {
                                              dot.push_back(LB);
                                              string description;
                                              int counter=0;
                                              while (cin>>description)
                                              {
                                                    for (int i=0;i<description.length()-1;i++)
                                                    {
                                                        if (description[i]=='R')
                                                           dot.push_back(make_pair(dot[counter].first+1,dot[counter].second));
                                                        if (description[i]=='T')
                                                           dot.push_back(make_pair(dot[counter].first,dot[counter].second+1));
                                                        if (description[i]=='L')
                                                           dot.push_back(make_pair(dot[counter].first-1,dot[counter].second));
                                                        if (description[i]=='B')
                                                           dot.push_back(make_pair(dot[counter].first,dot[counter].second-1));
                                                    }
                                                    counter++;
                                              }
      }
      int run()
      {
          sort(dot.begin(),dot.end());
          cout<<dot.size()<<endl;
          for (int i=0;i<dot.size();i++)
              cout<<dot[i].first<<" "<<dot[i].second<<endl;
          return 0;
      }
};
class Application
{
      int readn;
      pair<int,int> readLB;
      bool NumberToString()
      {
           string first_line;
           getline(cin,first_line);
           stringstream sin_LB(first_line);
           if (sin_LB>>readLB.first>>readLB.second) return false;
           stringstream sin_n(first_line);
           if (sin_n>>readn) return true;
      }
      public:
      int run()
      {
          if (NumberToString())
          {
             ApplicationNumberToString app(readn);
             return app.run();
          }
          else
          {
              ApplicationStringToNumber app(readLB);
              return app.run();
          }
      }
}; 
int main()
{
    Application app;
    return app.run();
}
