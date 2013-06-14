import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main
{
	public static void main(String[] arg)
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		int n=scanner.nextInt();
		String[] s=new String[n];
		for (int i=0;i<n;i++) s[i]=scanner.next();
		int ans=-1;
		boolean check=true;
		while (check)
		{
			ans++;
			for (int j=0;j<n;j++)
				if (s[j].charAt(ans)!=s[0].charAt(ans))
					check=false;
		}
		System.out.println(ans);
		scanner.close();
	}
}
