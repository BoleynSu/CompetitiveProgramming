/*
Author: Su Jiao
Author's website: boleynsu.tk
Date: 2011-09-14
Description:

*/
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

#define Point pair<int,int>
#define x first
#define y second

const int oo=0x7f7f7f7f;
const int MAXW=110,MAXH=110;
const int MAXM=MAXW*MAXH*4;
const int DIRS=4;
const int U=0,D=1,L=2,R=3;
const int dx[DIRS]={0,0,-1,+1};
const int dy[DIRS]={+1,-1,0,0};
int T,W,H;
char path[MAXW*MAXH];
int M;
Point A[MAXM],B[MAXM];
int beginx,beginy;
int endx,endy;
bool on_the_path[MAXW][MAXH];
int path_length;
int connect[MAXW][MAXH];
int begin_distance[MAXW][MAXH];
int end_distance[MAXW][MAXH];
int qhead;
int qtail;
int qx[MAXW*MAXH];
int qy[MAXW*MAXH];
bool inq[MAXW][MAXH];

void go()
{
     memset(on_the_path,0,sizeof(on_the_path));
     beginx=endx=0;
     beginy=endy=0;
     path_length=0;
     char* now=path;
     on_the_path[beginx][beginy]=true;
     while (*now)
     {
           switch (*now)
           {
                  case 'U':
                       endy++;
                       break;
                  case 'R':
                       endx++;
                       break;
                  case 'D':
                       endy--;
                       break;
                  case 'L':
                       endx--;
                       break;
           }
           on_the_path[endx][endy]=true;
           now++;
           path_length++;
     }
}
void build_wall()
{
     memset(connect,0,sizeof(connect));
     for (int m=0;m<M;m++)
     {
         int x1=A[m].x,y1=A[m].y;
         int x2=B[m].x,y2=B[m].y;
         if (x1==x2)
         {
            if (y1+1==y2)
            {
               connect[x1][y1]|=1<<U;
               connect[x2][y2]|=1<<D;
            }
            else if (y2+1==y1)
            {
               connect[x1][y1]|=1<<D;
               connect[x2][y2]|=1<<U;
            }
         }
         else if (y1==y2)
         {
              if (x1+1==x2)
              {
                 connect[x1][y1]|=1<<R;
                 connect[x2][y2]|=1<<L;
              }
              else if (x2+1==x1)
              {
                 connect[x1][y1]|=1<<L;
                 connect[x2][y2]|=1<<R;
              }
         }
     }
}
void bfs(int distance[MAXW][MAXH],int x,int y)
{
     memset(inq,0,sizeof(inq));
     memset(distance,oo,sizeof(int)*MAXW*MAXH);
     distance[x][y]=0;
     inq[x][y]=true;
     qhead=qtail=0;
     qx[qtail]=x;
     qy[qtail]=y;
     while (qhead<=qtail)
     {
           int nowx=qx[qhead];
           int nowy=qy[qhead];
           for (int i=0;i<DIRS;i++)
           {
               if (!(connect[nowx][nowy]&(1<<i)))
               {
                  int nextx=nowx+dx[i];
                  int nexty=nowy+dy[i];
                  if (nextx>=0&&nextx<W&&nexty>=0&&nexty<H&&!inq[nextx][nexty])
                  {
                     distance[nextx][nexty]=distance[nowx][nowy]+1;
                     inq[nextx][nexty]=true;
                     qtail++;
                     qx[qtail]=nextx;
                     qy[qtail]=nexty;
                  }
               }
           }
           qhead++;
     }
}

int main()
{
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%d%d%s",&W,&H,path);
        go();
        scanf("%d",&M);
        for (int m=0;m<M;m++)
            scanf("%d%d%d%d",&A[m].x,&A[m].y,&B[m].x,&B[m].y);
        build_wall();
        bfs(begin_distance,beginx,beginy);
        bfs(end_distance,endx,endy);
        bool correct=true;
        for (int x=0;x<W;x++)
            for (int y=0;y<H;y++)
                if ((!on_the_path[x][y])&&(begin_distance[x][y]+end_distance[x][y]<=path_length))
                   correct=false;
        for (int m=0;m<M;m++)
        {
            if ((begin_distance[A[m].x][A[m].y]+end_distance[B[m].x][B[m].y]+1>path_length)
                &&(begin_distance[B[m].x][B[m].y]+end_distance[A[m].x][A[m].y]+1>path_length))
               correct=false;
        }
        printf("%s\n",correct?"CORRECT":"INCORRECT");
    }
    return 0;
}
