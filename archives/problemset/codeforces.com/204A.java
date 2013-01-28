import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String arg[])
    {
        new Main();
    }
    public Main()
    {
        new TaskA();
    }
}

class TaskA
{
    public TaskA()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        long l=cin.nextLong(),r=cin.nextLong();
        long answer=0;
        long a=1,b=1;
        while (a!=1000000000000000000l&&a*10<=l) a*=10;
        while (b!=1000000000000000000l&&b*10<=r) b*=10;
        for (long i=a;i<=b;i*=10)
        {
            long begin=i==a?l/i:1;
            long end=i==b?r/i:9;
            if (i==1)
            {
                for (long j=begin;j<=end;j++)
                {
                    long x=j;
                    long y=j;
                    if (l>x) x=l;
                    if (r<y) y=r;
                    if (x<=y) answer+=y-x+1;
                }
            }
            else
            {
                for (long j=begin;j<=end;j++)
                {
                    long x=0;
                    long y=(i/10-1)*10;
                    if (l-(j*i+j)>x) x=((l/10+(l%10>l/i?1:0))*10+l/i)-(j*i+j);
                    if (r-(j*i+j)<y) y=((r/10+(r%10<r/i?-1:0))*10+r/i)-(j*i+j);
                    if (x<=y) answer+=(y-x)/10+1;
                }
            }
        }
        System.out.println(answer);
        cin.close();
    }
}    
