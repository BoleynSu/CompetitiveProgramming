/*
ID: sujiao1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("holstein.in");
std::ofstream cout("holstein.out");
const int MAXV=25;
const int MAXG=15;
const int MAXVV=1000;
int V,G,P;
int v[MAXV+2];
int got[MAXV+2];
int g[MAXG+2][MAXV+2];
int p[MAXG+2];
bool use[MAXG+2];

void search(int step,int total)
{
     bool get=true;
     for (int i=1;i<=V;i++)
         if (got[i]<v[i]) get=false;
     //cout<<"search("<<step<<","<<total<<")\n";
     if (get)
     {
        if (total<P)
        {
           P=total;
           int _P=0;
           for (int i=1;i<=G;i++)
           {
               if (use[i]) p[++_P]=i;
           }
        }
        return;
     }
     
     if (step>G) return;
     
     for (int i=1;i<=V;i++)
         got[i]+=g[step][i];
     use[step]=true;
     search(step+1,total+1);
     use[step]=false;
     for (int i=1;i<=V;i++)
         got[i]-=g[step][i];
     search(step+1,total);
     
}

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    cin>>V;
    for (int i=1;i<=V;i++)
        cin>>v[i];
    cin>>G;
    for (int j=1;j<=G;j++)
        for (int i=1;i<=V;i++)
            cin>>g[j][i];
    P=MAXG;
    search(1,0);
    
    cout<<P;
    for (int i=1;i<=P;i++)
        cout<<" "<<p[i];
    cout<<endl;
    //cout<<clock()<<endl;
    return 0;
}
