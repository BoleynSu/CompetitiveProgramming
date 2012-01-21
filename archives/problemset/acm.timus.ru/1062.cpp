//DATE:2010-4-1
#include <cstdio>
using std::printf;
using std::scanf;
#include <cstring>
using std::memcpy;

#define MAXN 100
#define KIND 3
#define oo 1e10
#define zero 1e-10

typedef int Player[MAXN][KIND];
struct Point{double x,y;};
struct Line{double a,b,c;};

int N;
Player player;
Line line[MAXN];
bool canWin[MAXN];

void read()
{
     scanf("%d",&N);
     for (int i=0;i<N;i++)
         for (int j=0;j<KIND;j++)
             scanf("%d",&player[i][j]);
}
void write()
{
     for (int i=0;i<N;i++)
         if (canWin[i]) printf("Yes\n");
         else printf("No\n");
}
void initLines()
{
     for (int i=0;i<N;i++)
         line[i].a=1.0/player[i][0],
         line[i].b=1.0/player[i][1],
         line[i].c=1.0/player[i][2];
}
Point intersect(Line l,Point a,Point b)
{
      Point get;
      double fa=l.a*a.x+l.b*a.y+l.c;
      double fb=l.a*b.x+l.b*b.y+l.c;
      get.x=(fb*a.x-fa*b.x)/(fb-fa);
      get.y=(fb*a.y-fa*b.y)/(fb-fa);
      return get;
}
void cut(Point* p,int& pn,Line cutter)
{
     Point q[MAXN+4];
     int qn=0;
     for (int i=0;i<pn;i++)
     {
         if (p[i].x*cutter.a+p[i].y*cutter.b+cutter.c>zero)
            q[qn++]=p[i];
         else
         {
             int before=(i-1+pn)%pn;
             int next=(i+1)%pn;
             if (p[before].x*cutter.a+p[before].y*cutter.b+cutter.c>zero)
                q[qn++]=intersect(cutter,p[before],p[i]);
             if (p[next].x*cutter.a+p[next].y*cutter.b+cutter.c>zero)
                q[qn++]=intersect(cutter,p[i],p[next]);
         }
     }
     memcpy(p,q,sizeof(q));
     pn=qn;
}
bool isEmpty(Line* l,int n)
{
     Point p[MAXN+4];
     int pn=0;
     p[pn].x=0;
     p[pn].y=0;
     pn++;
     p[pn].x=oo;
     p[pn].y=0;
     pn++;
     p[pn].x=oo;
     p[pn].y=oo;
     pn++;
     p[pn].x=0;
     p[pn].y=oo;
     pn++;
     for (int i=0;i<n;i++)
         cut(p,pn,l[i]);
     return pn<3;
     
}
bool can(int id)
{
     Line l[MAXN];
     memcpy(l,line,sizeof(line));
     for (int i=0;i<N;i++)
         if (i!=id)
            l[i].a-=l[id].a,
            l[i].b-=l[id].b,
            l[i].c-=l[id].c;
     l[id]=l[N-1];
     if (isEmpty(l,N-1)) return false;
     else return true;
}
void solve()
{
     initLines();
     for (int i=0;i<N;i++)
         canWin[i]=can(i);
}
int main()
{
    read();
    solve();
    write();
    return 0;
}
