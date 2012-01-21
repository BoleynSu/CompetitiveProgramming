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

class Application
{
      static const int RED=0;
      static const int BLUE=1;
      static const int NOTCOLORED=-1;
      int N;
      vector<vector<int> > link;
      vector<int> color;
      bool color_it(int who,int with)
      {
           if (color[who]!=NOTCOLORED)
              return color[who]==with;
           else
           {
               color[who]=with;
               for (int i=0;i<link[who].size();i++)
                   if (!color_it(link[who][i],with==RED?BLUE:RED)) return false;
               return true;
           }
      }
      public:
      Application()
      {
                   cin>>N;
                   link.resize(N);
                   for (int i=0;i<N;i++)
                   {
                       int get;
                       for (;;)
                       {
                           cin>>get;
                           if (get)
                           {
                              link[i].push_back(get-1);
                              link[get-1].push_back(i);
                           }
                           else break;
                       }
                   }
      }
      int run()
      {
          bool can_color_it_in_red_and_blue=true;
          color.resize(N,NOTCOLORED);
          for (int i=0;i<N;i++)
              if (color[i]==NOTCOLORED)
                 if (!color_it(i,RED))
                 {
                    can_color_it_in_red_and_blue=false;
                    break;
                 }
          if (can_color_it_in_red_and_blue)
          {
             for (int i=0;i<N;i++)
                 cout<<color[i];
             cout<<endl;
          }
          else cout<<-1<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
