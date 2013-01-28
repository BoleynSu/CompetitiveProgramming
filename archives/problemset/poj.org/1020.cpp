#include <iostream>
#include <cstring>
using namespace std;

int s;
int c[10+2];

bool table[40+2][40+2];
bool cleared[40+2];
bool dfs()
{
     //static int depth;
     //static int opt[1024];
     //for (int i=0;i<depth;i++) cout<<opt[i]<<" ";cout<<endl;
     for (int x=1;x<=s;x++)
         if (!cleared[x])
         {
            for (int y=1;y<=s;y++)
                if (!table[x][y])
                {
                   for (int i=10;i>=1;i--)
                       if (c[i])
                       {
                          bool empty=true;
                          for (int tx=x;tx<x+i&&empty;tx++)
                              for (int ty=y;ty<y+i&&empty;ty++)
                                  empty=!table[tx][ty];
                          if (empty)
                          {
                             c[i]--;
                             for (int tx=x;tx<x+i;tx++)
                                 for (int ty=y;ty<y+i;ty++)
                                     table[tx][ty]=true;
                             for (int tx=x;tx<x+i;tx++)
                             {
                                 cleared[tx]=true;
                                 for (int ty=1;ty<=s;ty++)
                                     cleared[tx]=cleared[tx]&&table[tx][ty];
                             }
                             //opt[depth++]=i;
                             if (dfs()) return true;
                             //depth--;
                             for (int tx=x;tx<x+i;tx++)
                                 cleared[tx]=false;
                             for (int tx=x;tx<x+i;tx++)
                                 for (int ty=y;ty<y+i;ty++)
                                     table[tx][ty]=false;
                             c[i]++;
                          }
                       }
                   break;
                }
            break;
         }
     for (int i=1;i<=10;i++)
         if (c[i]) return false;
     return true;
}
bool possible()
{
     int sum=0;
     for (int i=1;i<=10;i++)
         sum+=i*i*c[i];
     if (sum!=s*s) return false;
     memset(table,true,sizeof(table));
     memset(cleared,false,sizeof(cleared));
     for (int i=1;i<=s;i++)
         for (int j=1;j<=s;j++)
             table[i][j]=0;
     return dfs();
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        int n,m;
        cin>>s>>n;
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            cin>>m;
            c[m]++;
        }
        if (possible()) cout<<"KHOOOOB!"<<endl;
        else cout<<"HUTUTU!"<<endl;
    }
    return 0;
}
