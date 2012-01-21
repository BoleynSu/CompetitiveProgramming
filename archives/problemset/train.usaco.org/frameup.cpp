/*
ID: sujiao1
PROG: frameup
LANG: C++
*/
/*
PROGRAM: frameup
AUTHOR: Su Jiao
DATE: 2010-1-12
DESCRIPTION:
看下面的五张 9 x 8 的图像： 
........   ........   ........   ........   .CCC....
EEEEEE..   ........   ........   ..BBBB..   .C.C....
E....E..   DDDDDD..   ........   ..B..B..   .C.C....
E....E..   D....D..   ........   ..B..B..   .CCC....
E....E..   D....D..   ....AAAA   ..B..B..   ........
E....E..   D....D..   ....A..A   ..BBBB..   ........
E....E..   DDDDDD..   ....A..A   ........   ........
E....E..   ........   ....AAAA   ........   ........
EEEEEE..   ........   ........   ........   ........
   1          2           3          4          5
现在，把这些图像按照 1—5 的编号从下到上重叠，第 1 张在最下面，第 5 张在最顶端。
如果一张图像覆盖了另外一张图像，那么底下的图像的一部分就变得不可见了。我们得到下
面的图像： 
            .CCC....
           ECBCBB..
           DCBCDB..
           DCCC.B..
           D.B.ABAA
           D.BBBB.A
           DDDDAD.A
           E...AAAA
           EEEEEE..
对于这样一张图像，计算构成这张图像的矩形图像从底部到顶端堆叠的顺序。 
下面是这道题目的规则： 
矩形的边的宽度为 1 ，每条边的长度都不小于 3 。 
矩形的每条边中，至少有一部分是可见的。注意，一个角同时属于两条边。 
矩形用大写字母表示，并且每个矩形的表示符号都不相同。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <string>
using std::string;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int SET='z'+2;
      static char* const SETLIST;
      static const int MAXH=30;
      static const int MAXW=30;
      struct Box
      {
             int x1,x2,y1,y2;
             Box():x1(Application::MAXH),x2(0),y1(Application::MAXW),y2(0)
             {
             }
             void update(int x,int y)
             {
                  if (x2<x) x2=x;
                  if (x1>x) x1=x;
                  if (y2<y) y2=y;
                  if (y1>y) y1=y;
             }
      };
      int H,W;
      char pic[MAXH+2][MAXW+2];
      bool appear[SET];
      Box box[SET];
      char appearSet[SET];
      int  appearSet_len;
      bool cover[SET][SET];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>H>>W;
                              memset(appear,false,sizeof(appear));
                              appearSet_len=0;
                              for (int i=1;i<=H;i++)
                                  for (int j=1;j<=W;j++)
                                  {
                                      cin>>pic[i][j];
                                      if (pic[i][j]!='.')
                                      {
                                         if (!appear[pic[i][j]])
                                            appearSet[++appearSet_len]=pic[i][j];
                                         appear[pic[i][j]]=true;
                                      }
                                      box[pic[i][j]].update(i,j);
                                  }
                              /*
                              for (int i=1;i<=H;i++)
                              {
                                  for (int j=1;j<=W;j++)
                                      cout<<pic[i][j];
                                  cout<<endl;
                              }
                              for (char* i=SETLIST;*i;i++)
                              {
                                  if (appear[*i])
                                     cout<<*i<<":"<<box[*i].x1<<","<<box[*i].y1<<" "
                                                  <<box[*i].x2<<","<<box[*i].y2<<endl;
                                  //cout<<*i<<":"<<appear[*i]<<endl;
                              }
                              for (int i=1;i<=appearSet_len;i++)
                                  cout<<appearSet[i]<<endl;
                              */
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      bool on(char a,char b)//a is on b ?
      {
           for (int i=box[b].x1;i<=box[b].x2;i++)
               if ((pic[i][box[b].y1]==a)||(pic[i][box[b].y2]==a)) return true;
           for (int i=box[b].y1;i<=box[b].y2;i++)
               if ((pic[box[b].x1][i]==a)||(pic[box[b].x2][i]==a)) return true;
           return false;
      }
      void initCover()
      {
           for (int i=1;i<=appearSet_len;i++)
               for (int j=i+1;j<=appearSet_len;j++)
                   if (appearSet[i]>appearSet[j])
                   {
                      char swap=appearSet[i];
                      appearSet[i]=appearSet[j];
                      appearSet[j]=swap;
                   }
           for (int i=1;i<=appearSet_len;i++)
               for (int j=1;j<=appearSet_len;j++)
                   cover[i][j]=(i!=j)&&on(appearSet[i],appearSet[j]);
           
           for (int k=1;k<=appearSet_len;k++)
               for (int i=1;i<=appearSet_len;i++)
                   for (int j=1;j<=appearSet_len;j++)
                       cover[i][j]=cover[i][j]||(cover[i][k]&&cover[k][j]);  
           /*
           for (int i=1;i<=appearSet_len;i++)
               for (int j=1;j<=appearSet_len;j++)
                   cout<<appearSet[i]<<appearSet[j]<<":"<<cover[i][j]<<endl;
           */
      }
      void dfs(int step)
      {
           static bool printed[SET];
           static char printList[SET];
           
           if (step==appearSet_len)
                cout<<printList<<endl;
           else
           {
               for (int j=1;j<=appearSet_len;j++)
                   if (!printed[j])
                   {
                      int degree=0;
                      for (int k=1;k<=appearSet_len;k++)
                          if ((!printed[k])&&(cover[j][k]))
                             degree++;
                      if (!degree)
                      {
                         printList[step]=appearSet[j];
                         printed[j]=true;
                         dfs(step+1);
                         printed[j]=false;
                      }
                   }
           }
      }
      void topologicalSort()
      {
           dfs(0);
      }
      int run()
      {
          initCover();
          topologicalSort();
          return 0;
      }
};
char* const Application::SETLIST="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    Application app("frameup.in","frameup.out");
    return app.run();
}
