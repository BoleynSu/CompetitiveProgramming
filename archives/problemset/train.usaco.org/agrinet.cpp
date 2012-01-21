/*
ID: sujiao1
PROG: agrinet
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
std::ifstream cin("agrinet.in");
std::ofstream cout("agrinet.out");

struct Program
{
       static const int MAXN=100;//3 to 100
       static const int MAXLEN=100000;//1 to 100000
       static const int oo=MAXN*MAXLEN;
       int N;
       int map[MAXN+2][MAXN+2];
       int answer;
       Program():answer(0)
       {
                cin>>N;
                for (int i=1;i<=N;i++)
                    for (int j=1;j<=N;j++)
                        cin>>map[i][j];
                /*
                for (int i=1;i<=N;i++)
                {
                    for (int j=1;j<=N;j++)
                        cout<<map[i][j]<<" ";
                    cout<<endl;
                }
                */
       }
       int prim()
       {
           int first=1;
           int low[MAXN+2];
           for (int i=1;i<=N;i++)
               low[i]=map[first][i];
           low[0]=oo;
           for (int k=2;k<=N;k++)
           {
               int min=0;
               for (int i=1;i<=N;i++)
                   if (low[i]!=0)
                      if (low[i]<low[min])
                         min=i;
               answer+=low[min];
               low[min]=0;
               for (int i=1;i<=N;i++)
                   if (low[i]!=0)
                      if (low[min]+map[min][i]<low[i])
                         low[i]=low[min]+map[min][i];
           }
       }
       int run()
       {
           prim();
           cout<<answer<<endl;
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
