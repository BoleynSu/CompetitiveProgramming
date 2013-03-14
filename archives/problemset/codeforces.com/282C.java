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
		String a=cin.next(),b=cin.next();
		if (a.length()!=b.length()) System.out.println("NO");
		else
		{
			int acnt=0,bcnt=0;
			for (int i=0;i<a.length();i++) if (a.charAt(i)=='1') acnt++;
			for (int i=0;i<b.length();i++) if (b.charAt(i)=='1') bcnt++;
			if (a.length()>1)
			{
				if ((bcnt!=0&&acnt==0)||(acnt!=0&&bcnt==0)) System.out.println("NO");
				else System.out.println("YES");
			}
			else
			{
				if (acnt!=bcnt) System.out.println("NO");
				else System.out.println("YES");
			}
		}
		cin.close();
	}
}
