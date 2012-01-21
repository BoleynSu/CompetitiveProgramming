/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-8
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>

#include <cmath>
using std::sqrt;
#include <cstring>
using std::memset;

#define oo 1e10
#define MAXN 50
#define MAXM 1000

typedef long long int Type;
struct Point{Type x,y;};

int N,M;
Point outter[MAXN];
Point inner[MAXM];
double answer;

void read()
{
     cin>>N>>M;
     for (int i=0;i<N;i++)
         cin>>outter[i].x>>outter[i].y;
     for (int i=0;i<M;i++)
         cin>>inner[i].x>>inner[i].y;
}
void write()
{
     cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
     cout<<answer<<endl;
}

Type cross(const Point& a,const Point& b,const Point& c)
{
     Type abx=b.x-a.x,
          aby=b.y-a.y,
          acx=c.x-a.x,
          acy=c.y-a.y;
     return abx*acy-aby*acx;
}
bool sameside(const Point& a,const Point& b,const Point& c,const Point& d)
{
     return cross(a,b,c)*cross(a,b,d)>=0;
}
bool inside(const Point& a,const Point& b,const Point& c,const Point& d)
{
     return sameside(a,b,c,d)&&sameside(a,c,b,d)&&sameside(b,c,a,d);
}
double distance(const Point& a,const Point& b)
{
       return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
void solve()
{
     bool can[MAXN][MAXN];
     memset(can,0,sizeof(can));
     for (int i=0;i<N;i++)
     {
         bool flag=true;
         for (int j=i+1;j<N+i;j++)
         {
             if (cross(outter[i],outter[j%N],outter[(j-1)%N])!=0)
                for (int k=0;k<M;k++)
                    if (inside(outter[i],outter[j%N],outter[(j-1)%N],inner[k]))
                    {
                       flag=false;
                       break;
                    }
             if (flag) can[i][j%N]=true;
         }
     }
     
     double map[MAXN][MAXN];
     for (int i=0;i<N;i++)
         for (int j=0;j<N;j++)
             if (can[i][j]) map[i][j]=distance(outter[i],outter[j]);
             else map[i][j]=oo;
     for (int k=0;k<N;k++)
         for (int i=0;i<N;i++)
             for (int j=0;j<N;j++)
                 if (map[i][k]+map[k][j]<map[i][j])
                    map[i][j]=map[i][k]+map[k][j];
     
     answer=oo;
     for (int i=0;i<N;i++)
         for (int j=i+1;j<N;j++)
             for (int k=j+1;k<N;k++)
                 if (cross(outter[i],outter[j],outter[k])!=0)
                    if (map[i][j]+map[j][k]+map[k][i]<answer)
                       answer=map[i][j]+map[j][k]+map[k][i];
}


int main()
{
    read();
    solve();
    write();
    return 0;
}
