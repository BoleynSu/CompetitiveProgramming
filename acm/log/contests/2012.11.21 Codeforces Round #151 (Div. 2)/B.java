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
        int[] a=new int[n];
        for (int i=0;i<n;i++) a[i]=cin.nextInt();
        int sum=0;
        for (int i=0;i<n;i++) sum+=a[i];
        if (sum%n==0) System.out.println(n);
        else System.out.println(n-1);
        cin.close();
    }
}