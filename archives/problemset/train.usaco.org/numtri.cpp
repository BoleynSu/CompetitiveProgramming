/*
ID: sujiao1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("numtri.in");
std::ofstream cout("numtri.out");

struct Program
{
       static const int MAXR=1000;//1 to 1000
       int r;
       int map[MAXR+2][MAXR+2];
       int f[MAXR+2][MAXR+2];
       Program()
       {
                cin>>r;
                for (int i=1;i<=r;i++)
                    for (int j=1;j<=i;j++)
                        cin>>map[i][j];
       }
       inline
       int max(int a,int b)
       {
           return a>b?a:b;
       }
       int run()
       {
           for (int i=1;i<=r+1;i++)
               f[r+1][i]=0;
           for (int k=r;k>=1;k--)
               for (int i=1;i<=k;i++)
                   f[k][i]=map[k][i]+max(f[k+1][i],f[k+1][i+1]);
           cout<<f[1][1]<<endl;
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
