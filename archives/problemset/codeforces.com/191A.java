import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String arg[])
	{
		new Main();
	}
	Main()
	{
		new TaskA();
	}
}

class TaskA
{
	TaskA()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		String s[]=new String[n];
		for (int i=0;i<n;i++)
			s[i]=cin.next();
		int ans=0;
		for (int r=0;r<26;r++)
		{
			int f[]=new int[26];
			Arrays.fill(f,-19930309);
			f[r]=0;
			for (int i=0;i<n;i++)
			{
				f[s[i].charAt(s[i].length()-1)-'a']=Math.max(f[s[i].charAt(s[i].length()-1)-'a'],f[s[i].charAt(0)-'a']+s[i].length());
			}
			ans=Math.max(f[r],ans);
		}
		System.out.println(ans);
		cin.close();
	}
}
