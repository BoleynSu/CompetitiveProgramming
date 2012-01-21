/*
ID: sujiao1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("milk2.in");
std::ofstream cout("milk2.out");

const int MAXT=1000000;
int n;
bool t[MAXT+2];

int main()
{
    int maxt=0;
    int mint=MAXT;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int f,to;
        cin>>f>>to;
        if (f<mint) mint=f;
        if (to>maxt) maxt=to;
        for (int j=f+1;j<=to;j++)
            t[j]=true;
    }
    int a=0,b=0;
    int i=mint+1;
    while (i<=maxt)
    {
          int j;
          for (j=i;t[j]&&(j<=maxt);j++) ;
          //cout<<j-i<<" ";
          if (a<j-i) a=j-i;
          i=j;
          for (j=i;(!t[j])&&(j<=maxt);j++) ;
          //cout<<j-i<<" ";
          if (b<j-i) b=j-i;
          i=j;
    }
    cout<<a<<" "<<b<<endl;
    //while (1);
    return 0;
}
