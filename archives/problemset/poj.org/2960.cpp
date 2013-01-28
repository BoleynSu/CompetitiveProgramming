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
#include <string.h>

class Application
{
      static const int MAXK=100;
      static const int MAXL=100;
      static const int MAXH=10000;
      int k,m,l;
      int S[MAXK],h[MAXL],_sg[MAXH+1];
      int SG(int x)
      {
          if (_sg[x]!=-1) return _sg[x];
          else 
          {
               bool found[MAXH];
               memset(found,0,sizeof(found));
               for (int i=0;i<k;i++)
                   if (x-S[i]>=0)
                      found[SG(x-S[i])]=true;
               for (int i=0;i<MAXH;i++)
                   if (!found[i]) return _sg[x]=i;
          }
      }
      char get()
      {
           int sg=0;
           for (int i=0;i<l;i++)
               sg^=SG(h[i]);
           if (sg) return 'W';
           else return 'L';
      }
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
      }
      int run()
      {
          for (cin>>k;k;cin>>k)
          {
              for (int i=0;i<k;i++)
                  cin>>S[i];
              memset(_sg,-1,sizeof(_sg));
              cin>>m;
              for (int i=0;i<m;i++)
              {
                  cin>>l;
                  int max;
                  for (int j=0;j<l;j++)
                  {
                      cin>>h[j];
                      if (h[j]>max) max=h[j];
                  }
                  cout<<get();
              }
              cout<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
