/*
AUTHOR: Su Jiao
DATE: $DATA
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Application
{
      int t,n,a,b;
      vector<int> pool;
      int get()
      {
          const int oo=~(1<<31);
          sort(pool.begin(),pool.end());
          //f[i]=pool[i]-max{f[next[i]]}
          vector<int> f(n,-oo);
          int answer=-oo;
          bool have_first=false;
          for (int i=n-1;i>=0;i--)
          {
              bool have_next=false;
              for (int j=i+1;j<n;j++)
                  if (a<=pool[j]-pool[i]
                      &&pool[j]-pool[i]<=b
                      &&f[i]<f[j])
                     f[i]=f[j],
                     have_next=true;
              if (have_next) f[i]=pool[i]-f[i];
              else f[i]=pool[i];
              //cout<<"f["<<pool[i]<<"]="<<f[i]<<endl;              
              if (a<=pool[i]
                  &&pool[i]<=b
                  &&answer<f[i])
                 answer=f[i],
                 have_first=true;
          }
          if (!have_first) answer=0;
          return answer;
      }
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
      }
      int run()
      {
          cin>>t;
          for (int i=0;i<t;i++)
          {
              cin>>n>>a>>b;
              pool.resize(n);
              for (int j=0;j<n;j++)
                  cin>>pool[j];
              cout<<get()<<endl;
              pool.clear();
          }
          //while (!cin.eof()) cin.get();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
