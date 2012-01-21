/*
ID: sujiao1
PROG: beads
LANG: C++
*/
#include <string>
using std::string;
/*
#include <iostream>
using namespace std;
*/
#include <fstream>
using std::endl;
std::ifstream cin("beads.in");
std::ofstream cout("beads.out");


struct Program 
{
       int n;
       string str;
       int answer;
       inline
       int f(int i)
       {
           return (i+n)%n;
       }
       bool can(char get,char compare)
       {
            //cout<<"can("<<get<<","<<compare<<")="<<((get=='w')||(get==compare));
            return (get=='w')||(get==compare);
       }
       int run()
       {
           cin>>n;
           cin>>str;
           answer=0;
           for (int i=0;i<n;i++)
           {
               //cout<<i<<"th:";
               int j,k,c=0;
               
               if (str[f(i)]=='w')
               {
                  bool find=false;
                  for (j=0;j<n;j++)
                  {
                      if (str[f(i+j)]!='w')
                      {
                         if (find) break;
                         find=true;
                      }
                      c++;
                  }
               }
               else
                   for (j=0;j<n;j++)
                   {
                       if (can(str[f(i+j)],str[f(i)])) c++;
                       else break;
                       //cout<<f(i+j)<<":"<<str[f(i+j)]/*<<":"<<c*/<<" ";
                   }
               
               if (str[f(i-1)]=='w')
               {
                  bool find=false;
                  for (k=0;k<n;k++)
                  {
                      if (str[f(i-1-k)]!='w')
                      {
                         if (find) break;
                         find=true;
                      }
                      c++;
                  }
               }
               else
                   for (k=0;k<n;k++)
                   {
                       if (can(str[f(i-1-k)],str[f(i-1)])) c++;
                       else break;
                       //cout<<f(i-1-k)<<":"<<str[f(i-1-k)]/*<<":"<<c*/<<" ";
                   }
               
               //cout<<endl<<c<<"j"<<j<<"k"<<k<<endl;
               if (c>n) c=n;
               if (c>answer) answer=c;
           }
           cout<<answer<<endl;
           //while (cin.get()!='q');
           return 0;
       }
};

int main()
{
    Program app;
    return app.run();
}
