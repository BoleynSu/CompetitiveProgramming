import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	public static void main(String arg[])
	{
		new Solution();
	}
	Solution()
	{
		final int oo=19930309;
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int f[]=new int[n+1];
		Arrays.fill(f,oo);
		f[0]=0;
		ArrayList<Integer> super_prime=new ArrayList<Integer>();
		for (int i=0,j=0;i<=n;i++)
		{
			if (BigInteger.valueOf(i).isProbablePrime(100))
			{
				j++;
				if (BigInteger.valueOf(j).isProbablePrime(100))
				{
					super_prime.add(i);
					for (int k=i;k<=n;k++)
						f[k]=Math.min(f[k],f[k-i]+1);
				}
			}
		}
		if (f[n]==oo) System.out.println("0");
		else
		{
			System.out.println(f[n]);
			int x=f[n],y=super_prime.size()-1;
			while (x!=0)
			{
				int z=0;
				while (n<super_prime.get(y)||f[n-super_prime.get(y)]>=x) y--;
				n-=super_prime.get(y);
				x--;
				System.out.printf("%d%c",super_prime.get(y),x==0?'\n':' ');
			}
		}
	}
}
