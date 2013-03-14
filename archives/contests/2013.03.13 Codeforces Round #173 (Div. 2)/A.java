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
		int x=0;
		for (int i=0;i<n;i++)
		{
			String op=cin.next();
			boolean add=false;
			for (int j=0;j<op.length();j++) if (op.charAt(j)=='+') add=true;
			if (add) x++;
			else x--;
		}
		System.out.println(x);
		cin.close();
	}
}
