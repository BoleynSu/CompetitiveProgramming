import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] arg)
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int a=cin.nextInt(),b=cin.nextInt(),n=cin.nextInt();
		boolean isPossible=true;
		for (int i=0,x=a;i<n;i++)
		{
			boolean found=false;
			for (int j=0;j<10;j++)
			{
				if ((x*10+j)%b==0)
				{
					x=(x*10+j)%b;
					found=true;
					break;
				}
			}
			if (!found) isPossible=false;
		}
		if (!isPossible) System.out.println(-1);
		else
		{
			System.out.print(a);
			for (int i=0,x=a;i<n;i++)
			{
				for (int j=0;j<10;j++)
				{
					if ((x*10+j)%b==0)
					{
						x=(x*10+j)%b;
						System.out.print(j);
						break;
					}
				}
			}
			System.out.println();
		}
	}
	
}

