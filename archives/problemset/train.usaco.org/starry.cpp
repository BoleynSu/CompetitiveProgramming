/*
ID: sujiao1
PROG: starry
LANG: C++
*/
/*
PROGRAM: starry
AUTHOR: Su Jiao
DATE: 2010-1-14
DESCRIPTION:
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXW=100;
      static const int MAXH=100;
      static const int MAXCLUSTER=500;
      struct Sky
      {
             int h,w;
             char m[MAXH+2][MAXW+2];
      };
      struct Cluster
      {
             bool outputed;
             int h,w;
             bool m[MAXH+2][MAXW+2];
             int p_h,p_w;
             bool pressed[MAXH+2][MAXW+2];
             Cluster()
             :h(0),w(0),outputed(false)
             {
                      memset(m,false,sizeof(m));
             }
             void update(int x,int y)
             {
                  if (x>h) h=x;
                  if (y>w) w=y;
                  m[x][y]=true;
             }
             void press()
             {
                  int xs,ys;
                  for (xs=1;xs<=h;xs++)
                  {
                      int counter=0;
                      for (int y=1;y<=w;y++)
                          if (m[xs][y]) counter++;
                      if (counter) break;
                  }
                  for (ys=1;ys<=w;ys++)
                  {
                      int counter=0;
                      for (int x=1;x<=h;x++)
                          if (m[x][ys]) counter++;
                      if (counter) break;
                  }
                  for (int i=xs;i<=h;i++)
                      for (int j=ys;j<=w;j++)
                          pressed[i-xs+1][j-ys+1]=m[i][j];
                  p_h=h-xs+1;
                  p_w=w-ys+1;
             }
             void print(char mark,Sky& sky)
             {
                  outputed=true;
                  for (int i=1;i<=h;i++)
                      for (int j=1;j<=w;j++)
                          if (m[i][j])
                             sky.m[i][j]=mark;
             }
             bool similar(Cluster& other)
             {
                  bool is;
                  if ((other.p_h==p_h)&&(other.p_w==p_w))
                  {
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[x][y])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[p_h+1-x][y])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[x][p_w+1-y])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[p_h+1-x][p_w+1-y])
                                is=false;
                     if (is) return true;
                  }
                  if ((other.p_h==p_w)&&(other.p_w==p_h))
                  {
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[y][x])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[y][p_h+1-x])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[p_w+1-y][x])
                                is=false;
                     if (is) return true;
                     
                     is=true;
                     for (int x=1;(x<=p_h)&&is;x++)
                         for (int y=1;(y<=p_w)&&is;y++)
                             if (pressed[x][y]!=other.pressed[p_w+1-y][p_h+1-x])
                                is=false;
                     if (is) return true;
                  }
                  return false;
             }
      };
      Sky sky;
      Cluster cluster[MAXCLUSTER+2];
      int cluster_len;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>sky.w>>sky.h;
                              for (int i=1;i<=sky.h;i++)
                                  for (int j=1;j<=sky.w;j++)
                                      cin>>sky.m[i][j];
                              /*
                              for (int i=1;i<=sky.h;i++)
                              {
                                  for (int j=1;j<=sky.w;j++)
                                      cout<<sky.m[i][j];
                                  cout<<endl;
                              }
                              */
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void dfs(Sky& s,int x,int y,int id)
      {
           if (x<1||y<1||x>s.h||y>s.w||s.m[x][y]!='1') ;//do nothing
           else
           {
               //cout<<id<<"update("<<x<<","<<y<<")"<<endl;
               s.m[x][y]=false;
               cluster[id].update(x,y);
               dfs(s,x+1,y-1,id);
               dfs(s,x-1,y+1,id);
               dfs(s,x+1,y+1,id);
               dfs(s,x-1,y-1,id);
               dfs(s,x+1,y,id);
               dfs(s,x-1,y,id);
               dfs(s,x,y+1,id);
               dfs(s,x,y-1,id);
           }
      }
      void floodfill()
      {
           Sky backup=sky;
           cluster_len=0;
           for (int i=1;i<=backup.h;i++)
               for (int j=1;j<=backup.w;j++)
                   if (backup.m[i][j]=='1')
                   {
                      dfs(backup,i,j,++cluster_len);
                      cluster[cluster_len].press();
                   }
      }
      int run()
      {
          floodfill();
          /*
          for (int id=1;id<=cluster_len;id++)
          {
              cout<<"cluster"<<id<<":"<<endl;
              for (int i=1;i<=cluster[id].h;i++)
              {
                  for (int j=1;j<=cluster[id].w;j++)
                      cout<<cluster[id].m[i][j];
                  cout<<endl;
              }
              for (int i=1;i<=cluster[id].p_h;i++)
              {
                  for (int j=1;j<=cluster[id].p_w;j++)
                      cout<<cluster[id].pressed[i][j];
                  cout<<endl;
              }
          }
          */
          char output='a';
          for (int i=1;i<=cluster_len;i++)
          {
              if (!cluster[i].outputed)
              {
                 cluster[i].print(output,sky);
                 for (int j=i+1;j<=cluster_len;j++)
                     if (cluster[i].similar(cluster[j]))
                        cluster[j].print(output,sky);
                 output++;
              }
          }
                              
          for (int i=1;i<=sky.h;i++)
          {
              for (int j=1;j<=sky.w;j++)
                  cout<<sky.m[i][j];
              cout<<endl;
          }
                              
          return 0;
      }
};

int main()
{
    static
    Application app("starry.in","starry.out");
    return app.run();
}
