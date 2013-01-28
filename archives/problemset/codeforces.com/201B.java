import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String arg[]) throws IOException
    {
        new Main();
    }
    public Main() throws IOException
    {
        new TaskA();
    }
}

class TaskA
{
    public TaskA() throws IOException
    {
        StreamTokenizer cin=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        cin.nextToken();
        int n=(int)cin.nval;
        cin.nextToken();
        int m=(int)cin.nval;
        long x2=0,x1=0,x0=0,y2=0,y1=0,y0=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                cin.nextToken();
                long x=i*4+2,y=j*4+2,c=(int)cin.nval;
                x2+=c;
                x1+=-c*2*x;
                x0+=c*x*x;
                y2+=c;
                y1+=-c*2*y;
                y0+=c*y*y;
            }
        long x=0,y=0,minxv=391993030919930309l,minyv=391993030919930309l;
        if (x2==0)
        {
            x=0;
            minxv=0;
        }
        else
        {
            for (int i=-1,t=(int)(-x1/(2*x2))/4;i<=1;i++)
                if (t+i>=0&&t+i<=n)
                {
                    long v=(x2*(t+i)*4+x1)*(t+i)*4+x0;
                    if (minxv>v)
                    {
                        minxv=v;
                        x=t+i;
                    }
                }
        }
        if (y2==0)
        {
            y=0;
            minyv=0;
        }
        else
        {
            for (int i=-1,t=(int)(-y1/(2*y2))/4;i<=1;i++)
            {
                if (t+i>=0&&t+i<=m)
                {
                    long v=(y2*(t+i)*4+y1)*(t+i)*4+y0;
                    if (minyv>v)
                    {
                        minyv=v;
                        y=t+i;
                    }
                }
            }
        }
        System.out.println(minxv+minyv);
        System.out.println(x+" "+y);
    }
}

