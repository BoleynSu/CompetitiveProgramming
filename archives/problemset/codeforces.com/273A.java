import java.io.BufferedInputStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] arg)
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int[] a=new int[n];
		for (int i=0;i<n;i++)
			a[i]=cin.nextInt();
		int m=cin.nextInt();
		long x=0;
		for (int i=0;i<m;i++)
		{
			int w=cin.nextInt(),h=cin.nextInt();
			if (a[w-1]>x) x=a[w-1];
			System.out.println(x);
			x+=h;
		}
		cin.close();
	}
}

