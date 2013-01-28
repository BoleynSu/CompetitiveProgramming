import java.io.*;
import java.util.*;

class Main
{
    public static void main(String arg[])
    {
        new Main();
    }
    Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=0;t<T;t++)
        {
            int n=cin.nextInt(),m=cin.nextInt();
            int a[]=new int[n],b[]=new int[m];
            for (int i=0;i<n;i++) a[i]=cin.nextInt();
            for (int i=0;i<m;i++) b[i]=cin.nextInt();
            Arrays.sort(a);
            for (int i=0;i<m;i++)
            {
                int min=32,mina=a[0];
                for (int j=0;j<n;j++)
                {
                    int get=0;
                    for (int temp=a[j]^b[i];temp!=0;temp>>=1)
                        if ((temp&1)!=0) get++;
                    if (min>get)
                    {
                        min=get;
                        mina=a[j];
                    }
                }
                System.out.println(mina);
            }
        }
    }
}

