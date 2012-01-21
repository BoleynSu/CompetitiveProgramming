/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-24 
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
      typedef long long int Type;
      int M,N;
      vector<vector<Type> > v;
      vector<pair<int,int> > p;
      static Type abs(Type n)
      {
             return n>=0?n:-n;
      }
      static Type gcd(Type a,Type b)
      {
             return b?gcd(b,a%b):a;
      }      
      bool push(vector<vector<Type> >& get,vector<Type> add)
      {
           vector<int> first(N);
           for (int i=0;i<get.size();i++)
               for (int j=0;j<N;j++)
                   if (get[i][j]!=0)
                   {
                      first[i]=j;
                      break;
                   }
           for (int i=0;i<get.size();i++)
           {
               static const Type BIGPRIME=549979;
               Type _gcd=gcd(abs(add[first[i]]),abs(get[i][first[i]]));
               //assert(_gcd!=0);
               if (_gcd)
               {
               Type mulj=get[i][first[i]]/_gcd;
               Type mulget=add[first[i]]/_gcd;
               for (int j=0;j<N;j++)
                   add[j]=(add[j]*mulj-get[i][j]*mulget)%BIGPRIME;
               }
               bool can=false;
               for (int j=0;j<N;j++)
                   if (add[j]!=0) can=true;
               if (!can) return false;
           }
           get.push_back(add);
           return true;
      }
      public:
      Application() 
      {
                    cin>>M>>N;
                    v.resize(M,vector<Type>(N));
                    for (int i=0;i<M;i++)
                        for (int j=0;j<N;j++)
                            cin>>v[i][j];
                    p.resize(M);
                    for (int i=0;i<M;i++)
                    {
                        cin>>p[i].first;
                        p[i].second=i;
                    }
      }
      int run()
      {
          sort(p.begin(),p.end());
          int total=0;
          vector<int> answer;
          vector<vector<Type> > get;
          for (int i=0;i<M;i++)
          {
              if (push(get,v[p[i].second]))
              {
                 total+=p[i].first;
                 answer.push_back(p[i].second);
              }
              if (get.size()==N) break;
          }
          if (get.size()==N)
          {
             cout<<total<<endl;
             sort(answer.begin(),answer.end());
             for (int i=0;i<answer.size();i++)
                 cout<<answer[i]+1<<endl;
          }
          else cout<<0<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
