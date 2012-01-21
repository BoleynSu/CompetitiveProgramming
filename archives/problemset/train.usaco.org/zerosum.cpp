/*
ID: sujiao1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::endl;
using std::string;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("zerosum.in");
std::ofstream cout("zerosum.out");

struct Program
{
       static const int MAXN=9;//3 to 9
       int N;
       char opt[MAXN+2];
       Program()
       {
                cin>>N;
       }
       void dfs(int pos)
       {
            if (pos==N)
            {
               int value=0;
               int start=0;
               int end=0;
               int first=true;
               for (int i=1;i<=N;i++)
               {
                   while ((opt[i]==' ')&&(i<N)) i++;
                   start=end+1;
                   end=i;
                   //cout<<start<<" "<<end<<endl;
                   int get=0;
                   for (int i=start;i<=end;i++)
                       get=get*10+i;
                   if (first||opt[start-1]=='+')
                   {
                      value+=get;
                      first=false;
                   }
                   else if(opt[start-1]=='-')
                   {
                        value-=get;
                   }
                   //cout<<opt[start-1]<<get<<"v"<<value<<endl;
               }
               //cout<<value<<endl;
               //value=0;
               if (value==0)
               {
                  for (int i=1;i<N;i++)
                      cout<<i<<opt[i];
                  cout<<N<<endl;
               }
               return;
            }
            opt[pos]=' ';
            dfs(pos+1);
            opt[pos]='+';
            dfs(pos+1);
            opt[pos]='-';
            dfs(pos+1);
       }
       int run()
       {
           dfs(1);
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
