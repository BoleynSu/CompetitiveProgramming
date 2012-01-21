import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	public static void main(String arg[])
	{
		new Solution();
	}
	int powWithMod(int a,int b,int c)
	{
		int d=1;
		a%=c;
		while (b!=0)
		{
			if (b%2==1)
			{
				d*=a;
				d%=c;
			}
			a*=a;
			a%=c;
			b/=2;
		}
		return d;
	}
	Solution()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int N=cin.nextInt(),M=cin.nextInt(),K=cin.nextInt();
		int y=0;
		for (int i=0;i<N;i++)
		{
			int x=cin.nextInt();
			int z=powWithMod(x,M,K);
			if (z==0) y++;
		}
		System.out.println(y);
	}
}
