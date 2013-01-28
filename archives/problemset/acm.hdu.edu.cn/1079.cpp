#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int ds[102][13];
int f[102][13][32];

int main()
{
    for (int i=0;i<=101;i++)
    {
        if (i!=0&&i%4==0) ds[i][2]=29;
        else ds[i][2]=28;
        ds[i][1]=ds[i][3]=ds[i][5]=ds[i][7]=ds[i][8]=ds[i][10]=ds[i][12]=31;
        ds[i][4]=ds[i][6]=ds[i][9]=ds[i][11]=30;
    }
    for (int y=101;y>=0;y--)
        for (int m=12;m>=1;m--)
            for (int d=ds[y][m];d>=1;d--)
            {
                f[y][m][d]=true;
                if (y==101&&(m>11||(m==11&&d>4))) f[y][m][d]=false;
                else
                {
                    int ny,nm,nd;
                    if (m==12) ny=y+1,nm=1,nd=d;
                    else ny=y,nm=m+1,nd=d;
                    if (ds[ny][nm]>=nd&&f[ny][nm][nd]) f[y][m][d]=false;

                    if (d==ds[y][m])
                    {
                        if (m==12) ny=y+1,nm=1,nd=1;
                        else ny=y,nm=m+1,nd=1;
                    }
                    else ny=y,nm=m,nd=d+1;
                    if (f[ny][nm][nd]) f[y][m][d]=false;
                }
            }
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int Y,M,D;
        scanf("%d%d%d",&Y,&M,&D);
        Y-=1900;
        puts(!f[Y][M][D]?"YES":"NO");
    }
}

