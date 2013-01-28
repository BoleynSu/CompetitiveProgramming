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
		int m=cin.nextInt(),k=cin.nextInt();
		int[] d=new int[m],s=new int[m];
		for (int i=0;i<m;i++)
		{
			d[i]=cin.nextInt();
		}
		for (int i=0;i<m;i++)
		{
			s[i]=cin.nextInt();
		}
		int max=0,sum=0,ans=0;
		for (int i=0;i<m;i++)
		{
			if (max<s[i]) max=s[i];
			sum+=s[i];
			sum-=d[i];
			while (sum<0)
			{
				sum+=max;
				ans+=k;
			}
			ans+=d[i];
		}
		System.out.println(ans);
		cin.close();
	}
}

