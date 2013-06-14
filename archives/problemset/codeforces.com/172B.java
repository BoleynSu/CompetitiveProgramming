import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
	public static void main(String[] arg)
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		int a=scanner.nextInt(),b=scanner.nextInt(),m=scanner.nextInt(),r0=scanner.nextInt();
		int[] occurrence=new int[m];
		Arrays.fill(occurrence,-1);
		occurrence[r0]=0;
		for (int i=1;i<=m;i++)
		{
			r0=(r0*a+b)%m;
			if (occurrence[r0]!=-1)
			{
				System.out.println(i-occurrence[r0]);
				break;
			}
			occurrence[r0]=i;
		}
		scanner.close();
	}
}
