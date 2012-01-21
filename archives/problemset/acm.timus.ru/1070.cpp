/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-8
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

struct Clock{int h,m;};
struct Flight{Clock start,end;};
class Application
{
      Flight gof,returnf;
      Clock distance(Clock a,Clock b)
      {
            while (a.h>=24) a.h-=24;
            while (b.h>=24) b.h-=24;
            while (a.h<0) a.h+=24;
            while (b.h<0) b.h+=24;
            
            if ((a.h<b.h)||(a.h==b.h&&a.m<b.m))
            {
               Clock s=a;
               a=b;
               b=s;
            }
            Clock d;
            d.h=a.h-b.h;
            d.m=a.m-b.m;
            if (d.m<0)
            {
               d.m+=60;
               d.h--;
            }
            if (d.h>12)
            {
               d.h=24-d.h-1;
               d.m=60-d.m;
               if (d.m>60)
               {
                  d.m-=60;
                  d.h++;
               }
            }
            return d;
      }
      bool check()
      {
           Clock god=distance(gof.start,gof.end),
                 returnd=distance(returnf.start,returnf.end);
           if ((god.h>6)||(god.h==6&&god.m!=0)) return false;
           if ((returnd.h>6)||(returnd.h==6&&returnd.m!=0)) return false;
           Clock d=distance(god,returnd);
           if ((d.h>0)||(d.h==0&&d.m>10)) return false;
           
           return true;
      }
      int abs(int n)
      {
          return n>0?n:-n;
      }
      public:
      Application()
      {
                   char dot;
                   cin>>gof.start.h>>dot>>gof.start.m
                      >>gof.end.h>>dot>>gof.end.m
                      >>returnf.start.h>>dot>>returnf.start.m
                      >>returnf.end.h>>dot>>returnf.end.m;
      }
      int run()
      {
          for (int answer=-5;answer<=5;answer++)
          {
              gof.start.h+=answer;
              returnf.start.h-=answer;
              if (check()) cout<<abs(answer)<<endl;
              returnf.start.h+=answer;
              gof.start.h-=answer;              
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}

