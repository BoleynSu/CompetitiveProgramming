/*
ID: sujiao1
PROG: fracdec
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
std::ifstream cin("fracdec.in");
std::ofstream cout("fracdec.out");

struct Program
{
       static const int MAXN=100000;//1 to 100000
       static const int MAXLEN=1024*256;
       int N,D;
       int c;
       int out[MAXLEN];
       char outstring[MAXLEN];
       int* mark;//[MAXN*10+2];
       bool breakpoint;
       int breakpoint_s,breakpoint_e;
       struct Sout
       {
              static const int MAXLINE=76;
              string output;
              Sout& operator <<(int a)
              {
                    int k;
                    for (k=1;k*10<=a;k*=10) ;//do nothing
                    for (;k>=1;k/=10)
                    {
                        output.push_back('0'+(a/k)%10);
                    }
                    return *this;
              }
              Sout& operator <<(char a)
              {
                    output.push_back(a);
                    return *this;
              }
              Sout& print()
              {
                    int i,j;
                    for (i=0;;i++)
                    {
                        for (j=0;j<MAXLINE;j++)
                        {
                            if (i*MAXLINE+j==output.length()) break;
                            cout<<output[i*MAXLINE+j];
                        }
                        cout<<endl;
                        if (i*MAXLINE+j==output.length()) break;
                    }
                    return *this;
              }
       };
       Sout sout;
       Program():c(0)
       {
                cin>>N>>D;
                //cout<<N<<"/"<<D<<endl;
                mark=new int[MAXN*10+2];
                for (int i=0;i<=MAXN;i++) mark[i]=0;
                //freopen("fracdec.err","w",stderr);
       }
       ~Program()
       {
                 delete[] mark;
       }
       void print()
       {
            if (c>=MAXLEN) return;
            cout<<c<<":"<<N<<"/"<<D<<endl;
            if (N==0)
            {
               breakpoint=false;
               breakpoint_e=c;
               return;
            }
            //cout<<c<<":"<<N<<"/"<<D<<endl;
            //cout<<N<<"assert\n";
            //assert(N<MAXN);
            if (mark[N%D]!=0)
            {
               breakpoint=true;
               breakpoint_s=mark[N];
               breakpoint_e=c;
               return;
            }
            mark[N%D]=c;
            out[c]=N/D;
            N=(N%D)*10;
            c++;
            print();
       }
       int run()
       {
           //print();
           for (;;)
           {
               if (c>=MAXLEN) break;
               //cout<<c<<":"<<N<<"/"<<D<<endl;
               if (N==0)
               {
                  breakpoint=false;
                  breakpoint_e=c;
                  break;
               }
               //cout<<c<<":"<<N<<"/"<<D<<endl;
               //cout<<N<<"assert\n";
               //assert(N<MAXN);
               if (mark[N]!=0)
               {
                  breakpoint=true;
                  breakpoint_s=mark[N];
                  breakpoint_e=c;
                  break;
               }
               mark[N]=c;
               out[c]=N/D;
               N=(N%D)*10;
               c++;
           }
           sout<<out[0]<<'.';
           if (breakpoint)
           {
              for (int i=1;i<breakpoint_s;i++) sout<<out[i];
              sout<<'(';
              for (int i=breakpoint_s;i<breakpoint_e;i++) sout<<out[i];
              sout<<')';
           }
           else
           {
              if (breakpoint_e==1) sout<<0;
              else for (int i=1;i<breakpoint_e;i++) sout<<out[i];
           }
           sout.print();
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
