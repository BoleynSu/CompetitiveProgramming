/*
ID: sujiao1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("checker.in");
std::ofstream cout("checker.out");

struct Program
{
       static const int MAXN=13;//1 to 13
       int N,total;
       bool A[MAXN*2+2];
       bool D[MAXN*2+2];
       bool Y[MAXN+2];
       int p[MAXN*2+2];
       Program():total(0)
       {
                cin>>N;
                for (int i=0;i<MAXN*2;i++)
                    p[i]=A[i]=D[i]=Y[i]=0;
       }
       void put1(int x=1)
       {
            if (x!=N+1)
            {
               for (p[x]=1;p[x]<=N;p[x]++)
                   if (!(Y[p[x]]||A[x+p[x]]||D[p[x]-x+N]))
                   {
                      Y[p[x]]=A[x+p[x]]=D[p[x]-x+N]=true;
                      put1(x+1);
                      Y[p[x]]=A[x+p[x]]=D[p[x]-x+N]=false;
                   }
            }
            else
            {
                total++;
                if (total<=3)
                {
                   for (int i=1;i<N;i++)
                       cout<<p[i]<<" ";
                   cout<<p[N]<<endl;
                }
            }
       }
       void put2()
       {
            int x=1;
            for (;;)
            {
                if (x==0) break;
                
                p[x]++;
                                
                if (p[x]!=N+1)
                {
                    if (x!=N+1)
                    {
                         if (!(Y[p[x]]||A[x+p[x]]||D[p[x]-x+N]))
                         {
                            Y[p[x]]=A[x+p[x]]=D[p[x]-x+N]=true;
                            x++;
                         }
                    }
                    else 
                    {
                       p[x]=0;
                       x--;
                       Y[p[x]]=A[x+p[x]]=D[p[x]-x+N]=false;
                       total++;
                       if (total<=3)
                       {
                          for (int i=1;i<N;i++)
                              cout<<p[i]<<" ";
                          cout<<p[N]<<endl;
                       }
                    }
                }
                else
                {
                     p[x]=0;
                     x--;
                     Y[p[x]]=A[x+p[x]]=D[p[x]-x+N]=false;
                }
            }
       }
       int max;
       void put3(int x=1,int y=0,int a=0,int d=0)
       {
            if (x!=N+1)
            {
               int n=(y|a|d)&max;
               while (n!=max)
               {
                     int i=(~n)&(n+1)&max;
                     p[x]=i;
                     put3(x+1,y|i,(a|i)<<1,(d|i)>>1);
                     n=n|i&max;
               }
            }
            else
            {
                total++;
                if (total<=3)
                {
                   for (int i=1;i<N;i++)
                       cout<<(int)(log2(p[i])+1)<<" ";
                   cout<<(int)(log2(p[N])+1)<<endl;
                }
            }
       }
       int run()
       {
           //put1();
           //put2();
           max=(1<<N)-1;
           put3();
           cout<<total<<endl;
           return 0;
       }
};
int main()
{
    Program app;
    return app.run();
}
