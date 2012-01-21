/*
ID: sujiao1
PROG: transform
LANG: C++
*/

//#include <iostream>
//using namespace std;

#include <string>
using std::string;

#include <fstream>
using std::endl;
std::ifstream cin("transform.in");
std::ofstream cout("transform.out");

int n;
char map[12][12];
char to[12][12];

char dt[12][12];
void d()
{/*
4
1000
1000
0000
1000
0000
0000
0000
1011

*/
     char tmp[12][12];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int x,y;
            if (n%2==1)
            {
            x=i-n/2-1;
            y=j-n/2-1;
            tmp[y+1+n/2][-x+1+n/2]=dt[i][j];
            }
            else
            {
            
            x=i-((n+1)/2);
            y=j-((n+1)/2);
            tmp[/*y+((n+1)/2)*/j][n+1-i/*-x+((n+1)/2)*/]=dt[i][j];
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dt[i][j]=tmp[i][j];
}

void f()
{
     for (int i=1;i<=n;i++)
         for (int j=1;j<=((n+1)/2);j++)
         {
             int swap=dt[i][j];
             dt[i][j]=dt[i][n+1-j];
             dt[i][n+1-j]=swap;
         }
}

bool same()
{
     
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (dt[i][j]!=to[i][j]) return false;
    return true;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>map[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>to[i][j];
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dt[i][j]=map[i][j];
    for (int i=1;i<4;i++)
    {
        d();
        if (same()) {cout<<i<<endl;exit(0);}
    }
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dt[i][j]=map[i][j];
    f();
    if (same()){cout<<4<<endl;exit(0);}
    
    for (int i=1;i<4;i++)
    {
        d();
        if (same()) {cout<<5<<endl;exit(0);}
    }
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dt[i][j]=map[i][j];   
    if (same()) {cout<<6<<endl;exit(0);}
    cout<<7<<endl;
    return 0;
}
