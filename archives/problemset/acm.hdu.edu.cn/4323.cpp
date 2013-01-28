#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 2048
int T,t,i,j,K,n,m,cnt;
char a[N][11],b[11];

inline int check2(char*A,char* B) {
  static int f[20][20],a[20],b[20];
  memset(f,0x7f,sizeof(f));
  f[0][0]=0;
  int la=strlen(A),
      lb=strlen(B);
  register int i,j;
  for (i=1;i<=la;i++) f[i][0]=i;
  for (i=1;i<=lb;i++) f[0][i]=i;
  for (i=1;i<=la;i++) a[i]=A[i-1];
  for (i=1;i<=lb;i++) b[i]=B[i-1];
  for (i=1;i<=la;i++)
    for (j=1;j<=lb;j++) {
      if (a[i]==b[j]) if (f[i][j]>f[i-1][j-1]) f[i][j]=f[i-1][j-1];
      if (a[i]!=b[j]) if (f[i][j]>f[i-1][j-1]+1) f[i][j]=f[i-1][j-1]+1;
      if (f[i][j]>f[i-1][j]+1) f[i][j]=f[i-1][j]+1;
      if (f[i][j]>f[i][j-1]+1) f[i][j]=f[i][j-1]+1;
    }
  //printf("f[%s][%s]=%d\n",A.data(),B.data(),f[la][lb]);
  return f[la][lb]<=K;
}


int main() {
  //freopen("in.txt","r",stdin);
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    printf("Case #%d:\n",t);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%s",a[i]);

    for (i=1;i<=m;i++) {
      scanf("%s%d",b,&K);
      for (j=1,cnt=0;j<=n;j++)
        cnt+=check2(a[j],b);
      printf("%d\n",cnt);
    }
  }
  return 0;
}
