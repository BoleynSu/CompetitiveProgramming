/*
ID: sujiao1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
#include <cassert>
#include <cstdio>
#include <cstring>
using std::memset;

//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("stamps.in");
std::ofstream cout("stamps.out");

struct Program
{
       static const int MAXK=200;//1 to 200
       static const int MAXN=50;//1 to 50
       static const int MAXVALUE=10000;//1 to 10000
       int K,N;
       int maxv;
       int v[MAXN+2];
       int answer;
       unsigned short int* f;
       Program()
       {
                cin>>K>>N;
                for (int i=1;i<=N;i++) cin>>v[i];
       }
       int run()
       {
           maxv=0;
           for (int i=1;i<=N;i++)
               if (maxv<v[i]) maxv=v[i];
           
           f=new unsigned short int[K*maxv+2];
           for (int i=1;i<=K*maxv;i++) f[i]=~0;
           
           f[0]=0;
           
           answer=K*maxv;
           for (int i=0;i<=K*maxv;i++)
           {
               for (int j=1;j<=N;j++)
                   if (i-v[j]>=0)
                   {
                      if (f[i-v[j]]+1<f[i])
                      {
                         f[i]=f[i-v[j]]+1;
                         //cout<<i+v[j]<<endl;
                      }
                      //cout<<j<<"j"<<endl;
                   }
               //cout<<i<<":"<<f[i]<<endl;
               if (f[i]>K)
               {
                  answer=i-1;
                  break;
               }
           }
           cout<<answer<<endl;
           //cout<<clock()<<endl;
           return 0;
       }
       /*
       unsigned short int f[MAXVALUE*2];
       inline
       int h(int k)
       {
           return k%(MAXVALUE*2);
       }
       int main()
       {
           f[h(0)]=0;
           for (answer=0;f[h(answer)]<=K;answer++)
           {
               for (int j=N;j>=1;j--)
                   if (f[h(answer)]+1<f[h(answer+v[j])])
                   f[h(answer+v[j])]=f[h(answer)]+1;
           }
           answer--;
           cout<<answer<<endl;
           return 0;
       }
       */
};

#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
