/*
ID: sujiao1
PROG: humble
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
#include <stdio.h>
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("humble.in");
std::ofstream cout("humble.out");

struct Program
{
       static const int MAXK=100;//1 to 100
       static const int MAXN=100000;//1 to 100000
       static const unsigned int oo=~0;
       int K,N;
       unsigned int S[MAXK+2];
       unsigned int answer;
       unsigned int find[MAXN+2];
       Program():answer(0) 
       {
                cin>>K>>N;
                for (int i=1;i<=K;i++)
                    cin>>S[i];                    
                /*
                cout<<K<<" "<<N<<endl<<S[1];
                for (int i=2;i<=K;i++)
                    cout<<" "<<S[i];
                cout<<endl;
                */
       }
       /*
       inline 
       void next(int& ret)
       {
            for (int i=ret+1;;i++)
            {
                int print=i;
                for (int j=1;j<=K;j++) 
                    while (print%S[j]==0) print/=S[j];
                if (print==1)
                {
                   ret=i;
                   return;
                }
            } 
       }
       */
       /*
       bool notFind(int key)
       {
            int l=1,r=findLen;
            int mid; 
            for (;l<=r;)
            {
                mid=(l+r)/2;
                if (find[mid]<key)
                   l=mid+1;
                else if (find[mid]>key)
                     r=mid-1;
                else return false;
            }
            return true;
       } 
       inline 
       unsigned int next()
       {
            unsigned int ret=oo; 
            //for (int i=1;i<=findLen;i++) cout<<find[i]<<" ";cout<<endl;
            for (int i=1;i<=findLen;i++)
                for (int j=1;j<=K;j++)
                    if ((find[i]*S[j]<ret)&&notFind(find[i]*S[j])) 
                       ret=find[i]*S[j];
            //cout<<ret<<"next\n";
            return ret;
       }
       int main()
       {
           N++;
           findLen=0;
           for (unsigned int i=1;findLen<=N;i=next())
           {
               findLen++;
               find[findLen]=i;
           }
           answer=find[N];
           cout<<answer<<endl;
           return 0;
       }
       */
       inline 
       void next()
       {
            find[0]=1;
            unsigned int last[MAXK+2];
            for (int i=1;i<=K;i++)
                last[i]=0;
            for (int n=1;n<=N;n++)
            {
                for (int i=1;i<=K;i++)
                    if (find[last[i]]*S[i]<=find[n-1]) last[i]++;
                int min=oo;
                for (int i=1;i<=K;i++)
                    if (find[last[i]]*S[i]<min)
                       min=find[last[i]]*S[i];
                find[n]=min;
            }
            cout<<find[N]<<endl;
       }
       int run()
       {
           next();
           //cout<<clock()<<endl;
           return 0;
       }
};

#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
