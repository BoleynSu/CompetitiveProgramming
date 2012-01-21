/*
ID: sujiao1
PROG: prefix
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
std::ifstream cin("prefix.in");
std::ofstream cout("prefix.out");

struct Program
{
       static const int __EOF__=-1; 
       static const int MAXELEMENT=200;//1 to 200
       static const int MAXLEN=200000;//1 to 200000
       string set[MAXELEMENT+2];
       int setlen;
       bool can[MAXLEN+2];
       char todo[MAXLEN+2];
       int todolen;
       int answer;
       Program():answer(0)
       {
                setlen=0;
                do
                {
                  setlen++;
                  cin>>set[setlen];
                }
                while (set[setlen]!=string("."));
                setlen--;
                /*
                for (int i=1;i<=setlen;i++)
                    cout<<set[i]<<endl;
                */
                todolen=0;
                char got;
                while ((got=cin.get())!=__EOF__)
                {
                      if (got!='\n') todo[todolen++]=got;
                }
                todo[todolen]='\0';
                //cout<<todo<<endl;
                for (int i=0;i<todolen;i++)
                    can[i]=false;
       }
       void dfs(int pos)
       {
            if (can[pos]||pos>todolen) return;
            can[pos]=true;
            if (pos>answer) answer=pos;
            for (int i=1;i<=setlen;i++)
            {
                bool same=true;
                for (int j=0;j<set[i].length();j++)
                    if (todo[pos+j]!=set[i][j])
                       same=false;
                if (same)
                   dfs(pos+set[i].length());
            }
       }
       int run()
       {
           dfs(0);
           /*
           for (int i=0;i<todolen;i++)
               cout<<todo[i]<<can[i];
           */
           cout<<answer<<endl;
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
    //cout<<clock()<<endl;
}
