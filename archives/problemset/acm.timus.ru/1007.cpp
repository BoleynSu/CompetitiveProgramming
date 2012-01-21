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
#include <cassert>
//using std::assert;

class Application
{
      public:
      int run()
      {
          int n;
          cin>>n;
          string word;
          while (cin>>word)
          {
                int sum;
                if (word.length()==n)
                {
                   sum=0;
                   for (int i=0;i<n;i++)
                       sum+=(word[i]=='1'?i+1:0);
                   if (sum%(n+1)==0) cout<<word<<endl;
                   else
                   {
                       for (int i=0;i<n;i++)
                           if ((word[i]=='1')&&(((sum-(i+1))%(n+1))==0))
                           { 
                              word[i]='0';
                              break;
                           }
                       cout<<word<<endl;
                   }
                }
                if (word.length()==n+1)
                {
                   int insert;
                   for (insert=0;insert<n+1;insert++)
                   {
                       sum=0;
                       for (int i=0;i<n+1;i++)
                           if (word[i]=='1')
                           { 
                              if (i<insert) sum+=i+1;
                              else if (i>insert) sum+=i+1-1;
                           }
                       if (sum%(n+1)==0) break;
                   }
                   for (int i=0;i<n+1;i++)
                       if (i!=insert) cout<<word[i];
                   cout<<endl;
                }
                if (word.length()==n-1)
                {
                   int remove;
                   bool is0;
                   for (remove=0;remove<n;remove++)
                   {
                       sum=0;
                       for (int i=0;i<n-1;i++) if (word[i]=='1')
                           { 
                              if (i<remove) sum+=i+1;
                              else if (i>=remove) sum+=i+1+1;
                           }
                       if (sum%(n+1)==0)
                       {
                          is0=true;
                          break;
                       }
                       if ((sum+remove+1)%(n+1)==0)
                       {
                          is0=false;
                          break;
                       }
                   }
                   for (int i=0;i<n;i++)
                   {
                       if (i==remove) cout<<char(is0?'0':'1');
                       if (i<n-1)cout<<word[i];
                   } 
                   cout<<endl;
                }
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
