import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] arg)
    {
        new Main();
    }
    public Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int n=cin.nextInt();
        if (n<=2) System.out.println(-1);
        else
        {
            System.out.print(n+" "+(n-1)+" ");
            for (int i=3;i<=n;i++) System.out.print((i-2)+(i==n?"\n":" "));
        }
        cin.close();
    }
}
