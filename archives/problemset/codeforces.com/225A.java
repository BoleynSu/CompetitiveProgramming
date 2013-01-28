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
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int x=cin.nextInt();
		x=Math.min(x,7-x);
		boolean possible=true;
		for (int i=0;i<n;i++)
		{
			int a=cin.nextInt(),b=cin.nextInt();
			a=Math.min(a,7-a);
			b=Math.min(b,7-b);
			if (x==a||x==b) possible=false;
		}
		System.out.println(possible?"YES":"NO");
		cin.close();
	}
}
