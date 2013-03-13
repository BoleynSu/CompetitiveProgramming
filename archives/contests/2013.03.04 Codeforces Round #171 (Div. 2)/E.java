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
		String s=cin.next();
		int lsts=0;
		int[] lst=new int[s.length()];
		lst[lsts]=1;
		for (int i=1;i<s.length();i++)
			if (s.charAt(i-1)!=s.charAt(i)) lst[++lsts]=1;
			else lst[lsts]++;
		int f=2,g=lst[0];
		if (lsts%2!=0) lsts--;
		for (int i=2;i<=lsts;i+=2)
		{
			int f_=Math.min(f+Math.min(lst[i-1],2),g+2);
			int g_=Math.min(f,g)+lst[i];
			f=f_;
			g=g_;
		}
		System.out.println(Math.min(f,g));
		cin.close();
	}
}
