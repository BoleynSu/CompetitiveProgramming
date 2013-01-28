#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

enum{MAXN=1000+2};
const double INF=1e10,EPS=1e-6;
int a,b;
int Ax,Ay,Bx,By;
int n;
int X1[MAXN],Y1[MAXN],X2[MAXN],Y2[MAXN];
double dist[MAXN][MAXN];

double SQR(double x)
{
       return x*x;
}
double get_dist(int xi,int yi1,int yi2,int xj,int yj1,int yj2)
{
       if (max(yi1,yi2)<min(yj1,yj2)) return sqrt(SQR(max(yi1,yi2)-min(yj1,yj2))+SQR(xi-xj));
       else if (min(yi1,yi2)>max(yj1,yj2)) return sqrt(SQR(min(yi1,yi2)-max(yj1,yj2))+SQR(xi-xj));
       else return fabs(xi-xj);
}
double get_dist(int i,int j)
{
       if (X1[i]==X2[i])
          if (X1[j]==X2[j]) return get_dist(X1[i],Y1[i],Y2[i],X1[j],Y1[j],Y2[j]);
          else
          {
              if (min(X1[j],X2[j])>=X1[i]) return get_dist(X1[i],Y1[i],Y2[i],min(X1[j],X2[j]),Y1[j],Y2[j]);
              else if (max(X1[j],X2[j])<=X1[i]) return get_dist(X1[i],Y1[i],Y2[i],max(X1[j],X2[j]),Y1[j],Y2[j]);
              else return get_dist(j,i);
          }
       else
       {
           if (X1[j]==X2[j])
           {
              if (min(Y1[j],Y2[j])>=Y1[i]) return get_dist(Y1[i],X1[i],X2[i],min(Y1[j],Y2[j]),X1[j],X2[j]);
              else if (max(Y1[j],Y2[j])<=Y1[i]) return get_dist(Y1[i],X1[i],X2[i],max(Y1[j],Y2[j]),X1[j],X2[j]);
              else return get_dist(j,i);
           }
           else return get_dist(Y1[i],X1[i],X2[i],Y1[j],X1[j],X2[j]);
       }
}
double dijkstra(int s,int t)
{
       static double d[MAXN];
       for (int i=0;i<n;i++) d[i]=INF;
       d[s]=0;
       for (;;)
       {
             double mind=INF;
             int mindu=t;
             for (int u=0;u<n;u++)
                 if (d[u]>-EPS&&d[u]<mind)
                    mind=d[mindu=u];
             if (mindu==t) return mind;
             else
             {
                 for (int v=0;v<n;v++)
                     if (d[v]>d[mindu]+dist[mindu][v])
                        d[v]=d[mindu]+dist[mindu][v];
                 d[mindu]=-INF;
             }
       }
}

int main()
{
    cin>>a>>b>>Ax>>Ay>>Bx>>By>>n;
    for (int i=0;i<n;i++)
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
    int s,t;
    X1[n]=Ax,X2[n]=Ax,Y1[n]=Ay,Y2[n]=Ay,s=n++;
    X1[n]=Bx,X2[n]=Bx,Y1[n]=By,Y2[n]=By,t=n++;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            dist[i][j]=get_dist(i,j);
            if (dist[i][j]>a) dist[i][j]=INF;
            else if (j!=t) dist[i][j]=a+b;
        }
    double get=dijkstra(s,t);
    if (get>=INF) cout<<-1<<endl;
    else cout<<get<<endl;
    return 0;
}

