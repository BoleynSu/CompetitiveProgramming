#include <cstdio>
#include <cstring>
using namespace std;

char s[1025];
int n;
int f[1025][1025];

int main()
{
    while (gets(s))
    {
          n=strlen(s)+1;
          for (int i=0;i<=n-1;i++) f[1][i]=i+1;
          for (int i=2;i<=n;i++)
              for (int j=0;j<=n-i;j++)
              {
                  if (s[i-2]=='I') if (j) f[i][j]=f[i][j-1]+f[i-1][n-(i-1)]-f[i-1][j];
                                   else f[i][j]=f[i-1][n-(i-1)]-f[i-1][j];
                  else if (s[i-2]=='D') if (j) f[i][j]=f[i][j-1]+f[i-1][j];
                                        else f[i][j]=f[i-1][j];
                  else
                      if (j) f[i][j]=f[i][j-1]+f[i-1][n-(i-1)];
                      else f[i][j]=f[i-1][n-(i-1)];
                  f[i][j]=(f[i][j]%1000000007+1000000007)%1000000007;
              }
          printf("%d\n",f[n][0]);
    }
}

