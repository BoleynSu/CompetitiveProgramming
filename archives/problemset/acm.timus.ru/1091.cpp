/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-13
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
      int K,S;
      int answer;
      static int C(int n,int m)
      {
             if (m>n||m<0) return 0;
             else
             {
                 int c=1;
                 for (int i=n;i>m;i--) c=c*i/(n-i+1);
                 return c;
             }
      }
      public:
      Application()
      {
                   cin>>K>>S; 
      }
      int run()
      {
          vector<bool> prime(S+1,false);
          for (int i=2;i<=S;i++)
          {
              prime[i]=true;
              for (int j=2;j<i;j++)
                  if (i%j==0)
                     prime[i]=false;
          }
          vector<bool> prime_prime(S+1,false);
          for (int i=2;i<=S;i++)
              for (int j=i+1;j<=S;j++)
                  if (prime[i]&&prime[j]&&(i*j<=S))
                     prime_prime[i*j]=true;
          vector<bool> prime_prime_prime(S+1,false);
          for (int i=2;i<=S;i++)
              for (int j=i+1;j<=S;j++)
                  for (int k=j+1;k<=S;k++)
                      if (prime[i]&&prime[j]&&prime[k]&&(i*j*k<=S))
                         prime_prime_prime[i*j*k]=true;
          vector<int> g(S+1,0);
          for (int i=2;i<=S;i++)
              for (int j=1;j<=S;j++)
                  if (j%i==0)
                     g[i]++;
          answer=0;
          for (int i=2;i<=S;i++)
          {
              if (prime[i]) answer+=C(g[i],K);
              else if (prime_prime[i]) answer-=C(g[i],K);
              else if (prime_prime_prime[i]) answer+=C(g[i],K);
          }
          cout<<(answer>10000?10000:answer)<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
