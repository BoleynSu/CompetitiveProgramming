import java.util.*;
import java.io.*;

public class Main {
	public static void main(String arg[])
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		long[] p=new long[n];
		for (int i=0;i<n;i++) p[i]=cin.nextLong();
		long[] q=new long[5];
		long[] c=new long[5];
		for (int i=0;i<5;i++)
		{
			q[i]=cin.nextLong();
			c[i]=0;
		}
		long m=0;
		for (int i=0;i<n;i++)
		{
			m+=p[i];
			for (int j=4;j>=0;j--)
			{
				c[j]+=m/q[j];
				m%=q[j];
			}
		}
		System.out.println(c[0]+" "+c[1]+" "+c[2]+" "+c[3]+" "+c[4]);
		System.out.println(m);
	}
}

