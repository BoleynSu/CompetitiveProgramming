/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-28
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
      Type X,Y;
      int K,B;
      static Type C(Type n,Type m)
      {
             if (m<0||m>n) return 0;
             Type c=1;
             for (int i=m+1;i<=n;i++) c=c*i/(i-m);
             return c;
      }
      public:
      Application()
      {
                   cin>>X>>Y
                      >>K
                      >>B;
      }
      int run()
      {
          vector<Type> b;
          b.push_back(1);
          while (b.back()*B<=Y) b.push_back(b.back()*B);
          
          Type min=0,max=0;
          vector<bool> min_state(b.size(),false),max_state(b.size(),false);
          int counter;
          
          counter=0;
          for (int i=b.size()-1;i>=0;i--)
              if (min+b[i]<X&&counter<K) min+=b[i],counter++,min_state[i]=true;
          counter=0;
          for (int i=b.size()-1;i>=0;i--)
              if (max+b[i]<=Y&&counter<K) max+=b[i],counter++,max_state[i]=true;
          
          Type min_index=1,max_index=1;
          counter=K;
          for (int i=min_state.size()-1;i>=0;i--)
              if (min_state[i]) min_index+=C(i,counter--);
          if (counter) min_index--;
          counter=K;
          for (int i=max_state.size()-1;i>=0;i--)
              if (max_state[i]) max_index+=C(i,counter--);
          if (counter) max_index--;
          cout<<max_index-min_index<<endl;
          
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}

