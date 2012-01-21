/*
ID: sujiao1
PROG: wissqu
LANG: C++
*/
/*
PROGRAM: wissqu
AUTHOR: Su Jiao
DATE: 2010-1-15
DESCRIPTION:
威斯康星州的春天来了，是该把小奶牛们赶到小牧场上并把大奶牛们赶到北纬 40 度的大牧
场上的时候了。 
农夫约翰的牧场上有五种奶牛（括号内的是缩写）：格恩西奶牛（A），泽西奶牛（B），赫
里福奶牛（C），黑安格斯奶牛（D），朗赫恩奶牛（E）。这些奶牛群放养在一片 16 英亩
的牧场上，每英亩上都有一小群奶牛，像下面这样排列成 4 x 4 的格子（用行和列标号）： 
  1 2 3 4
+-------
1|A B A C
2|D C D E
3|B E B C
4|C A D E
最初，牧场上的奶牛群总共有 3 群 A，3 群 B，4 群 C，3 群 D，3 群 E。今年的 D 种小
奶牛比去年多一群 ，C 种少一群，共有 3 群 A，3 群 B，3 群 C，4 群 D，3 群 E。 
农夫约翰对于他牧场上的奶牛群的布局非常小心。这是因为如果同一种类型的奶牛群靠得太
近，她们就乱来：她们聚集在栅栏边上抽烟，喝牛奶。如果她们在相同的格子上或者在临近
的 8 个格子上，就是靠得太近了。 
农夫约翰得用他的棕色旧福特皮卡把他的大奶牛群运出牧场，并把他的小奶牛群运进牧场，
皮卡一次只能运一群奶牛。他装上一群小奶牛，开车到小牧场的一个方格中，卸下这群小奶
牛，再装上这个格子上的那群大奶牛，开到北纬 40 度的大牧场卸下来。他重复这样的操作
 16 次，然后开车去杰克商店办理低脂酸奶的交易和家居装修。 
帮助农夫约翰。他必须选择正确的顺序来替换他的奶牛群，使得他从不把一群小奶牛放入当
前被同样类型奶牛占有的方格或者当前被同样类型奶牛占据的方格的临近方格。当然，一旦
大奶牛走了，小奶牛就被安置好（in place），他必须小心以后的情况，要根据新的排列把
奶牛群分开。 
非常重要的提示：农夫约翰从过去的经验知道，他必须先移动 D 种奶牛群。 
找出农夫约翰将他的小奶牛搬迁到她们的新牧场上的办法。输出 16 个连续的 奶牛群类型/
行/列 的信息，使得这样的安排能够符合安全经验。 
计算 4 x 4 牧场的最终排列总数和产生那些排列的方式的总数。 
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
      static const int N=4;
      char map[N+2][N+2];
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        for (int i=1;i<=N;i++)
                            for (int j=1;j<=N;j++)
                            {
                                cin>>map[i][j];
                                //cout<<map[j][i];
                                //if (j==N) cout<<endl;
                            }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int total;
      bool put[N+2][N+2];
      int counter['Z'+2];
      char record[N*N+2];
      int rx[N*N+2],ry[N*N+2];
      /*
                      int xs=i>1?i-1:i;
                      int ys=j>1?j-1:j;
                      int xe=i<N?i+1:i;
                      int ye=j<N?j+1:j;
                      for (int x=xs;x<=xe;x++)
                          for (int y=ys;y<=ye;y++)
                              if (x!=i||y!=j)
                              {
                                 near[i][j][map[x][y]]=true;
                                 //cout<<"near["<<i<<","<<j<<"]:"<<map[x][y]<<endl;
                              }
      */
      void dfs(int step)
      {
           if (step==0)
           {
              total=0;
              memset(put,false,sizeof(put));
              counter['A']=counter['B']=counter['C']=counter['E']=3;
              counter['D']=4;                  
           }
           
           if (++step>N*N)
           {
              if (!total)
              for (int i=1;i<=N*N;i++) cout<<record[i]<<" "<<rx[i]<<" "<<ry[i]<<endl;
              total++;
           } 
           else
           {
               /*
               for (int i=1;i<=N;i++)
                   for (int j=1;j<=N;j++)
                       if (!put[i][j])
                       {
                          if (step==1)
                          {
                             char p='D';
                             if (counter[p]>0)
                             {
                                bool near=false;
                                int xs=i>1?i-1:i;
                                int ys=j>1?j-1:j;
                                int xe=i<N?i+1:i;
                                int ye=j<N?j+1:j;
                                for (int x=xs;!near&&(x<=xe);x++)
                                    for (int y=ys;!near&&(y<=ye);y++)
                                        if (map[x][y]==p)
                                           near=true;
                                
                                if (!near)
                                {
                                   record[step]=p;
                                   rx[step]=i;
                                   ry[step]=j;
                                   char backup=map[i][j];
                                   put[i][j]=true;
                                   counter[p]--;
                                   map[i][j]=p;
                                   dfs(step);
                                   map[i][j]=backup;
                                   counter[p]++;
                                   put[i][j]=false;
                                }
                             }
                          }
                          else
                          {
                              for (char p='A';p<='E';p++)
                                  if (counter[p]>0)
                                  {
                                     bool near=false;
                                     int xs=i>1?i-1:i;
                                     int ys=j>1?j-1:j;
                                     int xe=i<N?i+1:i;
                                     int ye=j<N?j+1:j;
                                     for (int x=xs;!near&&(x<=xe);x++)
                                         for (int y=ys;!near&&(y<=ye);y++)
                                             if (map[x][y]==p)
                                                near=true;
                                     
                                     if (!near)
                                     {
                                        record[step]=p;
                                        rx[step]=i;
                                        ry[step]=j;
                                        char backup=map[i][j];
                                        put[i][j]=true;
                                        counter[p]--;
                                        map[i][j]=p;
                                        dfs(step);
                                        map[i][j]=backup;
                                        counter[p]++;
                                        put[i][j]=false;
                                     }
                                  }
                          }
                       }
               */
                          if (step==1)
                          {
                             char p='D';
                             if (counter[p]>0)
                             {
               for (int i=1;i<=N;i++)
                   for (int j=1;j<=N;j++)
                       if (!put[i][j])
                       {
                                bool near=false;
                                int xs=i>1?i-1:i;
                                int ys=j>1?j-1:j;
                                int xe=i<N?i+1:i;
                                int ye=j<N?j+1:j;
                                for (int x=xs;!near&&(x<=xe);x++)
                                    for (int y=ys;!near&&(y<=ye);y++)
                                        if (map[x][y]==p)
                                           near=true;
                                
                                if (!near)
                                {
                                   record[step]=p;
                                   rx[step]=i;
                                   ry[step]=j;
                                   char backup=map[i][j];
                                   put[i][j]=true;
                                   counter[p]--;
                                   map[i][j]=p;
                                   dfs(step);
                                   map[i][j]=backup;
                                   counter[p]++;
                                   put[i][j]=false;
                                }
                       }
                             }
                          }
                          else
                          {
                              for (char p='A';p<='E';p++)
                                  if (counter[p]>0)
                                  {
               for (int i=1;i<=N;i++)
                   for (int j=1;j<=N;j++)
                       if (!put[i][j])
                       {
                                     bool near=false;
                                     int xs=i>1?i-1:i;
                                     int ys=j>1?j-1:j;
                                     int xe=i<N?i+1:i;
                                     int ye=j<N?j+1:j;
                                     for (int x=xs;!near&&(x<=xe);x++)
                                         for (int y=ys;!near&&(y<=ye);y++)
                                             if (map[x][y]==p)
                                                near=true;
                                     
                                     if (!near)
                                     {
                                        record[step]=p;
                                        rx[step]=i;
                                        ry[step]=j;
                                        char backup=map[i][j];
                                        put[i][j]=true;
                                        counter[p]--;
                                        map[i][j]=p;
                                        dfs(step);
                                        map[i][j]=backup;
                                        counter[p]++;
                                        put[i][j]=false;
                                     }
                       }
                                  }
                          }
           }
      }
      int run()
      {
          dfs(0);
          cout<<total<<endl;
          return 0;
      }
};

int main()
{
    Application app("wissqu.in","wissqu.out");
    return app.run();
}
