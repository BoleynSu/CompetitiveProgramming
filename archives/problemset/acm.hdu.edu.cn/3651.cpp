#include <cstdio>
#include <algorithm>
using namespace std;

const int oo=(~0u)>>3;
int f[1024][10][10];
int c2i[256];

int main()
{
    c2i['1']=0;
    c2i['2']=1;
    c2i['3']=2;
    c2i['4']=3;
    c2i['5']=4;
    c2i['6']=5;
    c2i['7']=6;
    c2i['8']=7;
    c2i['9']=8;
    c2i['0']=9;
    char s[1024];
    while (gets(s))
    {
          int answer;
          for (int i=0;i<10;i++)
              for (int j=0;j<10;j++)
                  f[0][i][j]=-oo;
          f[0][c2i['5']][c2i['6']]=0;
          for (int t=1;;t++)
          {
              for (int i=0;i<10;i++)
                  for (int j=0;j<10;j++)
                      f[t][i][j]=-oo;
              for (int i=0;i<10;i++)
                  for (int j=i+1;j<10;j++)
                  {
                      for (int di=-1;di<=1;di++)
                          for (int dj=-1;dj<=1;dj++)
                              if ((i+di>=0&&i+di<10&&j+dj>=0&&j+dj<10)&&(f[t-1][i+di][j+dj]>=0))
                              {
                                 if (di==0||dj==0)
                                 {
                                    if (di==0&&i==c2i[s[f[t-1][i+di][j+dj]]])
                                       f[t][i][j]=max(f[t-1][i+di][j+dj]+1,f[t][i][j]);
                                    if (dj==0&&j==c2i[s[f[t-1][i+di][j+dj]]])
                                       f[t][i][j]=max(f[t-1][i+di][j+dj]+1,f[t][i][j]);
                                 }
                                 else f[t][i][j]=max(f[t-1][i+di][j+dj],f[t][i][j]);
                              }
                      if (f[t][i][j]>=0&&!s[f[t][i][j]])
                      {
                         answer=t;
                         goto print_answer;
                      }
                  }
          }
          print_answer:
          printf("%d\n",answer);
    }
}

