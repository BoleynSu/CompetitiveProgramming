#include <stdio.h>
#include <string.h>

const int MAXLENGTH=400+1;
typedef char string[MAXLENGTH];
int n;
string a,b,c;
int f[MAXLENGTH][MAXLENGTH];
string s[]={"no","yes"};

int main()
{
    scanf("%d",&n);
    for (int nn=1;nn<=n;nn++)
    {
        scanf("%s%s%s",&a,&b,&c);
        int al=strlen(a),bl=strlen(b),cl=strlen(c);
        for (int i=0;i<=al;i++)
            for (int j=0;j<=bl;j++)
            {
                f[i][j]=false;
                if (j>0&&b[j-1]==c[i+j-1]&&f[i][j-1]) f[i][j]=true;
                if (i>0&&a[i-1]==c[i+j-1]&&f[i-1][j]) f[i][j]=true;
                if (!i&&!j) f[i][j]=true;
            }
        printf("Data set %d: %s\n",nn,s[al+bl==cl&&f[al][bl]]);
    }
}
