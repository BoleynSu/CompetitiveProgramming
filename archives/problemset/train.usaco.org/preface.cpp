/*
ID: sujiao1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("preface.in");
std::ofstream cout("preface.out");

struct Program
{
       static const int MAXN=3500;//1 to 3500
       static const int MAXK=10;
       static const int MAXUSE=7;
       static const int MAXUSELIST=3;
       static const int uselist[MAXK][MAXUSELIST];
       static const char getName[MAXUSE];
       typedef int use[MAXUSE];
       int N;
       Program()
       {
                cin>>N;
       }
       void get(int n,use got)
       {
            for (int i=0;i<MAXUSE;i++)
                got[i]=0;
            int pos=0;
            for (int k=1;k<MAXN;k*=10)
            {
                int g=(n/k)%MAXK;
                for (int i=0;i<MAXUSELIST;i++)
                {
                    got[i+pos]+=uselist[g][i];
                }
                pos+=2;
            }
       }
       int run()
       {
           use answer;
           for (int i=0;i<MAXUSE;i++)
               answer[i]=0;
           for (int i=1;i<=N;i++)
           {
               use got;
               get(i,got);
               for (int i=0;i<MAXUSE;i++)
                   answer[i]+=got[i];
           }
           for (int i=0;i<MAXUSE;i++)
           {
               if (answer[i]!=0)
                  cout<<getName[i]<<" "<<answer[i]<<endl;
           }
           return 0;
       }
};
const int Program::uselist[MAXK][MAXUSELIST]=
{
      {0,0,0},//0
      {1,0,0},//1 i
      {2,0,0},//2 ii
      {3,0,0},//3 iii
      {1,1,0},//4 iv
      {0,1,0},//5 v
      {1,1,0},//6 vi
      {2,1,0},//7 vii
      {3,1,0},//8 viii
      {1,0,1},//9 ix
};
const char Program::getName[MAXUSE]=
{
      'I',//1
      'V',//5
      'X',//10
      'L',//50
      'C',//100
      'D',//500
      'M',//1000
}; 
//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
    //cout<<clock()<<endl;
}
