import java.io.BufferedInputStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] arg)
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		int n=scanner.nextInt();
		int[] a=new int[n];
		for (int i=0;i<n;i++) a[i]=scanner.nextInt();
		int m=scanner.nextInt();
		for (int i=0;i<m;i++)
		{
			int x=scanner.nextInt(),y=scanner.nextInt();
			x--;
			if (x-1>=0) a[x-1]+=y-1;
			if (x+1<n) a[x+1]+=a[x]-y;
			a[x]=0;
		}
		for (int i=0;i<n;i++) System.out.println(a[i]);
		scanner.close();
	}
}

