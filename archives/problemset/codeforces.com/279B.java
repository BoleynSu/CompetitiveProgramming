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
		int n=cin.nextInt(),t=cin.nextInt();
		int[] a=new int[n];
		for (int i=0;i<n;i++) a[i]=cin.nextInt();
		int sum=0,ans=0;
		for (int i=0,j=0;i<n;i++)
		{
			sum+=a[i];
			while (sum>t&&j<=i) sum-=a[j++];
			ans=Math.max(i-j+1,ans);
		}
		System.out.println(ans);
		cin.close();
	}
}
