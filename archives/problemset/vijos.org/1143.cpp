#include <stdio.h>

const int MAXN=20;
typedef int array[MAXN+2][MAXN+2];
typedef int function[2][MAXN+2][MAXN+2][MAXN+2];
#define K(n) ((n)%2)
int n;
array map;
function F;

int point(int k,int x,int y,int z)
{
    int p=map[x][k-x];
    if (y!=x) p+=map[y][k-y];
    if ((z!=y)&&(z!=x)) p+=map[z][k-z];
    //printf("point(%d,%d,%d,%d)=%d\n",k,x,y,z,p);
    return p;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
    
    F[K(1)][1][1][1]=map[1][1];
    for (int k=2;k<n*2;k++)
    {
        int end=(k<n?k:n);
        for (int x=1;x<=end;x++)
            for (int y=1;y<=end;y++)
                for (int z=1;z<=end;z++)
                {
                    F[K(k)][x][y][z]=0;
                    for (int dx=-1;dx<=0;dx++)
                        for (int dy=-1;dy<=0;dy++)
                            for (int dz=-1;dz<=0;dz++)
                            {
                                int nx=x+dx,ny=y+dy,nz=z+dz;
                                if ((nx>0)&&(ny>0)&&(nz>0)&&(nx<k)&&(ny<k)&&(nz<k))
                                {
                                   //printf("F[k-1][...]%d\n",F[K(k-1)][nx][ny][nz]);
                                   int value=F[K(k-1)][nx][ny][nz]+point(k+1,x,y,z);
                                   if (value>F[K(k)][x][y][z]) F[K(k)][x][y][z]=value;
                                }
                            }
                    //printf("F[%d][(%d,%d),(%d,%d),(%d,%d)]=%d\n",k,x,k+1-x,y,k+1-y,z,k+1-z,F[K(k)][x][y][z]);
                }
    }
    printf("%d\n",F[K(n*2-1)][n][n][n]);
    //scanf("%%");
}
