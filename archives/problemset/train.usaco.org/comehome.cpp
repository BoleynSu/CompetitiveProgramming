/*
ID: sujiao1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("comehome.in");
std::ofstream cout("comehome.out");

struct Program
{
       static const char MAXCHAR='z';
       static char* const SET;
       static char* const SETOFCOW;
       static const int MAXLEN=1000;//1 to 1000
       static const int MAXP=10000;//1 to 10000
       static const int oo=MAXLEN*MAXP;
       int map[MAXCHAR+2][MAXCHAR+2];
       int dist[MAXCHAR+2];
       double answer;
       Program()
       {
                for (char* i=SET;*i!='\0';i++)
                    for (char* j=SET;*j!='\0';j++)
                        map[*i][*j]=oo*(*i!=*j);
                /*
                cout<<int('Z')<<" "<<int('z')<<endl;
                for (char* j=SET;*j!='\0';j++)
                    cout<<*j;
                cout<<endl;
                for (char* i=SET;*i!='\0';i++)
                {
                    cout<<*i;
                    for (char* j=SET;*j!='\0';j++)
                        cout<<map[*i][*j];
                    cout<<endl;
                }
                */
                int P;
                cin>>P;
                for (int i=1;i<=P;i++)
                {
                    char f,t;
                    int length;
                    cin>>f>>t>>length;
                    if (length<map[f][t]/*&&length<map[t][f]*/)
                       map[f][t]=map[t][f]=length;
                }                
       }
       int dijkstra(char to)
       {
           for (char* i=SET;*i!='\0';i++)
               dist[*i]=oo;           
           dist[to]=0;
           dist[0]=oo;
           
           bool visited[MAXCHAR+2];
           for (char* i=SET;*i!='\0';i++)
               visited[*i]=false;
           
           for (char* i=SET;*i!='\0';i++)
           {
               char close=0;
               for (char* j=SET;*j!='\0';j++)
                   if (!visited[*j])
                      if (dist[*j]<dist[close])
                         close=*j;
               
               if (dist[close]==oo) break;
               visited[close]=true;
               
               for (char* j=SET;*j!='\0';j++)
                   if (dist[*j]>dist[close]+map[close][*j])
                      dist[*j]=dist[close]+map[close][*j];
           }
           return 0;
       }
       int run()
       {
           dijkstra('Z');
           char answer=0;
           for (char* i=SETOFCOW;*i!='\0';i++)
               if (dist[answer]>dist[*i])
                  answer=*i;
           cout<<answer<<" "<<dist[answer]<<endl;
           //cout<<clock()<<endl;
           return 0;
       }
};
char* const Program::SET="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* const Program::SETOFCOW="ABCDEFGHIJKLMNOPQRSTUVWXY";

#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
