/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[])
    {
        new Main();
    }
    boolean isPossible(int x,int y)
    {
        return 1<=x&&x<=10&&1<=y&&y<=9;
    }
    public Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        for (;;)
        {
            int N=cin.nextInt(),x=cin.nextInt(),y=cin.nextInt();
            if (N==0&&x==0&&y==0) break;
            char map[][]=new char[10+2][9+2];
            for (int i=1;i<=10;i++)
                for (int j=1;j<=9;j++)
                    map[i][j]=' ';
            char tl[]=new char[N];
            int xl[]=new int[N],yl[]=new int[N];
            for (int i=0;i<N;i++)
            {
                tl[i]=cin.next().charAt(0);
                xl[i]=cin.nextInt();
                yl[i]=cin.nextInt();
                map[xl[i]][yl[i]]=tl[i];
            }
            boolean YES=true;
            int ddx[]=new int[]{-1,1,0,0},ddy[]=new int[]{0,0,-1,1};
            for (int di=0;di<4;di++)
            {
                int gx=x+ddx[di],gy=y+ddy[di];
                if (!(1<=gx&&gx<=3&&4<=gy&&gy<=6)) continue;
                
                char backup=map[gx][gy];
                map[gx][gy]='*';
                boolean NOTYES=true;
                
                for (int i=0;i<N;i++)
                {
                    if (map[xl[i]][yl[i]]!=tl[i]) continue;
                    switch (tl[i])
                    {
                    case 'G':
                    {
                        for (int dx=1;xl[i]-dx>=1;dx++)
                            if (map[xl[i]-dx][yl[i]]==' ') ;
                            else if (map[xl[i]-dx][yl[i]]=='*') NOTYES=false;
                            else break;
                        for (int dx=1;xl[i]+dx<=10;dx++)
                            if (map[xl[i]+dx][yl[i]]==' ') ;
                            else if (map[xl[i]+dx][yl[i]]=='*') NOTYES=false;
                            else break;
                        break;
                    }
                    case 'R':
                    {
                        for (int dx=1;xl[i]-dx>=1;dx++)
                            if (map[xl[i]-dx][yl[i]]==' ') ;
                            else if (map[xl[i]-dx][yl[i]]=='*') NOTYES=false;
                            else break;
                        for (int dx=1;xl[i]+dx<=10;dx++)
                            if (map[xl[i]+dx][yl[i]]==' ') ;
                            else if (map[xl[i]+dx][yl[i]]=='*') NOTYES=false;
                            else break;
                        for (int dy=1;yl[i]-dy>=1;dy++)
                            if (map[xl[i]][yl[i]-dy]==' ') ;
                            else if (map[xl[i]][yl[i]-dy]=='*') NOTYES=false;
                            else break;
                        for (int dy=1;yl[i]+dy<=9;dy++)
                            if (map[xl[i]][yl[i]+dy]==' ') ;
                            else if (map[xl[i]][yl[i]+dy]=='*') NOTYES=false;
                            else break;
                        break;
                    }
                    case 'H':
                    {
                        int cdx[]=new int[]{-1,-1,1,1,0,0,0,0},cdy[]=new int[]{0,0,0,0,-1,-1,1,1};
                        int dx[]=new int[]{-2,-2,2,2,-1,1,-1,1},dy[]=new int[]{-1,1,-1,1,-2,-2,2,2};
                        for (int j=0;j<8;j++)
                        {
                            if (isPossible(xl[i]+cdx[j],yl[i]+cdy[j])
                                &&map[xl[i]+cdx[j]][yl[i]+cdy[j]]==' '
                                &&isPossible(xl[i]+dx[j],yl[i]+dy[j])
                                &&map[xl[i]+dx[j]][yl[i]+dy[j]]=='*')
                                NOTYES=false;
                        }
                        break;
                    }
                    case 'C':
                    {
                        boolean found;
                        found=false;
                        for (int dx=1;xl[i]-dx>=1;dx++)
                            if (map[xl[i]-dx][yl[i]]==' ') ;
                            else if(map[xl[i]-dx][yl[i]]=='*')
                            {
                                if (found) NOTYES=false;
                            }
                            else
                            {
                                if (found) break;
                                else found=true;
                            }
                        found=false;
                        for (int dx=1;xl[i]+dx<=10;dx++)
                            if (map[xl[i]+dx][yl[i]]==' ') ;
                            else if(map[xl[i]+dx][yl[i]]=='*')
                            {
                                if (found) NOTYES=false;
                            }
                            else
                            {
                                if (found) break;
                                else found=true;
                            }
                        found=false;
                        for (int dy=1;yl[i]-dy>=1;dy++)
                            if (map[xl[i]][yl[i]-dy]==' ') ;
                            else if (map[xl[i]][yl[i]-dy]=='*')
                            {
                                if (found) NOTYES=false;
                            }
                            else
                            {
                                if (found) break;
                                else found=true;
                            }
                        found=false;
                        for (int dy=1;yl[i]+dy<=9;dy++)
                            if (map[xl[i]][yl[i]+dy]==' ') ;
                            else if (map[xl[i]][yl[i]+dy]=='*')
                            {
                                if (found) NOTYES=false;
                            }
                            else
                            {
                                if (found) break;
                                else found=true;
                            }
                        break;
                    }
                    }
                }
                if (NOTYES) YES=false;
                map[gx][gy]=backup;
            }
            System.out.println(YES?"YES":"NO");
        }
    }
}

