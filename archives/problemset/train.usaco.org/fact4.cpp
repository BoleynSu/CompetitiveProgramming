/*
ID: sujiao1
PROG: fact4
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
std::ifstream cin("fact4.in");
std::ofstream cout("fact4.out");

struct Program
{
       static const int MAXN=4220;//1 to 4220
       int N;
       Program()
       {
                cin>>N;
       }
       int run()
       {
           unsigned long long int answer=1;
           for (int i=1;i<=N;i++)
           {
               //cout<<answer<<endl;
               answer*=i;
               while (answer%10==0) answer/=10;
               answer%=1000000000000ll;
           }
           answer%=10;
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
