import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int delta=0;
		char[] ans=new char[n];
		for (int i=0;i<n;i++)
		{
			int a=cin.nextInt(),g=cin.nextInt();
			if (-500<=delta+g&&delta+g<=500)
			{
				delta+=g;
				ans[i]='G';
			}
			else
			{
				delta-=a;
				ans[i]='A';
			}
		}
		System.out.println(String.copyValueOf(ans));
		cin.close();
	}
}
