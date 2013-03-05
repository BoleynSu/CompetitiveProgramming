import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt(),m=cin.nextInt();
		int[] a=new int[n+2];
		for (int i=1;i<=n;i++)
			a[i]=cin.nextInt();
		int[] G=new int[n+2],L=new int[n+2];
		for (int i=1;i<=n;i++)
		{
			L[i]=i;
			G[i]=i;
			if (i>1&&a[i-1]<=a[i]) L[i]=L[i-1];
			if (i>1&&a[i-1]>=a[i]) G[i]=G[i-1];
		}
		for (int i=0;i<m;i++)
		{
			int l=cin.nextInt(),r=cin.nextInt();
			if (L[G[r]]<=l) System.out.println("Yes");
			else System.out.println("No");
		}
		cin.close();
	}
}
