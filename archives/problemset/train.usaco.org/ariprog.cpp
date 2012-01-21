/*
ID: sujiao1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("ariprog.in");
std::ofstream cout("ariprog.out");

struct Program
{
       static const int MAXN=25;//3 to 25
       static const int MAXM=250;//1 to 250
       static const int MAXANSWERLEN=10000;
       int N,M;
       bool is[MAXM*MAXM*2+2];
       int A[MAXM*MAXM*2+2];
       int Al;
       int al;
       int aa[MAXANSWERLEN+2];
       int ab[MAXANSWERLEN+2];
       Program()
       {
                cin>>N>>M;
                for (int i=0;i<=M*M*2;i++)
                    is[i]=false;
                for (int i=0;i<=M;i++)
                    for (int j=i;j<=M;j++)
                        is[i*i+j*j]=true;
                Al=0;
                for (int i=0;i<=M*M*2;i++)
                    if (is[i]) A[++Al]=i;
       }
       void qsort(int l,int r)//stable
       {
            for (int i=1;i<al;i++)
                for (int j=al;j>i;j--)
                    if (ab[j-1]>ab[j])
                    {
                     int swap;
                     swap=ab[j];
                     ab[j]=ab[j-1];
                     ab[j-1]=swap;
                     swap=aa[j];
                     aa[j]=aa[j-1];
                     aa[j-1]=swap;
                    }
            return;
            /*
            int i=l;
            int j=r;
            int mid=ab[(l+r)/2];
            while (i<=j)
            {
                  while (ab[i]<mid) i++;
                  while (ab[j]>mid) j--;
                  if (i<=j)
                  {
                     int swap;
                     swap=ab[i];
                     ab[i]=ab[j];
                     ab[j]=swap;
                     swap=aa[i];
                     aa[i]=aa[j];
                     aa[j]=swap;
                     i++;
                     j--;
                  }
            }
            if (l<j) qsort(l,j);
            if (i<r) qsort(i,r);
            */
       }
       int run()
       {
           al=0;
           for (int ai=1;ai<=Al;ai++)
               for (int bi=ai+1;bi<=Al;bi++)//(int b=1;b<=M*M*2;b++)
               {
                   int a=A[ai];
                   int b=A[bi]-A[ai];
                   
                   {
                       bool answer=true;
                       for (int i=1;i<N;i++)
                           if ((a+i*b)>M*M*2||(!is[a+i*b]))
                           {
                              answer=false;
                              break;
                           }
                       if (answer)
                       {
                          al++;
                          aa[al]=a;
                          ab[al]=b;
                       }
                   }
               }
           if (al==0) cout<<"NONE"<<endl;
           else
           {
               qsort(1,al);
               for (int i=1;i<=al;i++)
                   cout<<aa[i]<<" "<<ab[i]<<endl;
           }
           //cout<<clock()<<endl;
           return 0;
       }
};
//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
